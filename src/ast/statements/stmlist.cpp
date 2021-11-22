#include "stmlist.h"

// ============= LastStmList =============
LastStmList::LastStmList(Stm* last):last{last}{};

int LastStmList::length() 
{
    // TODO: implement
}

SymbolTable* LastStmList::interp(SymbolTable& table)
{
    // TODO: implement
}

// ============= PairStmList =============
PairStmList::PairStmList(Stm* head, StmList* tail): head{head}, tail{tail}{};

int PairStmList::length() 
{
    // TODO: implement
}

SymbolTable* PairStmList::interp(SymbolTable& table)
{
    // TODO: implement
}