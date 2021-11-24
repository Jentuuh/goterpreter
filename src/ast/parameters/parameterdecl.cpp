#include "parameterdecl.h"

// ============= ParameterDecl =============
ParameterDecl::ParameterDecl(Type* type, IdentifierList* identifiers): type{type}, identifiers{identifiers}{}

Environments ParameterDecl::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}
