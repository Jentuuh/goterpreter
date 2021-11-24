#include "srcfile.h"

// ============= SrcFile =============
SrcFile::SrcFile(PackageClause* packageClause, ImportDeclList* imports, DeclList* topLvlDecls): topLvlDeclarations{topLvlDecls}, imports{imports}, packageClause{packageClause}{}

Environments SrcFile::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // Environments updatedTable = topLvlDeclarations->interp(table);

    // // if(imports != NULL)
    // // {
    // //     updatedTable = imports->interp(*updatedTable);
    // // }
    std::cout << "Start..." << std::endl;
    Environments updatedTables = packageClause->interp(env, funcEnv);
    std::cout << "After..." << std::endl;
    if(imports != NULL)
    {
        std::cout << "Interpreting imports..." << std::endl;
        updatedTables = imports->interp(env, funcEnv);
    }
    if(topLvlDeclarations != NULL)
    {
        std::cout << "Interpreting topleveldeclarations..." << std::endl;
        Environments updatedTables2 = topLvlDeclarations->interp(env, funcEnv);
    }

    std::cout << "Hello from AST!" << std::endl;
    return updatedTables;
}