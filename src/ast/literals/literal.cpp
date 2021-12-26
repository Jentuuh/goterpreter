#include "literal.h"
#include <iostream>

// ============= BoolLiteral =============
BoolLiteral::BoolLiteral(bool value): value{value}{}

void BoolLiteral::opposite()
{
    value = !value;
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


void IntLiteral::opposite()

{
    value = -value;
}

void IntLiteral::printValue()
{
    std::cout << value << std::endl;
}

