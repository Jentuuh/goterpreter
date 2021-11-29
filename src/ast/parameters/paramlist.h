#pragma once
#include <memory>
#include <utility>
#include "./parameterdecl.h"

struct ScopedEnv;
struct FunctionEnv;

struct ParameterList{
    virtual int length() = 0;
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
    virtual void getIdentifiersWithTypes(std::vector<std::pair<std::vector<std::string>, std::shared_ptr<Type>>>& container) = 0;
    virtual void getIdentifiers(std::vector<std::string>& container) = 0; 

};

struct LastParamList:ParameterList{
    std::shared_ptr<ParameterDecl> last;

    LastParamList(ParameterDecl* last);
    int length() override;
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void getIdentifiersWithTypes(std::vector<std::pair<std::vector<std::string>, std::shared_ptr<Type>>>& container) override;
    void getIdentifiers(std::vector<std::string>& container) override;
};

struct PairParamList:ParameterList{
    std::shared_ptr<ParameterDecl> head;
    std::shared_ptr<ParameterList> tail; 

    PairParamList(ParameterDecl* head, ParameterList* tail);
    int length() override;
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void getIdentifiersWithTypes(std::vector<std::pair<std::vector<std::string>, std::shared_ptr<Type>>>& container) override;
    void getIdentifiers(std::vector<std::string>& container) override;
};