%{
 // C-DECLARATIONS
 #include <stdio.h>
 #include "../ast/srcfile/srcfile.h"

 #include "../ast/block/block.h"
 
 #include "../ast/expressions/explist.h"
 #include "../ast/expressions/exp.h"

 #include "../ast/identifiers/identifier.h"

 #include "../ast/declarations/decllist.h"
 #include "../ast/declarations/decl.h"
 #include "../ast/declarations/varspec.h"

 #include "../ast/functions/signature.h"
 #include "../ast/functions/result.h"

 #include "../ast/literals/literal.h"

 #include "../ast/statements/stmlist.h"
 #include "../ast/statements/stm.h"
 #include "../ast/statements/forclause.h"

 #include "../ast/packages/packageclause.h"

 #include "../ast/types/type.h"

 #include "../ast/literals/literal.h"
 #include "../ast/symboltable.h"

 int yylex(void);
 int yyerror(char *s);

 SrcFile * ast;

%}
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
        FunctionDecl* funcdecl;
        Signature* signature;
        Result* result;

        Literal* literal;

        ParameterList* paramlist;
        ParameterDecl* paramdecl;

        Type* type; 

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
    SHORTVARASSIGN

%token <id> IDENTIFIER
%token <boollit> BOOLLITERAL
%token <intlit> INTLITERAL
%type <identifier> packagename
%type <srcfile> sourcefile 
%type <decllist> topleveldeclarations
%type <packageclause> packageclause
%type <identifierlist> identifierlist
%type <block> block

%type <toplvldecl> topleveldecl
%type <decl> declaration
%type <decl> vardecl
%type <varspec> varspec

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
%type <simplestm> initstatement
%type <simplestm> poststatement
%type <stm> emptystatement
%type <stm> expressionstatement
%type <stm> forstatement
%type <stm> assignment
%type <stm> ifstatement
%type <stm> incdecstatement
%type <stm> returnstatement
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

%type <type> type
%type <type> typename

%type <paramlist> parameters
%type <paramlist> parameterlist
%type <paramdecl> parameterdecl

%left OR
%left AND
%left EQ NE GT GE LT LE
%left PLUS MIN
%left MUL DIV
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

declaration: vardecl     {$$ = new VarDecl(); }
           ;

vardecl: VAR varspec                                        {$$ = new VarDecl($2); }
        | VAR LPAREN varspec SEMICOLON RPAREN               {$$ = new VarDecl($3); }
        ;

shortvardecl: identifierlist SHORTVARASSIGN expressionlist  {puts("identifierlist SHORTVARASSIGN expressionlist"); }
            ;

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

typename: IDENTIFIER            { puts("IDENTIFIER"); }
        | INTEGER               { $$ = new IntegerType(); } 
        | BOOLEAN               { $$ = new BooleanType(); }
        ;

result: parameters              { $$ = new ParametersResult($1); }
        | type                  { $$ = new TypeResult($1); }
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
    | expr EQ expr              { $$ = new BinaryExp($1, $3, BinaryOperator.EQ); }
    | expr NE expr              { $$ = new BinaryExp($1, $3, BinaryOperator.NE); }
    | expr LT expr              { $$ = new BinaryExp($1, $3, BinaryOperator.LT); }
    | expr LE expr              { $$ = new BinaryExp($1, $3, BinaryOperator.LE); } 
    | expr GT expr              { $$ = new BinaryExp($1, $3, BinaryOperator.GT); } 
    | expr GE expr              { $$ = new BinaryExp($1, $3, BinaryOperator.GE); } 
    | expr MUL expr             { $$ = new BinaryExp($1, $3, BinaryOperator.MUL); }
    | expr DIV expr             { $$ = new BinaryExp($1, $3, BinaryOperator.DIV); }
    | expr PLUS expr            { $$ = new BinaryExp($1, $3, BinaryOperator.PLUS); }
    | expr MIN expr             { $$ = new BinaryExp($1, $3, BinaryOperator.MIN); }
    | expr OR expr              { $$ = new BinaryExp($1, $3, BinaryOperator.OR); }
    | expr AND expr             { $$ = new BinaryExp($1, $3, BinaryOperator.AND); }
    ;

expressionlist: expressionlist COMMA expr       { $$ = new PairExpList($3, $1); }
              | expr                            { $$ = new LastExpList($1); }
              ;

identifierlist: IDENTIFIER COMMA identifierlist         { $$ = new PairIdentifierList($1, $3); }
              | IDENTIFIER                              { $$ = new LastIdentifierList($1); }
              ;

unaryexpr: primaryexpr         { $$ = $1; }
          | unary_op unaryexpr { $$ = new UnaryExpr($2, $1); }
          ;

unary_op: PLUS                  { $$ = UnaryOperator.PLUS; }
        | UMINUS                { $$ = UnaryOperator.MIN; }
        | NOT                   { $$ = UnaryOperator.NOT; }
        ;

operand: literal                { $$ = new LiteralOperand($1); }
        | operandname           { $$ = new VariableOperand($1); }
        | LPAREN expr RPAREN    { $$ = new ExprOperand($2); }
        ;

literal: basiclit               { $$ = $1; }
        ;

basiclit: INTLITERAL            { $$ = new IntLiteral($1); }
        | BOOLLITERAL           { $$ = new BoolLiteral($1); }
        ;

operandname: IDENTIFIER         { $$ = new Identifier($1); }
            ;

primaryexpr: operand            { $$ = new PrimaryExp($1); }
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
        ;

simplestatement: expressionstatement     { $$ = $1; }
                | assignment             { $$ = $1; }
                | incdecstatement        { $$ = $1; }
                | emptystatement         { $$ = $1; }
                | shortvardecl           {puts("shortvardecl");}
                ;

emptystatement: { $$ = new EmptyStm();} ;

expressionstatement: expr { $$ = new ExprStm($1); } ;

assignment: expressionlist assign_op expressionlist { $$ = new AssignmentStm($1, $3, $2); };

assign_op: ASSIGN                                   { $$ = AssignOperator.ASSIGN;} 
         | PLUSASSIGN                               { $$ = AssignOperator.PLUSASSIGN; } 
         | MINASSIGN                                { $$ = AssignOperator.MINASSIGN; } 
         | MULASSIGN                                { $$ = AssignOperator.MULASSIGN; } 
         | DIVASSIGN                                { $$ = AssignOperator.DIVASSIGN;}            
         ;

incdecstatement: expr INC                           { $$ = new IncDecStm($1, IncDecOperator.PLUSPLUS); } 
                | expr DEC                          { $$ = new IncDecStm($1, IncDecOperator.MINMIN); } 
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
         ;             

initstatement: simplestatement  { $$ = $1; };

poststatement: simplestatement   { $$ = $1; };

returnstatement: RETURN expressionlist   { $$ = new ReturnStm($2); }
                | RETURN                 { $$ = new ReturnStm(nullptr); }
                ;

%%