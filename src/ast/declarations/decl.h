#pragma once
#include <memory>
#include <utility>
#include "./varspec.h"
#include "./varspeclist.h"
#include "../identifiers/identifier.h"
#include "../functions/signature.h"
#include "../block/block.h"

struct ScopedEnv;
struct FunctionEnv; 
struct Block;
struct VarSpec;
struct VarSpecList;

struct TopLevelDecl{
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
    virtual void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) = 0;
    virtual void preBuildFunctionEnvironment(FunctionEnv& preBuiltEnv) = 0;
    virtual void preBuildGlobalsEnvironment(ScopedEnv& preBuiltEnv, FunctionEnv& funcEnv) = 0;
};

struct Decl:TopLevelDecl{
    virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
    virtual void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) = 0;
    virtual void preBuildFunctionEnvironment(FunctionEnv& preBuiltEnv) = 0;
    virtual void preBuildGlobalsEnvironment(ScopedEnv& preBuiltEnv, FunctionEnv& funcEnv) = 0;
};

struct VarDecl:Decl{

    std::shared_ptr<VarSpecList> varspecs;

    VarDecl(VarSpecList* varspecs);
    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) override;
    void preBuildFunctionEnvironment(FunctionEnv& preBuiltEnv) override;
    void preBuildGlobalsEnvironment(ScopedEnv& preBuiltEnv, FunctionEnv& funcEnv) override;
};

struct FunctionDecl: TopLevelDecl{
    std::shared_ptr<Identifier> funcName;
    std::shared_ptr<Signature> funcSign;
    std::shared_ptr<Block> funcBody;

    FunctionDecl(Identifier* funcName, Signature* sign, Block* body);
    FunctionDecl(std::shared_ptr<Identifier> funcName, std::shared_ptr<Signature> sign, std::shared_ptr<Block> body);

    void interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
    void typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) override;
    void preBuildFunctionEnvironment(FunctionEnv& preBuiltEnv) override;
    void preBuildGlobalsEnvironment(ScopedEnv& preBuiltEnv, FunctionEnv& funcEnv) override;
};