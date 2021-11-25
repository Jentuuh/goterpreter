#include "exp.h"

// ============= UnaryExp =============
UnaryExp::UnaryExp(Exp* unaryExp, UnaryOperator op): unaryExp{unaryExp}, op{op}{}

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
    // TODO: implement
}

// ============= OperandExp =============

OperandExp::OperandExp(Operand* operand): operand{operand}{}

std::shared_ptr<Literal> OperandExp::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    return operand->interp(env, funcEnv);
}
// ============= BinaryExp =============
BinaryExp::BinaryExp(Exp* left, Exp* right, BinaryOperator op): left{left}, right{right}, op{op}{}

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
