#include "forclause.h"

// ============= ForClause =============
ForClause::ForClause(Stm* init, Exp* cond, Stm* post): initStm{init}, condition{cond}, postStm{post}{}

Environments ForClause::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}