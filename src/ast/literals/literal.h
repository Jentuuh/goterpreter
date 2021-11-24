#pragma once
#include <utility>
#include <utility>

struct ScopedEnv;
struct FunctionEnv;

struct Literal{
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
    virtual void printValue() = 0;
};

struct BoolLiteral: Literal{
    bool value;

    BoolLiteral(bool value);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void printValue() override;
};

struct IntLiteral: Literal{
    int value;

    IntLiteral(int value);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void printValue() override;
};

