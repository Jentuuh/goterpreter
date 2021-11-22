#pragma once
#include "./importdecl.h"
#include <memory>

struct SymbolTable;

struct ImportDeclList{
    virtual int length() = 0;
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct PairImportDeclList:ImportDeclList{

    std::shared_ptr<ImportDecl> head;
    std::shared_ptr<ImportDeclList> tail;

    PairImportDeclList(ImportDecl* h, ImportDeclList* t);
    int length() override;
    SymbolTable* interp(SymbolTable& table) override;
};

struct LastImportDeclList:ImportDeclList{
    std::shared_ptr<ImportDecl> last;

    LastImportDeclList(ImportDecl* l);
    int length() override;
    SymbolTable* interp(SymbolTable& table) override;
};