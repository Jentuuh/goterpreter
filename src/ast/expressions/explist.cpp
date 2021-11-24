#include "explist.h"

// ============= LastExpList =============
LastExpList::LastExpList(Exp* l): last{l}{}

int LastExpList::length()
{
    // TODO: implement
}

void LastExpList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= PairExpList =============
PairExpList::PairExpList(Exp* h, ExpList* t): head{h}, tail{t}{}

int PairExpList::length()
{
    // TODO: implement
}

void PairExpList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

