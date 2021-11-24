#pragma once
#include <memory>
#include <utility>
#include "../parameters/paramlist.h"
#include "./result.h"

struct ScopedEnv;
struct FunctionEnv;
typedef std::pair<ScopedEnv*, FunctionEnv*> Environments;

struct Signature{
    std::shared_ptr<ParameterList> parameters;
    std::shared_ptr<Result> result;

    Signature(ParameterList* params, Result* res);
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv);
};