#include "literal.h"
#include <iostream>

// ============= BoolLiteral =============
BoolLiteral::BoolLiteral(bool value): value{value}{}

SymbolTable* BoolLiteral::interp(SymbolTable& table)
{
    // TODO: interp
}

void BoolLiteral::printValue()
{
    if(value)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
}


// ============= IntLiteral =============
IntLiteral::IntLiteral(int value): value{value}{};

SymbolTable* IntLiteral::interp(SymbolTable& table)
{
    // TODO: interp
}

void IntLiteral::printValue()
{
    std::cout << value << std::endl;
}

