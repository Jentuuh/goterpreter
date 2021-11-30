#include "./env.h"
#include <iostream>

GlobalEnv::GlobalEnv(){}

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
    scopeSymbolTables.push_back(SymbolTable{0});
}

SymbolTable* ScopedEnv::currentScope()
{
    // Return address of top of stack
    return &scopeSymbolTables.back();
}

std::shared_ptr<Literal> ScopedEnv::lookupVar(std::string id)
{
    int scopeDepth = scopeSymbolTables.size();

    for(int i = scopeDepth - 1; i >= 0; i--)
    {
        // We can only look up variables from the same scope level (same function), and globals!
        if(scopeSymbolTables[i].entries.count(id) && (scopeSymbolTables[i].localScopeId == scopeLevel || i == 0))
        {
            return scopeSymbolTables[i].entries.at(id).value;
        }
    }

    // if(scopeSymbolTables[scopeDepth - 1].entries.count(id))
    // {
    //     // If we find the symbol in the current scope
    //     return scopeSymbolTables[scopeDepth - 1].entries.at(id).value;
    // }  
    // if (scopeSymbolTables[0].entries.count(id))
    // {
    //     // If we find the symbol in the global environment
    //     return scopeSymbolTables[0].entries.at(id).value;
    // }
    
    // In case we found nothing, we return NULL
    return nullptr;
}

void ScopedEnv::updateVar(std::string id, std::shared_ptr<Literal> newVal)
{
    for(int i = scopeSymbolTables.size() - 1; i >= 0; i++)
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

void ScopedEnv::popScope(bool decScopeLevel)
{
    if(decScopeLevel)
    {
        scopeLevel--;
    }
    // Pop the symbol table of the current scope off the stack
    scopeSymbolTables.pop_back();
}

void ScopedEnv::pushScope(bool incScopeLevel)
{
    if(incScopeLevel)
    {
        scopeLevel++;
    }
    // Push a fresh symbol table on top of the stack
    scopeSymbolTables.push_back(SymbolTable{scopeLevel});

}

void ScopedEnv::printScopes()
{
    std::cout << std::endl;
    
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

std::string FunctionEnv::currentFunc()
{
    return callStack.back();
}

void FunctionEnv::pushFunc(std::string funcName)
{
    callStack.push_back(funcName);
}

void FunctionEnv::popFunc()
{
    callStack.pop_back();
}

