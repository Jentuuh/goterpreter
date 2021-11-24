#include "exp.h"

// ============= UnaryExp =============
UnaryExp::UnaryExp(Exp* unaryExp, UnaryOperator op): unaryExp{unaryExp}, op{op}{}

void UnaryExp::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= FunctionCall =============

FunctionCall::FunctionCall(Exp* primExp, ExpList* expList): primaryExp{primExp}, arguments{expList}{}

void FunctionCall::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= OperandExp =============

OperandExp::OperandExp(Operand* operand): operand{operand}{}

void OperandExp::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}
// ============= BinaryExp =============
BinaryExp::BinaryExp(Exp* left, Exp* right, BinaryOperator op): left{left}, right{right}, op{op}{}

void BinaryExp::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}
