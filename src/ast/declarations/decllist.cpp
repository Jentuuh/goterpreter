#include "decllist.h"


// ============= PairDeclList =============
PairDeclList::PairDeclList(TopLevelDecl* h, DeclList* t): head{h}, tail{t}{}

int PairDeclList::length()
{
    // TODO: implement
}

SymbolTable* PairDeclList::interp(SymbolTable& table)
{
    // TODO: implement
}


// ============= LastDeclList =============
LastDeclList::LastDeclList(TopLevelDecl* l): last{l}{}

int LastDeclList::length()
{
    // TODO: implement
}

SymbolTable* LastDeclList::interp(SymbolTable& table)
{
    // TODO: implement
}

