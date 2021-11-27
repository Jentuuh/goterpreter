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
    if(std::dynamic_pointer_cast<FunctionCall>(last) == nullptr)
    {
        valueContainer.push_back(last->interp(env, funcEnv));
    }
    else
    {
        std::vector<std::shared_ptr<Literal>> returnValues = std::dynamic_pointer_cast<FunctionCall>(last)->executeFunction(env, funcEnv);
        for (std::shared_ptr<Literal> r : returnValues)
        {
            valueContainer.push_back(r);
        }
    }

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
    if(std::dynamic_pointer_cast<FunctionCall>(head) == nullptr)
    {
        valueContainer.push_back(head->interp(env, funcEnv));
    }
    else
    {
        std::vector<std::shared_ptr<Literal>> returnValues = std::dynamic_pointer_cast<FunctionCall>(head)->executeFunction(env, funcEnv);
        for (std::shared_ptr<Literal> r : returnValues)
        {
            valueContainer.push_back(r);
        }
    }
    tail->interp(env, funcEnv, valueContainer);
}


