#pragma once
#include <memory>
#include <utility>
#include "./varspec.h"
#include "../identifiers/identifier.h"
#include "../functions/signature.h"
#include "../block/block.h"

struct ScopedEnv;
struct FunctionEnv; 
typedef std::pair<ScopedEnv*, FunctionEnv*> Environments;
struct Block;

struct TopLevelDecl{
    virtual Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
};

struct Decl:TopLevelDecl{
    virtual Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
};

struct VarDecl:Decl{

    std::shared_ptr<VarSpec> varspec;

    VarDecl(VarSpec* varspec);
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};

struct FunctionDecl:public std::enable_shared_from_this<FunctionDecl>, TopLevelDecl{
    std::shared_ptr<Identifier> funcName;
    std::shared_ptr<Signature> funcSign;
    std::shared_ptr<Block> funcBody;

    FunctionDecl(Identifier* funcName, Signature* sign, Block* body);
    Environments interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
};