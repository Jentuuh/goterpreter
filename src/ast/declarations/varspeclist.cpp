#include "./varspeclist.h"
#include "../../environment/interp/env.h"

// ============= PairVarSpecList =============
PairVarSpecList::PairVarSpecList(VarSpec* h, VarSpecList* tail): head{h}, tail{tail}{}

int PairVarSpecList::length()
{

}

void PairVarSpecList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{   
    // Get variable identifiers on the left
        std::vector<std::string> identifiers;
        head->idList->getIdentifierStrings(identifiers);

        // Get values from the expression list on the right
        std::vector<std::shared_ptr<Literal>> values;
        if(head->expList.get() != nullptr)
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

    // TODO: CHECK IF IDENTIFIERS DIDN'T ALREADY EXIST IN CURRENT/GLOBAL SCOPE!
    for (std::string i : identifiers)
    {
            if(env.varExists(i))
                    typeErrors.push_back("Type error in VarDecl: Variable '" + i + "' was already declared in the current scope.");
    }


    // Get values from the expression list on the right
    std::vector<std::shared_ptr<Type>> types;
    if(head->expList.get() != nullptr)
    {
            head->expList->typecheck(env, funcEnv, types, typeErrors);
    }

    if(identifiers.size() != types.size() && types.size() != 0)
    {
            typeErrors.push_back("Type error in VarDecl: The amount of variables on the left side of the assignment operator should be equal to the amount of expressions on the right.");  
    }         

    // Check if type in var decl corresponds to types in expression list
    for(std::shared_ptr<Type> t : types)
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

    // Add variables to the current scope (without values)
    for (int i = 0; i < identifiers.size(); i++)
    {
            env.currentScope()->add(identifiers[i], head->type, nullptr);
    }

    tail->typecheck(env, funcEnv, typeErrors);
}

 void PairVarSpecList::buildReferenceGraph(std::vector<std::pair<std::string, std::string>>& referenceGraph)
 {
        head->getReferencePairs(referenceGraph);
        tail->buildReferenceGraph(referenceGraph);
 }


// ============= LastVarSpecList =============
LastVarSpecList::LastVarSpecList(VarSpec* l): last{l}{}

int LastVarSpecList::length()
{

}

void LastVarSpecList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
        // Get variable identifiers on the left
        std::vector<std::string> identifiers;
        last->idList->getIdentifierStrings(identifiers);

        // Get values from the expression list on the right
        std::vector<std::shared_ptr<Literal>> values;
        if(last->expList.get() != nullptr)
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

    // TODO: CHECK IF IDENTIFIERS DIDN'T ALREADY EXIST IN CURRENT/GLOBAL SCOPE!
    for (std::string i : identifiers)
    {
            if(env.varExists(i))
                    typeErrors.push_back("Type error in VarDecl: Variable '" + i + "' was already declared in the current scope.");
    }


    // Get values from the expression list on the right
    std::vector<std::shared_ptr<Type>> types;
    if(last->expList.get() != nullptr)
    {
            last->expList->typecheck(env, funcEnv, types, typeErrors);
    }

    if(identifiers.size() != types.size() && types.size() != 0)
    {
            typeErrors.push_back("Type error in VarDecl: The amount of variables on the left side of the assignment operator should be equal to the amount of expressions on the right.");  
    }         

    // Check if type in var decl corresponds to types in expression list
    for(std::shared_ptr<Type> t : types)
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

    // Add variables to the current scope (without values)
    for (int i = 0; i < identifiers.size(); i++)
    {
            env.currentScope()->add(identifiers[i], last->type, nullptr);
    }
}

 void LastVarSpecList::buildReferenceGraph(std::vector<std::pair<std::string, std::string>>& referenceGraph)
 {
        last->getReferencePairs(referenceGraph);
 }

