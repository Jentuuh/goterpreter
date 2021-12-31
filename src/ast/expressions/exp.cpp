#include "exp.h"
#include "../../environment/interp/env.h"
#include <iostream>
#include <algorithm>

// ============= UnaryExp =============
UnaryExp::UnaryExp(Exp* unaryExp, UnaryOperator op): unaryExp{unaryExp}, op{op}{}

std::string UnaryExp::getOperandName() 
{
    return std::string("NO_OPERAND_EXPRESSION");
}

void UnaryExp::getRefNames(std::vector<std::string>& refContainer)
{
    unaryExp->getRefNames(refContainer);
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
            break;
        }
    }

    return intermediateResult;
}

std::shared_ptr<Type> UnaryExp::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    if(std::dynamic_pointer_cast<FunctionCall>(unaryExp) != nullptr) {

        std::vector<std::shared_ptr<Type>> returnTypes = std::dynamic_pointer_cast<FunctionCall>(unaryExp)->typeCheckFunction(env, funcEnv, typeErrors);
        if(returnTypes.size() > 1 || returnTypes.size() == 0)
        {
            typeErrors.push_back("Type error in UnaryExp: The function used in a UnaryExp has 0 or more than 1 return value. Can only use functions with 1 return value in a UnaryExp.");
            return nullptr;
        }
    }

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
                typeErrors.push_back("Type error in UnaryExp: Tried to use non-valid unary operator on boolean unary expression!");
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
            typeErrors.push_back("Type error in UnaryExp: Tried to use non-valid unary operator on integer unary expression!");
            break;
        }
    }

    return resultType;
}


std::vector<std::shared_ptr<Type>> UnaryExp::getType(ScopedEnv& env,FunctionEnv& funcEnv)
{
    return unaryExp->getType(env, funcEnv);
}


// ============= FunctionCall =============

FunctionCall::FunctionCall(Exp* primExp, ExpList* expList): primaryExp{primExp}, arguments{expList}{}

std::vector<std::shared_ptr<Literal>> FunctionCall::executeFunction(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // Get the name of the function that's being called 
    std::string funcName = primaryExp->getOperandName();

    // Push function on the call stack
    funcEnv.pushFunc(funcName);

    // Evaluate the parameters
    std::vector<std::shared_ptr<Literal>> argValues;
    if(arguments != nullptr)
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

    // Correct the reversed order of the argument names and types
    std::reverse(argNamesAndTypes.begin(), argNamesAndTypes.end());

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

    std::vector<std::shared_ptr<Literal>> returnVals = funcEnv.lookupVar(funcName)->returnValues;

    // We need to reset the return values, so next function calls can overwrite it again
    funcEnv.declaredFunctions.resetReturnValues(funcName);
    return returnVals;
};


std::vector<std::shared_ptr<Type>> FunctionCall::typeCheckFunction(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{

    std::string funcName = primaryExp->getOperandName();

    std::shared_ptr<FuncTableEntry> functionEntry = funcEnv.lookupVar(funcName);

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
    if(arguments != nullptr)
    {  
        arguments->typecheck(env, funcEnv, argTypes, typeErrors);
    }

    // Get parameter types
    std::vector<std::pair<std::vector<std::string>, std::shared_ptr<Type>>> idsAndTypes;
    if(funcEnv.lookupVar(funcName)->funcDecl->funcSign->parameters != nullptr)
    {
        functionEntry->funcDecl->funcSign->parameters->getIdentifiersWithTypes(idsAndTypes);
    }

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

    // Pop function from call stack
    funcEnv.popFunc();

    if(funcEnv.lookupVar(funcName)->funcDecl->funcSign->result == nullptr)
    {
        std::vector<std::shared_ptr<Type>> empty {};
        return empty;
    } else {
        
        std::vector<std::shared_ptr<Type>> returnTypes{};
        funcEnv.lookupVar(funcName)->funcDecl->funcSign->result->getTypes(returnTypes);
        return returnTypes;
    }
}


std::shared_ptr<Type> FunctionCall::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    // TODO: This is quite a dirty solution, find something better
    std::vector<std::shared_ptr<Type>> result = this->typeCheckFunction(env, funcEnv, typeErrors);
    if(result.size() > 0)
    {
        return result[0];
    }
    return nullptr;
}

std::shared_ptr<Literal> FunctionCall::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: This is quite a dirty solution, find something better
    std::vector<std::shared_ptr<Literal>> result = this->executeFunction(env, funcEnv);
    if(result.size() > 0)
    {
        return result[0];
    }
    return nullptr;
}


std::string FunctionCall::getOperandName() 
{
    return std::string("FUNCTION_CALL");
}

void FunctionCall::getRefNames(std::vector<std::string>& refContainer)
{
    refContainer.push_back("FUNCTION_CALL");
}

std::vector<std::shared_ptr<Type>> FunctionCall::getType(ScopedEnv& env,FunctionEnv& funcEnv)
{
    std::string funcName = primaryExp->getOperandName();

    std::shared_ptr<FuncTableEntry> functionEntry = funcEnv.lookupVar(funcName);

    // Check if function exists
    if(functionEntry == nullptr)
    {
        std::vector<std::shared_ptr<Type>> empty{};
        return empty;
    }

    if(functionEntry->funcDecl->funcSign->result == nullptr)
    {
        std::vector<std::shared_ptr<Type>> empty {};
        return empty;
    } else {
        std::vector<std::shared_ptr<Type>> returnTypes{};
        functionEntry->funcDecl->funcSign->result->getTypes(returnTypes);
        return returnTypes;
    }
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

void OperandExp::getRefNames(std::vector<std::string>& refContainer)
{
    if(std::dynamic_pointer_cast<VariableOperand>(operand) != nullptr)
        refContainer.push_back(std::dynamic_pointer_cast<VariableOperand>(operand)->operandName->name);
    else{
        refContainer.push_back(std::string("NO_OPERAND_EXPRESSION"));
    }
}

std::shared_ptr<Type> OperandExp::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    return operand->typecheck(env, funcEnv, typeErrors);
}


std::vector<std::shared_ptr<Type>> OperandExp::getType(ScopedEnv& env,FunctionEnv& funcEnv)
{
    return operand->getType(env, funcEnv);
}


// ============= BinaryExp =============
BinaryExp::BinaryExp(Exp* left, Exp* right, BinaryOperator op): left{left}, right{right}, op{op}{}

std::string BinaryExp::getOperandName() 
{
    return std::string("NO_OPERAND_EXPRESSION");
}

void BinaryExp::getRefNames(std::vector<std::string>& refContainer)
{
    left->getRefNames(refContainer);
    right->getRefNames(refContainer);
}


std::shared_ptr<Literal> BinaryExp::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
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
        break;
    }
    return nullptr;
}


std::shared_ptr<Type> BinaryExp::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    bool shouldReturn = false;
    // In case the left and/or right expression is a function, check whether they return exactly 1 value.
    if(std::dynamic_pointer_cast<FunctionCall>(left) != nullptr) {

        std::vector<std::shared_ptr<Type>> returnTypes = std::dynamic_pointer_cast<FunctionCall>(left)->typeCheckFunction(env, funcEnv, typeErrors);
        if(returnTypes.size() > 1 || returnTypes.size() == 0)
        {
            typeErrors.push_back("Type error in BinaryExp: Multiple-value or zero-value function used in single-value context.");
            shouldReturn = true;
        }
    }

    if(std::dynamic_pointer_cast<FunctionCall>(right) != nullptr) {

        std::vector<std::shared_ptr<Type>> returnTypes = std::dynamic_pointer_cast<FunctionCall>(right)->typeCheckFunction(env, funcEnv, typeErrors);
        if(returnTypes.size() > 1 || returnTypes.size() == 0)
        {
            typeErrors.push_back("Type error in BinaryExp: Multiple-value or zero-value function used in single-value context.");
            shouldReturn = true;
        }
    }

    // If we are trying to use multiple-value functions in a BinaryExp, the next steps will go fatally wrong, so return here.
    if(shouldReturn)
        return nullptr;


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
        if((std::dynamic_pointer_cast<IntegerType>(left->typecheck(env, funcEnv, typeErrors)) == nullptr ||  std::dynamic_pointer_cast<IntegerType>(right->typecheck(env, funcEnv, typeErrors)) == nullptr))
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
        return nullptr;
        break;
    }
}


std::vector<std::shared_ptr<Type>> BinaryExp::getType(ScopedEnv& env,FunctionEnv& funcEnv)
{
    std::vector<std::shared_ptr<Type>> result{};

    switch (op)
    {
       // EQ_BIN and NE_BIN can be used on both integers and booleans
        case EQ_BIN:

            result.push_back(std::make_shared<BooleanType>());
            break;

        case NE_BIN:

            result.push_back(std::make_shared<BooleanType>());
            break;

    case LT_BIN:

        result.push_back(std::make_shared<BooleanType>());
        break;
    case LE_BIN:
    
        result.push_back(std::make_shared<BooleanType>());
        break;
    case GT_BIN:

        result.push_back(std::make_shared<BooleanType>());
        break;
    case GE_BIN:

        result.push_back(std::make_shared<BooleanType>());
        break;
    case OR_BIN:

        result.push_back(std::make_shared<BooleanType>());
        break;
    case AND_BIN:

        result.push_back(std::make_shared<BooleanType>());
        break;

    // INTEGERS
    case MUL_BIN:

        result.push_back(std::make_shared<IntegerType>());
        break;
    case DIV_BIN:

        result.push_back(std::make_shared<IntegerType>());
        break;
    case PLUS_BIN:  

        result.push_back(std::make_shared<IntegerType>());
        break;
    case MIN_BIN:

        result.push_back(std::make_shared<IntegerType>());
        break;

    default:
        break;
    }
    return result;
}
