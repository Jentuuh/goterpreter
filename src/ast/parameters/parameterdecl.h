#pragma once
#include <memory>
#include "../identifiers/identifierlist.h"
#include "../types/type.h"

struct SymbolTable;

// TODO: Make local function scope (symbol table) of these parameters!

struct ParameterDecl{

    std::shared_ptr<Type> type;
    std::shared_ptr<IdentifierList> identifiers;

    ParameterDecl(Type* type, IdentifierList* identifiers);
    SymbolTable* interp(SymbolTable& table);
};