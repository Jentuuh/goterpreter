#pragma once
#include <memory>
#include <utility>
#include "../parameters/paramlist.h"
#include "./result.h"

struct ScopedEnv;
struct FunctionEnv;

struct Signature{
    std::shared_ptr<ParameterList> parameters;
    std::shared_ptr<Result> result;

    Signature(ParameterList* params, Result* res);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv);
};