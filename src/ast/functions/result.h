#pragma once
#include <memory>
#include <utility>
#include "../types/type.h"
#include "../parameters/paramlist.h"

struct ScopedEnv;
struct FunctionEnv;

struct Result{
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
    virtual std::vector<std::shared_ptr<Type>> getTypes() = 0;
};

struct ParametersResult:Result{
    std::shared_ptr<ParameterList> parameters;

    ParametersResult(ParameterList* params);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    std::vector<std::shared_ptr<Type>> getTypes() override;
};

struct TypeResult:Result{
    std::shared_ptr<Type> type;

    TypeResult(Type* type);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    std::vector<std::shared_ptr<Type>> getTypes() override;
};