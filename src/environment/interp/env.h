#pragma once
#include <vector>
#include "./symboltable.h"
#include "./functiontable.h"


struct Env{
    virtual std::shared_ptr<Literal> lookupVar(std::string id) = 0;
    virtual std::pair<int, bool> varExists(std::string id) = 0;
};

struct GlobalEnv:Env{
    SymbolTable globals{0};

    GlobalEnv();
    std::shared_ptr<Literal> lookupVar(std::string id) override;
    std::pair<int, bool> varExists(std::string id) override;
};

struct ScopedEnv:Env{
    std::vector<std::shared_ptr<SymbolTable>> scopeSymbolTables;
    int scopeLevel = 0;

    ScopedEnv();
    std::shared_ptr<Literal> lookupVar(std::string id) override;
    std::pair<int, bool> varExists(std::string id) override;  
    std::shared_ptr<Type> getVarType(std::string id);
    std::shared_ptr<SymbolTable> currentScope();

    void reset();
    void updateVar(std::string id, std::shared_ptr<Literal> newVal);
    void popScope(bool decScopeLevel = true);
    void pushScope(bool incScopeLevel = true);
    void printScopes();
};

struct FunctionEnv{
    FunctionTable declaredFunctions;
    std::vector<std::string> callStack;    

    std::shared_ptr<FuncTableEntry> lookupVar(std::string id);
    std::string currentFunc();
    
    void reset();
    void pushFunc(std::string funcName);
    void popFunc();
};