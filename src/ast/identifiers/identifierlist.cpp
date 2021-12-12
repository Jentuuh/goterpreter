#include "identifierlist.h"
#include <iostream>
#include <algorithm>

// ============= LastIdentifierList =============
LastIdentifierList::LastIdentifierList(Identifier* l): last{l}{}

void LastIdentifierList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

int LastIdentifierList::length()
{
    // TODO: implement
}

void LastIdentifierList::getIdentifierStrings(std::vector<std::string>& container)
{
    container.push_back(std::string(last->name));
}


// ============= PairIdentifierList =============
PairIdentifierList::PairIdentifierList(Identifier* h, IdentifierList* t): head{h}, tail{t}{}

void PairIdentifierList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

int PairIdentifierList::length()
{
    // TODO: implement
}

void PairIdentifierList::getIdentifierStrings(std::vector<std::string>& container)
{
    container.push_back(head->name);
    tail->getIdentifierStrings(container);
}
