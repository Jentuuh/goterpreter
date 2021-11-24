#include "result.h"

// ============= ParametersResult =============
ParametersResult::ParametersResult(ParameterList* params): parameters{params}{}

void ParametersResult::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: Implement
}

// ============= TypeResult =============
TypeResult::TypeResult(Type* type): type{type}{}

void TypeResult::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: Implement
}
