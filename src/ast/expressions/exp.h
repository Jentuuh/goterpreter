#pragma once
#include <memory>
#include <utility>
#include <vector>
#include "./operand.h"
#include "./explist.h"

/**
 * Abstract Expression class.
 * Jente Vandersanden - Compilers 2021-2022 - Hasselt University
 */
struct ScopedEnv;
struct FunctionEnv;
struct Operand;
struct ExpList;
struct Literal;

enum UnaryOperator { PLUS_UNARY, MIN_UNARY, NOT_UNARY };
enum BinaryOperator { EQ_BIN, NE_BIN, LT_BIN, LE_BIN, GT_BIN, GE_BIN, MUL_BIN, DIV_BIN, PLUS_BIN, MIN_BIN, OR_BIN, AND_BIN };

struct Exp{
	virtual std::shared_ptr<Literal> interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
	virtual std::shared_ptr<Type> typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) = 0;
	virtual std::string getOperandName() = 0;
	virtual void getRefNames(std::vector<std::string>& refContainer) = 0;
    virtual std::vector<std::shared_ptr<Type>> getType(ScopedEnv& env,FunctionEnv& funcEnv) = 0;
};

// struct PrimaryExp:Exp{
// 	virtual void interp(ScopedEnv& env, FunctionEnv& funcEnv) = 0;
// };

struct OperandExp:Exp{
	std::shared_ptr<Operand> operand;

	OperandExp(Operand* operand);
	std::string getOperandName() override;
	void getRefNames(std::vector<std::string>& refContainer) override;
	std::shared_ptr<Literal> interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
	std::shared_ptr<Type> typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) override;
    std::vector<std::shared_ptr<Type>> getType(ScopedEnv& env,FunctionEnv& funcEnv) override;
};

struct FunctionCall:Exp{
	std::shared_ptr<Exp> primaryExp; 
	std::shared_ptr<ExpList> arguments;

	FunctionCall(Exp* primExp, ExpList* expList);
	std::string getOperandName() override;
	void getRefNames(std::vector<std::string>& refContainer) override;
	std::vector<std::shared_ptr<Literal>> executeFunction(ScopedEnv& env, FunctionEnv& funcEnv);
	std::vector<std::shared_ptr<Type>> typeCheckFunction(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors);

	std::shared_ptr<Literal> interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
	std::shared_ptr<Type> typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) override;
    std::vector<std::shared_ptr<Type>> getType(ScopedEnv& env,FunctionEnv& funcEnv) override;
};

struct UnaryExp:Exp{

	UnaryOperator op;
	std::shared_ptr<Exp> unaryExp;

	UnaryExp(Exp* unaryExp, UnaryOperator op);
	std::string getOperandName() override;
	void getRefNames(std::vector<std::string>& refContainer) override;
	std::shared_ptr<Literal> interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
	std::shared_ptr<Type> typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) override;
    std::vector<std::shared_ptr<Type>> getType(ScopedEnv& env,FunctionEnv& funcEnv) override;
};


struct BinaryExp:Exp{

	std::shared_ptr<Exp> left;
	std::shared_ptr<Exp> right;
	BinaryOperator op;

	BinaryExp(Exp* left, Exp* right, BinaryOperator op);
	std::string getOperandName() override;
	void getRefNames(std::vector<std::string>& refContainer) override;
	std::shared_ptr<Literal> interp(ScopedEnv& env, FunctionEnv& funcEnv) override;
	std::shared_ptr<Type> typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors) override;
    std::vector<std::shared_ptr<Type>> getType(ScopedEnv& env,FunctionEnv& funcEnv) override;
};