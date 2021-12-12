#include "./env.h"
#include <iostream>

// ============= GlobalEnv =============
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

bool GlobalEnv::varExists(std::string id)
{
        // Check if table contains the id we're looking for
        if(globals.entries.count(id))
        {
            return true;
        }

        // If not, we return false
        return false;
}

// ============= ScopedEnv =============
ScopedEnv::ScopedEnv()
{
    // Init highest level scope
    scopeSymbolTables.push_back(std::make_shared<SymbolTable>(0));
}

void ScopedEnv::reset()
{
    // Reinit environment
    scopeSymbolTables.clear();
    scopeSymbolTables.push_back(std::make_shared<SymbolTable>(0));
}


std::shared_ptr<SymbolTable> ScopedEnv::currentScope()
{
    // Return address of top of stack
    return scopeSymbolTables.back();
}

std::shared_ptr<Literal> ScopedEnv::lookupVar(std::string id)
{
    int scopeDepth = scopeSymbolTables.size();

    for(int i = scopeDepth - 1; i >= 0; i--)
    {
        // We can only look up variables from the same scope level (same function), and globals!
        if(scopeSymbolTables[i]->entries.count(id) && (scopeSymbolTables[i]->localScopeId == scopeLevel || i == 0))
        {
            return scopeSymbolTables[i]->entries.at(id).value;
        }
    }
    
    // In case we found nothing, we return NULL
    return nullptr;
}

bool ScopedEnv::varExists(std::string id)
{
    int scopeDepth = scopeSymbolTables.size();

    for(int i = scopeDepth - 1; i >= 0; i--)
    {
        // We can only look up variables from the same scope level (same function), and globals!
        if(scopeSymbolTables[i]->entries.count(id) && (scopeSymbolTables[i]->localScopeId == scopeLevel || i == 0))
        {
            return true;
        }
    }
    return false;
}

std::shared_ptr<Type> ScopedEnv::getVarType(std::string id)
{
    int scopeDepth = scopeSymbolTables.size();

    for(int i = scopeDepth - 1; i >= 0; i--)
    {
        // We can only look up variables from the same scope level (same function), and globals!
        if(scopeSymbolTables[i]->entries.count(id) && (scopeSymbolTables[i]->localScopeId == scopeLevel || i == 0))
        {
            return scopeSymbolTables[i]->entries.at(id).type;
        }
    }

    // If we found no variable in the current scope with this ID, return nullptr
    return nullptr;
}


void ScopedEnv::updateVar(std::string id, std::shared_ptr<Literal> newVal)
{
    for(int i = scopeSymbolTables.size() - 1; i >= 0; i++)
    {

        // Check if the symbol is defined anywhere
        if(scopeSymbolTables[i]->entries.count(id))
        {
            // Update the value
            scopeSymbolTables[i]->entries.at(id).value = newVal;
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
    scopeSymbolTables.push_back(std::make_shared<SymbolTable>(scopeLevel));

}

void ScopedEnv::printScopes()
{
    std::cout << std::endl;
    
    int scopeLevel = 0;
    for (std::shared_ptr<SymbolTable> s : scopeSymbolTables)
    {
        std::cout << "================ Scope Depth: " << scopeLevel << " ================"  << std::endl;
        s->printValues();
        std::cout << std::endl;
        scopeLevel++;
    }
}

// ============= FunctionEnv =============
std::shared_ptr<FuncTableEntry> FunctionEnv::lookupVar(std::string id)
{
        // Check if table contains the id we're looking for
        if(declaredFunctions.entries.count(id))
        {
            return declaredFunctions.entries.at(id);
        }

        // If not, we return NULL
        return nullptr;
}

std::string FunctionEnv::currentFunc()
{
    return callStack.back();
}

void FunctionEnv::reset()
{
    declaredFunctions.entries.clear();
}

void FunctionEnv::pushFunc(std::string funcName)
{
    callStack.push_back(funcName);
}

void FunctionEnv::popFunc()
{
    callStack.pop_back();
}

