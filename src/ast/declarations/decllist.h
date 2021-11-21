#include "decl.h"
#include <memory>

struct DeclList{
    virtual int length() = 0;
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct PairDeclList:DeclList{

    std::shared_ptr<TopLevelDecl> head;
    std::shared_ptr<DeclList> tail;

    PairDeclList(TopLevelDecl* h, DeclList* t): head{h}, tail{t}{};
    
    int length()
    {

    };

    SymbolTable* interp(SymbolTable& table)
    {

    };

};

struct LastDeclList:DeclList{
    std::shared_ptr<TopLevelDecl> last;

    LastDeclList(TopLevelDecl* l): last{l}{};

    SymbolTable* interp(SymbolTable& table)
    {

    };
};