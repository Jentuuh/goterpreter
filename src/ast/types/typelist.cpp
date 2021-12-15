#include "typelist.h"
#include <iostream>

// ============= LastTypeList =============
LastTypeList::LastTypeList(Type* l): last{l}{};

void LastTypeList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{

}

void LastTypeList::getTypes(std::vector<std::shared_ptr<Type>>& typeContainer) 
{
    typeContainer.push_back(last);
}

// ============= PairTypeList =============
PairTypeList::PairTypeList(Type* h, TypeList* t): head{h}, tail{t}{};

void PairTypeList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{

}

void PairTypeList::getTypes(std::vector<std::shared_ptr<Type>>& typeContainer) 
{
    typeContainer.push_back(head);
    tail->getTypes(typeContainer);
}
