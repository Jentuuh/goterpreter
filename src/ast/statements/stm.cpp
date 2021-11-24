#include "stm.h"

// ============= DeclStm =============
DeclStm::DeclStm(TopLevelDecl* decl): declaration{decl}{}

Environments DeclStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= BlockStm =============
BlockStm::BlockStm(Block* block): block{block}{}

Environments BlockStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= IfStm =============
IfStm::IfStm(Stm* simpleStm, Exp* cond, Block* ifBlock, Block* elseBlock, Stm* nestedIf): simpleStm{simpleStm}, condition{cond}, ifBlock{ifBlock}, elseBlock{elseBlock}, nestedIfStm{nestedIf}{}

Environments IfStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= ForCondStm =============
ForCondStm::ForCondStm(Exp* cond, Block* body): condition{cond}, body{body}{}

Environments ForCondStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= ForClauseStm =============
ForClauseStm::ForClauseStm(ForClause* forclause, Block* body): forclause{forclause}, body{body}{}

Environments ForClauseStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= ForStm =============
ForStm::ForStm(Block* body): body{body}{}

Environments ForStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= ReturnStm =============
ReturnStm::ReturnStm(ExpList* expList): expressionList{expList}{}

Environments ReturnStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= EmptyStm =============
EmptyStm::EmptyStm(){}

Environments EmptyStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= AssignmentStm =============
AssignmentStm::AssignmentStm(ExpList* left, ExpList* right, AssignOperator assign_op): leftExpList{left}, rightExpList{right}, assignOp{assign_op}{}

Environments AssignmentStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= IncDecStm =============
IncDecStm::IncDecStm(Exp* exp, IncDecOperator op): exp{exp}, op{op}{}

Environments IncDecStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

// ============= ExprStm =============
ExprStm::ExprStm(Exp* exp): exp{exp}{}

Environments ExprStm::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}



