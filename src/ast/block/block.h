#pragma once
#include <memory>
#include "../statements/stmlist.h"

struct StmList;
struct SymbolTable;

struct Block
{
    std::shared_ptr<StmList> statements;

    Block(StmList* stmList);
    SymbolTable* interp(SymbolTable& table);
};