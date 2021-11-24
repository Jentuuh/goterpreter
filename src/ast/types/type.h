#pragma once
#include <utility>

struct ScopedEnv;
struct FunctionEnv;
typedef std::pair<ScopedEnv*, FunctionEnv*> Environments;


struct Type{
    virtual Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
};

struct IntegerType:Type{
    IntegerType();
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct BooleanType:Type{
    BooleanType();
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};