#include <memory>

struct IdentifierList;

// TODO: Make local function scope of these parameters!

struct ParameterDecl{

    std::shared_ptr<Type> type;
    std::shared_ptr<IdentifierList> identifiers;

    ParameterDecl(Type* type, IdentifierList* identifiers): type{type}, identifiers{identifiers}{};


    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };

};