#pragma once
#include <memory>
#include <utility>
#include <vector>
#include <string>
#include "./varspec.h"

struct ScopedEnv;
struct FunctionEnv;

struct VarSpecList{
    virtual int length() = 0;
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
    virtual void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) = 0;

};

struct LastVarSpecList:VarSpecList{
    std::shared_ptr<VarSpec> last;

    LastVarSpecList(VarSpec* l);
    int length() override;
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) override;
};

struct PairVarSpecList:VarSpecList{
    std::shared_ptr<VarSpec> head;
    std::shared_ptr<VarSpecList> tail;

    PairVarSpecList(VarSpec* h, VarSpecList* tail);
    int length() override;
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) override;
};