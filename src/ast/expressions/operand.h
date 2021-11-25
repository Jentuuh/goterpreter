#pragma once
#include <memory>
#include <utility>
#include "./exp.h"
#include "../identifiers/identifier.h"
#include "../literals/literal.h"

struct ScopedEnv;
struct FunctionEnv;

struct Exp;
struct Literal;
struct Identifier;

struct Operand{
    virtual std::shared_ptr<Literal> interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
};

struct LiteralOperand: Operand{
    std::shared_ptr<Literal> literal;

    LiteralOperand(Literal* lit);
    std::shared_ptr<Literal> interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct VariableOperand: Operand{
    std::shared_ptr<Identifier> operandName;

    VariableOperand(Identifier* operandName);
    std::shared_ptr<Literal> interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct ExprOperand: Operand{
    std::shared_ptr<Exp> exp;

    ExprOperand(Exp* exp);
    std::shared_ptr<Literal> interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

