#pragma once
#include <memory>
#include <utility>
#include "./stm.h"
#include "../expressions/exp.h"

struct ScopedEnv;
struct FunctionEnv;
typedef std::pair<ScopedEnv*, FunctionEnv*> Environments;
struct Stm;

struct ForClause{
    std::shared_ptr<Stm> initStm;
    std::shared_ptr<Exp> condition;
    std::shared_ptr<Stm> postStm;

    ForClause(Stm* init, Exp* cond, Stm* post);
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv);
};