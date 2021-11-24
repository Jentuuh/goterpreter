#pragma once
#include <utility>

struct ScopedEnv;
struct FunctionEnv;

struct Identifier{
    char* name;

    Identifier(char* name);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv);
};