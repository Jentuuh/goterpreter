#include <memory>

struct ParameterDecl;
struct SymbolTable;

struct ParameterList{
    virtual int length() = 0;
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};


struct LastParamList:ParameterList{
    std::shared_ptr<ParameterDecl> last;

    LastParamList(ParameterDecl* last):last{last}{};

    int length() 
    {
        // TODO: implement
    };

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};


struct PairParamList:ParameterList{
    std::shared_ptr<ParameterDecl> head;
    std::shared_ptr<ParameterList> tail; 

    PairParamList(ParameterDecl* head, ParameterList* tail): head{head}, tail{tail}{};

    int length() 
    {
        // TODO: implement  
    };

    SymbolTable* interp(SymbolTable& table)
    {
        // TODO: implement
    };
};