#pragma once
#include <memory>
#include "./stm.h"
/**
 * Abstract StatementList class.
 * Jente Vandersanden - Compilers 2021-2022 - Hasselt University
 */ 
struct SymbolTable;
struct Stm;

struct StmList{
    virtual int length() = 0;
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct LastStmList:StmList{
    std::shared_ptr<Stm> last;

    LastStmList(Stm* last);
    int length() override;
    SymbolTable* interp(SymbolTable& table) override;
};

struct PairStmList:StmList{
    std::shared_ptr<Stm> head;
    std::shared_ptr<StmList> tail; 

    PairStmList(Stm* head, StmList* tail);
    int length() override;
    SymbolTable* interp(SymbolTable& table) override;
};