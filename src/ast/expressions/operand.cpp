#include "operand.h"
#include "../../environment/interp/env.h"

// ============= LiteralOperand =============
LiteralOperand::LiteralOperand(Literal* lit): literal{lit}{}

std::shared_ptr<Literal> LiteralOperand::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    return literal;
}

std::shared_ptr<Type> LiteralOperand::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    // Integer literal operand
    if(std::dynamic_pointer_cast<IntLiteral>(literal) != nullptr)
    {
        return std::make_shared<IntegerType>();
    }

    // Boolean literal operand
    if(std::dynamic_pointer_cast<BoolLiteral>(literal) != nullptr)
    {
        return std::make_shared<BooleanType>();
    }
}

// ============= VariableOperand =============
VariableOperand::VariableOperand(Identifier* operandName): operandName{operandName}{}

std::shared_ptr<Literal> VariableOperand::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    return env.lookupVar(operandName->name);
}

std::shared_ptr<Type> VariableOperand::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    // Integer variable operand
    if(std::dynamic_pointer_cast<IntLiteral>(env.lookupVar(operandName->name)) != nullptr)
    {
        return std::make_shared<IntegerType>();
    }

    // Boolean variable operand
    if(std::dynamic_pointer_cast<BoolLiteral>(env.lookupVar(operandName->name)) != nullptr)
    {
        return std::make_shared<BooleanType>();
    }
}


// ============= ExprOperand =============
ExprOperand::ExprOperand(Exp* exp): exp{exp}{};

std::shared_ptr<Literal> ExprOperand::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    return exp->interp(env, funcEnv);
}

std::shared_ptr<Type> ExprOperand::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    return exp->typecheck(env, funcEnv, typeErrors);
}
