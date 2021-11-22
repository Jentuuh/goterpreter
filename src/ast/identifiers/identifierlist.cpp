#include "identifierlist.h"

// ============= LastIdentifierList =============
LastIdentifierList::LastIdentifierList(Identifier* l): last{last}{}

SymbolTable* LastIdentifierList::interp(SymbolTable& table)
{
    // TODO: implement
}

int LastIdentifierList::length()
{
    // TODO: implement
}

// ============= PairIdentifierList =============
PairIdentifierList::PairIdentifierList(Identifier* h, IdentifierList* t): head{h}, tail{t}{}

SymbolTable* PairIdentifierList::interp(SymbolTable& table)
{
    // TODO: implement
}

int PairIdentifierList::length()
{
    // TODO: implement
}
