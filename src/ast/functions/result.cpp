#include "result.h"

// ============= ParametersResult =============
ParametersResult::ParametersResult(ParameterList* params): parameters{params}{}

SymbolTable* ParametersResult::interp(SymbolTable& table)
{
    // TODO: Implement
}

// ============= TypeResult =============
TypeResult::TypeResult(Type* type): type{type}{}

SymbolTable* TypeResult::interp(SymbolTable& table)
{
    // TODO: Implement
}
