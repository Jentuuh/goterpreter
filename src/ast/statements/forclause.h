#pragma once
#include <memory>
#include "./stm.h"
#include "../expressions/exp.h"

struct SymbolTable;
struct Stm;

struct ForClause{
    std::shared_ptr<Stm> initStm;
    std::shared_ptr<Exp> condition;
    std::shared_ptr<Stm> postStm;

    ForClause(Stm* init, Exp* cond, Stm* post);
    SymbolTable* interp(SymbolTable& table);
};