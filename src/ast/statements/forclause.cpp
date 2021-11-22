#include "forclause.h"

// ============= ForClause =============
ForClause::ForClause(Stm* init, Exp* cond, Stm* post): initStm{init}, condition{cond}, postStm{post}{}

SymbolTable* ForClause::interp(SymbolTable& table)
{
    // TODO: implement
}