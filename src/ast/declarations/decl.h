#include "../functions/signature.h"
#include "../block/block.h"
#include "varspec.h"

struct SymbolTable;

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
        // TODO: implement
    };
};

struct FunctionDecl:TopLevelDecl{
    std::shared_ptr<Identifier> funcName;
    std::shared_ptr<Signature> funcSign;
    std::shared_ptr<Block> funcBody;

    FunctionDecl(Identifier* funcName, Signature* sign, Block* body): funcName{funcName}, funcSign{sign}, funcBody{body}{};

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};