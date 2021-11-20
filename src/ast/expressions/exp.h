#include "../symboltable.h"

/**
 * Abstract Expression class.
 * Jente Vandersanden - Compilers 2021-2022 - Hasselt University
 */

struct Exp{
	virtual SymbolTable* interp(SymbolTable& table) = 0;

};