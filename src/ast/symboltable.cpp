#include "symboltable.h"

void SymbolTable::update(std::string i, int v)
{
    entries[i] = v;
}

void SymbolTable::update(std::string i, bool v)
{
    entries[i] = v;
}