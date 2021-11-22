#include "srcfile.h"

// ============= SrcFile =============
SrcFile::SrcFile(PackageClause* packageClause, ImportDeclList* imports, DeclList* topLvlDecls): topLvlDeclarations{topLvlDecls}, imports{imports}, packageClause{packageClause}{}

SymbolTable* SrcFile::interp(SymbolTable& table)
{
    std::cout << "Hello from AST!" << std::endl;
    return nullptr;
}