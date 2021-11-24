#include "signature.h"

// ============= Signature =============
Signature::Signature(ParameterList* params, Result* res):parameters{params}, result{res}{}

Environments Signature::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}