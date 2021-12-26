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
        topLvlDeclarations->preBuildFunctionEnvironment(funcEnv);
        topLvlDeclarations->interp(env, funcEnv);
    }

    // ================== MAIN FUNCTION CALL ==================
    // In Go, the main function is always called after the file has been evaluated
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
        // std::vector<std::pair<std::string, std::string>> refGraph;
        // topLvlDeclarations->refAnalysis(refGraph);

        // for(auto p: refGraph)
        // {
        //     std::cout << p.first << "-->" << p.second << std::endl;
        // }

        // Read in all function declarations first, these might be required for other top-level var declarations
        topLvlDeclarations->preBuildFunctionEnvironment(funcTypeEnv);
        topLvlDeclarations->preBuildGlobalsEnvironment(varTypeEnv, funcTypeEnv);

        topLvlDeclarations->typecheck(varTypeEnv, funcTypeEnv, typeErrors);
    }

    // Check if main function is declared
    if(funcTypeEnv.lookupVar(std::string("main")) != nullptr)
    {
        if(funcTypeEnv.lookupVar(std::string("main"))->funcDecl->funcSign->parameters != nullptr)
        {
            typeErrors.push_back("Type error: Main function must not accept any arguments.");
        }
        if(funcTypeEnv.lookupVar(std::string("main"))->funcDecl->funcSign->result != nullptr)
        {
            typeErrors.push_back("Type error: Main function must not have any return values.");
        }
    } else {
        typeErrors.push_back("Type error: No main function was found in the package.");
    }

}
