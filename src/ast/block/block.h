#pragma once
#include <memory>
#include <utility>
#include "../statements/stmlist.h"

struct StmList;
struct ScopedEnv; 
struct FunctionEnv;
typedef std::pair<ScopedEnv*, FunctionEnv*> Environments;


struct Block
{
    std::shared_ptr<StmList> statements;

    Block(StmList* stmList);
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv);
};