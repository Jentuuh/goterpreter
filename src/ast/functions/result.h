#pragma once
#include <memory>
#include <utility>
#include "../types/type.h"
#include "../parameters/paramlist.h"

struct ScopedEnv;
struct FunctionEnv;
typedef std::pair<ScopedEnv*, FunctionEnv*> Environments;


struct Result{
    virtual Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
};

struct ParametersResult:Result{
    std::shared_ptr<ParameterList> parameters;

    ParametersResult(ParameterList* params);
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct TypeResult:Result{
    std::shared_ptr<Type> type;

    TypeResult(Type* type);
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};