#pragma once
#include <utility>

struct ScopedEnv;
struct FunctionEnv;

struct Type{
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
};

struct IntegerType:Type{
    IntegerType();
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct BooleanType:Type{
    BooleanType();
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};