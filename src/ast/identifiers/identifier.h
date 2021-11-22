#pragma once

struct SymbolTable;

struct Identifier{
    char* name;

    Identifier(char* name);
    SymbolTable* interp(SymbolTable& table);
};