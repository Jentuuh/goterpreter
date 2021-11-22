#pragma once
#include <memory>
#include "./varspec.h"
#include "../identifiers/identifier.h"
#include "../functions/signature.h"
#include "../block/block.h"

struct SymbolTable;
struct Block;

struct TopLevelDecl{
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct Decl:TopLevelDecl{
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct VarDecl:Decl{

    std::shared_ptr<VarSpec> varspec;

    VarDecl(VarSpec* varspec);
    SymbolTable* interp(SymbolTable& table) override;
};

struct FunctionDecl:TopLevelDecl{
    std::shared_ptr<Identifier> funcName;
    std::shared_ptr<Signature> funcSign;
    std::shared_ptr<Block> funcBody;

    FunctionDecl(Identifier* funcName, Signature* sign, Block* body);
    SymbolTable* interp(SymbolTable& table) override;
};