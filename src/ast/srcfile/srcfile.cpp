#include "srcfile.h"
#include "../../environment/interp/env.h"

// ============= SrcFile =============
SrcFile::SrcFile(PackageClause* packageClause, ImportDeclList* imports, DeclList* topLvlDecls): topLvlDeclarations{topLvlDecls}, imports{imports}, packageClause{packageClause}{}

void SrcFile::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    packageClause->interp(env, funcEnv);
    if(imports != NULL)
    {
        imports->interp(env, funcEnv);
    }
    if(topLvlDeclarations != NULL)
    {
        topLvlDeclarations->interp(env, funcEnv);
    }

    // ================== MAIN FUNCTION CALL ==================
    // In Go, the main function is always called after the file has been evaluated
    // TODO: typechecking: Check if function main exists, CONTAINS NO ARGUMENTS AND NO RETURN VALUES!!
    env.pushScope();
    funcEnv.pushFunc(std::string("main"));
    funcEnv.lookupVar(std::string("main"))->funcDecl->funcBody->interp(env, funcEnv);
    funcEnv.popFunc();
    env.popScope();
    return;
}

void SrcFile::typecheck(ScopedEnv& varTypeEnv, FunctionEnv& funcTypeEnv, std::vector<std::string>& typeErrors)
{
    // We only need to typecheck topLevelDeclarations (imports and packageclause cannot have type errors)
    if(topLvlDeclarations != NULL)
    {
        std::vector<std::pair<std::string, std::string>> refGraph;
        topLvlDeclarations->refAnalysis(refGraph);

        for(auto p: refGraph)
        {
            std::cout << p.first << "-->" << p.second << std::endl;
        }

        topLvlDeclarations->typecheck(varTypeEnv, funcTypeEnv, typeErrors);
    }
}
