#include "../expressions/exp.h"
#include <memory>

struct SimpleStm;

struct ForClause{
    std::shared_ptr<SimpleStm> initStm;
    std::shared_ptr<Exp> condition;
    std::shared_ptr<SimpleStm> postStm;

    ForClause(SimpleStm* init, Exp* cond, SimpleStm* post): initStm{init}, condition{cond}, postStm{post}{};

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};