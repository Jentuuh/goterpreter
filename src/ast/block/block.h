#pragma once
#include <memory>
#include <utility>
#include "../statements/stmlist.h"

struct StmList;
struct ScopedEnv; 
struct FunctionEnv;

struct Block
{
    std::shared_ptr<StmList> statements;

    Block(StmList* stmList);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv);
    void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors);
    int amountPaths();
    int countReturnStatements();
    bool hasBaseReturnStatement();
};