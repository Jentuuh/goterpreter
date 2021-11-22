#include "block.h"


Block::Block(StmList* stmList): statements{stmList}{};


SymbolTable* Block::interp(SymbolTable& table)
{
    // TODO: implement
};