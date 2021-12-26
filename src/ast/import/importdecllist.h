#pragma once
#include "./importdecl.h"
#include <memory>
#include <utility>

struct ScopedEnv;
struct FunctionEnv;

struct ImportDeclList{
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
};

struct PairImportDeclList:ImportDeclList{

    std::shared_ptr<ImportDecl> head;
    std::shared_ptr<ImportDeclList> tail;

    PairImportDeclList(ImportDecl* h, ImportDeclList* t);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct LastImportDeclList:ImportDeclList{
    std::shared_ptr<ImportDecl> last;

    LastImportDeclList(ImportDecl* l);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};