#include "stm.h"
#include "../symboltable.h"
#include <memory>

/**
 * Abstract StatementList class.
 * Jente Vandersanden - Compilers 2021-2022 - Hasselt University
 */ 

struct StmList{
    virtual int length() = 0;
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct LastStmList:StmList{
    std::shared_ptr<Stm> last;

    LastStmList(Stm* last):last{last}{};

    int length() 
    {
        // TODO: implement
    };

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};

struct PairStmList:StmList{
    std::shared_ptr<Stm> head;
    std::shared_ptr<StmList> tail; 

    PairStmList(Stm* head, StmList* tail): head{head}, tail{tail}{};

    int length() 
    {
        // TODO: implement  
    };

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};