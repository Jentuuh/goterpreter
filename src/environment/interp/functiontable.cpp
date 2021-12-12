#include "./functiontable.h"
#include <iostream>

FuncTableEntry::FuncTableEntry(std::shared_ptr<FunctionDecl> f): funcDecl{f}{}

FunctionTable::FunctionTable()
{
    entries = {};
}


void FunctionTable::add(std::string i, std::shared_ptr<FunctionDecl> f)
{
    entries.insert(std::pair<std::string, std::shared_ptr<FuncTableEntry>>(i,std::make_shared<FuncTableEntry>(f)));
}

void FunctionTable::addReturnValues(std::string i, std::vector<std::shared_ptr<Literal>> values)
{
    entries.at(i)->returnValues = values;
}

void FunctionTable::getReturnTypes(std::string i, std::vector<std::shared_ptr<Type>>& typeContainer)
{
    for (auto const& [key, val] : entries)
    {
        if(key == i)
        {
            if (val->funcDecl->funcSign->result != nullptr)
            {
                std::vector<std::shared_ptr<Type>> returnTypes{};
                val->funcDecl->funcSign->result->getTypes(returnTypes);
                for(auto t : returnTypes)
                {
                    typeContainer.push_back(t);
                }
            } else{
                return;
            }
        }
    }
}


void FunctionTable::printValues()
{
    std::cout << "================ Functions ================" << std::endl;
    for (auto const& [key, val] : entries)
    {
        std::cout << key << " : " << val->funcDecl->funcName->name << std::endl;
    }
}


