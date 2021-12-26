#pragma once
#include <memory>
#include <utility>
#include "./stm.h"
#include "../expressions/exp.h"

struct ScopedEnv;
struct FunctionEnv;
struct Stm;
struct Exp;

struct ForClause{
    std::shared_ptr<Stm> initStm;
    std::shared_ptr<Exp> condition;
    std::shared_ptr<Stm> postStm;

    ForClause(Stm* init, Exp* cond, Stm* post);
};