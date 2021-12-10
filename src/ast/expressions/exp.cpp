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

std::shared_ptr<Type> UnaryExp::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    std::shared_ptr<Type> resultType = unaryExp->typecheck(env, funcEnv, typeErrors);

    // Typecheck for booleans
    if(std::dynamic_pointer_cast<BooleanType>(resultType) != nullptr)
    {
        switch (op)
        {
            case NOT_UNARY:
                // Everything is fine
                break;
            default:
                typeErrors.push_back("Tried to use non-valid unary operator on boolean unary expression!");
                break;
        }
    }

    // Typecheck for integers
    if(std::dynamic_pointer_cast<IntegerType>(resultType) != nullptr)
    {
        switch (op)
        {
        case PLUS_UNARY:
            // Everything is fine
            break;
        case MIN_UNARY:
            // Everything is fine
            break;
        default:
            typeErrors.push_back("Tried to use non-valid unary operator on integer unary expression!");
            break;
        }
    }

    return resultType;
}



// ============= FunctionCall =============

FunctionCall::FunctionCall(Exp* primExp, ExpList* expList): primaryExp{primExp}, arguments{expList}{}

std::vector<std::shared_ptr<Literal>> FunctionCall::executeFunction(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: Typechecker: Check if function exists + if parameters have correct type!!
    // Get the name of the function that's being called 
    std::string funcName = primaryExp->getOperandName();

    // Push function on the call stack
    funcEnv.pushFunc(funcName);

    // Evaluate the parameters
    std::vector<std::shared_ptr<Literal>> argValues;
    if(arguments.get() != nullptr)
    {
        arguments->interp(env, funcEnv, argValues);
    }

    // We are entering the function's scope
    env.pushScope();

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

    // Pop function from call stack
    funcEnv.popFunc();

    // Pop scope after the function has been executed
    env.popScope();

    return funcEnv.lookupVar(funcName)->returnValues;
};


std::vector<std::shared_ptr<Type>> FunctionCall::typeCheckFunction(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    std::string funcName = primaryExp->getOperandName();

    FuncTableEntry* functionEntry = funcEnv.lookupVar(funcName);

    // Check if function exists
    if(functionEntry == nullptr)
    {
        typeErrors.push_back("Trying to call non-existing function: " + funcName);
        std::vector<std::shared_ptr<Type>> empty{};
        return empty;
    }

    // Push function on the call stack
    funcEnv.pushFunc(funcName);

    // Typecheck the arguments!
    std::vector<std::shared_ptr<Type>> argTypes;
    if(arguments.get() != nullptr)
    {
        arguments->typecheck(env, funcEnv, argTypes, typeErrors);
    }

    // Get parameter types
    std::vector<std::pair<std::vector<std::string>, std::shared_ptr<Type>>> idsAndTypes;
    functionEntry->funcDecl->funcSign->parameters->getIdentifiersWithTypes(idsAndTypes);

    // Check argument types with parameter types (signature)!
    int argCounter = 0;
    for (auto t : idsAndTypes)
    {
        for (int i = 0; i < t.first.size(); i++)
        {
            // Integer and non-integer
            if(std::dynamic_pointer_cast<IntegerType>(t.second) != nullptr && std::dynamic_pointer_cast<IntegerType>(argTypes[argCounter]) == nullptr)
            {
                typeErrors.push_back("Function argument " + std::to_string(argCounter) + " is non-integer and function was expecting integer.");
            }

            // Boolean and non-boolean
            if(std::dynamic_pointer_cast<BooleanType>(t.second) != nullptr && std::dynamic_pointer_cast<BooleanType>(argTypes[argCounter]) == nullptr)
            {
                typeErrors.push_back("Function argument " + std::to_string(argCounter) + " is non-boolean and function was expecting boolean.");
            }
            
            argCounter++;
        }
    }

    // We are entering the function's scope
    env.pushScope();

    // Add argument types to function scope
    int valueIndex = 0;
    for(int i = 0; i < idsAndTypes.size(); i++)
    {
        for(int j = 0; j < idsAndTypes.at(i).first.size(); j++)
        {
             env.currentScope()->add(idsAndTypes.at(i).first.at(j), idsAndTypes.at(i).second, nullptr);
             valueIndex++;
        }
    }

    // Typecheck the function's body
    //funcEnv.lookupVar(funcName)->funcDecl->funcBody->typecheck(env, funcEnv, typeErrors);

    // Pop function from call stack
    funcEnv.popFunc();

    // Pop scope after the function has been executed
    env.popScope();

    // TODO: typecheck return statement with getTypes()!!!
    return funcEnv.lookupVar(funcName)->funcDecl->funcSign->result->getTypes();
}


std::shared_ptr<Type> FunctionCall::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    // TODO: This is quite a dirty solution, find something better
    return this->typeCheckFunction(env, funcEnv, typeErrors)[0];
}

std::shared_ptr<Literal> FunctionCall::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: This is quite a dirty solution, find something better
    return this->executeFunction(env, funcEnv)[0];
}


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

std::shared_ptr<Type> OperandExp::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    return operand->typecheck(env, funcEnv, typeErrors);
}

// ============= BinaryExp =============
BinaryExp::BinaryExp(Exp* left, Exp* right, BinaryOperator op): left{left}, right{right}, op{op}{}

std::string BinaryExp::getOperandName() 
{
    return std::string("NO_OPERAND_EXPRESSION");
}

std::shared_ptr<Literal> BinaryExp::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: TYPECHECKING, also check, in case there are functions, that the function doesn't return more than 2 values!!!
    switch (op)
    {
        // EQ_BIN and NE_BIN can be used on both integers and booleans
        case EQ_BIN:
            if(std::dynamic_pointer_cast<BoolLiteral>(left->interp(env, funcEnv)) != nullptr)
            {
                return std::make_shared<BoolLiteral>(std::dynamic_pointer_cast<BoolLiteral>(left->interp(env, funcEnv))->value == std::dynamic_pointer_cast<BoolLiteral>(right->interp(env, funcEnv))->value);
            }
            if(std::dynamic_pointer_cast<IntLiteral>(left->interp(env, funcEnv)) != nullptr)
            {
                return std::make_shared<BoolLiteral>(std::dynamic_pointer_cast<IntLiteral>(left->interp(env, funcEnv))->value == std::dynamic_pointer_cast<IntLiteral>(right->interp(env, funcEnv))->value);
            }
            break;

        case NE_BIN:
            if(std::dynamic_pointer_cast<BoolLiteral>(left->interp(env, funcEnv)) != nullptr)
            {
                return std::make_shared<BoolLiteral>(std::dynamic_pointer_cast<BoolLiteral>(left->interp(env, funcEnv))->value != std::dynamic_pointer_cast<BoolLiteral>(right->interp(env, funcEnv))->value);
            }
            if(std::dynamic_pointer_cast<IntLiteral>(left->interp(env, funcEnv)) != nullptr)
            {
                return std::make_shared<BoolLiteral>(std::dynamic_pointer_cast<IntLiteral>(left->interp(env, funcEnv))->value != std::dynamic_pointer_cast<IntLiteral>(right->interp(env, funcEnv))->value);
            }
            break;

    case LT_BIN:
        return std::make_shared<BoolLiteral>(std::dynamic_pointer_cast<IntLiteral>(left->interp(env, funcEnv))->value < std::dynamic_pointer_cast<IntLiteral>(right->interp(env, funcEnv))->value);
        break;
    case LE_BIN:
        return std::make_shared<BoolLiteral>(std::dynamic_pointer_cast<IntLiteral>(left->interp(env, funcEnv))->value <= std::dynamic_pointer_cast<IntLiteral>(right->interp(env, funcEnv))->value);
        break;
    case GT_BIN:
        return std::make_shared<BoolLiteral>(std::dynamic_pointer_cast<IntLiteral>(left->interp(env, funcEnv))->value > std::dynamic_pointer_cast<IntLiteral>(right->interp(env, funcEnv))->value);
        break;
    case GE_BIN:
        return std::make_shared<BoolLiteral>(std::dynamic_pointer_cast<IntLiteral>(left->interp(env, funcEnv))->value >= std::dynamic_pointer_cast<IntLiteral>(right->interp(env, funcEnv))->value);
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


std::shared_ptr<Type> BinaryExp::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
     // TODO: TYPECHECKING, also check, in case there are functions, that the function doesn't return more than 2 values!!!
    switch (op)
    {
        // EQ_BIN and NE_BIN can be used on both integers and booleans
        case EQ_BIN:
            // Boolean type check on left and right operand
            if((std::dynamic_pointer_cast<BooleanType>(left->typecheck(env, funcEnv, typeErrors)) != nullptr 
                && std::dynamic_pointer_cast<BooleanType>(right->typecheck(env, funcEnv, typeErrors)) == nullptr) ||
                (std::dynamic_pointer_cast<BooleanType>(right->typecheck(env, funcEnv, typeErrors)) != nullptr 
                && std::dynamic_pointer_cast<BooleanType>(left->typecheck(env, funcEnv, typeErrors)) == nullptr))
                {
                    typeErrors.push_back("Type error in BinExp: If left operand of EQ_BIN is boolean, right operand should be boolean as well, and vice versa.");
                }

            // Integer type check on left and right operand
            if((std::dynamic_pointer_cast<IntegerType>(left->typecheck(env, funcEnv, typeErrors)) != nullptr 
                && std::dynamic_pointer_cast<IntegerType>(right->typecheck(env, funcEnv, typeErrors)) == nullptr) ||
                (std::dynamic_pointer_cast<IntegerType>(right->typecheck(env, funcEnv, typeErrors)) != nullptr 
                && std::dynamic_pointer_cast<IntegerType>(left->typecheck(env, funcEnv, typeErrors)) == nullptr))
                {
                    typeErrors.push_back("Type error in BinExp: If left operand of EQ_BIN is integer, right operand should be integer as well, and vice versa.");
                }
            return std::make_shared<BooleanType>();
            break;

        case NE_BIN:
            // Boolean type check on left and right operand
            if((std::dynamic_pointer_cast<BooleanType>(left->typecheck(env, funcEnv, typeErrors)) != nullptr 
                && std::dynamic_pointer_cast<BooleanType>(right->typecheck(env, funcEnv, typeErrors)) == nullptr) ||
                (std::dynamic_pointer_cast<BooleanType>(right->typecheck(env, funcEnv, typeErrors)) != nullptr 
                && std::dynamic_pointer_cast<BooleanType>(left->typecheck(env, funcEnv, typeErrors)) == nullptr))
                {
                    typeErrors.push_back("Type error in BinExp: If left operand of NE_BIN is boolean, right operand should be boolean as well, and vice versa.");
                }
                
            // Integer type check on left and right operand
            if((std::dynamic_pointer_cast<IntegerType>(left->typecheck(env, funcEnv, typeErrors)) != nullptr 
                && std::dynamic_pointer_cast<IntegerType>(right->typecheck(env, funcEnv, typeErrors)) == nullptr) ||
                (std::dynamic_pointer_cast<IntegerType>(right->typecheck(env, funcEnv, typeErrors)) != nullptr 
                && std::dynamic_pointer_cast<IntegerType>(left->typecheck(env, funcEnv, typeErrors)) == nullptr))
                {
                    typeErrors.push_back("Type error in BinExp: If left operand of NE_BIN is integer, right operand should be integer as well, and vice versa.");
                }
            return std::make_shared<BooleanType>();
            break;

    case LT_BIN:
        if(std::dynamic_pointer_cast<IntegerType>(left->typecheck(env, funcEnv, typeErrors)) == nullptr ||  std::dynamic_pointer_cast<IntegerType>(right->typecheck(env, funcEnv, typeErrors)) == nullptr)
        {
            typeErrors.push_back("Type error in BinExp: Operator LT_BIN is only defined for integer literal operands.");
        }
        return std::make_shared<BooleanType>();
        break;
    case LE_BIN:
        if(std::dynamic_pointer_cast<IntegerType>(left->typecheck(env, funcEnv, typeErrors)) == nullptr ||  std::dynamic_pointer_cast<IntegerType>(right->typecheck(env, funcEnv, typeErrors)) == nullptr)
        {
            typeErrors.push_back("Type error in BinExp: Operator LE_BIN is only defined for integer literal operands.");
        }
        return std::make_shared<BooleanType>();
        break;
    case GT_BIN:
        if(std::dynamic_pointer_cast<IntegerType>(left->typecheck(env, funcEnv, typeErrors)) == nullptr ||  std::dynamic_pointer_cast<IntegerType>(right->typecheck(env, funcEnv, typeErrors)) == nullptr)
        {
            typeErrors.push_back("Type error in BinExp: Operator GT_BIN is only defined for integer literal operands.");
        }
        return std::make_shared<BooleanType>();
        break;
    case GE_BIN:
        if(std::dynamic_pointer_cast<IntegerType>(left->typecheck(env, funcEnv, typeErrors)) == nullptr ||  std::dynamic_pointer_cast<IntegerType>(right->typecheck(env, funcEnv, typeErrors)) == nullptr)
        {
            typeErrors.push_back("Type error in BinExp: Operator GE_BIN is only defined for integer literal operands");
        }
        return std::make_shared<BooleanType>();
        break;
    case OR_BIN:
        if(std::dynamic_pointer_cast<BooleanType>(left->typecheck(env, funcEnv, typeErrors)) == nullptr ||  std::dynamic_pointer_cast<BooleanType>(right->typecheck(env, funcEnv, typeErrors)) == nullptr)
        {
            typeErrors.push_back("Type error in BinExp: Operator OR_BIN is only defined for boolean literal operands.");
        }
        return std::make_shared<BooleanType>();
        break;
    case AND_BIN:
        if(std::dynamic_pointer_cast<BooleanType>(left->typecheck(env, funcEnv, typeErrors)) == nullptr ||  std::dynamic_pointer_cast<BooleanType>(right->typecheck(env, funcEnv, typeErrors)) == nullptr)
        {
            typeErrors.push_back("Type error in BinExp: Operator AND_BIN is only defined for boolean literal operands.");
        }
        return std::make_shared<BooleanType>();
        break;

    // INTEGERS
    case MUL_BIN:
        if(std::dynamic_pointer_cast<IntegerType>(left->typecheck(env, funcEnv, typeErrors)) == nullptr ||  std::dynamic_pointer_cast<IntegerType>(right->typecheck(env, funcEnv, typeErrors)) == nullptr)
        {
            typeErrors.push_back("Type error in BinExp: Operator MUL_BIN is only defined for integer literal operands.");
        }
        return std::make_shared<IntegerType>();
        break;
    case DIV_BIN:
        if(std::dynamic_pointer_cast<IntegerType>(left->typecheck(env, funcEnv, typeErrors)) == nullptr ||  std::dynamic_pointer_cast<IntegerType>(right->typecheck(env, funcEnv, typeErrors)) == nullptr)
        {
            typeErrors.push_back("Type error in BinExp: Operator DIV_BIN is only defined for integer literal operands.");
        }
        return std::make_shared<IntegerType>();
        break;
    case PLUS_BIN:  
        if(std::dynamic_pointer_cast<IntegerType>(left->typecheck(env, funcEnv, typeErrors)) == nullptr ||  std::dynamic_pointer_cast<IntegerType>(right->typecheck(env, funcEnv, typeErrors)) == nullptr)
        {
            typeErrors.push_back("Type error in BinExp: Operator PLUS_BIN is only defined for integer literal operands.");
        }
        return std::make_shared<IntegerType>();  
        break;
    case MIN_BIN:
        if(std::dynamic_pointer_cast<IntegerType>(left->typecheck(env, funcEnv, typeErrors)) == nullptr ||  std::dynamic_pointer_cast<IntegerType>(right->typecheck(env, funcEnv, typeErrors)) == nullptr)
        {
            typeErrors.push_back("Type error in BinExp: Operator MIN_BIN is only defined for integer literal operands.");
        }
        return std::make_shared<IntegerType>();
        break;

    default:
        typeErrors.push_back("Type error in BinExp: Unknown operator.");
        break;
    }
}