#include "srcfile.h"

// ============= SrcFile =============
SrcFile::SrcFile(PackageClause* packageClause, ImportDeclList* imports, DeclList* topLvlDecls): topLvlDeclarations{topLvlDecls}, imports{imports}, packageClause{packageClause}{}

void SrcFile::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // void updatedTable = topLvlDeclarations->interp(table);

    // // if(imports != NULL)
    // // {
    // //     updatedTable = imports->interp(*updatedTable);
    // // }
    std::cout << "Start..." << std::endl;
    packageClause->interp(env, funcEnv);
    std::cout << "After..." << std::endl;
    if(imports != NULL)
    {
        std::cout << "Interpreting imports..." << std::endl;
        imports->interp(env, funcEnv);
    }
    if(topLvlDeclarations != NULL)
    {
        std::cout << "Interpreting topleveldeclarations..." << std::endl;
        topLvlDeclarations->interp(env, funcEnv);
    }

    return;
}