#pragma once
#include <memory>
#include <utility>
#include "./decl.h"

struct ScopedEnv;
struct FunctionEnv;

struct DeclList{

    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
    virtual void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) = 0;
    virtual void refAnalysis(std::vector<std::pair<std::string, std::string>>& referenceGraph) = 0;
    virtual void preBuildFunctionEnvironment(FunctionEnv& preBuiltEnv) = 0;
    virtual void preBuildGlobalsEnvironment(ScopedEnv& preBuiltEnv, FunctionEnv& funcEnv) = 0;
};

struct PairDeclList:DeclList{

    std::shared_ptr<TopLevelDecl> head;
    std::shared_ptr<DeclList> tail;

    PairDeclList(TopLevelDecl* h, DeclList* t);

    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) override;
    void refAnalysis(std::vector<std::pair<std::string, std::string>>& referenceGraph) override;
    void preBuildFunctionEnvironment(FunctionEnv& preBuiltEnv) override;
    void preBuildGlobalsEnvironment(ScopedEnv& preBuiltEnv, FunctionEnv& funcEnv) override;
};

struct LastDeclList:DeclList{
    std::shared_ptr<TopLevelDecl> last;

    LastDeclList(TopLevelDecl* l);

    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) override;
    void refAnalysis(std::vector<std::pair<std::string, std::string>>& referenceGraph) override;
    void preBuildFunctionEnvironment(FunctionEnv& preBuiltEnv) override;
    void preBuildGlobalsEnvironment(ScopedEnv& preBuiltEnv, FunctionEnv& funcEnv) override;
};