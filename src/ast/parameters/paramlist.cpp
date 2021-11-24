#include "paramlist.h"

// ============= LastParamList =============
LastParamList::LastParamList(ParameterDecl* last):last{last}{}

int LastParamList::length()
{
    // TODO: implement
}

Environments LastParamList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= PairParamList =============
PairParamList::PairParamList(ParameterDecl* head, ParameterList* tail): head{head}, tail{tail}{};

int PairParamList::length()
{
    // TODO: implement
}

Environments PairParamList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}