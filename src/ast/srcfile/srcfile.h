#pragma once
#include <iostream>
#include <utility>
#include <memory>
#include "../declarations/decllist.h"
#include "../import/importdecllist.h"
#include "../packages/packageclause.h"

struct ScopedEnv;
struct FunctionEnv;
typedef std::pair<ScopedEnv*, FunctionEnv*> Environments;

struct SrcFile{
    std::shared_ptr<DeclList> topLvlDeclarations;
    std::shared_ptr<ImportDeclList> imports;
    std::shared_ptr<PackageClause> packageClause;

    SrcFile(PackageClause* packageClause, ImportDeclList* imports, DeclList* topLvlDecls);
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv);
};