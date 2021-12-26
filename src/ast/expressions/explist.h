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
struct Type;
struct Literal;

struct ExpList{
    virtual void getOperandNames(std::vector<std::string>& names) = 0;
    virtual void getRefNames(std::vector<std::vector<std::string>>& refContainer) = 0;
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::shared_ptr<Literal>>& valueContainer) = 0;
    virtual void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::shared_ptr<Type>>& typeContainer, std::vector<std::string>& typeErrors) = 0;
    virtual void getTypes(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::shared_ptr<Type>>& typeContainer) = 0;
};

struct LastExpList:ExpList{
    std::shared_ptr<Exp> last;

    LastExpList(Exp* l);

    void getOperandNames(std::vector<std::string>& names);
    void getRefNames(std::vector<std::vector<std::string>>& refContainer) override;
    void interp(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::shared_ptr<Literal>>& valueContainer) override;
    void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::shared_ptr<Type>>& typeContainer, std::vector<std::string>& typeErrors) override;
    void getTypes(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::shared_ptr<Type>>& typeContainer) override;
};

struct PairExpList:ExpList{
    std::shared_ptr<Exp> head;
    std::shared_ptr<ExpList> tail;

    PairExpList(Exp* h, ExpList* t);

    void getOperandNames(std::vector<std::string>& names);
    void getRefNames(std::vector<std::vector<std::string>>& refContainer) override;
    void interp(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::shared_ptr<Literal>>& valueContainer) override;
    void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::shared_ptr<Type>>& typeContainer, std::vector<std::string>& typeErrors) override;
    void getTypes(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::shared_ptr<Type>>& typeContainer) override;
};