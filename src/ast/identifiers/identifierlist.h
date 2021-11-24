#pragma once
#include <memory>
#include <utility>
#include "./identifier.h"

struct ScopedEnv;
struct FunctionEnv;
struct Identifier; 

struct IdentifierList{
    virtual int length() = 0;
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
};

struct LastIdentifierList:IdentifierList{
    std::shared_ptr<Identifier> last;

    LastIdentifierList(Identifier* l);
    int length() override;
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct PairIdentifierList:IdentifierList{
    std::shared_ptr<Identifier> head;
    std::shared_ptr<IdentifierList> tail;

    PairIdentifierList(Identifier* h, IdentifierList* t);
    int length() override;
    void interp(ScopedEnv& env, FunctionEnv& funcEnv); 
};