#pragma once
#include <utility>
#include <utility>

struct ScopedEnv;
struct FunctionEnv;
typedef std::pair<ScopedEnv*, FunctionEnv*> Environments;

struct Literal{
    virtual Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
    virtual void printValue() = 0;
};

struct BoolLiteral: Literal{
    bool value;

    BoolLiteral(bool value);
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void printValue() override;
};

struct IntLiteral: Literal{
    int value;

    IntLiteral(int value);
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void printValue() override;
};

