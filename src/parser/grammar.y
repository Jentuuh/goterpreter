%{
 // C-DECLARATIONS
 #include <stdio.h>
 #include "../ast/types/srcfile.h"
 
 #include "../ast/expressions/explist.h"
 #include "../ast/expressions/exp.h"

 #include "../ast/identifier/identifier.h"

 #include "../ast/declarations/decllist.h"
 #include "../ast/declarations/decl.h"
 #include "../ast/declarations/varspec.h"

 #include "../ast/statements/stmlist.h"
 #include "../ast/statements/stm.h"

 #include "../ast/packages/packageclause.h"

 #include "../ast/literals/literal.h"
 #include "../ast/symboltable.h"

 int yylex(void);
 int yyerror(char *s);

 SrcFile * ast;

%}
%union{
        SrcFile* srcfile;
        char* id;
        
        Stm* stm; 
        StmList* stmlist;

        Exp* exp; 
        ExpList* explist;
        Identifier* identifier;
        
        DeclList* decllist;
        TopLevelDecl* toplvldecl;
        Decl* decl;
        VarDecl* vardecl;
        VarSpec* varspec;

        PackageClause* packageclause;
}

%token
    SEMICOLON INTEGER BOOLEAN
    PACKAGE RETURN VAR IF FOR
    LPAREN RPAREN LBRACE RBRACE
    PLUS MIN MUL DIV
    PLUSASSIGN MINASSIGN MULASSIGN DIVASSIGN
    AND OR NOT INC DEC GT GE LT LE EQ NE
    INTLITERAL BOOLLITERAL ASSIGN FUNC NEWLINE 
    IMPORT COMMA ELSE SHORTVARASSIGN

%token <id> IDENTIFIER
%type <identifier> packagename
%type <srcfile> sourcefile 
%type <decllist> topleveldeclarations
%type <packageclause> packageclause
%type <toplvldecl> topleveldecl
%type <decl> declaration
%type <vardecl> vardecl
%type <varspec> varspec


%left OR
%left AND
%left EQ NE GT GE LT LE
%left PLUS MIN
%left MUL DIV
%right UMINUS
%%
sourcefile: packageclause SEMICOLON topleveldeclarations {$$ = new SrcFile($1, $3);
                                                          ast = $$;
                                                         };

topleveldeclarations: topleveldecl SEMICOLON topleveldeclarations  {$$ = new PairDeclList($1, $3);}
                    | topleveldecl SEMICOLON                       {$$ = new LastDeclList($1);}
                    ;

packageclause: PACKAGE packagename  {$$ = new PackageClause($2);};

packagename: IDENTIFIER {$$ = new Identifier($1);}
           ;

topleveldecl: declaration          {$$ = $1; }
            | functiondeclaration  {$$ = $1; }
            ;

declaration: vardecl     {$$ = new VarDecl(); }
           ;

vardecl: VAR varspec                                        {$$ = new VarDecl($2); }
        | VAR LPAREN varspec SEMICOLON RPAREN               {$$ = new VarDecl($3); }
        ;

shortvardecl: identifierlist SHORTVARASSIGN expressionlist  {puts("identifierlist SHORTVARASSIGN expressionlist"); }
            ;

varspec: identifierlist type ASSIGN expressionlist      {$$ = new VarSpec($1, $2, $4); }
        | identifierlist type                           {$$ = new VarSpec($1, $2, nullptr);}
        | identifierlist ASSIGN expressionlist          {$$ = new VarSpec($1, nullptr, $4); }
        ;

functiondeclaration: FUNC functionname signature functionbody {puts("FUNC functionname signature functionbody"); };

functionname: IDENTIFIER  {puts("IDENTIFIER"); };

functionbody: block  {puts("block"); }; 

signature: parameters result    {puts("parameters result"); }
         | parameters           {puts("parameters"); } 
         ; 

type: typename                  {puts("typename"); }
    | LPAREN type RPAREN        {puts("LPAREN type RPAREN"); }
    ;

typename: IDENTIFIER            {puts("IDENTIFIER"); }
        | INTEGER               {puts("INTEGER"); } 
        | BOOLEAN               {puts("BOOLEAN"); }
        ;

result: parameters              {puts("parameters"); }
        | type                  {puts("type"); }
        ;

parameters: LPAREN RPAREN
           | LPAREN parameterlist COMMA RPAREN    {puts("LPAREN parameterlist COMMA RPAREN"); }
           | LPAREN parameterlist RPAREN          {puts("LPAREN parameterlist RPAREN  "); }
           ;

parameterlist: parameterlist COMMA parameterdecl     {puts("parameterdecl COMMA parameterdecl"); }
             | parameterdecl                         {puts("parameterdecl"); }
             ;

parameterdecl: identifierlist type              {puts("identifierlist type"); }
             | type                             {puts("type"); }
             ;

expr: unaryexpr                 {puts("unaryexpr"); }
    | expr EQ expr              {puts("expr EQ expr"); }
    | expr NE expr              {puts("expr NE expr"); }
    | expr LT expr              {puts("expr LT expr"); }
    | expr LE expr              {puts("expr LE expr"); } 
    | expr GT expr              {puts("expr GT expr"); } 
    | expr GE expr              {puts("expr GE expr"); } 
    | expr MUL expr             {puts("expr MUL expr"); }
    | expr DIV expr             {puts("expr DIV expr"); }
    | expr PLUS expr            {puts("expr PLUS expr"); }
    | expr MIN expr             {puts("expr MIN expr"); }
    | expr OR expr              {puts("expr OR expr"); }
    | expr AND expr             {puts("expr AND expr"); }
    ;

expressionlist: expressionlist COMMA expr       {puts("expressionlist COMMA expr"); }
              | expr                            {puts("expr"); }
              ;

identifierlist: IDENTIFIER COMMA identifierlist         {puts("IDENTIFIER COMMA identifierlist"); }
              | IDENTIFIER                              {puts("IDENTIFIER"); }
              ;

unaryexpr: primaryexpr         {puts("primaryexpr"); }
          | unary_op unaryexpr {puts("unary_op unaryexpr"); }
          ;

unary_op: PLUS                  {puts("PLUS"); }
        | MIN                   {puts("MIN"); }
        | NOT                   {puts("NOT"); }
        ;

operand: literal                {puts("literal"); }
        | operandname           {puts("operandname"); }
        | LPAREN expr RPAREN    {puts("LPAREN expr RPAREN"); }
        ;

literal: basiclit               {puts("basiclit"); }
        ;

basiclit: INTLITERAL            {puts("INTLITERAL"); }
        | BOOLLITERAL           {puts("BOOLLITERAL"); }
        ;

operandname: IDENTIFIER         {puts("IDENTIFIER"); }
            ;

primaryexpr: operand            {puts("operand"); }
            ;

block: LBRACE statementlist RBRACE      {puts("LBRACE statementlist RBRACE"); }
       ;

statementlist: statement SEMICOLON                      {puts("statement SEMICOLON");}
               | statementlist statement SEMICOLON      {puts("statementlist statement SEMICOLON");}
               ;

statement: declaration                   {puts("declaration");}
        | block                          {puts("block");}
        | ifstatement                    {puts("ifstatement");}
        | forstatement                   {puts("forstatement");}
        | returnstatement                {puts("returnstatement");}
        | simplestatement                {puts("simplestatement");}                   
        ;

simplestatement: expressionstatement     {puts("expressionstatement");}
                | assignment             {puts("assignment");}
                | incdecstatement        {puts("incdecstatement");}
                | emptystatement         {puts("emptystatement");}
                | shortvardecl           {puts("shortvardecl");}
                ;

emptystatement: {puts("nothing");} ;

expressionstatement: expr {puts("expr");} ;

assignment: expressionlist assign_op expressionlist {puts("expressionlist assign_op expressionlist");}  ;

assign_op: ASSIGN                                   {puts("ASSIGN");} 
         | PLUSASSIGN                               {puts("PLUSASSIGN");} 
         | MINASSIGN                                {puts("MINASSIGN");} 
         | MULASSIGN                                {puts("MULASSIGN");} 
         | DIVASSIGN                                {puts("DIVASSIGN");}            
         ;

incdecstatement: expr INC                           {puts("expr INC");} 
                | expr DEC                          {puts("expr DEC");} 
                ;


ifstatement: IF simplestatement SEMICOLON expr block ELSE ifstatement   {puts("IF simplestatement SEMICOLON expr block ELSE ifstatement"); }
            | IF simplestatement SEMICOLON expr block ELSE block        {puts("IF simplestatement SEMICOLON expr block ELSE block"); }
            | IF expr block ELSE ifstatement                            {puts("IF expr block ELSE ifstatement"); }
            | IF expr block ELSE block                                  {puts("IF expr block ELSE block"); }
            ;

forstatement: FOR condition block       {puts("FOR condition block"); }
            | FOR forclause block       {puts("FOR forclause block"); }
            | FOR block                 {puts("FOR block"); }
            ;

condition: expr                         {puts("expr"); };

forclause: initstatement SEMICOLON condition SEMICOLON poststatement    {puts("initstatement SEMICOLON condition SEMICOLON poststatement"); }
         ;             

initstatement: simplestatement  {puts("simplestatement"); };

poststatement: simplestatement   {puts("simplestatement"); };

returnstatement: RETURN expressionlist   {puts("RETURN expressionlist"); }
                | RETURN                 {puts("RETURN"); }
                ;

%%