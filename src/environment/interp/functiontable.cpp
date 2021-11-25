#include "./functiontable.h"
#include <iostream>

FuncTableEntry::FuncTableEntry(std::shared_ptr<FunctionDecl> f): funcDecl{f}{}

FunctionTable::FunctionTable()
{
    entries = {};
}


void FunctionTable::add(std::string i, std::shared_ptr<FunctionDecl> f)
{
    std::cout << "Adding new function entry..." << std::endl;
    FuncTableEntry entry = FuncTableEntry{f};
    entries.insert(std::pair<std::string, FuncTableEntry>(i, entry));
}

void FunctionTable::addReturnValues(std::string i, std::vector<std::shared_ptr<Literal>> values)
{
    entries.at(i).returnValues = values;
}


void FunctionTable::printValues()
{
    std::cout << "================ Functions ================" << std::endl;
    for (auto const& [key, val] : entries)
    {
        std::cout << key << " : " << val.funcDecl->funcName->name << std::endl;
    }
}

