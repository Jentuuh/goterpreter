#include "result.h"

// ============= ParametersResult =============
ParametersResult::ParametersResult(ParameterList* params): parameters{params}{}

void ParametersResult::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: Implement
}

std::vector<std::shared_ptr<Type>> ParametersResult::getTypes()
{
    std::vector<std::pair<std::vector<std::string>, std::shared_ptr<Type>>> idsAndTypes;
    parameters->getIdentifiersWithTypes(idsAndTypes);

    std::vector<std::shared_ptr<Type>> types{};

    for(auto it : idsAndTypes)
    {
        types.push_back(it.second);
    }

    return types;
}

// ============= TypeResult =============
TypeResult::TypeResult(Type* type): type{type}{}

void TypeResult::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: Implement
}

std::vector<std::shared_ptr<Type>> TypeResult::getTypes()
{
    std::vector<std::shared_ptr<Type>> types;
    types.push_back(type);

    return types;
}

