#include "importdecllist.h"

// ============= PairImportDeclList =============
PairImportDeclList::PairImportDeclList(ImportDecl* h, ImportDeclList* t): head{h}, tail{t}{}

int PairImportDeclList::length()
{
    // TODO: implement
}

SymbolTable* PairImportDeclList::interp(SymbolTable& table)
{
    // TODO: implement
}

// ============= LastImportDeclList =============
LastImportDeclList::LastImportDeclList(ImportDecl* l): last{l}{}

int LastImportDeclList::length()
{
    // TODO: implement
}

SymbolTable* LastImportDeclList::interp(SymbolTable& table)
{
    // TODO: implement
}