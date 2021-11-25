#include "stm.h"
#include "../../environment/interp/env.h"
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
    block->interp(env, funcEnv);
}

// ============= IfStm =============
IfStm::IfStm(Stm* simpleStm, Exp* cond, Block* ifBlock, Block* elseBlock, Stm* nestedIf): simpleStm{simpleStm}, condition{cond}, ifBlock{ifBlock}, elseBlock{elseBlock}, nestedIfStm{nestedIf}{}

void IfStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    std::cout << "In if statement..." << std::endl;
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
    // TODO: implement
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
            env.updateVar(n, newValues[0]);
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
                env.updateVar(operandNames[i], newValues[i]);
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



