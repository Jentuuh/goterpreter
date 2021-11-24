#include "importdecllist.h"

// ============= PairImportDeclList =============
PairImportDeclList::PairImportDeclList(ImportDecl* h, ImportDeclList* t): head{h}, tail{t}{}

int PairImportDeclList::length()
{
    // TODO: implement
}

void PairImportDeclList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= LastImportDeclList =============
LastImportDeclList::LastImportDeclList(ImportDecl* l): last{l}{}

int LastImportDeclList::length()
{
    // TODO: implement
}

void LastImportDeclList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}