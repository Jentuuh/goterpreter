#include <iostream>
#include "decl.h"
#include "../../environment/interp/env.h"

// ============= VarDecl =============
VarDecl::VarDecl(VarSpec* varspec): varspec{varspec}{};

Environments VarDecl::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
        // TODO: implement
}

// ============= FunctionDecl =============
FunctionDecl::FunctionDecl(Identifier* funcName, Signature* sign, Block* body): funcName{funcName}, funcSign{sign}, funcBody{body}{}

Environments FunctionDecl::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
        // Add the function declaration to our function environment
        funcEnv.declaredFunctions.add(funcName->name, std::make_shared<FunctionDecl>(funcName.get(), funcSign.get(), funcBody.get()));
        return Environments(&env, &funcEnv);
}