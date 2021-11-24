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
typedef std::pair<ScopedEnv*, FunctionEnv*> Environments;
struct Stm;

struct StmList{
    virtual int length() = 0;
    virtual Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
};

struct LastStmList:StmList{
    std::shared_ptr<Stm> last;

    LastStmList(Stm* last);
    int length() override;
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct PairStmList:StmList{
    std::shared_ptr<Stm> head;
    std::shared_ptr<StmList> tail; 

    PairStmList(Stm* head, StmList* tail);
    int length() override;
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};