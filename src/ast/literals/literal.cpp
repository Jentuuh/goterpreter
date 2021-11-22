#include "literal.h"

// ============= BoolLiteral =============
BoolLiteral::BoolLiteral(bool value): value{value}{}

SymbolTable* BoolLiteral::interp(SymbolTable& table)
{
    // TODO: interp
}

// ============= IntLiteral =============
IntLiteral::IntLiteral(int value): value{value}{};

SymbolTable* IntLiteral::interp(SymbolTable& table)
{
    // TODO: interp
}
