#pragma once
struct SymbolTable;

struct Literal{
    virtual SymbolTable* interp(SymbolTable& table) = 0;
    virtual void printValue() = 0;
};

struct BoolLiteral: Literal{
    bool value;

    BoolLiteral(bool value);
    SymbolTable* interp(SymbolTable& table) override;
    void printValue() override;
};

struct IntLiteral: Literal{
    int value;

    IntLiteral(int value);
    SymbolTable* interp(SymbolTable& table) override;
    void printValue() override;
};

