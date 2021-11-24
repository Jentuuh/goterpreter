#include "operand.h"

// ============= LiteralOperand =============
LiteralOperand::LiteralOperand(Literal* lit): literal{lit}{}

void LiteralOperand::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: Implement
}

// ============= VariableOperand =============
VariableOperand::VariableOperand(Identifier* operandName): operandName{operandName}{}

void VariableOperand::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: Implement
}

// ============= ExprOperand =============
ExprOperand::ExprOperand(Exp* exp): exp{exp}{};

void ExprOperand::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: Implement
}