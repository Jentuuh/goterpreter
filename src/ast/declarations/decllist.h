#pragma once
#include <memory>
#include <utility>
#include "./decl.h"

struct ScopedEnv;
struct FunctionEnv;

struct DeclList{
    virtual int length() = 0;
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
    virtual void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) = 0;
};

struct PairDeclList:DeclList{

    std::shared_ptr<TopLevelDecl> head;
    std::shared_ptr<DeclList> tail;

    PairDeclList(TopLevelDecl* h, DeclList* t);
    int length() override;
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) override;
};

struct LastDeclList:DeclList{
    std::shared_ptr<TopLevelDecl> last;

    LastDeclList(TopLevelDecl* l);
    int length() override;
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) override;
};