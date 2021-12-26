#pragma once
#include <utility>
#include <utility>

struct ScopedEnv;
struct FunctionEnv;

struct Literal{
    virtual void opposite() = 0;
    virtual void printValue() = 0;
};

struct BoolLiteral: Literal{
    bool value;

    BoolLiteral(bool value);

    void opposite() override;
    void printValue() override;
};

struct IntLiteral: Literal{
    int value;

    IntLiteral(int value);

    void opposite() override;
    void printValue() override;
};

