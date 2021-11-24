#include "packageclause.h"

// ============= PackageClause =============
PackageClause::PackageClause(Identifier* pack_name): packageName{pack_name}{}

Environments PackageClause::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
    return Environments(&env, &funcEnv);
}
