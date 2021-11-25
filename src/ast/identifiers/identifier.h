#pragma once
#include <utility>
#include <string>

struct ScopedEnv;
struct FunctionEnv;

struct Identifier{
    std::string name;

    Identifier(char* name);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv);
};