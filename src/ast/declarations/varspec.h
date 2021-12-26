#pragma once
#include <memory>
#include <utility>
#include "../identifiers/identifierlist.h"
#include "../types/type.h"
#include "../expressions/explist.h"

struct ScopedEnv;
struct FunctionEnv;
struct ExpList;


struct VarSpec{
    std::shared_ptr<IdentifierList> idList;
    std::shared_ptr<Type> type;
    std::shared_ptr<ExpList> expList;

    VarSpec(IdentifierList* idList, Type* type, ExpList* expList);
    void getReferencePairs(std::vector<std::pair<std::string, std::string>>& referenceGraph);
};