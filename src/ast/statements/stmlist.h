#pragma once
#include <memory>
#include <utility>
#include "./stm.h"

/**
 * Abstract StatementList class.
 * Jente Vandersanden - Compilers 2021-2022 - Hasselt University
 */ 
struct ScopedEnv;
struct FunctionEnv;
struct Stm;

struct StmList{
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
    virtual void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) = 0;
    virtual int amountPaths() = 0;
    virtual int countReturnStatements() = 0;
    virtual bool hasBaseReturnStatement() = 0;

};

struct LastStmList:StmList{
    std::shared_ptr<Stm> last;

    LastStmList(Stm* last);
    
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) override;
    int amountPaths() override;
    int countReturnStatements() override;
    bool hasBaseReturnStatement() override;
};

struct PairStmList:StmList{
    std::shared_ptr<Stm> head;
    std::shared_ptr<StmList> tail; 

    PairStmList(Stm* head, StmList* tail);

    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) override;
    int amountPaths() override;
    int countReturnStatements() override;
    bool hasBaseReturnStatement() override;
};