#pragma once
#include <memory>
#include <utility>
#include "../identifiers/identifierlist.h"
#include "../types/type.h"

struct ScopedEnv; 
struct FunctionEnv;
typedef std::pair<ScopedEnv*, FunctionEnv*> Environments;

// TODO: Make local function scope (symbol table) of these parameters!

struct ParameterDecl{

    std::shared_ptr<Type> type;
    std::shared_ptr<IdentifierList> identifiers;

    ParameterDecl(Type* type, IdentifierList* identifiers);
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv);
};