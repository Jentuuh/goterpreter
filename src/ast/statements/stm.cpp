#include "stm.h"
#include "../../environment/interp/env.h"
#include <algorithm>
#include <iostream>

// ============= DeclStm =============
DeclStm::DeclStm(TopLevelDecl* decl): declaration{decl}{}

void DeclStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    declaration->interp(env, funcEnv);
}

// ============= BlockStm =============
BlockStm::BlockStm(Block* block): block{block}{}

void BlockStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    env.pushScope();
    block->interp(env, funcEnv);
}

// ============= IfStm =============
IfStm::IfStm(Stm* simpleStm, Exp* cond, Block* ifBlock, Block* elseBlock, Stm* nestedIf): simpleStm{simpleStm}, condition{cond}, ifBlock{ifBlock}, elseBlock{elseBlock}, nestedIfStm{nestedIf}{}

void IfStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // First, execute simple statement if there is any
    if(simpleStm.get() != nullptr)
    {
        simpleStm->interp(env, funcEnv);
    }

    // Check if condition is true
    if(std::dynamic_pointer_cast<BoolLiteral>(condition->interp(env, funcEnv))->value)
    {
        ifBlock->interp(env, funcEnv);
    }
    else
    {
        // Execute else block (if there is one)
        if(elseBlock.get() != nullptr)
        {
            elseBlock->interp(env, funcEnv);
        }
        // Execute nested if statement (if there is one)
        if(nestedIfStm.get() != nullptr)
        {
            nestedIfStm->interp(env, funcEnv);
        }
    }
}

// ============= ForCondStm =============
ForCondStm::ForCondStm(Exp* cond, Block* body): condition{cond}, body{body}{}

void ForCondStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // The for-loop can be executed as long as the condition evaluates to true
    while(std::dynamic_pointer_cast<BoolLiteral>(condition->interp(env, funcEnv))->value)
    {
        body->interp(env, funcEnv);
    }
}

// ============= ForClauseStm =============
ForClauseStm::ForClauseStm(ForClause* forclause, Block* body): forclause{forclause}, body{body}{}

void ForClauseStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // We execute the init statement once before evaluating the condition (if there is one)
    if(forclause->initStm.get() != nullptr)
        forclause->initStm->interp(env, funcEnv);

    while(std::dynamic_pointer_cast<BoolLiteral>(forclause->condition->interp(env, funcEnv))->value)
    {
        // Execute the body of the for-loop
        body->interp(env, funcEnv);

        // Update condition variable with poststatement (if there is one)
        if(forclause->postStm.get() != nullptr)
            forclause->postStm->interp(env, funcEnv);
    }
}

// ============= ForStm =============
ForStm::ForStm(Block* body): body{body}{}

void ForStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    while(true)
    {
        body->interp(env, funcEnv);
    }
}

// ============= ReturnStm =============
ReturnStm::ReturnStm(ExpList* expList): expressionList{expList}{}

void ReturnStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    std::vector<std::shared_ptr<Literal>> returnValues;

    // TODO: Typecheck! Check if type matches return type of function!
    std::string funcName = funcEnv.currentFunc();
    FuncTableEntry* funcDetails = funcEnv.lookupVar(funcName);
    
    // 1. Check if func signature has any return values specified (This means there should be a ParametersResult)
    if(std::dynamic_pointer_cast<ParametersResult>(funcDetails->funcDecl->funcSign->result) != nullptr)
    {
        // 2. If so, retrieve these values from the environment, and return them
        std::vector<std::string> returnValueIdentifiers;
        std::dynamic_pointer_cast<ParametersResult>(funcDetails->funcDecl->funcSign->result)->parameters->getIdentifiers(returnValueIdentifiers);

        for(std::string r : returnValueIdentifiers)
        {
            returnValues.push_back(env.lookupVar(r));
        }

        funcEnv.declaredFunctions.addReturnValues(funcName, returnValues);
    }
    else
    {
        // 3. If not, return whatever expressionlist is behind the return statement
        // 4. If there isn't anything, return an empty list
        if(expressionList.get() != nullptr)
        {
            expressionList->interp(env, funcEnv, returnValues);
            funcEnv.declaredFunctions.addReturnValues(funcName, returnValues);
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

// ============= AssignmentStm =============
AssignmentStm::AssignmentStm(ExpList* left, ExpList* right, AssignOperator assign_op): leftExpList{left}, rightExpList{right}, assignOp{assign_op}{}

void AssignmentStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: different assignment operators!!!

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
            // TODO: typecheck that the operatorAssign operators are only used on integers!!!
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
            // TODO: type checking: Check if every variable exists and has the correct type assigned to them!
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
        else
        {
            // TODO: ERROR: LENGTH EXPRESSION LIST ON LEFT SIZE DOES NOT MATCH LENGTH ON RIGHT SIDE (or does this need to happen in type checker?)
        }
    }
}

// ============= IncDecStm =============
IncDecStm::IncDecStm(Exp* exp, IncDecOperator op): exp{exp}, op{op}{}

void IncDecStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: Typechecker: check if expression has type int (and if it is a addressable variable)!
    std::string varName = exp->getOperandName();
    // std::shared_ptr<IntLiteral> updatedVal;

    switch (op)
    {
        case PLUSPLUS:
            // TODO: check: does this work? 
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

// ============= ExprStm =============
ExprStm::ExprStm(Exp* exp): exp{exp}{}

void ExprStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    exp->interp(env, funcEnv);
}

// ============= PrintStm =============
PrintStm::PrintStm(ExpList* expList): expressions{expList}{}

void PrintStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    std::vector<std::shared_ptr<Literal>> values;
    expressions->interp(env, funcEnv, values);
    std::reverse(values.begin(), values.end());

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


