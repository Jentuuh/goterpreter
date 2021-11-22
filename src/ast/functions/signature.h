#pragma once
#include <memory>
#include "../parameters/paramlist.h"
#include "./result.h"

struct SymbolTable;

struct Signature{
    std::shared_ptr<ParameterList> parameters;
    std::shared_ptr<Result> result;

    Signature(ParameterList* params, Result* res);
    SymbolTable* interp(SymbolTable& table);
};