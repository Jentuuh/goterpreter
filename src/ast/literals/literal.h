#pragma once
struct SymbolTable;

struct Literal{
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct BoolLiteral: Literal{
    bool value;

    BoolLiteral(bool value);
    SymbolTable* interp(SymbolTable& table) override;
};

struct IntLiteral: Literal{
    int value;

    IntLiteral(int value);
    SymbolTable* interp(SymbolTable& table) override;
};

