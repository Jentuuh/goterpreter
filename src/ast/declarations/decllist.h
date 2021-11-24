#pragma once
#include <memory>
#include <utility>
#include "./decl.h"

struct ScopedEnv;
struct FunctionEnv;
typedef std::pair<ScopedEnv*, FunctionEnv*> Environments;


struct DeclList{
    virtual int length() = 0;
    virtual Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
};

struct PairDeclList:DeclList{

    std::shared_ptr<TopLevelDecl> head;
    std::shared_ptr<DeclList> tail;

    PairDeclList(TopLevelDecl* h, DeclList* t);
    int length() override;
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) override;

};

struct LastDeclList:DeclList{
    std::shared_ptr<TopLevelDecl> last;

    LastDeclList(TopLevelDecl* l);
    int length() override;
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};