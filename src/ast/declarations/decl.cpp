#include "decl.h"

// ============= VarDecl =============
VarDecl::VarDecl(VarSpec* varspec): varspec{varspec}{};

SymbolTable* VarDecl::interp(SymbolTable& table)
{
        // TODO: implement
}

// ============= FunctionDecl =============
FunctionDecl::FunctionDecl(Identifier* funcName, Signature* sign, Block* body): funcName{funcName}, funcSign{sign}, funcBody{body}{}

SymbolTable* FunctionDecl::interp(SymbolTable& table)
{
        // TODO: implement
}