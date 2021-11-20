#include "../symboltable.h"

/**
 * Abstract Statement struct.
 * Jente Vandersanden - Compilers 2021-2022 - Hasselt University
 */

struct Stm
{
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};