#include "exp.h"

// ============= UnaryExp =============
UnaryExp::UnaryExp(Exp* unaryExp, UnaryOperator op): unaryExp{unaryExp}, op{op}{}

SymbolTable* UnaryExp::interp(SymbolTable& table)
{
    // TODO: implement
}

// ============= PrimaryExp =============
PrimaryExp::PrimaryExp(Operand* operand): operand{operand}{}

SymbolTable* PrimaryExp::interp(SymbolTable& table)
{
    // TODO: implement
}

// ============= BinaryExp =============
BinaryExp::BinaryExp(Exp* left, Exp* right, BinaryOperator op): left{left}, right{right}, op{op}{}

SymbolTable* BinaryExp::interp(SymbolTable& table)
{
    // TODO: implement
}
