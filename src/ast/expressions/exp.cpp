#include "exp.h"
#include "../../environment/interp/env.h"
#include <iostream>

// ============= UnaryExp =============
UnaryExp::UnaryExp(Exp* unaryExp, UnaryOperator op): unaryExp{unaryExp}, op{op}{}

std::string UnaryExp::getOperandName() 
{
    return std::string("NO_OPERAND_EXPRESSION");
}


std::shared_ptr<Literal> UnaryExp::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    std::shared_ptr<Literal> intermediateResult = unaryExp->interp(env, funcEnv);

    // Boolean literal evaluation
    if(std::dynamic_pointer_cast<BoolLiteral>(intermediateResult) != nullptr)
    {
        switch (op)
        {
            case NOT_UNARY:
                std::dynamic_pointer_cast<BoolLiteral>(intermediateResult)->opposite();
                break;
            default:
            // TODO: Throw error(wrong operator?) in typecheck!
            break;
        }
    }

    // Integer literal evaluation
    if(std::dynamic_pointer_cast<IntLiteral>(intermediateResult) != nullptr)
    {
        switch (op)
        {
        case PLUS_UNARY:
            // Nothing happens to the integer value when we prefix with plus
            break;
        case MIN_UNARY:
            std::dynamic_pointer_cast<IntLiteral>(intermediateResult)->opposite();
            break;
        default:
            // TODO: Throw error(wrong operator?) in typecheck!
            break;
        }
    }

    return intermediateResult;
}

// ============= FunctionCall =============

FunctionCall::FunctionCall(Exp* primExp, ExpList* expList): primaryExp{primExp}, arguments{expList}{}

std::shared_ptr<Literal> FunctionCall::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: Typechecker: Check if function exists + if parameters have correct type!!

    std::cout << "In function call!" << std::endl;

    // Get the name of the function that's being called 
    std::string funcName = primaryExp->getOperandName();

    // Push function on the call stack
    funcEnv.pushFunc(funcName);

    std::cout << "Function name: " << funcName <<  std::endl;

    // Evaluate the parameters
    std::vector<std::shared_ptr<Literal>> argValues;
    if(arguments.get() != nullptr)
    {
        arguments->interp(env, funcEnv, argValues);
        std::cout << "Got argument values!" << std::endl;
    }

    // We are entering the function's scope
    env.pushScope();
    std::cout << "New scope!" << std::endl;

    // Add arguments to this scope
    std::vector<std::pair<std::vector<std::string>, std::shared_ptr<Type>>> argNamesAndTypes;
    if(funcEnv.lookupVar(funcName)->funcDecl->funcSign->parameters != nullptr)
    {
        funcEnv.lookupVar(funcName)->funcDecl->funcSign->parameters->getIdentifiersWithTypes(argNamesAndTypes);
    }

    int valueIndex = 0;
    for(int i = 0; i < argNamesAndTypes.size(); i++)
    {
        for(int j = 0; j < argNamesAndTypes.at(i).first.size(); j++)
        {
             env.currentScope()->add(argNamesAndTypes.at(i).first.at(j), argNamesAndTypes.at(i).second, argValues[valueIndex]);
             valueIndex++;
        }
    }

    // Execute the function's body
    funcEnv.lookupVar(funcName)->funcDecl->funcBody->interp(env, funcEnv);

    std::cout << "Executed function " << funcName << "!" << std::endl;
    // Pop function from call stack
    funcEnv.popFunc();

    // Pop scope after the function has been executed
    env.printScopes();

    // TODO: This function does not return a literal pointer, that's why I get a segmentation fault!
};

std::string FunctionCall::getOperandName() 
{
    return std::string("NO_OPERAND_EXPRESSION");
}

// ============= OperandExp =============

OperandExp::OperandExp(Operand* operand): operand{operand}{}

std::shared_ptr<Literal> OperandExp::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    return operand->interp(env, funcEnv);
}

std::string OperandExp::getOperandName() 
{
    if(std::dynamic_pointer_cast<VariableOperand>(operand) != nullptr)
        return std::dynamic_pointer_cast<VariableOperand>(operand)->operandName->name;
    return std::string("NO_OPERAND_EXPRESSION");
}

// ============= BinaryExp =============
BinaryExp::BinaryExp(Exp* left, Exp* right, BinaryOperator op): left{left}, right{right}, op{op}{}

std::string BinaryExp::getOperandName() 
{
    return std::string("NO_OPERAND_EXPRESSION");
}

std::shared_ptr<Literal> BinaryExp::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: TYPECHECKING!!
    switch (op)
    {
    // BOOLEANS
    case EQ_BIN:
        return std::make_shared<BoolLiteral>(std::dynamic_pointer_cast<BoolLiteral>(left->interp(env, funcEnv))->value == std::dynamic_pointer_cast<BoolLiteral>(right->interp(env, funcEnv))->value);
        break;
    case NE_BIN:
        return std::make_shared<BoolLiteral>(std::dynamic_pointer_cast<BoolLiteral>(left->interp(env, funcEnv))->value != std::dynamic_pointer_cast<BoolLiteral>(right->interp(env, funcEnv))->value);
        break;
    case LT_BIN:
        return std::make_shared<BoolLiteral>(std::dynamic_pointer_cast<BoolLiteral>(left->interp(env, funcEnv))->value < std::dynamic_pointer_cast<BoolLiteral>(right->interp(env, funcEnv))->value);
        break;
    case LE_BIN:
        return std::make_shared<BoolLiteral>(std::dynamic_pointer_cast<BoolLiteral>(left->interp(env, funcEnv))->value <= std::dynamic_pointer_cast<BoolLiteral>(right->interp(env, funcEnv))->value);
        break;
    case GT_BIN:
        return std::make_shared<BoolLiteral>(std::dynamic_pointer_cast<BoolLiteral>(left->interp(env, funcEnv))->value > std::dynamic_pointer_cast<BoolLiteral>(right->interp(env, funcEnv))->value);
        break;
    case GE_BIN:
        return std::make_shared<BoolLiteral>(std::dynamic_pointer_cast<BoolLiteral>(left->interp(env, funcEnv))->value >= std::dynamic_pointer_cast<BoolLiteral>(right->interp(env, funcEnv))->value);
        break;
    case OR_BIN:
        return std::make_shared<BoolLiteral>(std::dynamic_pointer_cast<BoolLiteral>(left->interp(env, funcEnv))->value || std::dynamic_pointer_cast<BoolLiteral>(right->interp(env, funcEnv))->value);
        break;
    case AND_BIN:
        return std::make_shared<BoolLiteral>(std::dynamic_pointer_cast<BoolLiteral>(left->interp(env, funcEnv))->value && std::dynamic_pointer_cast<BoolLiteral>(right->interp(env, funcEnv))->value);
        break;

    // INTEGERS
    case MUL_BIN:
        return std::make_shared<IntLiteral>(std::dynamic_pointer_cast<IntLiteral>(left->interp(env, funcEnv))->value * std::dynamic_pointer_cast<IntLiteral>(right->interp(env, funcEnv))->value);
        break;
    case DIV_BIN:
        return std::make_shared<IntLiteral>(std::dynamic_pointer_cast<IntLiteral>(left->interp(env, funcEnv))->value / std::dynamic_pointer_cast<IntLiteral>(right->interp(env, funcEnv))->value);
        break;
    case PLUS_BIN:
        return std::make_shared<IntLiteral>(std::dynamic_pointer_cast<IntLiteral>(left->interp(env, funcEnv))->value + std::dynamic_pointer_cast<IntLiteral>(right->interp(env, funcEnv))->value);
        break;
    case MIN_BIN:
        return std::make_shared<IntLiteral>(std::dynamic_pointer_cast<IntLiteral>(left->interp(env, funcEnv))->value - std::dynamic_pointer_cast<IntLiteral>(right->interp(env, funcEnv))->value);
        break;

    default:
        // TODO: Throw error(wrong operator?) in typecheck!
        break;
    }
}
