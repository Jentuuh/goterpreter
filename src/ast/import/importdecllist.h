#pragma once
#include "./importdecl.h"
#include <memory>
#include <utility>

struct ScopedEnv;
struct FunctionEnv;

struct ImportDeclList{
    virtual int length() = 0;
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
};

struct PairImportDeclList:ImportDeclList{

    std::shared_ptr<ImportDecl> head;
    std::shared_ptr<ImportDeclList> tail;

    PairImportDeclList(ImportDecl* h, ImportDeclList* t);
    int length() override;
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct LastImportDeclList:ImportDeclList{
    std::shared_ptr<ImportDecl> last;

    LastImportDeclList(ImportDecl* l);
    int length() override;
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};