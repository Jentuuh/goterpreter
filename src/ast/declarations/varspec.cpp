#include "varspec.h"

// ============= VarSpec =============
VarSpec::VarSpec(IdentifierList* idList, Type* type, ExpList* expList): idList{idList}, type{type}, expList{expList}{}

SymbolTable* VarSpec::interp(SymbolTable& table)
{
    // TODO: implement
}


