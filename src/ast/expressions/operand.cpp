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
    return nullptr;
}

std::vector<std::shared_ptr<Type>> LiteralOperand::getType(ScopedEnv& env,FunctionEnv& funcEnv)
{
    std::vector<std::shared_ptr<Type>> result{};
    // Integer literal operand
    if(std::dynamic_pointer_cast<IntLiteral>(literal) != nullptr)
    {
        result.push_back(std::make_shared<IntegerType>());
        return result;
    }

    // Boolean literal operand
    if(std::dynamic_pointer_cast<BoolLiteral>(literal) != nullptr)
    {
        result.push_back(std::make_shared<BooleanType>());
        return result;
    }

    return result;
}


// ============= VariableOperand =============
VariableOperand::VariableOperand(Identifier* operandName): operandName{operandName}{}

std::shared_ptr<Literal> VariableOperand::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    return env.lookupVar(operandName->name);
}

std::shared_ptr<Type> VariableOperand::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{

    std::pair<int, bool> varExists = env.varExists(operandName->name);
    if(varExists.first == 0)
    {
        typeErrors.push_back("Type error in VariableOperand: Variable " + operandName->name + " is not defined.");
    }

    return env.getVarType(operandName->name);

    // // Integer variable operand
    // if(std::dynamic_pointer_cast<IntegerType>(env.getVarType(operandName->name)) != nullptr)
    // {
    //     return std::make_shared<IntegerType>();
    // }

    // // Boolean variable operand
    // if(std::dynamic_pointer_cast<BoolLiteral>(env.lookupVar(operandName->name)) != nullptr)
    // {
    //     return std::make_shared<BooleanType>();
    // }
}

std::vector<std::shared_ptr<Type>> VariableOperand::getType(ScopedEnv& env, FunctionEnv& funcEnv)
{
    std::vector<std::shared_ptr<Type>> result;
    std::pair<int, bool> varExists = env.varExists(operandName->name);
    if(varExists.first == 0)
    {
        // Return an empty result if the variable does not exist
        return result;
    }
    result.push_back(env.getVarType(operandName->name));
    return result;
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

std::vector<std::shared_ptr<Type>> ExprOperand::getType(ScopedEnv& env,FunctionEnv& funcEnv)
{
    return exp->getType(env, funcEnv);
}