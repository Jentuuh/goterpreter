#include "paramlist.h"

// ============= LastParamList =============
LastParamList::LastParamList(ParameterDecl* last):last{last}{}

int LastParamList::length()
{
    // TODO: implement
}

void LastParamList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

void LastParamList::getIdentifiersWithTypes(std::vector<std::pair<std::vector<std::string>, std::shared_ptr<Type>>> container)
{
    std::vector<std::string> ids;
    last->identifiers->getIdentifierStrings(ids);
    container.push_back(std::pair<std::vector<std::string>, std::shared_ptr<Type>>(ids, last->type));
}

void LastParamList::getIdentifiers(std::vector<std::string> container)
{
    last->identifiers->getIdentifierStrings(container);
}

// ============= PairParamList =============
PairParamList::PairParamList(ParameterDecl* head, ParameterList* tail): head{head}, tail{tail}{};

int PairParamList::length()
{
    // TODO: implement
}

void PairParamList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}

void PairParamList::getIdentifiersWithTypes(std::vector<std::pair<std::vector<std::string>, std::shared_ptr<Type>>> container)
{
    // Head
    std::vector<std::string> ids;
    head->identifiers->getIdentifierStrings(ids);
    container.push_back(std::pair<std::vector<std::string>, std::shared_ptr<Type>>(ids, head->type));

    // Tail
    tail->getIdentifiersWithTypes(container);
}

void PairParamList::getIdentifiers(std::vector<std::string> container)
{
    head->identifiers->getIdentifierStrings(container);
    tail->getIdentifiers(container);
}



