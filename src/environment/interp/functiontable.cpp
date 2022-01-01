#include "./functiontable.h"
#include <iostream>

FuncTableEntry::FuncTableEntry(std::shared_ptr<FunctionDecl> f): funcDecl{f}
{ 
    count = 1; 
    hasReturned = false;
}

FunctionTable::FunctionTable()
{
    entries = {};
}


void FunctionTable::add(std::string i, std::shared_ptr<FunctionDecl> f)
{
    std::pair<std::map<std::string,std::shared_ptr<FuncTableEntry>>::iterator,bool> ret;
    ret = entries.insert(std::pair<std::string, std::shared_ptr<FuncTableEntry>>(i,std::make_shared<FuncTableEntry>(f)));

    // Checks if function already existed
    if (!ret.second)
    {
        entries.at(i)->count++;
    }
}

void FunctionTable::addReturnValues(std::string i, std::vector<std::shared_ptr<Literal>> values)
{
    entries.at(i)->returnValues = values;
}

void FunctionTable::resetReturnValues(std::string i)
{
    entries.at(i)->returnValues.clear();
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
                val->funcDecl->funcSign->result->getTypes(typeContainer);
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


