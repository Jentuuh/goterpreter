#include <stdio.h>
#include "./lexer/lexer.hpp"
#include "./parser/parser.hpp"
#include "./environment/interp/env.h"
#include "./environment/interp/symboltable.h"

extern int yyparse();
SrcFile* ast;

/* Array with tokens such that index = tokenid - 250*/
char *tokens[] = {
"SEMICOLON",
"IDENTIFIER",
"INTEGER", "BOOLEAN",
"PACKAGE", "RETURN", "VAR", "IF", "FOR",
"LPAREN", "RPAREN", "LBRACE", "RBRACE",
"PLUS", "MIN", "MUL", "DIV", 
"PLUSASSIGN", "MINASSIGN", "MULASSIGN", "DIVASSIGN",
"AND", "OR", "NOT",
"INC", "DEC",
"GT", "GE", "LT", "LE", "EQ", "NE",
"INTLITERAL", "BOOLLITERAL", "ASSIGN", "FUNCTION", "NEWLINE", 
"IMPORT", "COMMA", "ELSE", "SHORTVARASSIGN"
}; 

int main(int argc, char* argv[])
{
    // Input from file
  FILE * inputFile;
  inputFile = fopen("correct_programs.go", "r");
  if (inputFile == NULL) perror ("Error opening file");
  yyrestart(inputFile);

  yyparse();
  fclose(inputFile);

  ScopedEnv scopeTypeEnvironment{};
  FunctionEnv functionTypeEnvironment{};
  std::vector<std::string> typeErrors{};

  ast->typecheck(scopeTypeEnvironment, functionTypeEnvironment, typeErrors);
  // If there were type errors, print them out
  if(!typeErrors.empty())
  {
    std::cout << "Type error found!" << std::endl;
    for (std::string e : typeErrors)
    {
      std::cout << e << std::endl;
    }
  } else {
    std::cout << "Typecheck succeeded!" << std::endl;
    ScopedEnv scopeEnvironment{};
    FunctionEnv functionEnvironment{};
    // If there were no type errors, we can interpret the program
    ast->interp(scopeEnvironment, functionEnvironment);

    scopeEnvironment.printScopes();
    functionEnvironment.declaredFunctions.printValues();
  }

  return 0;
}
