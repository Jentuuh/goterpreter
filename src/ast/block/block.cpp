#include "block.h"


Block::Block(StmList* stmList): statements{stmList}{};


void Block::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
};