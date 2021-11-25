#include "operand.h"
#include "../../environment/interp/env.h"

// ============= LiteralOperand =============
LiteralOperand::LiteralOperand(Literal* lit): literal{lit}{}

std::shared_ptr<Literal> LiteralOperand::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    return literal;
}

// ============= VariableOperand =============
VariableOperand::VariableOperand(Identifier* operandName): operandName{operandName}{}

std::shared_ptr<Literal> VariableOperand::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    return env.lookupVar(operandName->name);
}

// ============= ExprOperand =============
ExprOperand::ExprOperand(Exp* exp): exp{exp}{};

std::shared_ptr<Literal> ExprOperand::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: Implement
}