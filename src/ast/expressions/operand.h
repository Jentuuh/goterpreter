#include "../literals/literal.h"
#include <memory>

struct Exp;
struct Identifier;

struct Operand{
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct LiteralOperand: Operand{
    std::shared_ptr<Literal> literal;

    LiteralOperand(Literal* lit): literal{lit}{};
 
    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: Implement
    };
};

struct VariableOperand: Operand{
    std::shared_ptr<Identifier> operandName;

    VariableOperand(Identifier* operandName): operandName{operandName}{};

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: Implement
    };

};

struct ExprOperand: Operand{
    std::shared_ptr<Exp> exp;

    ExprOperand(Exp* exp): exp{exp}{};

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: Implement
    };
};

