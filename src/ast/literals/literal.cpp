#include "literal.h"
#include <iostream>

// ============= BoolLiteral =============
BoolLiteral::BoolLiteral(bool value): value{value}{}

Environments BoolLiteral::interp(ScopedEnv& env, FunctionEnv& funcEnv)
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

Environments IntLiteral::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: interp
}

void IntLiteral::printValue()
{
    std::cout << value << std::endl;
}

