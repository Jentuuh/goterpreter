#pragma once
#include <memory>
#include "./parameterdecl.h"

struct SymbolTable;

struct ParameterList{
    virtual int length() = 0;
    virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct LastParamList:ParameterList{
    std::shared_ptr<ParameterDecl> last;

    LastParamList(ParameterDecl* last);
    int length() override;
    SymbolTable* interp(SymbolTable& table) override;
};

struct PairParamList:ParameterList{
    std::shared_ptr<ParameterDecl> head;
    std::shared_ptr<ParameterList> tail; 

    PairParamList(ParameterDecl* head, ParameterList* tail);
    int length() override;
    SymbolTable* interp(SymbolTable& table) override;
};