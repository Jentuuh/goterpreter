#pragma once
#include <utility>

struct ScopedEnv;
struct FunctionEnv;
typedef std::pair<ScopedEnv*, FunctionEnv*> Environments;

struct Identifier{
    char* name;

    Identifier(char* name);
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv);
};