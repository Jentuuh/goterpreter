#include "stm.h"
#include "../../environment/interp/env.h"
#include <algorithm>
#include <iostream>

// ============= DeclStm =============
DeclStm::DeclStm(TopLevelDecl* decl): declaration{decl}{}

void DeclStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    if(funcEnv.lookupVar(funcEnv.currentFunc()) != nullptr){
        if(funcEnv.lookupVar(funcEnv.currentFunc())->hasReturned)
            return;
    } 
    declaration->interp(env, funcEnv);
}

void DeclStm::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    declaration->typecheck(env, funcEnv, typeErrors);
}


// ============= BlockStm =============
BlockStm::BlockStm(Block* block): block{block}{}

void BlockStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    if(funcEnv.lookupVar(funcEnv.currentFunc()) != nullptr){
        if(funcEnv.lookupVar(funcEnv.currentFunc())->hasReturned)
            return;
    } 
    env.pushScope(false);
    block->interp(env, funcEnv);
    env.popScope(false);
}

void BlockStm::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    env.pushScope(false);
    block->typecheck(env, funcEnv, typeErrors);
    env.popScope(false);
}

// ============= IfStm =============
IfStm::IfStm(Stm* simpleStm, Exp* cond, Block* ifBlock, Block* elseBlock, Stm* nestedIf): simpleStm{simpleStm}, condition{cond}, ifBlock{ifBlock}, elseBlock{elseBlock}, nestedIfStm{nestedIf}{}

void IfStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    if(funcEnv.lookupVar(funcEnv.currentFunc()) != nullptr){
        if(funcEnv.lookupVar(funcEnv.currentFunc())->hasReturned)
            return;
    } 
    // First, execute simple statement if there is any
    if(simpleStm != nullptr)
    {
        simpleStm->interp(env, funcEnv);
    }

    env.pushScope(false);
    // Check if condition is true
    if(std::dynamic_pointer_cast<BoolLiteral>(condition->interp(env, funcEnv))->value)
    {
        ifBlock->interp(env, funcEnv);
    }
    else
    {
        // Execute else block (if there is one)
        if(elseBlock != nullptr)
        {
            elseBlock->interp(env, funcEnv);
        }
        // Execute nested if statement (if there is one)
        if(nestedIfStm != nullptr)
        {
            nestedIfStm->interp(env, funcEnv);
        }
    }
    env.popScope(false);
}

void IfStm::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{

    if(simpleStm != nullptr)
    {
        simpleStm->typecheck(env, funcEnv, typeErrors);
    }

    env.pushScope(false);
    // Check if condition has boolean type
    if(std::dynamic_pointer_cast<BooleanType>(condition->typecheck(env, funcEnv, typeErrors)) == nullptr) 
    {
        typeErrors.push_back("Type error in IfStm: Condition needs to be a boolean type!");
    }

    // Typecheck if-block
    ifBlock->typecheck(env, funcEnv, typeErrors);
    // Typecheck else-block and nested stm (if there are any)
    if(elseBlock != nullptr)
    {
        elseBlock->typecheck(env, funcEnv, typeErrors);
    }
    if(nestedIfStm != nullptr)
    {
        nestedIfStm->typecheck(env, funcEnv, typeErrors);
    }

    env.popScope(false);
}


int IfStm::amountPaths()
{
    if(elseBlock != nullptr)
    {
        return 2;
    } else {

        if(nestedIfStm != nullptr)
            return 1 + std::dynamic_pointer_cast<IfStm>(nestedIfStm)->amountPaths();
    }
    return 1;
}

int IfStm::countReturnStatements()
{
    if(elseBlock != nullptr)
    {
        // If the if-else blocks do not both contain return statements, return 0 (because they both should)
        if(ifBlock->countReturnStatements() < 1 && elseBlock->countReturnStatements() < 1 )
            return 0;
        if(ifBlock->countReturnStatements() < 1 || elseBlock->countReturnStatements() < 1 )
            return 1;
        if(ifBlock->countReturnStatements() >= 1 && elseBlock->countReturnStatements() >= 1 )
            return 2;

        return ifBlock->countReturnStatements() + elseBlock->countReturnStatements();
    } else {

        if(nestedIfStm != nullptr){
            // If the nested if statements do not pass the test, let the whole if statement fail
            // if(std::dynamic_pointer_cast<IfStm>(nestedIfStm)->countReturnStatements() < std::dynamic_pointer_cast<IfStm>(nestedIfStm)->amountPaths() || ifBlock->countReturnStatements() < 1)
            //     return 0;

            return ifBlock->countReturnStatements() + std::dynamic_pointer_cast<IfStm>(nestedIfStm)->countReturnStatements();
        }
    }
    return ifBlock->countReturnStatements();
}

bool IfStm::checkReturnPaths(bool isOkay)
{
        // if(nestedIfStm != nullptr)
        // {
        //     return isOkay || (ifBlock->checkReturnPaths(isOkay) && elseBlock->checkReturnPaths(isOkay) && std::dynamic_pointer_cast<IfStm>(nestedIfStm)->checkReturnPaths(isOkay));
        // } else {
        //     return isOkay || (ifBlock->checkReturnPaths(isOkay) && elseBlock->checkReturnPaths(isOkay));
        // }

    if(elseBlock != nullptr)
    {
        return isOkay || (ifBlock->checkReturnPaths(isOkay) && elseBlock->checkReturnPaths(isOkay));
    }

    if(elseBlock == nullptr && nestedIfStm == nullptr)
    {
        return isOkay;
    }

    if(elseBlock == nullptr && nestedIfStm != nullptr)
    {
        return isOkay || (ifBlock->checkReturnPaths(isOkay) && std::dynamic_pointer_cast<IfStm>(nestedIfStm)->checkReturnPaths(isOkay));
    }
}



// ============= ForCondStm =============
ForCondStm::ForCondStm(Exp* cond, Block* body): condition{cond}, body{body}{}

void ForCondStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    env.pushScope(false);
    // The for-loop can be executed as long as the condition evaluates to true
    while(std::dynamic_pointer_cast<BoolLiteral>(condition->interp(env, funcEnv))->value)
    {
        if(funcEnv.lookupVar(funcEnv.currentFunc()) != nullptr){
            if(funcEnv.lookupVar(funcEnv.currentFunc())->hasReturned)
                return;
        } 
        body->interp(env, funcEnv);
    }
    env.popScope(false);
}

void ForCondStm::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    env.pushScope(false);
    // Check if condition has boolean type 
    if(std::dynamic_pointer_cast<BooleanType>(condition->typecheck(env, funcEnv, typeErrors)) == nullptr) 
    {
        typeErrors.push_back("Type error in ForCondStm: Condition needs to be a boolean type!");
    }
    body->typecheck(env, funcEnv, typeErrors);
    env.popScope(false);
}

int ForCondStm::amountPaths()
{
    return body->amountPaths();
}

int ForCondStm::countReturnStatements()
{
    return body->countReturnStatements();
}

bool ForCondStm::checkReturnPaths(bool isOkay)
{
    return body->checkReturnPaths(isOkay);
}


// ============= ForClauseStm =============
ForClauseStm::ForClauseStm(ForClause* forclause, Block* body): forclause{forclause}, body{body}{}

void ForClauseStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // We execute the init statement once before evaluating the condition (if there is one)
    if(forclause->initStm != nullptr)
        forclause->initStm->interp(env, funcEnv);
    
    env.pushScope(false);
    if(forclause->condition != nullptr)
    {
        while(std::dynamic_pointer_cast<BoolLiteral>(forclause->condition->interp(env, funcEnv))->value)
        {
            if(funcEnv.lookupVar(funcEnv.currentFunc()) != nullptr){
                if(funcEnv.lookupVar(funcEnv.currentFunc())->hasReturned)
                    return;
            } 
            // Execute the body of the for-loop
            body->interp(env, funcEnv);

            // Update condition variable with poststatement (if there is one)
            if(forclause->postStm != nullptr)
                forclause->postStm->interp(env, funcEnv);
        }
    } else {
        // If condition is nullptr, it is the same as for (true) {...}
        while(true)
        {
            if(funcEnv.lookupVar(funcEnv.currentFunc()) != nullptr){
                if(funcEnv.lookupVar(funcEnv.currentFunc())->hasReturned)
                    return;
            } 
            // Execute the body of the for-loop
            body->interp(env, funcEnv);

            // Update condition variable with poststatement (if there is one)
            if(forclause->postStm != nullptr)
                forclause->postStm->interp(env, funcEnv);
        }
    }

    env.popScope(false);
}

void ForClauseStm::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    // Typecheck init statement (if there is one)
    if(forclause->initStm != nullptr)
        forclause->initStm->typecheck(env, funcEnv, typeErrors);

    env.pushScope(false);
    // Check if condition has boolean type 
    if(forclause->condition != nullptr)
    {
        if(std::dynamic_pointer_cast<BooleanType>(forclause->condition->typecheck(env, funcEnv, typeErrors)) == nullptr) 
        {
            typeErrors.push_back("Type error in ForCondStm: Condition needs to be a boolean type!");
        }
    }

    body->typecheck(env, funcEnv, typeErrors);

    // Typecheck post statement (if there is one)
    if(forclause->postStm != nullptr)
        forclause->postStm->typecheck(env, funcEnv, typeErrors);

    env.popScope(false);
}

int ForClauseStm::amountPaths()
{
    return body->amountPaths();
}

int ForClauseStm::countReturnStatements()
{
    return body->countReturnStatements();
}

bool ForClauseStm::checkReturnPaths(bool isOkay)
{
    return body->checkReturnPaths(isOkay);
}

// ============= ForStm =============
ForStm::ForStm(Block* body): body{body}{}

void ForStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{   
    env.pushScope(false);
    while(true)
    {
        if(funcEnv.lookupVar(funcEnv.currentFunc()) != nullptr){
            if(funcEnv.lookupVar(funcEnv.currentFunc())->hasReturned)
                return;
        } 
        body->interp(env, funcEnv);
    }
    env.popScope(false);
}

void ForStm::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    env.pushScope(false);
    body->typecheck(env, funcEnv, typeErrors);
    env.popScope(false);
}

int ForStm::amountPaths()
{
    return body->amountPaths();
}

int ForStm::countReturnStatements()
{
    return body->countReturnStatements();
}

bool ForStm::checkReturnPaths(bool isOkay)
{
    std::cout << "TEST" << std::endl;
    std::cout << std::to_string(body->checkReturnPaths(isOkay)) << std::endl;
    return body->checkReturnPaths(isOkay);
}

// ============= ReturnStm =============
ReturnStm::ReturnStm(ExpList* expList): expressionList{expList}{}

void ReturnStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    std::vector<std::shared_ptr<Literal>> returnValues;

    std::string funcName = funcEnv.currentFunc();
    std::shared_ptr<FuncTableEntry> funcDetails = funcEnv.lookupVar(funcName);

    if(funcEnv.lookupVar(funcEnv.currentFunc()) != nullptr){
        if(funcEnv.lookupVar(funcEnv.currentFunc())->hasReturned)
            return;
    } 
    // Set function's `hasReturned` to true, so no more statements will be evaluated.
    funcEnv.lookupVar(funcName)->hasReturned = true;

    // 1. Check if func signature has any return values specified (This means there should be a ParametersResult)
    if(std::dynamic_pointer_cast<ParametersResult>(funcDetails->funcDecl->funcSign->result) != nullptr)
    {
        std::vector<std::string> returnValueIdentifiers;
        // 2. If so, retrieve these values from the environment, and return them
        if(expressionList != nullptr)
        {
            expressionList->getOperandNames(returnValueIdentifiers);
            for(std::string r : returnValueIdentifiers)
            {
                returnValues.push_back(env.lookupVar(r));
            }
            std::reverse(returnValues.begin(), returnValues.end());
            funcEnv.declaredFunctions.addReturnValues(funcName, returnValues);
            
        } else {

            std::dynamic_pointer_cast<ParametersResult>(funcDetails->funcDecl->funcSign->result)->parameters->getIdentifiers(returnValueIdentifiers);

            for(std::string r : returnValueIdentifiers)
            {
                returnValues.push_back(env.lookupVar(r));
            }
                // std::reverse(returnValues.begin(), returnValues.end());
            funcEnv.declaredFunctions.addReturnValues(funcName, returnValues);
            
        }
    }
    else
    {
        // 3. If not, return whatever expressionlist is behind the return statement
        // 4. If there isn't anything, return an empty list
        if(expressionList != nullptr)
        {
            expressionList->interp(env, funcEnv, returnValues);

            std::reverse(returnValues.begin(), returnValues.end());
            funcEnv.declaredFunctions.addReturnValues(funcName, returnValues);
           
        }
    }
}

void ReturnStm::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{

    std::string funcName = funcEnv.currentFunc();
    std::shared_ptr<FuncTableEntry> funcDetails = funcEnv.lookupVar(funcName);

    std::vector<std::shared_ptr<Type>> returnTypes;
    funcEnv.declaredFunctions.getReturnTypes(funcName, returnTypes);
    

    // 1. Check if func signature has any return values specified (This means there should be a ParametersResult)
    if(std::dynamic_pointer_cast<ParametersResult>(funcDetails->funcDecl->funcSign->result) != nullptr)
    {

        if(expressionList != nullptr)
        {   
            std::vector<std::string> nameContainer;
            expressionList->getOperandNames(nameContainer);

            // 2. If so, retrieve these values from the environment, and return them
            std::vector<std::string> returnValueIdentifiers;
            std::dynamic_pointer_cast<ParametersResult>(funcDetails->funcDecl->funcSign->result)->parameters->getIdentifiers(returnValueIdentifiers);

            if(returnValueIdentifiers.size() != nameContainer.size() && nameContainer.size() != 0)
            {
                typeErrors.push_back("Type error in ReturnStm: " + std::to_string(returnValueIdentifiers.size()) + " return values expected for function " + funcName + " but " + std::to_string(nameContainer.size()) + " return values found.");
            }

            std::reverse(returnValueIdentifiers.begin(), returnValueIdentifiers.end());

            int typeCounter = 0;
            for(std::string s : nameContainer)
            {
                if(std::find(returnValueIdentifiers.begin(), returnValueIdentifiers.end(), s) != returnValueIdentifiers.end()) {
                    // The identifier we are returning is indeed one of our ParameterResult parameters!
                } else {
                    // The identifier we are returning is not one of the ParameterResult parameters that we have specified
                    typeErrors.push_back("Type error in ReturnStm: Function " + funcName + " was trying to return operand '" + s + ", but this identifier is not specified in the ParameterResult.");
                }
            }
        }

    }
    else
    {
        // 3. If not, return whatever expressionlist is behind the return statement
        // 4. If there isn't anything, return an empty list
        if(expressionList != nullptr)
        {   
            std::vector<std::shared_ptr<Type>> expTypes;
            expressionList->typecheck(env, funcEnv, expTypes, typeErrors);

            if(expTypes.size() != returnTypes.size())
            {
                typeErrors.push_back("Type error in ReturnStm: " + std::to_string(returnTypes.size()) + " return values expected for function " + funcName + " but " + std::to_string(expTypes.size()) + " return values found.");
            } else {

                // std::reverse(expTypes.begin(), expTypes.end());
                std::reverse(returnTypes.begin(), returnTypes.end());
                int typeCounter = 0;
                // Check if type corresponds with function signature
                for(auto t : expTypes)
                {
                    if(std::dynamic_pointer_cast<IntegerType>(returnTypes[typeCounter]) != nullptr && std::dynamic_pointer_cast<IntegerType>(t) == nullptr)
                    {
                        typeErrors.push_back("Type error in ReturnStm: Function " + funcName + " was expecting return value '" + std::to_string(typeCounter) + "' of type Integer, but a non-integer was returned.");
                    }

                    if(std::dynamic_pointer_cast<BooleanType>(returnTypes[typeCounter]) != nullptr && std::dynamic_pointer_cast<BooleanType>(t) == nullptr)
                    {
                        typeErrors.push_back("Type error in ReturnStm: Function " + funcName + " was expecting return value '" + std::to_string(typeCounter) + "' of type Integer, but a non-integer was returned.");
                    }
                    typeCounter++;
                }
            }
        } else {
            // If the function is expecting return values but the return expression is empty, there's a type error
            if(returnTypes.size() != 0)
            {
                typeErrors.push_back("Type error in ReturnStm: Function " + funcName + " was expecting a return value(s), but one of the return paths return no value(s).");
            }
        }
    }
}

// ============= EmptyStm =============
EmptyStm::EmptyStm(){}

void EmptyStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // An empty statement does nothing
    return;
}

void EmptyStm::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    return;
}

// ============= AssignmentStm =============
AssignmentStm::AssignmentStm(ExpList* left, ExpList* right, AssignOperator assign_op): leftExpList{left}, rightExpList{right}, assignOp{assign_op}{}

void AssignmentStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    if(funcEnv.lookupVar(funcEnv.currentFunc()) != nullptr){
        if(funcEnv.lookupVar(funcEnv.currentFunc())->hasReturned)
            return;
    } 
    // Evaluate the right side of the assignment to get the values that we will assign
    std::vector<std::shared_ptr<Literal>> newValues;
    rightExpList->interp(env, funcEnv, newValues);

    // Get the variable names (identifiers) of the left side of the assignment
    std::vector<std::string> operandNames;
    leftExpList->getOperandNames(operandNames);

    if(newValues.size() == 1)
    {
        // Update all variables on the left side with this value
        for(std::string n : operandNames)
        {
            switch (assignOp)
            {
                case ASSIGN_OP:
                    env.updateVar(n, newValues[0]);
                    break;
                case PLUSASSIGN_OP:
                    std::dynamic_pointer_cast<IntLiteral>(env.lookupVar(n))->value += std::dynamic_pointer_cast<IntLiteral>(newValues[0])->value;
                    break;
                case MINASSIGN_OP:
                    std::dynamic_pointer_cast<IntLiteral>(env.lookupVar(n))->value -= std::dynamic_pointer_cast<IntLiteral>(newValues[0])->value;
                    break;
                case MULASSIGN_OP:
                    std::dynamic_pointer_cast<IntLiteral>(env.lookupVar(n))->value *= std::dynamic_pointer_cast<IntLiteral>(newValues[0])->value;
                    break;
                case DIVASSIGN_OP:
                    std::dynamic_pointer_cast<IntLiteral>(env.lookupVar(n))->value /= std::dynamic_pointer_cast<IntLiteral>(newValues[0])->value;
                    break;
                default:
                    // Error: wrong operator
                    break;
            }
        }
    }
    else
    {
        if (operandNames.size() == newValues.size())
        {
            // Update each n'th variable with the n'th value
            for(int i = 0; i < operandNames.size(); i++)
            {
                 switch (assignOp)
                {
                    case ASSIGN_OP:
                        env.updateVar(operandNames[i], newValues[i]);
                        break;
                    case PLUSASSIGN_OP:
                        std::dynamic_pointer_cast<IntLiteral>(env.lookupVar(operandNames[i]))->value += std::dynamic_pointer_cast<IntLiteral>(newValues[i])->value;
                        break;
                    case MINASSIGN_OP:
                        std::dynamic_pointer_cast<IntLiteral>(env.lookupVar(operandNames[i]))->value -= std::dynamic_pointer_cast<IntLiteral>(newValues[i])->value;
                        break;
                    case MULASSIGN_OP:
                        std::dynamic_pointer_cast<IntLiteral>(env.lookupVar(operandNames[i]))->value *= std::dynamic_pointer_cast<IntLiteral>(newValues[i])->value;
                        break;
                    case DIVASSIGN_OP:
                        std::dynamic_pointer_cast<IntLiteral>(env.lookupVar(operandNames[i]))->value /= std::dynamic_pointer_cast<IntLiteral>(newValues[i])->value;
                        break;
                    default:
                        // Error: wrong operator
                        break;
                }
            }
        }
    }
}

void AssignmentStm::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    // Evaluate the right side of the assignment to get the values that we will assign
    std::vector<std::shared_ptr<Type>> rightTypes;
    rightExpList->typecheck(env, funcEnv, rightTypes, typeErrors);

    // Get the variable names (identifiers) of the left side of the assignment
    std::vector<std::string> leftOperandNames;
    leftExpList->getOperandNames(leftOperandNames);

    int leftCounter = 0;
    for(auto n: leftOperandNames)
    {
        // Check if left-hand expressions are addressable
        if(n == "NO_OPERAND_EXPRESSION" || n == "FUNCTION_CALL")
        {
            typeErrors.push_back("Type error in AssignmentStm: Left-hand expression " + std::to_string(leftCounter) + " should be an addressable expression (e.g. Operand Expression).");
        }
        else{
            // Check if left-hand expressions are defined in this scope
            std::pair<int, bool> varExists = env.varExists(n);
            if(varExists.first == 0)
            {
                typeErrors.push_back("Type error in AssignmentStm: variable " + n + " was not defined.");
            }
        }
        leftCounter++;
    }

    // TODO: Check that BLANK OPERATOR is not used in operator assignment!
    switch (assignOp)
    {
        case ASSIGN_OP:
        {

            if(rightTypes.size() != leftOperandNames.size())
            {
                typeErrors.push_back("Type error in AssignmentStm: ASSIGN_OP expects an equal amount of expressions on the left and right hand side of the operator.");
            }

            int typeCounter = 0;
            for(auto n : leftOperandNames)
            {
                // Check if we are trying to assign a non-integer to an integer variable
                if(std::dynamic_pointer_cast<IntegerType>(env.getVarType(n)) != nullptr && std::dynamic_pointer_cast<IntegerType>(rightTypes[typeCounter]) == nullptr)
                {
                    typeErrors.push_back("Type error in AssignmentStm: Trying to assign non-integer to variable " + n + " but " + n + " is of type Integer.");
                }

                // Check if we are trying to assign a non-boolean to an boolean variable
                if(std::dynamic_pointer_cast<BooleanType>(env.getVarType(n)) != nullptr && std::dynamic_pointer_cast<BooleanType>(rightTypes[typeCounter]) == nullptr)
                {
                    typeErrors.push_back("Type error in AssignmentStm: Trying to assign non-boolean to variable " + n + " but " + n + " is of type Boolean.");
                }
                typeCounter++;
            }
            break;
        }
        case PLUSASSIGN_OP:
        {

            if(rightTypes.size() != 1 || leftOperandNames.size() != 1)
            {
                typeErrors.push_back("Type error in AssignmentStm: An operator assignment can only have 1 left-hand and 1 right-hand expression.");
            }
            
            // Operator assignments are only allowed on integers
            if(std::dynamic_pointer_cast<IntegerType>(env.getVarType(leftOperandNames[0])) == nullptr || std::dynamic_pointer_cast<IntegerType>(rightTypes[0]) == nullptr)
            {
                typeErrors.push_back("Type error in AssignmentStm: An operator assignment is only allowed on integers. Either variable " + leftOperandNames[0] + " is not an Integer or its corresponding right-hand expression does not evaluate to an Integer.");
            }
            
            break;
        }

        case MINASSIGN_OP:
        {
            if(rightTypes.size() != 1 || leftOperandNames.size() != 1)
            {
                typeErrors.push_back("Type error in AssignmentStm: An operator assignment can only have 1 left-hand and 1 right-hand expression.");
            }
            
            // Operator assignments are only allowed on integers
            if(std::dynamic_pointer_cast<IntegerType>(env.getVarType(leftOperandNames[0])) == nullptr || std::dynamic_pointer_cast<IntegerType>(rightTypes[0]) == nullptr)
            {
                typeErrors.push_back("Type error in AssignmentStm: An operator assignment is only allowed on integers. Either variable " + leftOperandNames[0] + " is not an Integer or its corresponding right-hand expression does not evaluate to an Integer.");
            }            
            break;
        }
        case MULASSIGN_OP:
        {
            if(rightTypes.size() != 1 || leftOperandNames.size() != 1)
            {
                typeErrors.push_back("Type error in AssignmentStm: An operator assignment can only have 1 left-hand and 1 right-hand expression.");
            }
            
            // Operator assignments are only allowed on integers
            if(std::dynamic_pointer_cast<IntegerType>(env.getVarType(leftOperandNames[0])) == nullptr || std::dynamic_pointer_cast<IntegerType>(rightTypes[0]) == nullptr)
            {
                typeErrors.push_back("Type error in AssignmentStm: An operator assignment is only allowed on integers. Either variable " + leftOperandNames[0] + " is not an Integer or its corresponding right-hand expression does not evaluate to an Integer.");
            }
            break;
        }

        case DIVASSIGN_OP:
        {
            if(rightTypes.size() != 1 || leftOperandNames.size() != 1)
            {
                typeErrors.push_back("Type error in AssignmentStm: An operator assignment can only have 1 left-hand and 1 right-hand expression.");
            }
            
            // Operator assignments are only allowed on integers
            if(std::dynamic_pointer_cast<IntegerType>(env.getVarType(leftOperandNames[0])) == nullptr || std::dynamic_pointer_cast<IntegerType>(rightTypes[0]) == nullptr)
            {
                typeErrors.push_back("Type error in AssignmentStm: An operator assignment is only allowed on integers. Either variable " + leftOperandNames[0] + " is not an Integer or its corresponding right-hand expression does not evaluate to an Integer.");
            }            
            break;
        }
        default:
        {
            typeErrors.push_back("Type error in AssignmentStm: Unknown operator.");
            break;
        }
    }
}

// ============= IncDecStm =============
IncDecStm::IncDecStm(Exp* exp, IncDecOperator op): exp{exp}, op{op}{}

void IncDecStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    if(funcEnv.lookupVar(funcEnv.currentFunc()) != nullptr){
        if(funcEnv.lookupVar(funcEnv.currentFunc())->hasReturned)
            return;
    } 

    std::string varName = exp->getOperandName();

    switch (op)
    {
        case PLUSPLUS:
            std::dynamic_pointer_cast<IntLiteral>(env.lookupVar(varName))->value++;
            break;
            
        case MINMIN:
            std::dynamic_pointer_cast<IntLiteral>(env.lookupVar(varName))->value--;
            break;
        
        default:
            break;
    }
    // env.updateVar(varName, updatedVal);
}

void IncDecStm::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
        std::string varName = exp->getOperandName();

        // Check if left-hand expressions are addressable
        if(varName == "NO_OPERAND_EXPRESSION" || varName == "FUNCTION_CALL")
        {
            typeErrors.push_back("Type error in IncDecStm: Expression should be an addressable expression (e.g. Operand Expression).");
        }
        else{
            // Check if left-hand expressions are defined in this scope
            std::pair<int, bool> varExists = env.varExists(varName);
            if(varExists.first == 0)
            {
                typeErrors.push_back("Type error in IncDecStm: variable " + varName + " was not defined.");
            }
        }

        if(std::dynamic_pointer_cast<IntegerType>(env.getVarType(varName)) == nullptr)
        {
            typeErrors.push_back("Type error in IncDecStm: PLUSPLUS and MINMIN are only defined on Integer variables. Variable " + varName + " was found not to be of type Integer.");
        }
}

// ============= ExprStm =============
ExprStm::ExprStm(Exp* exp): exp{exp}{}

void ExprStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    if(funcEnv.lookupVar(funcEnv.currentFunc()) != nullptr){
        if(funcEnv.lookupVar(funcEnv.currentFunc())->hasReturned)
            return;
    } 
    exp->interp(env, funcEnv);
}

void ExprStm::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    exp->typecheck(env, funcEnv, typeErrors);
}

// ============= PrintStm =============
PrintStm::PrintStm(ExpList* expList): expressions{expList}{}

void PrintStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    if(funcEnv.lookupVar(funcEnv.currentFunc()) != nullptr){
        if(funcEnv.lookupVar(funcEnv.currentFunc())->hasReturned)
            return;
    } 

    if(expressions != nullptr)
    {
        std::vector<std::shared_ptr<Literal>> values;
        expressions->interp(env, funcEnv, values);

        for (std::shared_ptr<Literal> v : values)
        {
            // Booleans
            if(std::dynamic_pointer_cast<BoolLiteral>(v) != nullptr)
            {
                if(std::dynamic_pointer_cast<BoolLiteral>(v)->value)
                {
                    std::cout << "true ";
                }
                else
                {
                    std::cout << "false ";
                }
            }

            // Integers
            if(std::dynamic_pointer_cast<IntLiteral>(v) != nullptr)
            {
                std::cout << std::dynamic_pointer_cast<IntLiteral>(v)->value << " ";
            }
        }
    }
    
}

void PrintStm::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    if(expressions != nullptr)
    {
        std::vector<std::shared_ptr<Type>> types;
        expressions->typecheck(env, funcEnv, types, typeErrors);
    }
    // TODO: check if type is supported for printing (for now all types can be printed)
}

// ============= PrintLnStm =============
PrintLnStm::PrintLnStm(ExpList* expList): expressions{expList}{}

void PrintLnStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    if(funcEnv.lookupVar(funcEnv.currentFunc()) != nullptr){
        if(funcEnv.lookupVar(funcEnv.currentFunc())->hasReturned)
            return;
    } 

    if(expressions != nullptr)
    {
        std::vector<std::shared_ptr<Literal>> values;
        expressions->interp(env, funcEnv, values);

        for (std::shared_ptr<Literal> v : values)
        {
            // Booleans
            if(std::dynamic_pointer_cast<BoolLiteral>(v) != nullptr)
            {
                if(std::dynamic_pointer_cast<BoolLiteral>(v)->value)
                {
                    std::cout << "true ";
                }
                else
                {
                    std::cout << "false ";
                }
            }

            // Integers
            if(std::dynamic_pointer_cast<IntLiteral>(v) != nullptr)
            {
                std::cout << std::dynamic_pointer_cast<IntLiteral>(v)->value << " ";
            }
        }
    }
    
    std::cout << std::endl;
}

void PrintLnStm::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    if(expressions != nullptr)
    {
        std::vector<std::shared_ptr<Type>> types;
        expressions->typecheck(env, funcEnv, types, typeErrors);
    }
    // TODO: check if type is supported for printing (for now all types can be printed)
}

