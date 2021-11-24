#include "varspec.h"

// ============= VarSpec =============
VarSpec::VarSpec(IdentifierList* idList, Type* type, ExpList* expList): idList{idList}, type{type}, expList{expList}{}

void VarSpec::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}


