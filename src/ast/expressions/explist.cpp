#include "explist.h"
#include <iostream>

// ============= LastExpList =============
LastExpList::LastExpList(Exp* l): last{l}{}

int LastExpList::length()
{
    // TODO: implement
}

void LastExpList::getOperandNames(std::vector<std::string>& names)
{
    names.push_back(last->getOperandName());
}


void LastExpList::interp(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::shared_ptr<Literal>>& valueContainer)
{
    std::cout << "In last exp list" << std::endl;
    valueContainer.push_back(last->interp(env, funcEnv));
    std::cout << "Done with last exp list!" << std::endl;
}



// ============= PairExpList =============
PairExpList::PairExpList(Exp* h, ExpList* t): head{h}, tail{t}{}

int PairExpList::length()
{
    // TODO: implement
}

void PairExpList::getOperandNames(std::vector<std::string>& names)
{
    names.push_back(head->getOperandName());
    tail->getOperandNames(names);
}

void PairExpList::interp(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::shared_ptr<Literal>>& valueContainer)
{
    std::cout << "In pair exp list" << std::endl;
    valueContainer.push_back(head->interp(env, funcEnv));
    tail->interp(env, funcEnv, valueContainer);
}


