#pragma once
#include <memory>
#include "../identifiers/identifierlist.h"
#include "../types/type.h"
#include "../expressions/explist.h"

struct SymbolTable;

struct VarSpec{
    std::shared_ptr<IdentifierList> idList;
    std::shared_ptr<Type> type;
    std::shared_ptr<ExpList> expList;

    VarSpec(IdentifierList* idList, Type* type, ExpList* expList);
    SymbolTable* interp(SymbolTable& table);
};