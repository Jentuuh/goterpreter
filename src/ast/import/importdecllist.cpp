#include "importdecllist.h"

// ============= PairImportDeclList =============
PairImportDeclList::PairImportDeclList(ImportDecl* h, ImportDeclList* t): head{h}, tail{t}{}

void PairImportDeclList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= LastImportDeclList =============
LastImportDeclList::LastImportDeclList(ImportDecl* l): last{l}{}

void LastImportDeclList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}