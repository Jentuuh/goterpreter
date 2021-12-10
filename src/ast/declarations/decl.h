#pragma once
#include <memory>
#include <utility>
#include "./varspec.h"
#include "../identifiers/identifier.h"
#include "../functions/signature.h"
#include "../block/block.h"

struct ScopedEnv;
struct FunctionEnv; 
struct Block;
struct VarSpec;

struct TopLevelDecl{
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
    virtual void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) = 0;
};

struct Decl:TopLevelDecl{
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
    virtual void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) = 0;
};

struct VarDecl:Decl{

    std::shared_ptr<VarSpec> varspec;

    VarDecl(VarSpec* varspec);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) override;
};

struct FunctionDecl:public std::enable_shared_from_this<FunctionDecl>, TopLevelDecl{
    std::shared_ptr<Identifier> funcName;
    std::shared_ptr<Signature> funcSign;
    std::shared_ptr<Block> funcBody;

    FunctionDecl(Identifier* funcName, Signature* sign, Block* body);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) override;
};