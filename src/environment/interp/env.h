#pragma once
#include <vector>
#include "./symboltable.h"

struct Env{
    virtual std::shared_ptr<Literal> lookupVar(std::string id) = 0;
};

struct GlobalEnv:Env{
    SymbolTable globals;

    GlobalEnv();
    std::shared_ptr<Literal> lookupVar(std::string id) override;

};

struct ScopedEnv:Env{
    std::vector<SymbolTable> scopeSymbolTables;

    ScopedEnv();
    std::shared_ptr<Literal> lookupVar(std::string id) override;
    SymbolTable* currentScope();
    void popScope();
    void pushScope();
};