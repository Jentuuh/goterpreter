#pragma once
#include <map>
#include <string>

// TODO: Make sure you put in `Types` and `Literals` in this table instead of `ints`!

struct SymbolTable{
    std::map<std::string, int> entries;

    void update(std::string i, int v);
    void update(std::string i, bool v);
};   