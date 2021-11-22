#pragma once
#include <memory>
#include "./exp.h"
#include "../identifiers/identifier.h"
#include "../literals/literal.h"

struct SymbolTable;
struct Exp;
struct Literal;
struct Identifier;

struct Operand{
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct LiteralOperand: Operand{
    std::shared_ptr<Literal> literal;

    LiteralOperand(Literal* lit);
    SymbolTable* interp(SymbolTable& table) override;
};

struct VariableOperand: Operand{
    std::shared_ptr<Identifier> operandName;

    VariableOperand(Identifier* operandName);
    SymbolTable* interp(SymbolTable& table) override;
};

struct ExprOperand: Operand{
    std::shared_ptr<Exp> exp;

    ExprOperand(Exp* exp);
    SymbolTable* interp(SymbolTable& table) override;
};

