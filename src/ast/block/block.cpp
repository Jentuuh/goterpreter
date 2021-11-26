#include "block.h"
#include "../../environment/interp/env.h"

Block::Block(StmList* stmList): statements{stmList}{};


void Block::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    statements->interp(env, funcEnv);
};