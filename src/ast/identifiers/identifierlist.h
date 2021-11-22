#pragma once
#include <memory>
#include "./identifier.h"

struct SymbolTable;

struct IdentifierList{
    virtual int length() = 0;
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct LastIdentifierList:IdentifierList{
    std::shared_ptr<Identifier> last;

    LastIdentifierList(Identifier* l);
    int length() override;
    SymbolTable* interp(SymbolTable& table) override;
};

struct PairIdentifierList:IdentifierList{
    std::shared_ptr<Identifier> head;
    std::shared_ptr<IdentifierList> tail;

    PairIdentifierList(Identifier* h, IdentifierList* t);
    int length() override;
    SymbolTable* interp(SymbolTable& table); 
};