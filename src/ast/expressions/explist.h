#include "exp.h"
#include <memory>

/**
 * Abstract ExpressionList class.
 * Jente Vandersanden - Compilers 2021-2022 - Hasselt University
 */

struct SymbolTable;

struct ExpList{
    virtual int length() = 0;
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct LastExpList:ExpList{
    std::shared_ptr<Exp> last;


    LastExpList(Exp* l): last{l}{};

    int length()
    {
        // TODO: implement
    };

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};

struct PairExpList:ExpList{
    std::shared_ptr<Exp> head;
    std::shared_ptr<ExpList> tail;

    PairExpList(Exp* h, ExpList* t): head{h}, tail{t}{};

    int length()
    {
        // TODO: implement
    };

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};