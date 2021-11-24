#include "exp.h"

// ============= UnaryExp =============
UnaryExp::UnaryExp(Exp* unaryExp, UnaryOperator op): unaryExp{unaryExp}, op{op}{}

Environments UnaryExp::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= FunctionCall =============

FunctionCall::FunctionCall(Exp* primExp, ExpList* expList): primaryExp{primExp}, arguments{expList}{}

Environments FunctionCall::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= OperandExp =============

OperandExp::OperandExp(Operand* operand): operand{operand}{}

Environments OperandExp::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}
// ============= BinaryExp =============
BinaryExp::BinaryExp(Exp* left, Exp* right, BinaryOperator op): left{left}, right{right}, op{op}{}

Environments BinaryExp::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}
