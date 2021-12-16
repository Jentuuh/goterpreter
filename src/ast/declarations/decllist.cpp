#include <iostream>
#include "decllist.h"


// ============= PairDeclList =============
PairDeclList::PairDeclList(TopLevelDecl* h, DeclList* t): head{h}, tail{t}{}

int PairDeclList::length()
{
    // TODO: implement
}

void PairDeclList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{    
    head->interp(env, funcEnv);
    tail->interp(env, funcEnv);
}

void PairDeclList::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    head->typecheck(env, funcEnv, typeErrors);
    tail->typecheck(env, funcEnv, typeErrors);
}

void PairDeclList::refAnalysis(std::vector<std::pair<std::string, std::string>>& referenceGraph) 
{
     if(std::dynamic_pointer_cast<VarDecl>(head) != nullptr)
    {
        std::dynamic_pointer_cast<VarDecl>(head)->varspecs->buildReferenceGraph(referenceGraph);
    }

    tail->refAnalysis(referenceGraph);
}

// ============= LastDeclList =============
LastDeclList::LastDeclList(TopLevelDecl* l): last{l}{}

int LastDeclList::length()
{
    // TODO: implement
}

void LastDeclList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    last->interp(env, funcEnv);
}

void LastDeclList::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    last->typecheck(env, funcEnv, typeErrors);
}

void LastDeclList::refAnalysis(std::vector<std::pair<std::string, std::string>>& referenceGraph) 
{
    if(std::dynamic_pointer_cast<VarDecl>(last) != nullptr)
    {
        std::dynamic_pointer_cast<VarDecl>(last)->varspecs->buildReferenceGraph(referenceGraph);
    }
}
