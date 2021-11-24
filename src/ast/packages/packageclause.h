#pragma once
#include <memory>
#include <utility>
#include "../identifiers/identifier.h"

struct ScopedEnv;
struct FunctionEnv;
typedef std::pair<ScopedEnv*, FunctionEnv*> Environments;

struct PackageClause{
    std::shared_ptr<Identifier> packageName;

    PackageClause(Identifier* pack_name);
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv);
};