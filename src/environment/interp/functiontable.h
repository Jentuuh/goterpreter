#pragma once
#include <map>
#include <string>
#include <memory>
#include "../../ast/declarations/decl.h"

struct FunctionDecl;


struct FuncTableEntry{
    std::shared_ptr<FunctionDecl> funcDecl;
    std::vector<std::shared_ptr<Literal>> returnValues;
    int count;

    FuncTableEntry(std::shared_ptr<FunctionDecl> f);
};

struct FunctionTable{
    std::map<std::string, std::shared_ptr<FuncTableEntry>> entries;

    FunctionTable();
    void add(std::string i, std::shared_ptr<FunctionDecl> f);
    void addReturnValues(std::string i, std::vector<std::shared_ptr<Literal>> values);
    void getReturnTypes(std::string i, std::vector<std::shared_ptr<Type>>& typeContainer);
    void printValues();
};   

