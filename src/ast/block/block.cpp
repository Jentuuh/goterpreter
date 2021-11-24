#include "block.h"


Block::Block(StmList* stmList): statements{stmList}{};


Environments Block::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
};