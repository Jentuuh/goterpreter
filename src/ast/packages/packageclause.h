#pragma once
#include <memory>
#include <utility>
#include "../identifiers/identifier.h"

struct ScopedEnv;
struct FunctionEnv;

struct PackageClause{
    std::shared_ptr<Identifier> packageName;

    PackageClause(Identifier* pack_name);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv);
};