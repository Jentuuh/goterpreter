#pragma once
struct SymbolTable;

struct Type{
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct IntegerType:Type{
    IntegerType();
    SymbolTable* interp(SymbolTable& table) override;
};

struct BooleanType:Type{
    BooleanType();
    SymbolTable* interp(SymbolTable& table) override;
};