#include <memory>

struct StmList;
struct SymbolTable;

struct Block{
    std::shared_ptr<StmList> statements;

    Block(StmList* stmList): statements{stmList}{};

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};