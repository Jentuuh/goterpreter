#pragma once
#include <vector>
#include "./symboltable.h"
#include "./functiontable.h"


struct Env{
    virtual std::shared_ptr<Literal> lookupVar(std::string id) = 0;
};

struct GlobalEnv:Env{
    SymbolTable globals{0};

    GlobalEnv();
    std::shared_ptr<Literal> lookupVar(std::string id) override;

};

struct ScopedEnv:Env{
    std::vector<SymbolTable> scopeSymbolTables;
    int scopeLevel = 0;

    ScopedEnv();
    std::shared_ptr<Literal> lookupVar(std::string id) override;
    SymbolTable* currentScope();
    void updateVar(std::string id, std::shared_ptr<Literal> newVal);
    void popScope(bool decScopeLevel = true);
    void pushScope(bool incScopeLevel = true);
    void printScopes();
};

struct FunctionEnv{
    FunctionTable declaredFunctions;
    std::vector<std::string> callStack;    

    FuncTableEntry* lookupVar(std::string id);
    std::string currentFunc();
    void pushFunc(std::string funcName);
    void popFunc();
};