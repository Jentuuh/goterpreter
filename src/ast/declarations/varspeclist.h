#pragma once
#include <memory>
#include <utility>
#include <vector>
#include <string>
#include "./varspec.h"

struct ScopedEnv;
struct FunctionEnv;

struct VarSpecList{
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
    virtual void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) = 0;
    virtual void buildReferenceGraph(std::vector<std::pair<std::string, std::string>>& referenceGraph) = 0;
    virtual void preBuildGlobalsEnvironment(ScopedEnv& preBuiltEnv, FunctionEnv& funcEnv) = 0;
};

struct LastVarSpecList:VarSpecList{
    std::shared_ptr<VarSpec> last;

    LastVarSpecList(VarSpec* l);

    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) override;
    void buildReferenceGraph(std::vector<std::pair<std::string, std::string>>& referenceGraph) override;
    void preBuildGlobalsEnvironment(ScopedEnv& preBuiltEnv, FunctionEnv& funcEnv) override;
};

struct PairVarSpecList:VarSpecList{
    std::shared_ptr<VarSpec> head;
    std::shared_ptr<VarSpecList> tail;

    PairVarSpecList(VarSpec* h, VarSpecList* tail);

    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) override;
    void buildReferenceGraph(std::vector<std::pair<std::string, std::string>>& referenceGraph) override;
    void preBuildGlobalsEnvironment(ScopedEnv& preBuiltEnv, FunctionEnv& funcEnv) override;
};