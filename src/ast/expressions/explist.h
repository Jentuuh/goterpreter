#pragma once
#include <memory>
#include <utility>
#include "./exp.h"

/**
 * Abstract ExpressionList class.
 * Jente Vandersanden - Compilers 2021-2022 - Hasselt University
 */

struct ScopedEnv;
struct FunctionEnv;
struct Exp;

struct ExpList{
    virtual int length() = 0;
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
};

struct LastExpList:ExpList{
    std::shared_ptr<Exp> last;

    LastExpList(Exp* l);
    int length() override;
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct PairExpList:ExpList{
    std::shared_ptr<Exp> head;
    std::shared_ptr<ExpList> tail;

    PairExpList(Exp* h, ExpList* t);
    int length() override;
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};