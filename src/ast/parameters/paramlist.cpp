#include "paramlist.h"

// ============= LastParamList =============
LastParamList::LastParamList(ParameterDecl* last):last{last}{}

int LastParamList::length()
{
    // TODO: implement
}

SymbolTable* LastParamList::interp(SymbolTable& table)
{
    // TODO: implement
}

// ============= PairParamList =============
PairParamList::PairParamList(ParameterDecl* head, ParameterList* tail): head{head}, tail{tail}{};

int PairParamList::length()
{
    // TODO: implement
}

SymbolTable* PairParamList::interp(SymbolTable& table)
{
    // TODO: implement
}