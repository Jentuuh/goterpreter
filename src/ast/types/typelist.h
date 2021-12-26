#pragma once
#include <memory>
#include <utility>
#include <vector>
#include <string>
#include "./type.h"

struct ScopedEnv;
struct FunctionEnv;
struct Type; 

struct TypeList{
    virtual void getTypes(std::vector<std::shared_ptr<Type>>& typeContainer) = 0;
};

struct LastTypeList:TypeList{
    std::shared_ptr<Type> last;

    LastTypeList(Type* l);
    void getTypes(std::vector<std::shared_ptr<Type>>& typeContainer) override;
};

struct PairTypeList:TypeList{
    std::shared_ptr<Type> head;
    std::shared_ptr<TypeList> tail;

    PairTypeList(Type* h, TypeList* t);
    void getTypes(std::vector<std::shared_ptr<Type>>& typeContainer) override;
};