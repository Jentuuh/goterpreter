#include "result.h"

// ============= ParametersResult =============
ParametersResult::ParametersResult(ParameterList* params): parameters{params}{}

Environments ParametersResult::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: Implement
}

// ============= TypeResult =============
TypeResult::TypeResult(Type* type): type{type}{}

Environments TypeResult::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: Implement
}
