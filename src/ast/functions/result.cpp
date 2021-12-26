#include "result.h"
#include <iostream>

// ============= ParametersResult =============
ParametersResult::ParametersResult(ParameterList* params): parameters{params}{}


void ParametersResult::getTypes(std::vector<std::shared_ptr<Type>>& typeContainer)
{
    std::vector<std::pair<std::vector<std::string>, std::shared_ptr<Type>>> idsAndTypes;
    parameters->getIdentifiersWithTypes(idsAndTypes);

    for(auto it : idsAndTypes)
    {
        typeContainer.push_back(it.second);
    }
}

// ============= TypeResult =============
TypeResult::TypeResult(TypeList* typelist): types{typelist}{}


void TypeResult::getTypes(std::vector<std::shared_ptr<Type>>& typeContainer)
{
    types->getTypes(typeContainer);
}

