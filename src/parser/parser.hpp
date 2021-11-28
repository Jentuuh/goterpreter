/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "./parser/grammar.y"

 // C-DECLARATIONS
 #include <stdio.h>
 #include "../includes.h"

 int yylex(void);
 int yyerror(char *s);

 extern SrcFile* ast;


#line 61 "./parser/parser.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SEMICOLON = 258,               /* SEMICOLON  */
    INTEGER = 259,                 /* INTEGER  */
    BOOLEAN = 260,                 /* BOOLEAN  */
    PACKAGE = 261,                 /* PACKAGE  */
    RETURN = 262,                  /* RETURN  */
    VAR = 263,                     /* VAR  */
    IF = 264,                      /* IF  */
    FOR = 265,                     /* FOR  */
    LPAREN = 266,                  /* LPAREN  */
    RPAREN = 267,                  /* RPAREN  */
    LBRACE = 268,                  /* LBRACE  */
    RBRACE = 269,                  /* RBRACE  */
    PLUS = 270,                    /* PLUS  */
    MIN = 271,                     /* MIN  */
    MUL = 272,                     /* MUL  */
    DIV = 273,                     /* DIV  */
    PLUSASSIGN = 274,              /* PLUSASSIGN  */
    MINASSIGN = 275,               /* MINASSIGN  */
    MULASSIGN = 276,               /* MULASSIGN  */
    DIVASSIGN = 277,               /* DIVASSIGN  */
    AND = 278,                     /* AND  */
    OR = 279,                      /* OR  */
    NOT = 280,                     /* NOT  */
    INC = 281,                     /* INC  */
    DEC = 282,                     /* DEC  */
    GT = 283,                      /* GT  */
    GE = 284,                      /* GE  */
    LT = 285,                      /* LT  */
    LE = 286,                      /* LE  */
    EQ = 287,                      /* EQ  */
    NE = 288,                      /* NE  */
    ASSIGN = 289,                  /* ASSIGN  */
    FUNC = 290,                    /* FUNC  */
    NEWLINE = 291,                 /* NEWLINE  */
    IMPORT = 292,                  /* IMPORT  */
    COMMA = 293,                   /* COMMA  */
    ELSE = 294,                    /* ELSE  */
    SHORTVARASSIGN = 295,          /* SHORTVARASSIGN  */
    PRINT = 296,                   /* PRINT  */
    IDENTIFIER = 297,              /* IDENTIFIER  */
    BOOLLITERAL = 298,             /* BOOLLITERAL  */
    INTLITERAL = 299,              /* INTLITERAL  */
    RSEMICOL = 300,                /* RSEMICOL  */
    RCOMMA = 301,                  /* RCOMMA  */
    UMINUS = 302                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "./parser/grammar.y"

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

#line 168 "./parser/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_PARSER_HPP_INCLUDED  */
