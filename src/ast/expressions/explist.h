#pragma once
#include <memory>
#include "./exp.h"

/**
 * Abstract ExpressionList class.
 * Jente Vandersanden - Compilers 2021-2022 - Hasselt University
 */

struct SymbolTable;

struct ExpList{
    virtual int length() = 0;
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct LastExpList:ExpList{
    std::shared_ptr<Exp> last;

    LastExpList(Exp* l);
    int length() override;
    SymbolTable* interp(SymbolTable& table) override;
};

struct PairExpList:ExpList{
    std::shared_ptr<Exp> head;
    std::shared_ptr<ExpList> tail;

    PairExpList(Exp* h, ExpList* t);
    int length() override;
    SymbolTable* interp(SymbolTable& table) override;
};