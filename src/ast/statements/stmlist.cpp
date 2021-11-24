#include "stmlist.h"

// ============= LastStmList =============
LastStmList::LastStmList(Stm* last):last{last}{};

int LastStmList::length() 
{
    // TODO: implement
}

Environments LastStmList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= PairStmList =============
PairStmList::PairStmList(Stm* head, StmList* tail): head{head}, tail{tail}{};

int PairStmList::length() 
{
    // TODO: implement
}

Environments PairStmList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}