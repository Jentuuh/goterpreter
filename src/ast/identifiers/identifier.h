#pragma once
#include <utility>
#include <string>

struct ScopedEnv;
struct FunctionEnv;

struct Identifier{
    std::string name;

    Identifier(char* name);
};