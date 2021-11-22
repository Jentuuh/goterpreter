#include "parameterdecl.h"

// ============= ParameterDecl =============
ParameterDecl::ParameterDecl(Type* type, IdentifierList* identifiers): type{type}, identifiers{identifiers}{}

SymbolTable* ParameterDecl::interp(SymbolTable& table)
{
    // TODO: implement
}
