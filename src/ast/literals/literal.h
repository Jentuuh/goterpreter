struct SymbolTable;

struct Literal{
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct BoolLiteral: Literal{
    bool value;

    BoolLiteral(bool value): value{value}{};

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: interp
    }

};

struct IntLiteral: Literal{

    int value;

    IntLiteral(int value): value{value}{};

   SymbolTable* interp(SymbolTable& table)
    {
        // TODO: interp
    }
};

