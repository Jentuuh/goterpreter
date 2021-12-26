#include "typelist.h"
#include <iostream>

// ============= LastTypeList =============
LastTypeList::LastTypeList(Type* l): last{l}{};


void LastTypeList::getTypes(std::vector<std::shared_ptr<Type>>& typeContainer) 
{
    typeContainer.push_back(last);
}

// ============= PairTypeList =============
PairTypeList::PairTypeList(Type* h, TypeList* t): head{h}, tail{t}{};


void PairTypeList::getTypes(std::vector<std::shared_ptr<Type>>& typeContainer) 
{
    typeContainer.push_back(head);
    tail->getTypes(typeContainer);
}
