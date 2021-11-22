#pragma once
#include <memory>
#include "../identifiers/identifier.h"

struct SymbolTable;

struct PackageClause{
    std::shared_ptr<Identifier> packageName;

    PackageClause(Identifier* pack_name);
    SymbolTable* interp(SymbolTable& table);
};