#include "stm.h"
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
    // TODO: implement
}

// ============= AssignmentStm =============
AssignmentStm::AssignmentStm(ExpList* left, ExpList* right, AssignOperator assign_op): leftExpList{left}, rightExpList{right}, assignOp{assign_op}{}

void AssignmentStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= IncDecStm =============
IncDecStm::IncDecStm(Exp* exp, IncDecOperator op): exp{exp}, op{op}{}

void IncDecStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= ExprStm =============
ExprStm::ExprStm(Exp* exp): exp{exp}{}

void ExprStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}



