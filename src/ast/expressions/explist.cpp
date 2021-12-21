#include "explist.h"
#include <iostream>
#include <algorithm>

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

void LastExpList::getRefNames(std::vector<std::vector<std::string>>& refContainer)
{
    std::vector<std::string> newReferences{};
    last->getRefNames(newReferences);
    refContainer.push_back(newReferences);
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

void LastExpList::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::shared_ptr<Type>>& typeContainer, std::vector<std::string>& typeErrors)
{
    if(std::dynamic_pointer_cast<FunctionCall>(last) == nullptr)
    {
        typeContainer.push_back(last->typecheck(env, funcEnv, typeErrors));
    }
    else
    {
        std::vector<std::shared_ptr<Type>> returnTypes = std::dynamic_pointer_cast<FunctionCall>(last)->typeCheckFunction(env, funcEnv, typeErrors);
        for (std::shared_ptr<Type> r : returnTypes)
        {
            if(std::dynamic_pointer_cast<BooleanType>(r) != nullptr)
            typeContainer.push_back(r);
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

void PairExpList::getRefNames(std::vector<std::vector<std::string>>& refContainer)
{
    std::vector<std::string> newReferences{};
    head->getRefNames(newReferences);
    refContainer.push_back(newReferences);
    tail->getRefNames(refContainer);
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

    // Reverse so values are in expected order
    std::reverse(valueContainer.begin(), valueContainer.end());
}

void PairExpList::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::shared_ptr<Type>>& typeContainer, std::vector<std::string>& typeErrors)
{
    if(std::dynamic_pointer_cast<FunctionCall>(head) == nullptr)
    {
        typeContainer.push_back(head->typecheck(env, funcEnv, typeErrors));
    }
    else
    {
        std::vector<std::shared_ptr<Type>> returnTypes = std::dynamic_pointer_cast<FunctionCall>(head)->typeCheckFunction(env, funcEnv, typeErrors);
        for (std::shared_ptr<Type> r : returnTypes)
        {
            typeContainer.push_back(r);
        }
    }
    tail->typecheck(env, funcEnv, typeContainer, typeErrors);
    std::reverse(typeContainer.begin(), typeContainer.end());
}


