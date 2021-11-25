#include "./env.h"
#include <iostream>

GlobalEnv::GlobalEnv()
{
    globals = SymbolTable{};
}

std::shared_ptr<Literal> GlobalEnv::lookupVar(std::string id)
{
        // Check if table contains the id we're looking for
        if(globals.entries.count(id))
        {
            return globals.entries.at(id).value;
        }

        // If not, we return NULL
        return nullptr;
}


ScopedEnv::ScopedEnv()
{
    // Init highest level scope
    scopeSymbolTables.push_back(SymbolTable{});
}

SymbolTable* ScopedEnv::currentScope()
{
    // Return address of top of stack
    return &scopeSymbolTables.back();
}

std::shared_ptr<Literal> ScopedEnv::lookupVar(std::string id)
{
    int scopeDepth = scopeSymbolTables.size();
    // Loop through the environment back-to-front to find a definition of the variable
    for (int i = scopeDepth - 1; i > -1; i--)
    {   
        if(scopeSymbolTables[i].entries.count(id))
        {
            // If we find the symbol in any higher scope
            return scopeSymbolTables[i].entries.at(id).value;
        }
    }

    // In case we found nothing, we return NULL
    return nullptr;
}

void ScopedEnv::updateVar(std::string id, std::shared_ptr<Literal> newVal)
{
    for(int i = scopeSymbolTables.size(); i >= 0; i++)
    {
        // Check if the symbol is defined anywhere
        if(scopeSymbolTables[i].entries.count(id))
        {
            // Update the value
            scopeSymbolTables[i].entries.at(id).value = newVal;
            return;
        }
    }
}

void ScopedEnv::popScope()
{
    // Pop the symbol table of the current scope off the stack
    scopeSymbolTables.pop_back();
}

void ScopedEnv::pushScope()
{
    // Push a fresh symbol table on top of the stack
    scopeSymbolTables.push_back(SymbolTable{});
}

void ScopedEnv::printScopes()
{
    int scopeLevel = 0;
    for (SymbolTable s : scopeSymbolTables)
    {
        std::cout << "================ Scope Depth: " << scopeLevel << " ================"  << std::endl;
        s.printValues();
        std::cout << std::endl;
        scopeLevel++;
    }
}

FuncTableEntry* FunctionEnv::lookupVar(std::string id)
{
        // Check if table contains the id we're looking for
        if(declaredFunctions.entries.count(id))
        {
            return &declaredFunctions.entries.at(id);
        }

        // If not, we return NULL
        return nullptr;
}
