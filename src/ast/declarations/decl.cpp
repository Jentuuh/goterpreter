#include <iostream>
#include "decl.h"
#include "../../environment/interp/env.h"

// ============= VarDecl =============
VarDecl::VarDecl(VarSpec* varspec): varspec{varspec}{};

void VarDecl::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
        // Get variable identifiers on the left
        std::vector<std::string> identifiers;
        varspec->idList->getIdentifierStrings(identifiers);

        // Get values from the expression list on the right
        std::vector<std::shared_ptr<Literal>> values;
        if(varspec->expList.get() != nullptr)
        {
                varspec->expList->interp(env, funcEnv, values);
        }
        else
        {
                // Default value for integers (0)
                if(std::dynamic_pointer_cast<IntegerType>(varspec->type) != nullptr)
                {
                        for (int i = 0; i < identifiers.size(); i++)
                        {
                                values.push_back(std::make_shared<IntLiteral>(0));
                        }
                }

                // Default value for booleans (false)
                if(std::dynamic_pointer_cast<BooleanType>(varspec->type) != nullptr)
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
                env.currentScope()->add(identifiers[i], varspec->type, values[i]);
        }
        // for (auto v : values)
        // {
        //       v->printValue();
        // }
        // for(auto s : identifiers)
        // {
        //         env.currentScope()->add(s, varspec->type, );
        //         std::cout << s << std::endl;
        // }
}

void VarDecl::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
        // Get variable identifiers on the left
        std::vector<std::string> identifiers;
        varspec->idList->getIdentifierStrings(identifiers);

        // Get values from the expression list on the right
        std::vector<std::shared_ptr<Type>> types;
        if(varspec->expList.get() != nullptr)
        {
                varspec->expList->typecheck(env, funcEnv, types, typeErrors);
        }         

        // Check if type in var decl corresponds to types in expression list
        for(std::shared_ptr<Type> t : types)
        {
                // Integer and non-integer
                if(std::dynamic_pointer_cast<IntegerType>(t) != nullptr && std::dynamic_pointer_cast<IntegerType>(varspec->type) == nullptr)
                {
                        typeErrors.push_back("Type error in VarDecl: Trying to assign non-integer to integer type variable.");
                }

                // Boolean and non-boolean
                if(std::dynamic_pointer_cast<BooleanType>(t) != nullptr && std::dynamic_pointer_cast<BooleanType>(varspec->type) != nullptr)
                {
                        typeErrors.push_back("Type error in VarDecl: Trying to assign non-boolean to boolean type variable.");
                }

        }

        // Add variables to the current scope (without values)
        for (int i = 0; i < identifiers.size(); i++)
        {
                env.currentScope()->add(identifiers[i], varspec->type, nullptr);
        }
}

// ============= FunctionDecl =============
FunctionDecl::FunctionDecl(Identifier* funcName, Signature* sign, Block* body): funcName{funcName}, funcSign{sign}, funcBody{body}{}

void FunctionDecl::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
        // Add the function declaration to our function environment
        funcEnv.declaredFunctions.add(funcName->name, std::make_shared<FunctionDecl>(funcName.get(), funcSign.get(), funcBody.get()));
        return;
}

void FunctionDecl::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
        // TODO: implement
}
