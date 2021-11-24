#pragma once
#include <memory>
#include <utility>
#include "./parameterdecl.h"

struct ScopedEnv;
struct FunctionEnv;
typedef std::pair<ScopedEnv*, FunctionEnv*> Environments;


struct ParameterList{
    virtual int length() = 0;
    virtual Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
};

struct LastParamList:ParameterList{
    std::shared_ptr<ParameterDecl> last;

    LastParamList(ParameterDecl* last);
    int length() override;
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct PairParamList:ParameterList{
    std::shared_ptr<ParameterDecl> head;
    std::shared_ptr<ParameterList> tail; 

    PairParamList(ParameterDecl* head, ParameterList* tail);
    int length() override;
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};