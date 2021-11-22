#pragma once
#include <memory>
#include "../types/type.h"
#include "../parameters/paramlist.h"

struct SymbolTable;

struct Result{
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct ParametersResult:Result{
    std::shared_ptr<ParameterList> parameters;

    ParametersResult(ParameterList* params);
    SymbolTable* interp(SymbolTable& table) override;
};

struct TypeResult:Result{
    std::shared_ptr<Type> type;

    TypeResult(Type* type);
    SymbolTable* interp(SymbolTable& table) override;
};