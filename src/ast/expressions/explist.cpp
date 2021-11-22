#include "explist.h"

// ============= LastExpList =============
LastExpList::LastExpList(Exp* l): last{l}{}

int LastExpList::length()
{
    // TODO: implement
}

SymbolTable* LastExpList::interp(SymbolTable& table)
{
    // TODO: implement
}

// ============= PairExpList =============
PairExpList::PairExpList(Exp* h, ExpList* t): head{h}, tail{t}{}

int PairExpList::length()
{
    // TODO: implement
}

SymbolTable* PairExpList::interp(SymbolTable& table)
{
    // TODO: implement
}

