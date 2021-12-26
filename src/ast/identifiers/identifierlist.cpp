#include "identifierlist.h"
#include <iostream>
#include <algorithm>

// ============= LastIdentifierList =============
LastIdentifierList::LastIdentifierList(Identifier* l): last{l}{}


void LastIdentifierList::getIdentifierStrings(std::vector<std::string>& container)
{
    container.push_back(std::string(last->name));
}


// ============= PairIdentifierList =============
PairIdentifierList::PairIdentifierList(Identifier* h, IdentifierList* t): head{h}, tail{t}{}


void PairIdentifierList::getIdentifierStrings(std::vector<std::string>& container)
{
    container.push_back(head->name);
    tail->getIdentifierStrings(container);
}
