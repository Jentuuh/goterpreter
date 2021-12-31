#include "./varspeclist.h"
#include "../../environment/interp/env.h"
#include <iostream>

// ============= PairVarSpecList =============
PairVarSpecList::PairVarSpecList(VarSpec* h, VarSpecList* tail): head{h}, tail{tail}{}


void PairVarSpecList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{   
        // Get variable identifiers on the left
        std::vector<std::string> identifiers;
        head->idList->getIdentifierStrings(identifiers);

        // Get values from the expression list on the right
        std::vector<std::shared_ptr<Literal>> values;
        if(head->expList != nullptr)
        {
                head->expList->interp(env, funcEnv, values);
        }
        else
        {
                // Default value for integers (0)
                if(std::dynamic_pointer_cast<IntegerType>(head->type) != nullptr)
                {
                        for (int i = 0; i < identifiers.size(); i++)
                        {
                                values.push_back(std::make_shared<IntLiteral>(0));
                        }
                }

                // Default value for booleans (false)
                if(std::dynamic_pointer_cast<BooleanType>(head->type) != nullptr)
                {
                        for (int i = 0; i < identifiers.size(); i++)
                        {
                                values.push_back(std::make_shared<BoolLiteral>(false));
                        }
                }       
        }

        // Add variables to the current scope
        for (int i = 0; i < identifiers.size(); i++)
        {
                env.currentScope()->add(identifiers[i], head->type, values[i]);
        }

        tail->interp(env, funcEnv);
}

void PairVarSpecList::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    // Get variable identifiers on the left
    std::vector<std::string> identifiers;
    head->idList->getIdentifierStrings(identifiers);

    for (std::string i : identifiers)
    {
            std::pair<int, bool> varExists = env.varExists(i);
            // Global variables can have an appearance count of 2, local variables only of 1 (because of the prebuilt environment)
            if((varExists.first >= 2 && varExists.second && env.currentScope()->localScopeId == 0) || (varExists.first >= 1 && !varExists.second))
                    typeErrors.push_back("Type error in VarDecl: Variable '" + i + "' was already declared in the current scope.");
    }


    // Get values from the expression list on the right
    std::vector<std::shared_ptr<Type>> types;
    if(head->expList != nullptr)
    {
            head->expList->typecheck(env, funcEnv, types, typeErrors);
    }

    if(identifiers.size() != types.size() && types.size() != 0)
    {
            typeErrors.push_back("Type error in VarDecl: The amount of variables/expressions on the left side of the assignment operator should be equal to the amount of expressions on the right.");  
    }         

    // Check if type in var decl corresponds to types in expression list
    for(std::shared_ptr<Type> t : types)
    {
        // If no type is specified, we don't need to check types
        if(head->type != nullptr)
        {
                // Integer and non-integer
                if(std::dynamic_pointer_cast<IntegerType>(head->type) != nullptr && std::dynamic_pointer_cast<IntegerType>(t) == nullptr)
                {
                        typeErrors.push_back("Type error in VarDecl: Trying to assign non-integer to integer type variable " + identifiers[0] + ".");
                }

                // Boolean and non-boolean
                if(std::dynamic_pointer_cast<BooleanType>(head->type) != nullptr && std::dynamic_pointer_cast<BooleanType>(t) == nullptr)
                {
                        typeErrors.push_back("Type error in VarDecl: Trying to assign non-boolean to boolean type variable " + identifiers[0] + ".");
                }
        } 
    }

    // Add variables to the current scope (without values)
    for (int i = 0; i < identifiers.size(); i++)
    {
            if(head->type != nullptr)
            {
                // If we specified a type, make sure we also pass it to the environment
                env.currentScope()->add(identifiers[i], head->type, nullptr);
            } else {
                if(i < types.size())
                {
                        // If we didn't specify any type, we assign the type of the right-hand expression
                        env.currentScope()->add(identifiers[i], types[i], nullptr);
                } else {
                        env.currentScope()->add(identifiers[i], nullptr, nullptr);
                }
            }
    }

    tail->typecheck(env, funcEnv, typeErrors);
}

 void PairVarSpecList::buildReferenceGraph(std::vector<std::pair<std::string, std::string>>& referenceGraph)
 {
        head->getReferencePairs(referenceGraph);
        tail->buildReferenceGraph(referenceGraph);
 }

void PairVarSpecList::preBuildGlobalsEnvironment(ScopedEnv& preBuiltEnv, FunctionEnv& funcEnv)
{
        // Get variable identifiers on the left
        std::vector<std::string> identifiers;
        head->idList->getIdentifierStrings(identifiers);

        // Get values from the expression list on the right
        std::vector<std::shared_ptr<Type>> types;
        if(head->expList != nullptr)
        {
                head->expList->getTypes(preBuiltEnv, funcEnv, types);
        }

       // Add variables to the current scope (without values)
        for (int i = 0; i < identifiers.size(); i++)
        {
                if(head->type != nullptr)
                {
                        // If we specified a type, make sure we also pass it to the environment
                        preBuiltEnv.currentScope()->add(identifiers[i], head->type, nullptr);
                } else {
                        if(i < types.size())
                        {
                                // If we didn't specify any type, we assign the type of the right-hand expression
                                preBuiltEnv.currentScope()->add(identifiers[i], types[i], nullptr);
                        } else {
                                preBuiltEnv.currentScope()->add(identifiers[i], nullptr, nullptr);
                        }
                }
        }

        tail->preBuildGlobalsEnvironment(preBuiltEnv, funcEnv);
}

// ============= LastVarSpecList =============
LastVarSpecList::LastVarSpecList(VarSpec* l): last{l}{}


void LastVarSpecList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
        // Get variable identifiers on the left
        std::vector<std::string> identifiers;
        last->idList->getIdentifierStrings(identifiers);

        // Get values from the expression list on the right
        std::vector<std::shared_ptr<Literal>> values;
        if(last->expList != nullptr)
        {
                last->expList->interp(env, funcEnv, values);
        }
        else
        {
                // Default value for integers (0)
                if(std::dynamic_pointer_cast<IntegerType>(last->type) != nullptr)
                {
                        for (int i = 0; i < identifiers.size(); i++)
                        {
                                values.push_back(std::make_shared<IntLiteral>(0));
                        }
                }

                // Default value for booleans (false)
                if(std::dynamic_pointer_cast<BooleanType>(last->type) != nullptr)
                {
                        for (int i = 0; i < identifiers.size(); i++)
                        {
                                values.push_back(std::make_shared<BoolLiteral>(false));
                        }
                }       
        }

        // Add variables to the current scope
        for (int i = 0; i < identifiers.size(); i++)
        {
                env.currentScope()->add(identifiers[i], last->type, values[i]);
        }
}

void LastVarSpecList::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    // Get variable identifiers on the left
    std::vector<std::string> identifiers;
    last->idList->getIdentifierStrings(identifiers);

    for (std::string i : identifiers)
    {
            std::pair<int, bool> varExists = env.varExists(i);
            if((varExists.first >= 2 && varExists.second && env.currentScope()->localScopeId == 0) || (varExists.first >= 1 && !varExists.second))
                    typeErrors.push_back("Type error in VarDecl: Variable '" + i + "' was already declared in the current scope.");
    }


    // Get values from the expression list on the right
    std::vector<std::shared_ptr<Type>> types;
    if(last->expList != nullptr)
    {
            last->expList->typecheck(env, funcEnv, types, typeErrors);
    }

    if(identifiers.size() != types.size() && types.size() != 0)
    {
            typeErrors.push_back("Type error in VarDecl: The amount of variables on the left side of the assignment operator should be equal to the amount of expressions on the right. Left size: " + std::to_string(identifiers.size()) + " Right size: " + std::to_string(types.size()));  
    }         

    // Check if type in var decl corresponds to types in expression list
    for(std::shared_ptr<Type> t : types)
    {
        // If no type is specified, we don't need to check types
        if(last->type != nullptr)
        {
            // Integer and non-integer
            if(std::dynamic_pointer_cast<IntegerType>(last->type) != nullptr && std::dynamic_pointer_cast<IntegerType>(t) == nullptr)
            {
                    typeErrors.push_back("Type error in VarDecl: Trying to assign non-integer to integer type variable " + identifiers[0] + ".");
            }

            // Boolean and non-boolean
            if(std::dynamic_pointer_cast<BooleanType>(last->type) != nullptr && std::dynamic_pointer_cast<BooleanType>(t) == nullptr)
            {
                    typeErrors.push_back("Type error in VarDecl: Trying to assign non-boolean to boolean type variable " + identifiers[0] + ".");
            }
        }
    }

    // Add variables to the current scope (without values)
    for (int i = 0; i < identifiers.size(); i++)
    {
        if(last->type != nullptr)
        {
        // If we specified a type, make sure we also pass it to the environment
        env.currentScope()->add(identifiers[i], last->type, nullptr);
        } else {
                if(i < types.size())
                {
                        // If we didn't specify any type, we assign the type of the right-hand expression
                        env.currentScope()->add(identifiers[i], types[i], nullptr);
                } else {
                        env.currentScope()->add(identifiers[i], nullptr, nullptr);
                }
        }
    }
}

 void LastVarSpecList::buildReferenceGraph(std::vector<std::pair<std::string, std::string>>& referenceGraph)
 {
        last->getReferencePairs(referenceGraph);
 }

void LastVarSpecList::preBuildGlobalsEnvironment(ScopedEnv& preBuiltEnv, FunctionEnv& funcEnv)
{
       // Get variable identifiers on the left
        std::vector<std::string> identifiers;
        last->idList->getIdentifierStrings(identifiers);

        // Get values from the expression list on the right
        std::vector<std::shared_ptr<Type>> types;
        if(last->expList != nullptr)
        {
                last->expList->getTypes(preBuiltEnv, funcEnv, types);
        }

       // Add variables to the current scope (without values)
        for (int i = 0; i < identifiers.size(); i++)
        {
                if(last->type != nullptr)
                {
                        // If we specified a type, make sure we also pass it to the environment
                        preBuiltEnv.currentScope()->add(identifiers[i], last->type, nullptr);
                } else {
                        if(i < types.size())
                        {
                                // If we didn't specify any type, we assign the type of the right-hand expression
                                preBuiltEnv.currentScope()->add(identifiers[i], types[i], nullptr);
                        } else {
                                preBuiltEnv.currentScope()->add(identifiers[i], nullptr, nullptr);
                        }
                }
        }
}