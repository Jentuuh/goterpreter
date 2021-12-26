%code requires{
 // C-DECLARATIONS
 #include <stdio.h>
 #include "../includes.h"

 int yylex(void);
 int yyerror(char *s);

 extern SrcFile* ast;

}
%union{
        enum UnaryOperator unaryoperator;
        enum BinaryOperator binaryoperator;
        enum AssignOperator assignoperator;
        enum IncDecOperator incdecoperator;

        SrcFile* srcfile;
        char* id;
        bool* boollit;
        int* intlit;

        Block* block;
        
        Stm* stm; 
        SimpleStm* simplestm;
        StmList* stmlist;
        ForClause* forclause;

        Exp* exp; 
        ExpList* explist;
        Identifier* identifier;
        IdentifierList* identifierlist;
        Operand* operand;
        
        DeclList* decllist;
        TopLevelDecl* toplvldecl;
        Decl* decl;
        VarDecl* vardecl;
        VarSpec* varspec;
        VarSpecList* varspeclist;
        FunctionDecl* funcdecl;
        Signature* signature;
        Result* result;

        Literal* literal;

        ParameterList* paramlist;
        ParameterDecl* paramdecl;

        Type* type; 
        TypeList* typelist;

        PackageClause* packageclause;
}
%token
    SEMICOLON INTEGER BOOLEAN
    PACKAGE RETURN VAR IF FOR
    LPAREN RPAREN LBRACE RBRACE
    PLUS MIN MUL DIV
    PLUSASSIGN MINASSIGN MULASSIGN DIVASSIGN
    AND OR NOT INC DEC GT GE LT LE EQ NE
    ASSIGN FUNC NEWLINE IMPORT COMMA ELSE 
    SHORTVARASSIGN PRINT

%token <id> IDENTIFIER
%token <boollit> BOOLLITERAL
%token <intlit> INTLITERAL
%type <identifier> packagename
%type <srcfile> sourcefile 
%type <decllist> topleveldeclarations
%type <packageclause> packageclause
%type <identifierlist> identifierlist
%type <identifier> identifier
%type <block> block

%type <toplvldecl> topleveldecl
%type <toplvldecl> declaration
%type <toplvldecl> vardecl
%type <varspec> varspec
%type <varspeclist> varspeclist

%type <exp> expr
%type <exp> unaryexpr
%type <exp> primaryexpr
%type <explist> expressionlist
%type <unaryoperator> unary_op
%type <operand> operand
%type <identifier> operandname

%type <stm> statement
%type <stmlist> statementlist
%type <stm> simplestatement
%type <stm> initstatement
%type <stm> poststatement
%type <stm> emptystatement
%type <stm> expressionstatement
%type <stm> forstatement
%type <stm> assignment
%type <stm> ifstatement
%type <stm> incdecstatement
%type <stm> returnstatement
%type <stm> printstatement
%type <forclause> forclause
%type <exp> condition
%type <assignoperator> assign_op

%type <literal> literal
%type <literal> basiclit

%type <toplvldecl> functiondeclaration
%type <block> functionbody
%type <identifier> functionname
%type <signature> signature
%type <result> result
%type <explist> arguments

%type <type> type
%type <type> typename
%type <typelist> typelist

%type <paramlist> parameters
%type <paramlist> parameterlist
%type <paramdecl> parameterdecl

%left OR
%left AND
%left EQ NE GT GE LT LE
%left PLUS MIN
%left MUL DIV
%right RSEMICOL
%right RCOMMA
%right UMINUS
%%
sourcefile: packageclause SEMICOLON  topleveldeclarations               {$$ = new SrcFile($1, nullptr, $3);
                                                                        ast = $$;
                                                                        }
          /* | packageclause SEMICOLON importdeclarations SEMICOLON topleveldeclarations   {$$ = new SrcFile($1, $3, $5);
                                                                                        ast = $$;
                                                                                        }
          | packageclause SEMICOLON importdeclarations                  {$$ = new SrcFile($1, $3, nullptr);
                                                                        ast = $$;
                                                                        } */
          | packageclause SEMICOLON                                     {$$ = new SrcFile($1, nullptr, nullptr);
                                                                        ast = $$;
                                                                        }
        ;

/* 
importdeclarations: IMPORT importspec
                  | IMPORT LPAREN importspeclist RPAREN
                  ;

importspeclist: importspec SEMICOLON
              | importspec SEMICOLON importspeclist
              ;

importspec: 

importpath: */


topleveldeclarations: topleveldecl SEMICOLON topleveldeclarations  {$$ = new PairDeclList($1, $3);}
                    | topleveldecl SEMICOLON                       {$$ = new LastDeclList($1);}
                    ;

packageclause: PACKAGE packagename  {$$ = new PackageClause($2);};

packagename: IDENTIFIER {$$ = new Identifier($1);}
           ;

topleveldecl: declaration          {$$ = $1; }
            | functiondeclaration  {$$ = $1; }
            ;

declaration: vardecl     {$$ = $1; }
           ;

vardecl: VAR LPAREN varspeclist RPAREN                       {$$ = new VarDecl($3); }
        | VAR varspec                                        {$$ = new VarDecl(new LastVarSpecList($2)); }
        ;

varspeclist: varspec                                         {$$ = new LastVarSpecList($1); }
           | varspec SEMICOLON varspeclist                   {$$ = new PairVarSpecList($1, $3); }
           ;
             
// shortvardecl: identifierlist SHORTVARASSIGN expressionlist  {puts("identifierlist SHORTVARASSIGN expressionlist"); }
//             ;

varspec: identifierlist type ASSIGN expressionlist      {$$ = new VarSpec($1, $2, $4); }
        | identifierlist type                           {$$ = new VarSpec($1, $2, nullptr);}
        | identifierlist ASSIGN expressionlist          {$$ = new VarSpec($1, nullptr, $3); }
        ;

functiondeclaration: FUNC functionname signature functionbody {$$ = new FunctionDecl($2, $3, $4); };

functionname: IDENTIFIER  {$$ = new Identifier($1); };

functionbody: block  {$$ = $1; }; 

signature: parameters result    { $$ = new Signature($1, $2); }
         | parameters           { $$ = new Signature($1, nullptr); } 
         ; 

type: typename                  { $$ = $1; }
    | LPAREN type RPAREN        { $$ = $2; }
    ;

typelist: type                                   {$$ = new LastTypeList($1); }
        | LPAREN typename COMMA typelist RPAREN  {$$ = new PairTypeList($2, $4); }
        ;

typename: INTEGER               { $$ = new IntegerType(); } 
        | BOOLEAN               { $$ = new BooleanType(); }
        ;

result: parameters                  { $$ = new ParametersResult($1); }
        | typelist                  { $$ = new TypeResult($1); }
        ;

parameters: LPAREN RPAREN                         { $$ = nullptr; }
           | LPAREN parameterlist COMMA RPAREN    { $$ = $2; }
           | LPAREN parameterlist RPAREN          { $$ = $2; }
           ;

parameterlist: parameterlist COMMA parameterdecl     { $$ = new PairParamList($3, $1); } 
             | parameterdecl                         { $$ = new LastParamList($1); }
             ;

parameterdecl: identifierlist type              { $$ = new ParameterDecl($2, $1); }
             | type                             { $$ = new ParameterDecl($1, nullptr); }
             ;

expr: unaryexpr                 { $$ = $1; }
    | expr EQ expr              { $$ = new BinaryExp($1, $3, EQ_BIN); }
    | expr NE expr              { $$ = new BinaryExp($1, $3, NE_BIN); }
    | expr LT expr              { $$ = new BinaryExp($1, $3, LT_BIN); }
    | expr LE expr              { $$ = new BinaryExp($1, $3, LE_BIN); } 
    | expr GT expr              { $$ = new BinaryExp($1, $3, GT_BIN); } 
    | expr GE expr              { $$ = new BinaryExp($1, $3, GE_BIN); } 
    | expr MUL expr             { $$ = new BinaryExp($1, $3, MUL_BIN); }
    | expr DIV expr             { $$ = new BinaryExp($1, $3, DIV_BIN); }
    | expr PLUS expr            { $$ = new BinaryExp($1, $3, PLUS_BIN); }
    | expr MIN expr             { $$ = new BinaryExp($1, $3, MIN_BIN); }
    | expr OR expr              { $$ = new BinaryExp($1, $3, OR_BIN); }
    | expr AND expr             { $$ = new BinaryExp($1, $3, AND_BIN); }
    ;

expressionlist: expressionlist COMMA expr       { $$ = new PairExpList($3, $1); }
              | expr                            { $$ = new LastExpList($1); }
              ;

identifierlist: identifier COMMA identifierlist                     { $$ = new PairIdentifierList($1, $3); }
              | identifier                                          { $$ = new LastIdentifierList($1); }
              ;

identifier: IDENTIFIER         { $$ = new Identifier($1); };

unaryexpr: primaryexpr         { $$ = $1; }
          | unary_op unaryexpr { $$ = new UnaryExp($2, $1); }
          ;

unary_op: PLUS                  { $$ = PLUS_UNARY; }
        | MIN   %prec UMINUS    { $$ = MIN_UNARY; }
        | NOT                   { $$ = NOT_UNARY; }
        ;

operand: literal                { $$ = new LiteralOperand($1); }
        | operandname           { $$ = new VariableOperand($1); }
        | LPAREN expr RPAREN    { $$ = new ExprOperand($2); }
        ;

literal: basiclit               { $$ = $1; }
        ;

basiclit: INTLITERAL            { $$ = new IntLiteral(*$1); }
        | BOOLLITERAL           { $$ = new BoolLiteral(*$1); }
        ;

operandname: IDENTIFIER         { $$ = new Identifier($1); }
            ;

primaryexpr: operand                              { $$ = new OperandExp($1); }
           | primaryexpr arguments                { $$ = new FunctionCall($1, $2); }
           ;

arguments: LPAREN RPAREN                                          { $$ = nullptr; }
         | LPAREN expressionlist RPAREN                           { $$ = $2; }
         | LPAREN expressionlist RCOMMA RPAREN                    { $$ = $2; }
         ;
         

block: LBRACE statementlist RBRACE      { $$ = new Block($2); }
       ;

statementlist: statement SEMICOLON                      { $$ = new LastStmList($1); }
               | statement SEMICOLON statementlist      { $$ = new PairStmList($1, $3);}
               ;

statement: declaration                   { $$ = new DeclStm($1); }
        | block                          { $$ = new BlockStm($1); }
        | ifstatement                    { $$ = $1; }
        | forstatement                   { $$ = $1; }
        | returnstatement                { $$ = $1; }
        | simplestatement                { $$ = $1; }  
        | printstatement                 { $$ = $1; }                 
        ;

simplestatement: expressionstatement     { $$ = $1; }
                | assignment             { $$ = $1; }
                | incdecstatement        { $$ = $1; }
                | emptystatement         { $$ = $1; }
                // | shortvardecl           {puts("shortvardecl");}
                ;

emptystatement: { $$ = new EmptyStm();} ;

expressionstatement: expr { $$ = new ExprStm($1); } ;

assignment: expressionlist assign_op expressionlist { $$ = new AssignmentStm($1, $3, $2); };

assign_op: ASSIGN                                   { $$ = ASSIGN_OP;} 
         | PLUSASSIGN                               { $$ = PLUSASSIGN_OP; } 
         | MINASSIGN                                { $$ = MINASSIGN_OP; } 
         | MULASSIGN                                { $$ = MULASSIGN_OP; } 
         | DIVASSIGN                                { $$ = DIVASSIGN_OP;}            
         ;

incdecstatement: expr INC                           { $$ = new IncDecStm($1, PLUSPLUS); } 
                | expr DEC                          { $$ = new IncDecStm($1, MINMIN); } 
                ;


ifstatement: IF simplestatement SEMICOLON expr block ELSE ifstatement   { $$ = new IfStm($2, $4, $5, nullptr, $7); }
            | IF simplestatement SEMICOLON expr block ELSE block        { $$ = new IfStm($2, $4, $5, $7, nullptr); }
            | IF expr block ELSE ifstatement                            { $$ = new IfStm(nullptr, $2, $3, nullptr, $5); }
            | IF expr block ELSE block                                  { $$ = new IfStm(nullptr, $2, $3, $5, nullptr); }
            | IF expr block                                             { $$ = new IfStm(nullptr, $2, $3, nullptr, nullptr); }
            ;

forstatement: FOR condition block       { $$ = new ForCondStm($2, $3); }
            | FOR forclause block       { $$ = new ForClauseStm($2, $3); }
            | FOR block                 { $$ = new ForStm($2); }
            ;

condition: expr                         { $$ = $1; };

forclause: initstatement SEMICOLON condition SEMICOLON poststatement    { $$ = new ForClause($1, $3, $5); }
         | initstatement SEMICOLON condition RSEMICOL                   { $$ = new ForClause($1, $3, nullptr); }
         | RSEMICOL condition RSEMICOL poststatement                    { $$ = new ForClause(nullptr, $2, $4); }
         ;             

initstatement: simplestatement  { $$ = $1; };

poststatement: simplestatement   { $$ = $1; };

printstatement: PRINT LPAREN expressionlist RPAREN { $$ = new PrintStm($3); }
              ;


returnstatement: RETURN expressionlist   { $$ = new ReturnStm($2); }
                | RETURN                 { $$ = new ReturnStm(nullptr); }
                ;

%%