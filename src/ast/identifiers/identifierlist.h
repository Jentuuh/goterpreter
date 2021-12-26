#pragma once
#include <memory>
#include <utility>
#include <vector>
#include <string>
#include "./identifier.h"

struct ScopedEnv;
struct FunctionEnv;
struct Identifier; 

struct IdentifierList{
    virtual void getIdentifierStrings(std::vector<std::string>& container) = 0;
    };

struct LastIdentifierList:IdentifierList{
    std::shared_ptr<Identifier> last;

    LastIdentifierList(Identifier* l);

    void getIdentifierStrings(std::vector<std::string>& container) override;
};

struct PairIdentifierList:IdentifierList{
    std::shared_ptr<Identifier> head;
    std::shared_ptr<IdentifierList> tail;

    PairIdentifierList(Identifier* h, IdentifierList* t);

    void getIdentifierStrings(std::vector<std::string>& container) override;
};