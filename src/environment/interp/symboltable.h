#pragma once
#include <map>
#include <string>
#include <memory>
#include "../../ast/types/type.h"
#include "../../ast/literals/literal.h"

struct TableEntry{
    std::shared_ptr<Type> type;
    std::shared_ptr<Literal> value;
    int count;

    TableEntry(std::shared_ptr<Type> t, std::shared_ptr<Literal> v);
};

struct SymbolTable{
    std::map<std::string, TableEntry> entries;
    int localScopeId;

    SymbolTable(int localScopeId);
    void add(std::string i, std::shared_ptr<Type> t, std::shared_ptr<Literal> v);
    void update(std::string i, std::shared_ptr<Literal> v);
    void printValues();
};   

