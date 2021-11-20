#include "../symboltable.h"
#include "varspec.h"

struct TopLevelDecl{
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct Decl:TopLevelDecl{
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct VarDecl:Decl{

    std::shared_ptr<VarSpec> varspec;

    VarDecl(VarSpec* varspec): varspec{varspec}{};

    SymbolTable* interp(SymbolTable& table)
    {

    };
};

struct FunctionDecl:TopLevelDecl{
    std::shared_ptr<Identifier> funcName;
    std::shared_ptr<Signature> funcSign;
    std::shared_ptr<FuncBody> funcBody;

    FunctionDecl(Identifier* funcName, Signature* sign, FuncBody* body): funcName{funcName}, funcSign{sign}, funcBody{body}{};
};