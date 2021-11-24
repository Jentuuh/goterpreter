#include "importdecllist.h"

// ============= PairImportDeclList =============
PairImportDeclList::PairImportDeclList(ImportDecl* h, ImportDeclList* t): head{h}, tail{t}{}

int PairImportDeclList::length()
{
    // TODO: implement
}

Environments PairImportDeclList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= LastImportDeclList =============
LastImportDeclList::LastImportDeclList(ImportDecl* l): last{l}{}

int LastImportDeclList::length()
{
    // TODO: implement
}

Environments LastImportDeclList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}