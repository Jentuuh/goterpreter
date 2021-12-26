#include "./symboltable.h"
#include <iostream>

TableEntry::TableEntry(std::shared_ptr<Type> t, std::shared_ptr<Literal> v): type{t}, value{v}
{
    count = 1;
}

void SymbolTable::add(std::string i, std::shared_ptr<Type> t, std::shared_ptr<Literal> v)
{
    // Insert a new table entry
    TableEntry entry(t, v);

    std::pair<std::map<std::string, TableEntry>::iterator,bool> ret;
    ret = entries.insert(std::pair<std::string, TableEntry>(i, entry));

    // Checks if variable already existed
    if(!ret.second)
    {
        entries.at(i).count++;
    }
}

void SymbolTable::update(std::string i, std::shared_ptr<Literal> v)
{
    if(entries.count(i))
    {
        entries.at(i).value = v;
    }
}

SymbolTable::SymbolTable(int localScopeId): localScopeId{localScopeId}
{
    entries = {};
}

void SymbolTable::printValues()
{
    for (auto const& [key, val] : entries)
    {
        std::cout << key << " : ";
        val.value->printValue();
    }
}





