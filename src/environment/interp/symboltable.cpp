#include "./symboltable.h"
#include <iostream>

TableEntry::TableEntry(std::shared_ptr<Type> t, std::shared_ptr<Literal> v): type{t}, value{v}{}

void SymbolTable::add(std::string i, std::shared_ptr<Type> t, std::shared_ptr<Literal> v)
{
    // Insert a new table entry
    TableEntry entry(t, v);
    entries.insert(std::pair<std::string, TableEntry>(i, entry));
}

void SymbolTable::update(std::string i, std::shared_ptr<Literal> v)
{
    // TODO: TYPECHECKING (should actually be done before interpreting the program) !!!
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





