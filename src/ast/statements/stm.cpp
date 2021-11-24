#include "stm.h"

// ============= DeclStm =============
DeclStm::DeclStm(TopLevelDecl* decl): declaration{decl}{}

void DeclStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= BlockStm =============
BlockStm::BlockStm(Block* block): block{block}{}

void BlockStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= IfStm =============
IfStm::IfStm(Stm* simpleStm, Exp* cond, Block* ifBlock, Block* elseBlock, Stm* nestedIf): simpleStm{simpleStm}, condition{cond}, ifBlock{ifBlock}, elseBlock{elseBlock}, nestedIfStm{nestedIf}{}

void IfStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= ForCondStm =============
ForCondStm::ForCondStm(Exp* cond, Block* body): condition{cond}, body{body}{}

void ForCondStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= ForClauseStm =============
ForClauseStm::ForClauseStm(ForClause* forclause, Block* body): forclause{forclause}, body{body}{}

void ForClauseStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= ForStm =============
ForStm::ForStm(Block* body): body{body}{}

void ForStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
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



