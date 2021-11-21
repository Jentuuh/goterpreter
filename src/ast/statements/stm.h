#include "../declarations/decl.h"
#include "../block/block.h"
#include "../expressions/exp.h"
#include "../expressions/explist.h"
#include "./forclause.h"
#include <memory>

/**
 * Abstract Statement struct.
 * Jente Vandersanden - Compilers 2021-2022 - Hasselt University
 */
struct SymbolTable;

enum AssignOperator{ ASSIGN, PLUSASSIGN, MINASSIGN, MULASSIGN, DIVASSIGN };
enum IncDecOperator{ PLUSPLUS, MINMIN };
struct Stm
{
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct SimpleStm:Stm{
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct DeclStm:Stm{
    std::shared_ptr<Decl> declaration;
    DeclStm(Decl* decl): declaration{decl}{};

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};

struct BlockStm:Stm{
    std::shared_ptr<Block> block;
    BlockStm(Block* block): block{block}{};

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};

struct IfStm:Stm{
    std::shared_ptr<SimpleStm> simpleStm;
    std::shared_ptr<Exp> condition;

    std::shared_ptr<Block> ifBlock;
    std::shared_ptr<Block> elseBlock;

    std::shared_ptr<Stm> nestedIfStm;

    IfStm(Stm* simpleStm, Exp* cond, Block* ifBlock, Block* elseBlock, Stm* nestedIf): simpleStm{simpleStm}, condition{cond}, ifBlock{ifBlock}, 
                                                                                       elseBlock{elseBlock}, nestedIfStm{nestedIf}{};

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};

struct ForCondStm:Stm{
    std::shared_ptr<Exp> condition;
    std::shared_ptr<Block> body;

    ForCondStm(Exp* cond, Block* body): condition{cond}, body{body}{};

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};

struct ForClauseStm:Stm{
    std::shared_ptr<ForClause> forclause;
    std::shared_ptr<Block> body;

    ForClauseStm(ForClause* forclause, Block* body): forclause{forclause}, body{body}{};

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};

struct ForStm:Stm{
    std::shared_ptr<Block> body;

    ForStm(Block* body): body{body}{};

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};

struct ReturnStm:Stm{
    std::shared_ptr<ExpList> expressionList;

    ReturnStm(ExpList* expList): expressionList{expList}{};


    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};

struct EmtpyStm:SimpleStm{
    EmptyStm();

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};

struct AssignmentStm:SimpleStm{
    std::shared_ptr<ExpList> leftExpList;
    std::shared_ptr<ExpList> rightExpList;
    AssignOperator assignOp;

    AssignmentStm(ExpList* left, ExpList* right, AssignOperator assign_op): leftExpList{left}, rightExpList{right}, assignOp{assign_op}{};
      
    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};


struct IncDecStm:SimpleStm{
    std::shared_ptr<Exp> exp;
    IncDecOperator op;

    IncDecStm(Exp* exp, IncDecOperator op): exp{exp}, op{op}{};

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};

struct ExprStm:SimpleStm{
    std::shared_ptr<Exp> exp; 

    ExprStm(Exp* exp): exp{exp}{};

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};

