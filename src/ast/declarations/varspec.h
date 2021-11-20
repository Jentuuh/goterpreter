#include "../expressions/explist.h"
#include "../types/type.h"
#include "../identifiers/identifierlist.h"
#include <memory>


struct VarSpec{
    std::shared_ptr<IdentifierList> idList;
    std::shared_ptr<Type> type;
    std::shared_ptr<ExpList> expList;

    VarSpec(IdentifierList* idList, Type* type, ExpList* expList): idList{idList}, type{type}, expList{expList}{};
};