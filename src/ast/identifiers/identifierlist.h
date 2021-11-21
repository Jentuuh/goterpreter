#include <memory>

struct SymbolTable;

struct IdentifierList{
    virtual int length() = 0;
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct LastIdentifierList:IdentifierList{
    std::shared_ptr<Identifier> last;

    LastIdentifierList(Identifier* l): last{last}{};

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };

};

struct PairIdentifierList:IdentifierList{
    std::shared_ptr<Identifier> head;
    std::shared_ptr<IdentifierList> tail;

    PairIdentifierList(Identifier* h, IdentifierList* t): head{h}, tail{t}{};

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
    
};