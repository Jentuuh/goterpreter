#include "identifierlist.h"

// ============= LastIdentifierList =============
LastIdentifierList::LastIdentifierList(Identifier* l): last{last}{}

Environments LastIdentifierList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

int LastIdentifierList::length()
{
    // TODO: implement
}

// ============= PairIdentifierList =============
PairIdentifierList::PairIdentifierList(Identifier* h, IdentifierList* t): head{h}, tail{t}{}

Environments PairIdentifierList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

int PairIdentifierList::length()
{
    // TODO: implement
}
