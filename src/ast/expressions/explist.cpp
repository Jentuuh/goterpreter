#include "explist.h"

// ============= LastExpList =============
LastExpList::LastExpList(Exp* l): last{l}{}

int LastExpList::length()
{
    // TODO: implement
}

void LastExpList::interp(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::shared_ptr<Literal>>& valueContainer)
{
    valueContainer.push_back(last->interp(env, funcEnv));
}



// ============= PairExpList =============
PairExpList::PairExpList(Exp* h, ExpList* t): head{h}, tail{t}{}

int PairExpList::length()
{
    // TODO: implement
}

void PairExpList::interp(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::shared_ptr<Literal>>& valueContainer)
{
    valueContainer.push_back(head->interp(env, funcEnv));
    tail->interp(env, funcEnv, valueContainer);
}


