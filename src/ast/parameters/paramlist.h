#pragma once
#include <memory>
#include <utility>
#include "./parameterdecl.h"

struct ScopedEnv;
struct FunctionEnv;

struct ParameterList{
    virtual int length() = 0;
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
};

struct LastParamList:ParameterList{
    std::shared_ptr<ParameterDecl> last;

    LastParamList(ParameterDecl* last);
    int length() override;
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct PairParamList:ParameterList{
    std::shared_ptr<ParameterDecl> head;
    std::shared_ptr<ParameterList> tail; 

    PairParamList(ParameterDecl* head, ParameterList* tail);
    int length() override;
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};