#include "operand.h"

// ============= LiteralOperand =============
LiteralOperand::LiteralOperand(Literal* lit): literal{lit}{}

SymbolTable* LiteralOperand::interp(SymbolTable& table)
{
    // TODO: Implement
}

// ============= VariableOperand =============
VariableOperand::VariableOperand(Identifier* operandName): operandName{operandName}{}

SymbolTable* VariableOperand::interp(SymbolTable& table)
{
    // TODO: Implement
}

// ============= ExprOperand =============
ExprOperand::ExprOperand(Exp* exp): exp{exp}{};

SymbolTable* ExprOperand::interp(SymbolTable& table)
{
    // TODO: Implement
}