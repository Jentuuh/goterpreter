#pragma once
#include <memory>
#include "./decl.h"

struct SymbolTable;

struct DeclList{
    virtual int length() = 0;
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct PairDeclList:DeclList{

    std::shared_ptr<TopLevelDecl> head;
    std::shared_ptr<DeclList> tail;

    PairDeclList(TopLevelDecl* h, DeclList* t);
    int length() override;
    SymbolTable* interp(SymbolTable& table) override;

};

struct LastDeclList:DeclList{
    std::shared_ptr<TopLevelDecl> last;

    LastDeclList(TopLevelDecl* l);
    int length() override;
    SymbolTable* interp(SymbolTable& table) override;
};