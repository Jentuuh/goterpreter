#include "./operand.h"
#include <memory>

/**
 * Abstract Expression class.
 * Jente Vandersanden - Compilers 2021-2022 - Hasselt University
 */
struct SymbolTable;
enum UnaryOperator { PLUS, MIN, NOT };
enum BinaryOperator { EQ, NE, LT, LE, GT, GE, MUL, DIV, PLUS, MIN, OR, AND };

struct Exp{
	virtual SymbolTable* interp(SymbolTable& table) = 0;

};

struct UnaryExp: Exp{

	UnaryOperator op;
	std::shared_ptr<Exp> unaryExp;

	UnaryExp(Exp* unaryExp, UnaryOperator op): unaryExp{unaryExp}, op{op}{};

	SymbolTable* interp(SymbolTable& table)
	{
		// TODO: implement
	};

};

struct PrimaryExp: Exp{
	std::shared_ptr<Operand> operand;

	PrimaryExp(Operand* operand): operand{operand}{};
	
	SymbolTable* interp(SymbolTable& table)
	{
		// TODO: implement
	};
};

struct BinaryExp: Exp{

	std::shared_ptr<Exp> left;
	std::shared_ptr<Exp> right;
	BinaryOperator op;

	BinaryExp(Exp* left, Exp* right, BinaryOperator op): left{left}, right{right}, op{op}{};

	SymbolTable* interp(SymbolTable& table)
	{
		// TODO: implement
	};
};