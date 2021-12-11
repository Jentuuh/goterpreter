#include "result.h"

// ============= ParametersResult =============
ParametersResult::ParametersResult(ParameterList* params): parameters{params}{}

void ParametersResult::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: Implement
}

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
TypeResult::TypeResult(Type* type): type{type}{}

void TypeResult::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: Implement
}

void TypeResult::getTypes(std::vector<std::shared_ptr<Type>>& typeContainer)
{
    typeContainer.push_back(type);
}

