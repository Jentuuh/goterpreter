#pragma once
#include <memory>
#include <utility>
#include <vector>
#include "./exp.h"

/**
 * Abstract ExpressionList class.
 * Jente Vandersanden - Compilers 2021-2022 - Hasselt University
 */

struct ScopedEnv;
struct FunctionEnv;
struct Exp;
struct Literal;

struct ExpList{
    virtual int length() = 0;
    virtual void getOperandNames(std::vector<std::string>& names) = 0;
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::shared_ptr<Literal>>& valueContainer) = 0;
};

struct LastExpList:ExpList{
    std::shared_ptr<Exp> last;

    LastExpList(Exp* l);
    int length() override;
    void getOperandNames(std::vector<std::string>& names);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::shared_ptr<Literal>>& valueContainer) override;
};

struct PairExpList:ExpList{
    std::shared_ptr<Exp> head;
    std::shared_ptr<ExpList> tail;

    PairExpList(Exp* h, ExpList* t);
    int length() override;
    void getOperandNames(std::vector<std::string>& names);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::shared_ptr<Literal>>& valueContainer) override;
};