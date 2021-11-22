#pragma once
#include <iostream>
#include <memory>
#include "../declarations/decllist.h"
#include "../import/importdecllist.h"
#include "../packages/packageclause.h"

struct SymbolTable;
struct SrcFile{
    std::shared_ptr<DeclList> topLvlDeclarations;
    std::shared_ptr<ImportDeclList> imports;
    std::shared_ptr<PackageClause> packageClause;

    SrcFile(PackageClause* packageClause, ImportDeclList* imports, DeclList* topLvlDecls);
    SymbolTable* interp(SymbolTable& table);
};