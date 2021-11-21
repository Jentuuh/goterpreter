#include "../declarations/decllist.h"
#include "../packages/packageclause.h"
#include "../import/importdecllist.h"
#include <iostream>
#include <memory>


struct SrcFile{
    std::shared_ptr<DeclList> topLvlDeclarations;
    std::shared_ptr<ImportDeclList> imports;
    std::shared_ptr<PackageClause> packageClause;

    SrcFile(PackageClause* packageClause, ImportDeclList* imports, DeclList* topLvlDecls): topLvlDeclarations{topLvlDecls}, imports{imports}, packageClause{packageClause}{};

    SymbolTable* interp(SymbolTable& table)
    {
        std::cout << "Hello from AST!" << std::endl;
    };

};