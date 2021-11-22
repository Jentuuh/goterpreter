#pragma once
#include <memory>
#include "./operand.h"

/**
 * Abstract Expression class.
 * Jente Vandersanden - Compilers 2021-2022 - Hasselt University
 */
struct SymbolTable;
struct Operand;

enum UnaryOperator { PLUS_UNARY, MIN_UNARY, NOT_UNARY };
enum BinaryOperator { EQ_BIN, NE_BIN, LT_BIN, LE_BIN, GT_BIN, GE_BIN, MUL_BIN, DIV_BIN, PLUS_BIN, MIN_BIN, OR_BIN, AND_BIN };

struct Exp
{
	virtual SymbolTable* interp(SymbolTable& table) = 0;
};

struct UnaryExp:Exp{

	UnaryOperator op;
	std::shared_ptr<Exp> unaryExp;

	UnaryExp(Exp* unaryExp, UnaryOperator op);
	SymbolTable* interp(SymbolTable& table) override;
};

struct PrimaryExp:Exp{
	std::shared_ptr<Operand> operand;

	PrimaryExp(Operand* operand);
	SymbolTable* interp(SymbolTable& table) override;
};

struct BinaryExp:Exp{

	std::shared_ptr<Exp> left;
	std::shared_ptr<Exp> right;
	BinaryOperator op;

	BinaryExp(Exp* left, Exp* right, BinaryOperator op);
	SymbolTable* interp(SymbolTable& table) override;
};