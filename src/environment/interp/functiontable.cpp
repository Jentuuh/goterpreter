#include "./functiontable.h"
#include <iostream>

FunctionTable::FunctionTable()
{
    entries = {};
}


void FunctionTable::add(std::string i, std::shared_ptr<FunctionDecl> f)
{
    std::cout << "Adding new function entry..." << std::endl;
    entries.insert(std::pair<std::string, std::shared_ptr<FunctionDecl>>(i, f));
}


void FunctionTable::update(std::string i, std::shared_ptr<FunctionDecl> f)
{
    if(entries.count(i))
    {
        entries.at(i) = f;
    }
}

void FunctionTable::printValues()
{
    for (auto const& [key, val] : entries)
    {
        std::cout << key << " : " << val->funcName->name << std::endl;
    }
}

