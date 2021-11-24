#include "paramlist.h"

// ============= LastParamList =============
LastParamList::LastParamList(ParameterDecl* last):last{last}{}

int LastParamList::length()
{
    // TODO: implement
}

void LastParamList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= PairParamList =============
PairParamList::PairParamList(ParameterDecl* head, ParameterList* tail): head{head}, tail{tail}{};

int PairParamList::length()
{
    // TODO: implement
}

void PairParamList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}