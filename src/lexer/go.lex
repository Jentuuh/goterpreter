%{
/* 
go.lex: lex-file for go basisniveau
*/
#include "../parser/parser.hpp"
#include <stdlib.h>
#include <string.h>

  /* Keep track of current position of lex for error messages, i.e. 
     the position just *after* the last token read */
  int line_nr = 1;
  int col_nr = 1; 
  int lexPos = 1;
  bool insert_semicolon = false;
  void ADJUST(bool insert_semicol = false) { col_nr = lexPos; 
                                             lexPos += yyleng; 
                                             insert_semicolon = insert_semicol;}

%}
whitespace (" "|"\t"|"\n")
comment "//".*"\n"
semicolon ";"
identifier ((_[a-zA-Z]+)|([a-zA-Z]))[a-zA-Z0-9_]*
integer "int"
boolean "bool"
package "package"
return "return"
print "print"
println "println"
var "var"
if "if"
for "for"
lparen "("
rparen ")"
lbrace "{"
rbrace "}"
plus "+"
minus "-"
multiplication "*"
division "/"
plusassign "+="
minassign "-="
mulassign "*="
divassign "/="
and "&&"
or "||"
not "!"
increment "++"
decrement "--"
greaterthan ">"
greaterthanequal ">="
lessthan "<"
lessthanequal "<="
equal "=="
notequal "!=" 
integerlit 0|-?([1-9]+)(_[0-9]|[0-9])*
boollit ("true"|"false")
assign "="
shortvarassign ":="
function "func"
import "import"
comma ","
else "else"

%%
\n { line_nr++; col_nr = 1; lexPos = 1; if(insert_semicolon){ insert_semicolon = false; return SEMICOLON; } }
{semicolon} { ADJUST(); return SEMICOLON; }
{integer} { ADJUST(true); return INTEGER; }
{boolean} { ADJUST(true); return BOOLEAN; }
{function} { ADJUST(); return FUNC; }
{package} { ADJUST(); return PACKAGE; }
{return} { ADJUST(true); return RETURN; }
{import} {ADJUST(); return IMPORT; }
{print} {ADJUST(); return PRINT; }
{println} {ADJUST(); return PRINTLN; }
{var} { ADJUST(); return VAR; }
{if} { ADJUST(); return IF; }
{else} {ADJUST(); return ELSE; }
{for} { ADJUST(); return FOR; }
{integerlit} { ADJUST(true); 
            char* s = strdup(yytext);
            long int value = strtol(s, NULL, 10);
            *yylval.intlit = value;
            return INTLITERAL;
            }
{boollit} { ADJUST(true); 
               char* s = strdup(yytext);
               if(strcmp(s, "true") == 0){
                *yylval.boollit = true;
               }
               else{
                 *yylval.boollit = false;
               }
              return BOOLLITERAL; 
          }
{identifier} { ADJUST(true); 
               char* s = strdup(yytext);
               yylval.id = s; 
               return IDENTIFIER; 
              }
{lparen} { ADJUST(); return LPAREN; }
{rparen} { ADJUST(true); return RPAREN; }
{lbrace} { ADJUST(); return LBRACE; }
{rbrace} { ADJUST(true); return RBRACE; }
{plus} { ADJUST(); return PLUS; }
{minus} { ADJUST(); return MIN; }
{multiplication} { ADJUST(); return MUL; }
{division} { ADJUST(); return DIV; }
{plusassign} { ADJUST(); return PLUSASSIGN; }
{minassign} { ADJUST(); return MINASSIGN; }
{mulassign} { ADJUST(); return MULASSIGN; }
{divassign} { ADJUST(); return DIVASSIGN; }
{and} { ADJUST(); return AND; }
{or} { ADJUST(); return OR; }
{not} { ADJUST(); return NOT; }
{increment} { ADJUST(true); return INC; }
{decrement} { ADJUST(true); return DEC; }
{greaterthan} { ADJUST(); return GT; }
{greaterthanequal} { ADJUST(); return GE; }
{lessthan} { ADJUST(); return LT; }
{lessthanequal} { ADJUST(); return LE; }
{equal} { ADJUST(); return EQ; }
{notequal} { ADJUST(); return NE; }
{assign} { ADJUST(); return ASSIGN; } 
{shortvarassign} {ADJUST(); return SHORTVARASSIGN; }
{comma} { ADJUST(); return COMMA; }


{comment}|{whitespace} {/* Do nothing */}

.      {
  if (yytext[0] < ' '){ /* non-printable char */
    /*yyerror*/ fprintf(stderr,"illegal character: ^%c",yytext[0] + '@'); 
  }
  else {
    if (yytext[0] > '~') {
      /* non-printable char printed as octal int padded with zeros, eg \012*/
      /*yyerror(*/fprintf(stderr,"illegal character: \\%03o", (int) yytext[0]);
    }
    else {
      /*yyerror(*/fprintf(stderr,"illegal character: %s",yytext);
    }
  }
  /* lex read exactly one char; the illegal one */
  fprintf(stderr," at line %d column %d\n", line_nr, (col_nr-1));
			       }

<<EOF>>  {
  line_nr++; col_nr = 1; lexPos = 1; 
  if(insert_semicolon){ printf("INSERT "); insert_semicolon = false; return SEMICOLON; }
  yyterminate();
}
%%

/* Function called by (f)lex when EOF is read. If yywrap returns a
   true (non-zero) (f)lex will terminate and continue otherwise.*/
int yywrap(){
  return (1);
}
int yyerror(char* s){
  fprintf(stderr, "Bison: syntax error at line %d column %d .\n", line_nr, (col_nr-1));
  return (1);
}
