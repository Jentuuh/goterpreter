#include <iostream>
#include "decllist.h"


// ============= PairDeclList =============
PairDeclList::PairDeclList(TopLevelDecl* h, DeclList* t): head{h}, tail{t}{}

int PairDeclList::length()
{
    // TODO: implement
}

Environments PairDeclList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    std::cout << "Interpreting PairDeclList..." << std::endl;
    head->interp(env, funcEnv);
    tail->interp(env, funcEnv);
}


// ============= LastDeclList =============
LastDeclList::LastDeclList(TopLevelDecl* l): last{l}{}

int LastDeclList::length()
{
    // TODO: implement
}

Environments LastDeclList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    std::cout << "Interpreting LastDeclList..." << std::endl;
    last->interp(env, funcEnv);
}

