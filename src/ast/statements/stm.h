#pragma once
#include <memory>
#include <utility>
#include "../declarations/decl.h"
#include "../block/block.h"
#include "../expressions/exp.h"
#include "../expressions/explist.h"
#include "./forclause.h"

/**
 * Abstract Statement struct.
 * Jente Vandersanden - Compilers 2021-2022 - Hasselt University
 */

struct ScopedEnv;
struct FunctionEnv;
struct ForClause;
struct Block;
struct Exp;
struct TopLevelDecl;
struct ExpList;

enum AssignOperator{ ASSIGN_OP, PLUSASSIGN_OP, MINASSIGN_OP, MULASSIGN_OP, DIVASSIGN_OP };
enum IncDecOperator{ PLUSPLUS, MINMIN };

struct Stm
{
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
};

struct SimpleStm:Stm{
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
};

struct DeclStm:Stm{
    std::shared_ptr<TopLevelDecl> declaration;

    DeclStm(TopLevelDecl* decl);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct BlockStm:Stm{
    std::shared_ptr<Block> block;

    BlockStm(Block* block);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct IfStm:Stm{
    std::shared_ptr<Stm> simpleStm;
    std::shared_ptr<Exp> condition;

    std::shared_ptr<Block> ifBlock;
    std::shared_ptr<Block> elseBlock;

    std::shared_ptr<Stm> nestedIfStm;

    IfStm(Stm* simpleStm, Exp* cond, Block* ifBlock, Block* elseBlock, Stm* nestedIf);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct ForCondStm:Stm{
    std::shared_ptr<Exp> condition;
    std::shared_ptr<Block> body;

    ForCondStm(Exp* cond, Block* body);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct ForClauseStm:Stm{
    std::shared_ptr<ForClause> forclause;
    std::shared_ptr<Block> body;

    ForClauseStm(ForClause* forclause, Block* body);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct ForStm:Stm{
    std::shared_ptr<Block> body;

    ForStm(Block* body);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct ReturnStm:Stm{
    std::shared_ptr<ExpList> expressionList;

    ReturnStm(ExpList* expList);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct EmptyStm:SimpleStm{
    EmptyStm();
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct AssignmentStm:SimpleStm{
    std::shared_ptr<ExpList> leftExpList;
    std::shared_ptr<ExpList> rightExpList;
    AssignOperator assignOp;

    AssignmentStm(ExpList* left, ExpList* right, AssignOperator assign_op);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct IncDecStm:SimpleStm{
    std::shared_ptr<Exp> exp;
    IncDecOperator op;

    IncDecStm(Exp* exp, IncDecOperator op);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct ExprStm:SimpleStm{
    std::shared_ptr<Exp> exp; 

    ExprStm(Exp* exp);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

