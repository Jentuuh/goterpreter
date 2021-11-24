#include "operand.h"

// ============= LiteralOperand =============
LiteralOperand::LiteralOperand(Literal* lit): literal{lit}{}

Environments LiteralOperand::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: Implement
}

// ============= VariableOperand =============
VariableOperand::VariableOperand(Identifier* operandName): operandName{operandName}{}

Environments VariableOperand::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: Implement
}

// ============= ExprOperand =============
ExprOperand::ExprOperand(Exp* exp): exp{exp}{};

Environments ExprOperand::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: Implement
}