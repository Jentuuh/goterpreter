#include "block.h"
#include "../../environment/interp/env.h"
#include <iostream>

Block::Block(StmList* stmList): statements{stmList}{};


void Block::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    if(statements != nullptr)
    {
        statements->interp(env, funcEnv);
    }
};

void Block::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    if(statements != nullptr)
    {
        statements->typecheck(env, funcEnv, typeErrors);
    }
}

int Block::amountPaths()
{
    if(statements != nullptr){
        return statements->amountPaths();
    }
    return 0;
}

int Block::countReturnStatements()
{
    if(statements != nullptr){
        return statements->countReturnStatements();
    }
    return 0;
}

bool Block::hasBaseReturnStatement()
{
    if(statements != nullptr){
        return statements->hasBaseReturnStatement();
    }
    return false;
}

