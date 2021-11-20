#include <stdio.h>
#include "lexer/lexer.h"
#include "parser/grammar.tab.h"

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
  inputFile = fopen("testProgram.go", "r");
  if (inputFile == NULL) perror ("Error opening file");
  yyrestart(inputFile);

  // int tokenid;
  // /* If we de not explicitly bind yyin to a file, stdin is assumed. */
  // while (tokenid=yylex())
  //   {
  //     /* Token codes start from 258 */ 
  //     printf(" %s", tokens[tokenid-258]);

  //     /* Append value */
  //     if ( (tokenid == IDENTIFIER) || (tokenid == INTEGER) || (tokenid == BOOLEAN) ) 
  //     printf("=\"%s\"", yytext);
  //       }
  //   printf("\n");

  yyparse();
  return 0;
}
