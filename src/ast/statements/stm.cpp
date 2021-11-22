#include "stm.h"

// ============= DeclStm =============
DeclStm::DeclStm(TopLevelDecl* decl): declaration{decl}{}

SymbolTable* DeclStm::interp(SymbolTable& table)
{
    // TODO: implement
}

// ============= BlockStm =============
BlockStm::BlockStm(Block* block): block{block}{}

SymbolTable* BlockStm::interp(SymbolTable& table)
{
    // TODO: implement
}

// ============= IfStm =============
IfStm::IfStm(Stm* simpleStm, Exp* cond, Block* ifBlock, Block* elseBlock, Stm* nestedIf): simpleStm{simpleStm}, condition{cond}, ifBlock{ifBlock}, elseBlock{elseBlock}, nestedIfStm{nestedIf}{}

SymbolTable* IfStm::interp(SymbolTable& table)
{
    // TODO: implement
}

// ============= ForCondStm =============
ForCondStm::ForCondStm(Exp* cond, Block* body): condition{cond}, body{body}{}

SymbolTable* ForCondStm::interp(SymbolTable& table)
{
    // TODO: implement
}

// ============= ForClauseStm =============
ForClauseStm::ForClauseStm(ForClause* forclause, Block* body): forclause{forclause}, body{body}{}

SymbolTable* ForClauseStm::interp(SymbolTable& table)
{
    // TODO: implement
}

// ============= ForStm =============
ForStm::ForStm(Block* body): body{body}{}

SymbolTable* ForStm::interp(SymbolTable& table)
{
    // TODO: implement
}

// ============= ReturnStm =============
ReturnStm::ReturnStm(ExpList* expList): expressionList{expList}{}

SymbolTable* ReturnStm::interp(SymbolTable& table)
{
    // TODO: implement
}

// ============= EmptyStm =============
EmptyStm::EmptyStm(){}

SymbolTable* EmptyStm::interp(SymbolTable& table)
{
    // TODO: implement
}

// ============= AssignmentStm =============
AssignmentStm::AssignmentStm(ExpList* left, ExpList* right, AssignOperator assign_op): leftExpList{left}, rightExpList{right}, assignOp{assign_op}{}

SymbolTable* AssignmentStm::interp(SymbolTable& table)
{
    // TODO: implement
}

// ============= IncDecStm =============
IncDecStm::IncDecStm(Exp* exp, IncDecOperator op): exp{exp}, op{op}{}

SymbolTable* IncDecStm::interp(SymbolTable& table)
{
    // TODO: implement
}

// ============= ExprStm =============
ExprStm::ExprStm(Exp* exp): exp{exp}{}

SymbolTable* ExprStm::interp(SymbolTable& table)
{
    // TODO: implement
}



