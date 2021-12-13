#include "block.h"
#include "../../environment/interp/env.h"
#include <iostream>

Block::Block(StmList* stmList): statements{stmList}{};


void Block::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    statements->interp(env, funcEnv);
};

void Block::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    statements->typecheck(env, funcEnv, typeErrors);
}

int Block::amountPaths()
{
    return statements->amountPaths();
}

int Block::countReturnStatements()
{
    return statements->countReturnStatements();
}

