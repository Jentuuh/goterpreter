#pragma once
#include <memory>
#include <utility>
#include "../types/typelist.h"
#include "../types/type.h"
#include "../parameters/paramlist.h"

struct ScopedEnv;
struct FunctionEnv;

struct Result{
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
    virtual void getTypes(std::vector<std::shared_ptr<Type>>& typeContainer) = 0;
};

struct ParametersResult:Result{
    std::shared_ptr<ParameterList> parameters;

    ParametersResult(ParameterList* params);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void getTypes(std::vector<std::shared_ptr<Type>>& typeContainer) override;
};

struct TypeResult:Result{
    std::shared_ptr<TypeList> types;

    TypeResult(TypeList* typelist);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void getTypes(std::vector<std::shared_ptr<Type>>& typeContainer) override;
};