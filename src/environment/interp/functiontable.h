#pragma once
#include <map>
#include <string>
#include <memory>
#include "../../ast/declarations/decl.h"

struct FunctionDecl;

struct FunctionTable{
    std::map<std::string, std::shared_ptr<FunctionDecl>> entries;

    FunctionTable();
    void add(std::string i, std::shared_ptr<FunctionDecl> f);
    void update(std::string i, std::shared_ptr<FunctionDecl> f);
    void printValues();
};   