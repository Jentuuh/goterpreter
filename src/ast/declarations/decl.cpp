#include <iostream>
#include "decl.h"
#include "../../environment/interp/env.h"

// ============= VarDecl =============
VarDecl::VarDecl(VarSpecList* varspecs): varspecs{varspecs}{};

void VarDecl::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
        varspecs->interp(env, funcEnv);
        // // Get variable identifiers on the left
        // std::vector<std::string> identifiers;
        // varspec->idList->getIdentifierStrings(identifiers);

        // // Get values from the expression list on the right
        // std::vector<std::shared_ptr<Literal>> values;
        // if(varspec->expList.get() != nullptr)
        // {
        //         varspec->expList->interp(env, funcEnv, values);
        // }
        // else
        // {
        //         // Default value for integers (0)
        //         if(std::dynamic_pointer_cast<IntegerType>(varspec->type) != nullptr)
        //         {
        //                 for (int i = 0; i < identifiers.size(); i++)
        //                 {
        //                         values.push_back(std::make_shared<IntLiteral>(0));
        //                 }
        //         }

        //         // Default value for booleans (false)
        //         if(std::dynamic_pointer_cast<BooleanType>(varspec->type) != nullptr)
        //         {
        //                 for (int i = 0; i < identifiers.size(); i++)
        //                 {
        //                         values.push_back(std::make_shared<BoolLiteral>(false));
        //                 }
        //         }       
        // }

        // // Add variables to the current scope
        // for (int i = 0; i < identifiers.size(); i++)
        // {
        //         env.currentScope()->add(identifiers[i], varspec->type, values[i]);
        // }
}

void VarDecl::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
        varspecs->typecheck(env, funcEnv,typeErrors);
        // // Get variable identifiers on the left
        // std::vector<std::string> identifiers;
        // varspec->idList->getIdentifierStrings(identifiers);

        // // TODO: CHECK IF IDENTIFIERS DIDN'T ALREADY EXIST IN CURRENT/GLOBAL SCOPE!
        // for (std::string i : identifiers)
        // {
        //         if(env.varExists(i))
        //                 typeErrors.push_back("Type error in VarDecl: Variable '" + i + "' was already declared in the current scope.");
        // }


        // // Get values from the expression list on the right
        // std::vector<std::shared_ptr<Type>> types;
        // if(varspec->expList.get() != nullptr)
        // {
        //         varspec->expList->typecheck(env, funcEnv, types, typeErrors);
        // }

        // if(identifiers.size() != types.size() && types.size() != 0)
        // {
        //         typeErrors.push_back("Type error in VarDecl: The amount of variables on the left side of the assignment operator should be equal to the amount of expressions on the right.");  
        // }         

        // // Check if type in var decl corresponds to types in expression list
        // for(std::shared_ptr<Type> t : types)
        // {
        //         // Integer and non-integer
        //         if(std::dynamic_pointer_cast<IntegerType>(varspec->type) != nullptr && std::dynamic_pointer_cast<IntegerType>(t) == nullptr)
        //         {
        //                 typeErrors.push_back("Type error in VarDecl: Trying to assign non-integer to integer type variable " + identifiers[0] + ".");
        //         }

        //         // Boolean and non-boolean
        //         if(std::dynamic_pointer_cast<BooleanType>(varspec->type) != nullptr && std::dynamic_pointer_cast<BooleanType>(t) == nullptr)
        //         {
        //                 typeErrors.push_back("Type error in VarDecl: Trying to assign non-boolean to boolean type variable " + identifiers[0] + ".");
        //         }
        // }

        // // Add variables to the current scope (without values)
        // for (int i = 0; i < identifiers.size(); i++)
        // {
        //         env.currentScope()->add(identifiers[i], varspec->type, nullptr);
        // }
}

// ============= FunctionDecl =============
FunctionDecl::FunctionDecl(Identifier* funcName, Signature* sign, Block* body): funcName{funcName}, funcSign{sign}, funcBody{body}{}
FunctionDecl::FunctionDecl(std::shared_ptr<Identifier> funcName, std::shared_ptr<Signature> sign, std::shared_ptr<Block> body): funcName{funcName}, funcSign{sign}, funcBody{body}{}

void FunctionDecl::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
        // Add the function declaration to our function environment
        funcEnv.declaredFunctions.add(funcName->name, std::make_shared<FunctionDecl>(funcName, funcSign, funcBody));
        return;
}

void FunctionDecl::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
        // Check if function is already defined
        if(funcEnv.lookupVar(funcName->name) != nullptr)
        {
                typeErrors.push_back("Type error in FunctionDecl: Trying to declare function " + funcName->name + " but " + funcName->name + " was already declared.");
                return;
        }

        // TODO: CHECK IF FUNCTION RETURNS AS MANY VALUES AS IT SAYS IT SHOULD!

        // Get parameter types
        std::vector<std::pair<std::vector<std::string>, std::shared_ptr<Type>>> idsAndTypes;
        if(funcSign->parameters != nullptr)
        {
                funcSign->parameters->getIdentifiersWithTypes(idsAndTypes);
        }

        // Need to push the function on the call stack (otherwise the typechecker of the body does not know where to find the function's information)
        funcEnv.pushFunc(funcName->name);

        // We are entering the function's scope
        env.pushScope();

        // Add argument types to function scope
        int valueIndex = 0;
        for(int i = 0; i < idsAndTypes.size(); i++)
        {
                for(int j = 0; j < idsAndTypes.at(i).first.size(); j++)
                {
                env.currentScope()->add(idsAndTypes.at(i).first.at(j), idsAndTypes.at(i).second, nullptr);
                valueIndex++;
                }
        }
        
        // We also need to add the function to the declared functions BEFORE typechecking the body (otherwise the typechecker can't find the function's information)
        funcEnv.declaredFunctions.add(funcName->name, std::make_shared<FunctionDecl>(funcName, funcSign, funcBody));

        // Typecheck the function's body
        funcBody->typecheck(env, funcEnv, typeErrors);

        env.popScope();
        funcEnv.popFunc();

}
