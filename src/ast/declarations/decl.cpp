#include <iostream>
#include "decl.h"
#include "../../environment/interp/env.h"

// ============= VarDecl =============
VarDecl::VarDecl(VarSpecList* varspecs): varspecs{varspecs}{};

void VarDecl::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
        varspecs->interp(env, funcEnv);
}

void VarDecl::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
        varspecs->typecheck(env, funcEnv,typeErrors);
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

        // Check whether function should return something, and if every path of the function returns something if that's the case
        if(funcBody->amountPaths() + 1 > funcBody->countReturnStatements() && funcSign->result !=nullptr)
        {
                typeErrors.push_back("Type error in FunctionDecl: Function " + funcName->name + " expects return value(s), but not all paths return a value.");
        }

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
