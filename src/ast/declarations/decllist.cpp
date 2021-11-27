#include <iostream>
#include "decllist.h"


// ============= PairDeclList =============
PairDeclList::PairDeclList(TopLevelDecl* h, DeclList* t): head{h}, tail{t}{}

int PairDeclList::length()
{
    // TODO: implement
}

void PairDeclList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{    
    head->interp(env, funcEnv);
    tail->interp(env, funcEnv);
}


// ============= LastDeclList =============
LastDeclList::LastDeclList(TopLevelDecl* l): last{l}{}

int LastDeclList::length()
{
    // TODO: implement
}

void LastDeclList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    last->interp(env, funcEnv);
}

