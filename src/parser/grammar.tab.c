/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "grammar.y"

 // C-DECLARATIONS
 #include <stdio.h>
 #include "../includes.h"

 int yylex(void);
 int yyerror(char *s);

 extern SrcFile* ast;


#line 113 "grammar.tab.c"

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
#line 12 "grammar.y"

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

#line 220 "grammar.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_BOOLEAN = 5,                    /* BOOLEAN  */
  YYSYMBOL_PACKAGE = 6,                    /* PACKAGE  */
  YYSYMBOL_RETURN = 7,                     /* RETURN  */
  YYSYMBOL_VAR = 8,                        /* VAR  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_LPAREN = 11,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 12,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 13,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 14,                    /* RBRACE  */
  YYSYMBOL_PLUS = 15,                      /* PLUS  */
  YYSYMBOL_MIN = 16,                       /* MIN  */
  YYSYMBOL_MUL = 17,                       /* MUL  */
  YYSYMBOL_DIV = 18,                       /* DIV  */
  YYSYMBOL_PLUSASSIGN = 19,                /* PLUSASSIGN  */
  YYSYMBOL_MINASSIGN = 20,                 /* MINASSIGN  */
  YYSYMBOL_MULASSIGN = 21,                 /* MULASSIGN  */
  YYSYMBOL_DIVASSIGN = 22,                 /* DIVASSIGN  */
  YYSYMBOL_AND = 23,                       /* AND  */
  YYSYMBOL_OR = 24,                        /* OR  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_INC = 26,                       /* INC  */
  YYSYMBOL_DEC = 27,                       /* DEC  */
  YYSYMBOL_GT = 28,                        /* GT  */
  YYSYMBOL_GE = 29,                        /* GE  */
  YYSYMBOL_LT = 30,                        /* LT  */
  YYSYMBOL_LE = 31,                        /* LE  */
  YYSYMBOL_EQ = 32,                        /* EQ  */
  YYSYMBOL_NE = 33,                        /* NE  */
  YYSYMBOL_ASSIGN = 34,                    /* ASSIGN  */
  YYSYMBOL_FUNC = 35,                      /* FUNC  */
  YYSYMBOL_NEWLINE = 36,                   /* NEWLINE  */
  YYSYMBOL_IMPORT = 37,                    /* IMPORT  */
  YYSYMBOL_COMMA = 38,                     /* COMMA  */
  YYSYMBOL_ELSE = 39,                      /* ELSE  */
  YYSYMBOL_SHORTVARASSIGN = 40,            /* SHORTVARASSIGN  */
  YYSYMBOL_PRINT = 41,                     /* PRINT  */
  YYSYMBOL_IDENTIFIER = 42,                /* IDENTIFIER  */
  YYSYMBOL_BOOLLITERAL = 43,               /* BOOLLITERAL  */
  YYSYMBOL_INTLITERAL = 44,                /* INTLITERAL  */
  YYSYMBOL_RSEMICOL = 45,                  /* RSEMICOL  */
  YYSYMBOL_RCOMMA = 46,                    /* RCOMMA  */
  YYSYMBOL_UMINUS = 47,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_sourcefile = 49,                /* sourcefile  */
  YYSYMBOL_topleveldeclarations = 50,      /* topleveldeclarations  */
  YYSYMBOL_packageclause = 51,             /* packageclause  */
  YYSYMBOL_packagename = 52,               /* packagename  */
  YYSYMBOL_topleveldecl = 53,              /* topleveldecl  */
  YYSYMBOL_declaration = 54,               /* declaration  */
  YYSYMBOL_vardecl = 55,                   /* vardecl  */
  YYSYMBOL_shortvardecl = 56,              /* shortvardecl  */
  YYSYMBOL_varspec = 57,                   /* varspec  */
  YYSYMBOL_functiondeclaration = 58,       /* functiondeclaration  */
  YYSYMBOL_functionname = 59,              /* functionname  */
  YYSYMBOL_functionbody = 60,              /* functionbody  */
  YYSYMBOL_signature = 61,                 /* signature  */
  YYSYMBOL_type = 62,                      /* type  */
  YYSYMBOL_typename = 63,                  /* typename  */
  YYSYMBOL_result = 64,                    /* result  */
  YYSYMBOL_parameters = 65,                /* parameters  */
  YYSYMBOL_parameterlist = 66,             /* parameterlist  */
  YYSYMBOL_parameterdecl = 67,             /* parameterdecl  */
  YYSYMBOL_expr = 68,                      /* expr  */
  YYSYMBOL_expressionlist = 69,            /* expressionlist  */
  YYSYMBOL_identifierlist = 70,            /* identifierlist  */
  YYSYMBOL_identifier = 71,                /* identifier  */
  YYSYMBOL_unaryexpr = 72,                 /* unaryexpr  */
  YYSYMBOL_unary_op = 73,                  /* unary_op  */
  YYSYMBOL_operand = 74,                   /* operand  */
  YYSYMBOL_literal = 75,                   /* literal  */
  YYSYMBOL_basiclit = 76,                  /* basiclit  */
  YYSYMBOL_operandname = 77,               /* operandname  */
  YYSYMBOL_primaryexpr = 78,               /* primaryexpr  */
  YYSYMBOL_arguments = 79,                 /* arguments  */
  YYSYMBOL_block = 80,                     /* block  */
  YYSYMBOL_statementlist = 81,             /* statementlist  */
  YYSYMBOL_statement = 82,                 /* statement  */
  YYSYMBOL_simplestatement = 83,           /* simplestatement  */
  YYSYMBOL_emptystatement = 84,            /* emptystatement  */
  YYSYMBOL_expressionstatement = 85,       /* expressionstatement  */
  YYSYMBOL_assignment = 86,                /* assignment  */
  YYSYMBOL_assign_op = 87,                 /* assign_op  */
  YYSYMBOL_incdecstatement = 88,           /* incdecstatement  */
  YYSYMBOL_ifstatement = 89,               /* ifstatement  */
  YYSYMBOL_forstatement = 90,              /* forstatement  */
  YYSYMBOL_condition = 91,                 /* condition  */
  YYSYMBOL_forclause = 92,                 /* forclause  */
  YYSYMBOL_initstatement = 93,             /* initstatement  */
  YYSYMBOL_poststatement = 94,             /* poststatement  */
  YYSYMBOL_printstatement = 95,            /* printstatement  */
  YYSYMBOL_returnstatement = 96            /* returnstatement  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   397

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   131,   131,   140,   159,   160,   163,   165,   168,   169,
     172,   176,   177,   180,   183,   184,   185,   188,   190,   192,
     194,   195,   198,   199,   202,   203,   204,   207,   208,   211,
     212,   213,   216,   217,   220,   221,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   239,
     240,   243,   244,   247,   249,   250,   253,   254,   255,   258,
     259,   260,   263,   266,   267,   270,   273,   274,   278,   279,
     280,   284,   287,   288,   291,   292,   293,   294,   295,   296,
     297,   300,   301,   302,   303,   304,   307,   309,   311,   313,
     314,   315,   316,   317,   320,   321,   325,   326,   327,   328,
     329,   332,   333,   334,   337,   339,   340,   341,   344,   346,
     348,   352,   353
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "INTEGER",
  "BOOLEAN", "PACKAGE", "RETURN", "VAR", "IF", "FOR", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "PLUS", "MIN", "MUL", "DIV", "PLUSASSIGN",
  "MINASSIGN", "MULASSIGN", "DIVASSIGN", "AND", "OR", "NOT", "INC", "DEC",
  "GT", "GE", "LT", "LE", "EQ", "NE", "ASSIGN", "FUNC", "NEWLINE",
  "IMPORT", "COMMA", "ELSE", "SHORTVARASSIGN", "PRINT", "IDENTIFIER",
  "BOOLLITERAL", "INTLITERAL", "RSEMICOL", "RCOMMA", "UMINUS", "$accept",
  "sourcefile", "topleveldeclarations", "packageclause", "packagename",
  "topleveldecl", "declaration", "vardecl", "shortvardecl", "varspec",
  "functiondeclaration", "functionname", "functionbody", "signature",
  "type", "typename", "result", "parameters", "parameterlist",
  "parameterdecl", "expr", "expressionlist", "identifierlist",
  "identifier", "unaryexpr", "unary_op", "operand", "literal", "basiclit",
  "operandname", "primaryexpr", "arguments", "block", "statementlist",
  "statement", "simplestatement", "emptystatement", "expressionstatement",
  "assignment", "assign_op", "incdecstatement", "ifstatement",
  "forstatement", "condition", "forclause", "initstatement",
  "poststatement", "printstatement", "returnstatement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-158)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-105)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,   -16,    28,    56,  -158,  -158,  -158,    -1,    12,    22,
    -158,    57,  -158,  -158,  -158,    25,  -158,  -158,    47,    30,
    -158,    63,    -1,    77,  -158,  -158,    91,   184,  -158,    45,
    -158,    25,     6,    70,   105,  -158,    85,    88,   184,  -158,
    -158,  -158,  -158,  -158,  -158,   336,    75,  -158,   184,  -158,
    -158,  -158,  -158,   104,   184,  -158,  -158,    76,  -158,    86,
    -158,    91,   142,  -158,  -158,     6,  -158,  -158,  -158,  -158,
    -158,   288,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,  -158,   154,  -158,    75,  -158,
      81,  -158,   184,   190,   148,   107,   -27,  -158,  -158,   222,
     324,    80,  -158,   108,   122,  -158,  -158,  -158,  -158,  -158,
    -158,  -158,  -158,  -158,    88,  -158,     3,     3,  -158,  -158,
     364,   355,   114,   114,   114,   114,   114,   114,   336,  -158,
      17,  -158,  -158,    75,   244,   132,   184,   266,  -158,  -158,
      70,    70,   136,   184,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,   184,   184,  -158,    62,  -158,   128,   102,   184,   336,
      98,  -158,  -158,   184,   100,    75,    75,  -158,  -158,    18,
     309,   190,     5,  -158,  -158,  -158,   106,  -158,  -158,   190,
    -158,    18,  -158,  -158,  -158
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     7,     6,     1,     3,     0,     0,
       2,     0,     8,    10,     9,     0,    53,    11,     0,    52,
      18,     0,     5,     0,    25,    26,     0,     0,    24,    15,
      22,     0,     0,     0,    21,     4,     0,     0,     0,    56,
      57,    58,    65,    64,    63,    50,    16,    36,     0,    66,
      59,    62,    60,    54,     0,    51,    29,    53,    35,     0,
      33,     0,    86,    17,    19,     0,    28,    20,    27,    12,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,    67,    14,    31,
       0,    34,   112,    86,    86,     0,    65,    74,    85,    50,
       0,     0,    75,     0,     0,    79,    84,    81,    82,    83,
      76,    77,    80,    78,    35,    61,    45,    46,    43,    44,
      48,    47,    41,    42,    39,    40,    37,    38,    49,    68,
       0,    30,    32,   111,    50,     0,     0,    50,   103,   108,
       0,     0,     0,     0,    94,    95,    90,    91,    92,    93,
      89,     0,     0,    71,    72,    69,     0,   100,     0,   104,
       0,   101,   102,     0,     0,    88,    13,    73,    70,     0,
       0,    86,     0,   110,    99,    98,     0,   109,   107,    86,
     106,     0,   105,    97,    96
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,   124,  -158,  -158,  -158,   -60,  -158,  -158,   129,
    -158,  -158,  -158,  -158,   -12,  -158,  -158,   120,  -158,    66,
     -37,   -24,     1,  -158,   112,  -158,  -158,  -158,  -158,  -158,
    -158,  -158,   -33,     8,  -158,   -89,  -158,  -158,  -158,  -158,
    -158,  -157,  -158,   -52,  -158,  -158,   -11,  -158,  -158
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,    10,     3,     5,    11,    12,    13,    98,    17,
      14,    21,    63,    33,    58,    30,    67,    34,    59,    60,
      45,   100,   101,    19,    47,    48,    49,    50,    51,    52,
      53,    87,   102,   103,   104,   105,   106,   107,   108,   151,
     109,   110,   111,   140,   141,   142,   178,   112,   113
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,    71,    97,    46,   135,   139,    29,     8,   179,    18,
      24,    25,   175,   -53,    37,     1,    18,    26,    56,   -53,
      74,    75,    66,    15,   184,    99,     4,    93,     6,   155,
      88,    62,    55,    61,     9,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    57,    91,
     180,    24,    25,   114,    16,    84,   134,   137,    26,     7,
      22,   138,   130,   156,    20,   -86,    61,    16,   133,    92,
       8,    93,    94,    38,    32,    62,    31,    39,    40,    54,
      36,    27,   177,    62,   160,    24,    25,    41,   -24,    28,
     177,    61,    26,   131,    97,    24,    25,    69,    89,   159,
      70,   157,    26,    95,    96,    43,    44,   161,   162,    24,
      25,   172,   173,    84,   -24,    86,    65,    99,   143,   164,
     152,   170,   153,    57,    90,   154,   159,   165,   166,    72,
      73,    74,    75,    28,    99,   158,   174,   176,    84,   163,
     168,   169,    99,   171,    23,   181,    35,    28,   183,    92,
       8,    93,    94,    38,    68,    62,   132,    39,    40,    38,
      85,    62,   167,    39,    40,    38,   129,    41,   182,    39,
      40,     0,     0,    41,     0,     0,     0,     0,     0,    41,
       0,     0,     0,    95,    96,    43,    44,     0,     0,     0,
      96,    43,    44,   136,     0,    38,    42,    43,    44,    39,
      40,    38,     0,     0,     0,    39,    40,     0,     0,    41,
       0,     0,     0,     0,     0,    41,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -87,    42,    43,    44,     0,
       0,     0,    96,    43,    44,   -87,     0,    72,    73,    74,
      75,     0,     0,     0,     0,    76,    77,   -87,   144,   145,
      78,    79,    80,    81,    82,    83,     0,    62,     0,    72,
      73,    74,    75,     0,     0,     0,     0,    76,    77,   -87,
     144,   145,    78,    79,    80,    81,    82,    83,     0,  -104,
       0,    72,    73,    74,    75,     0,     0,     0,     0,    76,
      77,     0,   144,   145,    78,    79,    80,    81,    82,    83,
     115,     0,     0,    72,    73,    74,    75,     0,     0,     0,
       0,    76,    77,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    62,     0,    72,    73,    74,    75,     0,     0,
       0,     0,    76,    77,     0,     0,     0,    78,    79,    80,
      81,    82,    83,   146,   147,   148,   149,     0,     0,     0,
       0,    72,    73,    74,    75,     0,     0,     0,   150,    76,
      77,     0,    84,     0,    78,    79,    80,    81,    82,    83,
      72,    73,    74,    75,     0,     0,     0,     0,    76,    72,
      73,    74,    75,    78,    79,    80,    81,    82,    83,     0,
       0,     0,    78,    79,    80,    81,    82,    83
};

static const yytype_int16 yycheck[] =
{
      33,    38,    62,    27,    93,    94,    18,     8,     3,     8,
       4,     5,   169,    40,    26,     6,    15,    11,    12,    46,
      17,    18,    34,    11,   181,    62,    42,     9,     0,    12,
      54,    13,    31,    32,    35,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    42,    61,
      45,     4,     5,    65,    42,    38,    93,    94,    11,     3,
       3,    94,    86,    46,    42,     3,    65,    42,    92,     7,
       8,     9,    10,    11,    11,    13,    46,    15,    16,    34,
       3,    34,   171,    13,   136,     4,     5,    25,    12,    42,
     179,    90,    11,    12,   154,     4,     5,    12,    12,   136,
      12,   134,    11,    41,    42,    43,    44,   140,   141,     4,
       5,   163,    12,    38,    38,    11,    11,   154,    11,   143,
      40,   158,    14,    42,    38,     3,   163,   151,   152,    15,
      16,    17,    18,    42,   171,     3,   169,   170,    38,     3,
      12,    39,   179,    45,    15,    39,    22,    42,   181,     7,
       8,     9,    10,    11,    34,    13,    90,    15,    16,    11,
      48,    13,   154,    15,    16,    11,    12,    25,   179,    15,
      16,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    41,    42,    43,    44,    -1,    -1,    -1,
      42,    43,    44,    45,    -1,    11,    42,    43,    44,    15,
      16,    11,    -1,    -1,    -1,    15,    16,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    42,    43,    44,    -1,
      -1,    -1,    42,    43,    44,    13,    -1,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    23,    24,     3,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,     3,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      12,    -1,    -1,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    23,    24,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    13,    -1,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    23,    24,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    -1,    -1,    34,    23,
      24,    -1,    38,    -1,    28,    29,    30,    31,    32,    33,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    15,
      16,    17,    18,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    49,    51,    42,    52,     0,     3,     8,    35,
      50,    53,    54,    55,    58,    11,    42,    57,    70,    71,
      42,    59,     3,    57,     4,     5,    11,    34,    42,    62,
      63,    46,    11,    61,    65,    50,     3,    62,    11,    15,
      16,    25,    42,    43,    44,    68,    69,    72,    73,    74,
      75,    76,    77,    78,    34,    70,    12,    42,    62,    66,
      67,    70,    13,    60,    80,    11,    62,    64,    65,    12,
      12,    68,    15,    16,    17,    18,    23,    24,    28,    29,
      30,    31,    32,    33,    38,    72,    11,    79,    69,    12,
      38,    62,     7,     9,    10,    41,    42,    54,    56,    68,
      69,    70,    80,    81,    82,    83,    84,    85,    86,    88,
      89,    90,    95,    96,    62,    12,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    12,
      69,    12,    67,    69,    68,    83,    45,    68,    80,    83,
      91,    92,    93,    11,    26,    27,    19,    20,    21,    22,
      34,    87,    40,    14,     3,    12,    46,    80,     3,    68,
      91,    80,    80,     3,    69,    69,    69,    81,    12,    39,
      68,    45,    91,    12,    80,    89,    80,    83,    94,     3,
      45,    39,    94,    80,    89
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    50,    50,    51,    52,    53,    53,
      54,    55,    55,    56,    57,    57,    57,    58,    59,    60,
      61,    61,    62,    62,    63,    63,    63,    64,    64,    65,
      65,    65,    66,    66,    67,    67,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    69,
      69,    70,    70,    71,    72,    72,    73,    73,    73,    74,
      74,    74,    75,    76,    76,    77,    78,    78,    79,    79,
      79,    80,    81,    81,    82,    82,    82,    82,    82,    82,
      82,    83,    83,    83,    83,    83,    84,    85,    86,    87,
      87,    87,    87,    87,    88,    88,    89,    89,    89,    89,
      89,    90,    90,    90,    91,    92,    92,    92,    93,    94,
      95,    96,    96
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     3,     2,     2,     1,     1,     1,
       1,     2,     5,     3,     4,     2,     3,     4,     1,     1,
       2,     1,     1,     3,     1,     1,     1,     1,     1,     2,
       4,     3,     3,     1,     2,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     2,     2,     3,
       4,     3,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     3,     1,
       1,     1,     1,     1,     2,     2,     7,     7,     5,     5,
       3,     3,     3,     2,     1,     5,     4,     4,     1,     1,
       4,     2,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* sourcefile: packageclause SEMICOLON topleveldeclarations  */
#line 131 "grammar.y"
                                                                        {(yyval.srcfile) = new SrcFile((yyvsp[-2].packageclause), nullptr, (yyvsp[0].decllist));
                                                                        ast = (yyval.srcfile);
                                                                        }
#line 1477 "grammar.tab.c"
    break;

  case 3: /* sourcefile: packageclause SEMICOLON  */
#line 140 "grammar.y"
                                                                        {(yyval.srcfile) = new SrcFile((yyvsp[-1].packageclause), nullptr, nullptr);
                                                                        ast = (yyval.srcfile);
                                                                        }
#line 1485 "grammar.tab.c"
    break;

  case 4: /* topleveldeclarations: topleveldecl SEMICOLON topleveldeclarations  */
#line 159 "grammar.y"
                                                                   {(yyval.decllist) = new PairDeclList((yyvsp[-2].toplvldecl), (yyvsp[0].decllist));}
#line 1491 "grammar.tab.c"
    break;

  case 5: /* topleveldeclarations: topleveldecl SEMICOLON  */
#line 160 "grammar.y"
                                                                   {(yyval.decllist) = new LastDeclList((yyvsp[-1].toplvldecl));}
#line 1497 "grammar.tab.c"
    break;

  case 6: /* packageclause: PACKAGE packagename  */
#line 163 "grammar.y"
                                    {(yyval.packageclause) = new PackageClause((yyvsp[0].identifier));}
#line 1503 "grammar.tab.c"
    break;

  case 7: /* packagename: IDENTIFIER  */
#line 165 "grammar.y"
                        {(yyval.identifier) = new Identifier((yyvsp[0].id));}
#line 1509 "grammar.tab.c"
    break;

  case 8: /* topleveldecl: declaration  */
#line 168 "grammar.y"
                                   {(yyval.toplvldecl) = (yyvsp[0].toplvldecl); }
#line 1515 "grammar.tab.c"
    break;

  case 9: /* topleveldecl: functiondeclaration  */
#line 169 "grammar.y"
                                   {(yyval.toplvldecl) = (yyvsp[0].toplvldecl); }
#line 1521 "grammar.tab.c"
    break;

  case 10: /* declaration: vardecl  */
#line 172 "grammar.y"
                         {(yyval.toplvldecl) = (yyvsp[0].toplvldecl); }
#line 1527 "grammar.tab.c"
    break;

  case 11: /* vardecl: VAR varspec  */
#line 176 "grammar.y"
                                                            {(yyval.toplvldecl) = new VarDecl((yyvsp[0].varspec)); }
#line 1533 "grammar.tab.c"
    break;

  case 12: /* vardecl: VAR LPAREN varspec SEMICOLON RPAREN  */
#line 177 "grammar.y"
                                                            {(yyval.toplvldecl) = new VarDecl((yyvsp[-2].varspec)); }
#line 1539 "grammar.tab.c"
    break;

  case 13: /* shortvardecl: identifierlist SHORTVARASSIGN expressionlist  */
#line 180 "grammar.y"
                                                            {puts("identifierlist SHORTVARASSIGN expressionlist"); }
#line 1545 "grammar.tab.c"
    break;

  case 14: /* varspec: identifierlist type ASSIGN expressionlist  */
#line 183 "grammar.y"
                                                        {(yyval.varspec) = new VarSpec((yyvsp[-3].identifierlist), (yyvsp[-2].type), (yyvsp[0].explist)); }
#line 1551 "grammar.tab.c"
    break;

  case 15: /* varspec: identifierlist type  */
#line 184 "grammar.y"
                                                        {(yyval.varspec) = new VarSpec((yyvsp[-1].identifierlist), (yyvsp[0].type), nullptr);}
#line 1557 "grammar.tab.c"
    break;

  case 16: /* varspec: identifierlist ASSIGN expressionlist  */
#line 185 "grammar.y"
                                                        {(yyval.varspec) = new VarSpec((yyvsp[-2].identifierlist), nullptr, (yyvsp[0].explist)); }
#line 1563 "grammar.tab.c"
    break;

  case 17: /* functiondeclaration: FUNC functionname signature functionbody  */
#line 188 "grammar.y"
                                                              {(yyval.toplvldecl) = new FunctionDecl((yyvsp[-2].identifier), (yyvsp[-1].signature), (yyvsp[0].block)); }
#line 1569 "grammar.tab.c"
    break;

  case 18: /* functionname: IDENTIFIER  */
#line 190 "grammar.y"
                          {(yyval.identifier) = new Identifier((yyvsp[0].id)); }
#line 1575 "grammar.tab.c"
    break;

  case 19: /* functionbody: block  */
#line 192 "grammar.y"
                     {(yyval.block) = (yyvsp[0].block); }
#line 1581 "grammar.tab.c"
    break;

  case 20: /* signature: parameters result  */
#line 194 "grammar.y"
                                { (yyval.signature) = new Signature((yyvsp[-1].paramlist), (yyvsp[0].result)); }
#line 1587 "grammar.tab.c"
    break;

  case 21: /* signature: parameters  */
#line 195 "grammar.y"
                                { (yyval.signature) = new Signature((yyvsp[0].paramlist), nullptr); }
#line 1593 "grammar.tab.c"
    break;

  case 22: /* type: typename  */
#line 198 "grammar.y"
                                { (yyval.type) = (yyvsp[0].type); }
#line 1599 "grammar.tab.c"
    break;

  case 23: /* type: LPAREN type RPAREN  */
#line 199 "grammar.y"
                                { (yyval.type) = (yyvsp[-1].type); }
#line 1605 "grammar.tab.c"
    break;

  case 24: /* typename: IDENTIFIER  */
#line 202 "grammar.y"
                                { puts("IDENTIFIER"); }
#line 1611 "grammar.tab.c"
    break;

  case 25: /* typename: INTEGER  */
#line 203 "grammar.y"
                                { (yyval.type) = new IntegerType(); }
#line 1617 "grammar.tab.c"
    break;

  case 26: /* typename: BOOLEAN  */
#line 204 "grammar.y"
                                { (yyval.type) = new BooleanType(); }
#line 1623 "grammar.tab.c"
    break;

  case 27: /* result: parameters  */
#line 207 "grammar.y"
                                { (yyval.result) = new ParametersResult((yyvsp[0].paramlist)); }
#line 1629 "grammar.tab.c"
    break;

  case 28: /* result: type  */
#line 208 "grammar.y"
                                { (yyval.result) = new TypeResult((yyvsp[0].type)); }
#line 1635 "grammar.tab.c"
    break;

  case 29: /* parameters: LPAREN RPAREN  */
#line 211 "grammar.y"
                                                  { (yyval.paramlist) = nullptr; }
#line 1641 "grammar.tab.c"
    break;

  case 30: /* parameters: LPAREN parameterlist COMMA RPAREN  */
#line 212 "grammar.y"
                                                  { (yyval.paramlist) = (yyvsp[-2].paramlist); }
#line 1647 "grammar.tab.c"
    break;

  case 31: /* parameters: LPAREN parameterlist RPAREN  */
#line 213 "grammar.y"
                                                  { (yyval.paramlist) = (yyvsp[-1].paramlist); }
#line 1653 "grammar.tab.c"
    break;

  case 32: /* parameterlist: parameterlist COMMA parameterdecl  */
#line 216 "grammar.y"
                                                     { (yyval.paramlist) = new PairParamList((yyvsp[0].paramdecl), (yyvsp[-2].paramlist)); }
#line 1659 "grammar.tab.c"
    break;

  case 33: /* parameterlist: parameterdecl  */
#line 217 "grammar.y"
                                                     { (yyval.paramlist) = new LastParamList((yyvsp[0].paramdecl)); }
#line 1665 "grammar.tab.c"
    break;

  case 34: /* parameterdecl: identifierlist type  */
#line 220 "grammar.y"
                                                { (yyval.paramdecl) = new ParameterDecl((yyvsp[0].type), (yyvsp[-1].identifierlist)); }
#line 1671 "grammar.tab.c"
    break;

  case 35: /* parameterdecl: type  */
#line 221 "grammar.y"
                                                { (yyval.paramdecl) = new ParameterDecl((yyvsp[0].type), nullptr); }
#line 1677 "grammar.tab.c"
    break;

  case 36: /* expr: unaryexpr  */
#line 224 "grammar.y"
                                { (yyval.exp) = (yyvsp[0].exp); }
#line 1683 "grammar.tab.c"
    break;

  case 37: /* expr: expr EQ expr  */
#line 225 "grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), EQ_BIN); }
#line 1689 "grammar.tab.c"
    break;

  case 38: /* expr: expr NE expr  */
#line 226 "grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), NE_BIN); }
#line 1695 "grammar.tab.c"
    break;

  case 39: /* expr: expr LT expr  */
#line 227 "grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), LT_BIN); }
#line 1701 "grammar.tab.c"
    break;

  case 40: /* expr: expr LE expr  */
#line 228 "grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), LE_BIN); }
#line 1707 "grammar.tab.c"
    break;

  case 41: /* expr: expr GT expr  */
#line 229 "grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), GT_BIN); }
#line 1713 "grammar.tab.c"
    break;

  case 42: /* expr: expr GE expr  */
#line 230 "grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), GE_BIN); }
#line 1719 "grammar.tab.c"
    break;

  case 43: /* expr: expr MUL expr  */
#line 231 "grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), MUL_BIN); }
#line 1725 "grammar.tab.c"
    break;

  case 44: /* expr: expr DIV expr  */
#line 232 "grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), DIV_BIN); }
#line 1731 "grammar.tab.c"
    break;

  case 45: /* expr: expr PLUS expr  */
#line 233 "grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), PLUS_BIN); }
#line 1737 "grammar.tab.c"
    break;

  case 46: /* expr: expr MIN expr  */
#line 234 "grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), MIN_BIN); }
#line 1743 "grammar.tab.c"
    break;

  case 47: /* expr: expr OR expr  */
#line 235 "grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), OR_BIN); }
#line 1749 "grammar.tab.c"
    break;

  case 48: /* expr: expr AND expr  */
#line 236 "grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), AND_BIN); }
#line 1755 "grammar.tab.c"
    break;

  case 49: /* expressionlist: expressionlist COMMA expr  */
#line 239 "grammar.y"
                                                { (yyval.explist) = new PairExpList((yyvsp[0].exp), (yyvsp[-2].explist)); }
#line 1761 "grammar.tab.c"
    break;

  case 50: /* expressionlist: expr  */
#line 240 "grammar.y"
                                                { (yyval.explist) = new LastExpList((yyvsp[0].exp)); }
#line 1767 "grammar.tab.c"
    break;

  case 51: /* identifierlist: identifier RCOMMA identifierlist  */
#line 243 "grammar.y"
                                                         { (yyval.identifierlist) = new PairIdentifierList((yyvsp[-2].identifier), (yyvsp[0].identifierlist)); }
#line 1773 "grammar.tab.c"
    break;

  case 52: /* identifierlist: identifier  */
#line 244 "grammar.y"
                                                         { (yyval.identifierlist) = new LastIdentifierList((yyvsp[0].identifier)); }
#line 1779 "grammar.tab.c"
    break;

  case 53: /* identifier: IDENTIFIER  */
#line 247 "grammar.y"
                               { (yyval.identifier) = new Identifier((yyvsp[0].id)); }
#line 1785 "grammar.tab.c"
    break;

  case 54: /* unaryexpr: primaryexpr  */
#line 249 "grammar.y"
                               { (yyval.exp) = (yyvsp[0].exp); }
#line 1791 "grammar.tab.c"
    break;

  case 55: /* unaryexpr: unary_op unaryexpr  */
#line 250 "grammar.y"
                               { (yyval.exp) = new UnaryExp((yyvsp[0].exp), (yyvsp[-1].unaryoperator)); }
#line 1797 "grammar.tab.c"
    break;

  case 56: /* unary_op: PLUS  */
#line 253 "grammar.y"
                                { (yyval.unaryoperator) = PLUS_UNARY; }
#line 1803 "grammar.tab.c"
    break;

  case 57: /* unary_op: MIN  */
#line 254 "grammar.y"
                                { (yyval.unaryoperator) = MIN_UNARY; }
#line 1809 "grammar.tab.c"
    break;

  case 58: /* unary_op: NOT  */
#line 255 "grammar.y"
                                { (yyval.unaryoperator) = NOT_UNARY; }
#line 1815 "grammar.tab.c"
    break;

  case 59: /* operand: literal  */
#line 258 "grammar.y"
                                { (yyval.operand) = new LiteralOperand((yyvsp[0].literal)); }
#line 1821 "grammar.tab.c"
    break;

  case 60: /* operand: operandname  */
#line 259 "grammar.y"
                                { (yyval.operand) = new VariableOperand((yyvsp[0].identifier)); }
#line 1827 "grammar.tab.c"
    break;

  case 61: /* operand: LPAREN expr RPAREN  */
#line 260 "grammar.y"
                                { (yyval.operand) = new ExprOperand((yyvsp[-1].exp)); }
#line 1833 "grammar.tab.c"
    break;

  case 62: /* literal: basiclit  */
#line 263 "grammar.y"
                                { (yyval.literal) = (yyvsp[0].literal); }
#line 1839 "grammar.tab.c"
    break;

  case 63: /* basiclit: INTLITERAL  */
#line 266 "grammar.y"
                                { (yyval.literal) = new IntLiteral(*(yyvsp[0].intlit)); }
#line 1845 "grammar.tab.c"
    break;

  case 64: /* basiclit: BOOLLITERAL  */
#line 267 "grammar.y"
                                { (yyval.literal) = new BoolLiteral(*(yyvsp[0].boollit)); }
#line 1851 "grammar.tab.c"
    break;

  case 65: /* operandname: IDENTIFIER  */
#line 270 "grammar.y"
                                { (yyval.identifier) = new Identifier((yyvsp[0].id)); }
#line 1857 "grammar.tab.c"
    break;

  case 66: /* primaryexpr: operand  */
#line 273 "grammar.y"
                                                  { (yyval.exp) = new OperandExp((yyvsp[0].operand)); }
#line 1863 "grammar.tab.c"
    break;

  case 67: /* primaryexpr: primaryexpr arguments  */
#line 274 "grammar.y"
                                                  { (yyval.exp) = new FunctionCall((yyvsp[-1].exp), (yyvsp[0].explist)); }
#line 1869 "grammar.tab.c"
    break;

  case 68: /* arguments: LPAREN RPAREN  */
#line 278 "grammar.y"
                                                                  { (yyval.explist) = nullptr; }
#line 1875 "grammar.tab.c"
    break;

  case 69: /* arguments: LPAREN expressionlist RPAREN  */
#line 279 "grammar.y"
                                                                  { (yyval.explist) = (yyvsp[-1].explist); }
#line 1881 "grammar.tab.c"
    break;

  case 70: /* arguments: LPAREN expressionlist RCOMMA RPAREN  */
#line 280 "grammar.y"
                                                                  { (yyval.explist) = (yyvsp[-2].explist); }
#line 1887 "grammar.tab.c"
    break;

  case 71: /* block: LBRACE statementlist RBRACE  */
#line 284 "grammar.y"
                                        { (yyval.block) = new Block((yyvsp[-1].stmlist)); }
#line 1893 "grammar.tab.c"
    break;

  case 72: /* statementlist: statement SEMICOLON  */
#line 287 "grammar.y"
                                                        { (yyval.stmlist) = new LastStmList((yyvsp[-1].stm)); }
#line 1899 "grammar.tab.c"
    break;

  case 73: /* statementlist: statement SEMICOLON statementlist  */
#line 288 "grammar.y"
                                                        { (yyval.stmlist) = new PairStmList((yyvsp[-2].stm), (yyvsp[0].stmlist));}
#line 1905 "grammar.tab.c"
    break;

  case 74: /* statement: declaration  */
#line 291 "grammar.y"
                                         { (yyval.stm) = new DeclStm((yyvsp[0].toplvldecl)); }
#line 1911 "grammar.tab.c"
    break;

  case 75: /* statement: block  */
#line 292 "grammar.y"
                                         { (yyval.stm) = new BlockStm((yyvsp[0].block)); }
#line 1917 "grammar.tab.c"
    break;

  case 76: /* statement: ifstatement  */
#line 293 "grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1923 "grammar.tab.c"
    break;

  case 77: /* statement: forstatement  */
#line 294 "grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1929 "grammar.tab.c"
    break;

  case 78: /* statement: returnstatement  */
#line 295 "grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1935 "grammar.tab.c"
    break;

  case 79: /* statement: simplestatement  */
#line 296 "grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1941 "grammar.tab.c"
    break;

  case 80: /* statement: printstatement  */
#line 297 "grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1947 "grammar.tab.c"
    break;

  case 81: /* simplestatement: expressionstatement  */
#line 300 "grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1953 "grammar.tab.c"
    break;

  case 82: /* simplestatement: assignment  */
#line 301 "grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1959 "grammar.tab.c"
    break;

  case 83: /* simplestatement: incdecstatement  */
#line 302 "grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1965 "grammar.tab.c"
    break;

  case 84: /* simplestatement: emptystatement  */
#line 303 "grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1971 "grammar.tab.c"
    break;

  case 85: /* simplestatement: shortvardecl  */
#line 304 "grammar.y"
                                         {puts("shortvardecl");}
#line 1977 "grammar.tab.c"
    break;

  case 86: /* emptystatement: %empty  */
#line 307 "grammar.y"
                { (yyval.stm) = new EmptyStm();}
#line 1983 "grammar.tab.c"
    break;

  case 87: /* expressionstatement: expr  */
#line 309 "grammar.y"
                          { (yyval.stm) = new ExprStm((yyvsp[0].exp)); }
#line 1989 "grammar.tab.c"
    break;

  case 88: /* assignment: expressionlist assign_op expressionlist  */
#line 311 "grammar.y"
                                                    { (yyval.stm) = new AssignmentStm((yyvsp[-2].explist), (yyvsp[0].explist), (yyvsp[-1].assignoperator)); }
#line 1995 "grammar.tab.c"
    break;

  case 89: /* assign_op: ASSIGN  */
#line 313 "grammar.y"
                                                    { (yyval.assignoperator) = ASSIGN_OP;}
#line 2001 "grammar.tab.c"
    break;

  case 90: /* assign_op: PLUSASSIGN  */
#line 314 "grammar.y"
                                                    { (yyval.assignoperator) = PLUSASSIGN_OP; }
#line 2007 "grammar.tab.c"
    break;

  case 91: /* assign_op: MINASSIGN  */
#line 315 "grammar.y"
                                                    { (yyval.assignoperator) = MINASSIGN_OP; }
#line 2013 "grammar.tab.c"
    break;

  case 92: /* assign_op: MULASSIGN  */
#line 316 "grammar.y"
                                                    { (yyval.assignoperator) = MULASSIGN_OP; }
#line 2019 "grammar.tab.c"
    break;

  case 93: /* assign_op: DIVASSIGN  */
#line 317 "grammar.y"
                                                    { (yyval.assignoperator) = DIVASSIGN_OP;}
#line 2025 "grammar.tab.c"
    break;

  case 94: /* incdecstatement: expr INC  */
#line 320 "grammar.y"
                                                    { (yyval.stm) = new IncDecStm((yyvsp[-1].exp), PLUSPLUS); }
#line 2031 "grammar.tab.c"
    break;

  case 95: /* incdecstatement: expr DEC  */
#line 321 "grammar.y"
                                                    { (yyval.stm) = new IncDecStm((yyvsp[-1].exp), MINMIN); }
#line 2037 "grammar.tab.c"
    break;

  case 96: /* ifstatement: IF simplestatement SEMICOLON expr block ELSE ifstatement  */
#line 325 "grammar.y"
                                                                        { (yyval.stm) = new IfStm((yyvsp[-5].stm), (yyvsp[-3].exp), (yyvsp[-2].block), nullptr, (yyvsp[0].stm)); }
#line 2043 "grammar.tab.c"
    break;

  case 97: /* ifstatement: IF simplestatement SEMICOLON expr block ELSE block  */
#line 326 "grammar.y"
                                                                        { (yyval.stm) = new IfStm((yyvsp[-5].stm), (yyvsp[-3].exp), (yyvsp[-2].block), (yyvsp[0].block), nullptr); }
#line 2049 "grammar.tab.c"
    break;

  case 98: /* ifstatement: IF expr block ELSE ifstatement  */
#line 327 "grammar.y"
                                                                        { (yyval.stm) = new IfStm(nullptr, (yyvsp[-3].exp), (yyvsp[-2].block), nullptr, (yyvsp[0].stm)); }
#line 2055 "grammar.tab.c"
    break;

  case 99: /* ifstatement: IF expr block ELSE block  */
#line 328 "grammar.y"
                                                                        { (yyval.stm) = new IfStm(nullptr, (yyvsp[-3].exp), (yyvsp[-2].block), (yyvsp[0].block), nullptr); }
#line 2061 "grammar.tab.c"
    break;

  case 100: /* ifstatement: IF expr block  */
#line 329 "grammar.y"
                                                                        { (yyval.stm) = new IfStm(nullptr, (yyvsp[-1].exp), (yyvsp[0].block), nullptr, nullptr); }
#line 2067 "grammar.tab.c"
    break;

  case 101: /* forstatement: FOR condition block  */
#line 332 "grammar.y"
                                        { (yyval.stm) = new ForCondStm((yyvsp[-1].exp), (yyvsp[0].block)); }
#line 2073 "grammar.tab.c"
    break;

  case 102: /* forstatement: FOR forclause block  */
#line 333 "grammar.y"
                                        { (yyval.stm) = new ForClauseStm((yyvsp[-1].forclause), (yyvsp[0].block)); }
#line 2079 "grammar.tab.c"
    break;

  case 103: /* forstatement: FOR block  */
#line 334 "grammar.y"
                                        { (yyval.stm) = new ForStm((yyvsp[0].block)); }
#line 2085 "grammar.tab.c"
    break;

  case 104: /* condition: expr  */
#line 337 "grammar.y"
                                        { (yyval.exp) = (yyvsp[0].exp); }
#line 2091 "grammar.tab.c"
    break;

  case 105: /* forclause: initstatement SEMICOLON condition SEMICOLON poststatement  */
#line 339 "grammar.y"
                                                                        { (yyval.forclause) = new ForClause((yyvsp[-4].stm), (yyvsp[-2].exp), (yyvsp[0].stm)); }
#line 2097 "grammar.tab.c"
    break;

  case 106: /* forclause: initstatement SEMICOLON condition RSEMICOL  */
#line 340 "grammar.y"
                                                                        { (yyval.forclause) = new ForClause((yyvsp[-3].stm), (yyvsp[-1].exp), nullptr); }
#line 2103 "grammar.tab.c"
    break;

  case 107: /* forclause: RSEMICOL condition RSEMICOL poststatement  */
#line 341 "grammar.y"
                                                                        { (yyval.forclause) = new ForClause(nullptr, (yyvsp[-2].exp), (yyvsp[0].stm)); }
#line 2109 "grammar.tab.c"
    break;

  case 108: /* initstatement: simplestatement  */
#line 344 "grammar.y"
                                { (yyval.stm) = (yyvsp[0].stm); }
#line 2115 "grammar.tab.c"
    break;

  case 109: /* poststatement: simplestatement  */
#line 346 "grammar.y"
                                 { (yyval.stm) = (yyvsp[0].stm); }
#line 2121 "grammar.tab.c"
    break;

  case 110: /* printstatement: PRINT LPAREN expressionlist RPAREN  */
#line 348 "grammar.y"
                                                   { (yyval.stm) = new PrintStm((yyvsp[-1].explist)); }
#line 2127 "grammar.tab.c"
    break;

  case 111: /* returnstatement: RETURN expressionlist  */
#line 352 "grammar.y"
                                         { (yyval.stm) = new ReturnStm((yyvsp[0].explist)); }
#line 2133 "grammar.tab.c"
    break;

  case 112: /* returnstatement: RETURN  */
#line 353 "grammar.y"
                                         { (yyval.stm) = new ReturnStm(nullptr); }
#line 2139 "grammar.tab.c"
    break;


#line 2143 "grammar.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 356 "grammar.y"
