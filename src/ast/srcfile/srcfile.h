#include "../symboltable.h"
#include "../declarations/decllist.h"
#include "../packages/packageclause.h"
#include <memory>


struct SrcFile{
    std::shared_ptr<DeclList> topLvlDeclarations;
    std::shared_ptr<PackageClause> packageClause;

    SrcFile(PackageClause* packageClause, DeclList* topLvlDecls): topLvlDeclarations{topLvlDecls}, packageClause{packageClause}{};

    SymbolTable* interp(SymbolTable& table);

};