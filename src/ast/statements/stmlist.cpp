#include "stmlist.h"

// ============= LastStmList =============
LastStmList::LastStmList(Stm* last):last{last}{};

int LastStmList::length() 
{
    // TODO: implement
}

void LastStmList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    last->interp(env, funcEnv);
}

void LastStmList::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    last->typecheck(env, funcEnv, typeErrors);
}


// ============= PairStmList =============
PairStmList::PairStmList(Stm* head, StmList* tail): head{head}, tail{tail}{};

int PairStmList::length() 
{
    // TODO: implement
}

void PairStmList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    head->interp(env, funcEnv);
    tail->interp(env, funcEnv);
}

void PairStmList::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    head->typecheck(env, funcEnv, typeErrors);
    tail->typecheck(env, funcEnv, typeErrors);
}
