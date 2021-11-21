#include "./importdecl.h"
#include <memory>

struct SymbolTable;

struct ImportDeclList{
    virtual int length() = 0;
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};


struct PairImportDeclList:ImportDeclList{

    std::shared_ptr<ImportDecl> head;
    std::shared_ptr<ImportDeclList> tail;

    PairImportDeclList(ImportDecl* h, ImportDeclList* t): head{h}, tail{t}{};
    
    int length()
    {

    };

    SymbolTable* interp(SymbolTable& table)
    {

    };

};

struct LastImportDeclList:ImportDeclList{
    std::shared_ptr<ImportDecl> last;

    LastImportDeclList(ImportDecl* l): last{l}{};

    SymbolTable* interp(SymbolTable& table)
    {

    };
};