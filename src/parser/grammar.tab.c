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




/* First part of user prologue.  */
#line 1 "grammar.y"

 // C-DECLARATIONS
 #include <stdio.h>
 int yylex(void);
 int yyerror(char *s);

#line 78 "grammar.tab.c"

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
    IDENTIFIER = 259,              /* IDENTIFIER  */
    INTEGER = 260,                 /* INTEGER  */
    BOOLEAN = 261,                 /* BOOLEAN  */
    PACKAGE = 262,                 /* PACKAGE  */
    RETURN = 263,                  /* RETURN  */
    VAR = 264,                     /* VAR  */
    IF = 265,                      /* IF  */
    FOR = 266,                     /* FOR  */
    LPAREN = 267,                  /* LPAREN  */
    RPAREN = 268,                  /* RPAREN  */
    LBRACE = 269,                  /* LBRACE  */
    RBRACE = 270,                  /* RBRACE  */
    PLUS = 271,                    /* PLUS  */
    MIN = 272,                     /* MIN  */
    MUL = 273,                     /* MUL  */
    DIV = 274,                     /* DIV  */
    PLUSASSIGN = 275,              /* PLUSASSIGN  */
    MINASSIGN = 276,               /* MINASSIGN  */
    MULASSIGN = 277,               /* MULASSIGN  */
    DIVASSIGN = 278,               /* DIVASSIGN  */
    AND = 279,                     /* AND  */
    OR = 280,                      /* OR  */
    NOT = 281,                     /* NOT  */
    INC = 282,                     /* INC  */
    DEC = 283,                     /* DEC  */
    GT = 284,                      /* GT  */
    GE = 285,                      /* GE  */
    LT = 286,                      /* LT  */
    LE = 287,                      /* LE  */
    EQ = 288,                      /* EQ  */
    NE = 289,                      /* NE  */
    INTLITERAL = 290,              /* INTLITERAL  */
    BOOLLITERAL = 291,             /* BOOLLITERAL  */
    ASSIGN = 292,                  /* ASSIGN  */
    FUNC = 293,                    /* FUNC  */
    NEWLINE = 294,                 /* NEWLINE  */
    IMPORT = 295,                  /* IMPORT  */
    COMMA = 296,                   /* COMMA  */
    ELSE = 297,                    /* ELSE  */
    SHORTVARASSIGN = 298,          /* SHORTVARASSIGN  */
    UMINUS = 299                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
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
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_BOOLEAN = 6,                    /* BOOLEAN  */
  YYSYMBOL_PACKAGE = 7,                    /* PACKAGE  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_VAR = 9,                        /* VAR  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_LPAREN = 12,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 13,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 14,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 15,                    /* RBRACE  */
  YYSYMBOL_PLUS = 16,                      /* PLUS  */
  YYSYMBOL_MIN = 17,                       /* MIN  */
  YYSYMBOL_MUL = 18,                       /* MUL  */
  YYSYMBOL_DIV = 19,                       /* DIV  */
  YYSYMBOL_PLUSASSIGN = 20,                /* PLUSASSIGN  */
  YYSYMBOL_MINASSIGN = 21,                 /* MINASSIGN  */
  YYSYMBOL_MULASSIGN = 22,                 /* MULASSIGN  */
  YYSYMBOL_DIVASSIGN = 23,                 /* DIVASSIGN  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_NOT = 26,                       /* NOT  */
  YYSYMBOL_INC = 27,                       /* INC  */
  YYSYMBOL_DEC = 28,                       /* DEC  */
  YYSYMBOL_GT = 29,                        /* GT  */
  YYSYMBOL_GE = 30,                        /* GE  */
  YYSYMBOL_LT = 31,                        /* LT  */
  YYSYMBOL_LE = 32,                        /* LE  */
  YYSYMBOL_EQ = 33,                        /* EQ  */
  YYSYMBOL_NE = 34,                        /* NE  */
  YYSYMBOL_INTLITERAL = 35,                /* INTLITERAL  */
  YYSYMBOL_BOOLLITERAL = 36,               /* BOOLLITERAL  */
  YYSYMBOL_ASSIGN = 37,                    /* ASSIGN  */
  YYSYMBOL_FUNC = 38,                      /* FUNC  */
  YYSYMBOL_NEWLINE = 39,                   /* NEWLINE  */
  YYSYMBOL_IMPORT = 40,                    /* IMPORT  */
  YYSYMBOL_COMMA = 41,                     /* COMMA  */
  YYSYMBOL_ELSE = 42,                      /* ELSE  */
  YYSYMBOL_SHORTVARASSIGN = 43,            /* SHORTVARASSIGN  */
  YYSYMBOL_UMINUS = 44,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_sourcefile = 46,                /* sourcefile  */
  YYSYMBOL_topleveldeclarations = 47,      /* topleveldeclarations  */
  YYSYMBOL_packageclause = 48,             /* packageclause  */
  YYSYMBOL_packagename = 49,               /* packagename  */
  YYSYMBOL_topleveldecl = 50,              /* topleveldecl  */
  YYSYMBOL_declaration = 51,               /* declaration  */
  YYSYMBOL_vardecl = 52,                   /* vardecl  */
  YYSYMBOL_shortvardecl = 53,              /* shortvardecl  */
  YYSYMBOL_varspec = 54,                   /* varspec  */
  YYSYMBOL_functiondeclaration = 55,       /* functiondeclaration  */
  YYSYMBOL_functionname = 56,              /* functionname  */
  YYSYMBOL_functionbody = 57,              /* functionbody  */
  YYSYMBOL_signature = 58,                 /* signature  */
  YYSYMBOL_type = 59,                      /* type  */
  YYSYMBOL_typename = 60,                  /* typename  */
  YYSYMBOL_result = 61,                    /* result  */
  YYSYMBOL_parameters = 62,                /* parameters  */
  YYSYMBOL_parameterlist = 63,             /* parameterlist  */
  YYSYMBOL_parameterdecl = 64,             /* parameterdecl  */
  YYSYMBOL_expr = 65,                      /* expr  */
  YYSYMBOL_expressionlist = 66,            /* expressionlist  */
  YYSYMBOL_identifierlist = 67,            /* identifierlist  */
  YYSYMBOL_unaryexpr = 68,                 /* unaryexpr  */
  YYSYMBOL_unary_op = 69,                  /* unary_op  */
  YYSYMBOL_operand = 70,                   /* operand  */
  YYSYMBOL_literal = 71,                   /* literal  */
  YYSYMBOL_basiclit = 72,                  /* basiclit  */
  YYSYMBOL_operandname = 73,               /* operandname  */
  YYSYMBOL_primaryexpr = 74,               /* primaryexpr  */
  YYSYMBOL_block = 75,                     /* block  */
  YYSYMBOL_statementlist = 76,             /* statementlist  */
  YYSYMBOL_statement = 77,                 /* statement  */
  YYSYMBOL_simplestatement = 78,           /* simplestatement  */
  YYSYMBOL_emptystatement = 79,            /* emptystatement  */
  YYSYMBOL_expressionstatement = 80,       /* expressionstatement  */
  YYSYMBOL_assignment = 81,                /* assignment  */
  YYSYMBOL_assign_op = 82,                 /* assign_op  */
  YYSYMBOL_incdecstatement = 83,           /* incdecstatement  */
  YYSYMBOL_ifstatement = 84,               /* ifstatement  */
  YYSYMBOL_forstatement = 85,              /* forstatement  */
  YYSYMBOL_condition = 86,                 /* condition  */
  YYSYMBOL_forclause = 87,                 /* forclause  */
  YYSYMBOL_initstatement = 88,             /* initstatement  */
  YYSYMBOL_poststatement = 89,             /* poststatement  */
  YYSYMBOL_returnstatement = 90            /* returnstatement  */
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
#define YYLAST   337

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    23,    23,    25,    26,    29,    31,    34,    35,    38,
      41,    42,    45,    48,    49,    50,    53,    55,    57,    59,
      60,    63,    64,    67,    68,    69,    72,    73,    76,    77,
      78,    81,    82,    85,    86,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   104,   105,
     108,   109,   112,   113,   116,   117,   118,   121,   122,   123,
     126,   129,   130,   133,   136,   139,   142,   143,   146,   147,
     148,   149,   150,   151,   154,   155,   156,   157,   158,   161,
     163,   165,   167,   168,   169,   170,   171,   174,   175,   179,
     180,   181,   182,   185,   186,   187,   190,   192,   195,   197,
     199,   200
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
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON",
  "IDENTIFIER", "INTEGER", "BOOLEAN", "PACKAGE", "RETURN", "VAR", "IF",
  "FOR", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "PLUS", "MIN", "MUL",
  "DIV", "PLUSASSIGN", "MINASSIGN", "MULASSIGN", "DIVASSIGN", "AND", "OR",
  "NOT", "INC", "DEC", "GT", "GE", "LT", "LE", "EQ", "NE", "INTLITERAL",
  "BOOLLITERAL", "ASSIGN", "FUNC", "NEWLINE", "IMPORT", "COMMA", "ELSE",
  "SHORTVARASSIGN", "UMINUS", "$accept", "sourcefile",
  "topleveldeclarations", "packageclause", "packagename", "topleveldecl",
  "declaration", "vardecl", "shortvardecl", "varspec",
  "functiondeclaration", "functionname", "functionbody", "signature",
  "type", "typename", "result", "parameters", "parameterlist",
  "parameterdecl", "expr", "expressionlist", "identifierlist", "unaryexpr",
  "unary_op", "operand", "literal", "basiclit", "operandname",
  "primaryexpr", "block", "statementlist", "statement", "simplestatement",
  "emptystatement", "expressionstatement", "assignment", "assign_op",
  "incdecstatement", "ifstatement", "forstatement", "condition",
  "forclause", "initstatement", "poststatement", "returnstatement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-146)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-97)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,    24,    13,    16,  -146,  -146,  -146,    11,     4,    49,
    -146,    67,  -146,  -146,  -146,    50,    86,  -146,    52,  -146,
      85,    11,    86,   106,  -146,  -146,  -146,    98,   129,    99,
    -146,    72,   105,   101,  -146,  -146,   124,   125,  -146,   129,
    -146,  -146,  -146,  -146,  -146,   275,    71,  -146,   129,  -146,
    -146,  -146,  -146,  -146,   129,     9,  -146,  -146,    10,  -146,
      98,   118,  -146,  -146,    72,  -146,  -146,  -146,  -146,  -146,
     227,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,  -146,    71,  -146,    75,  -146,   -29,
     129,   135,    82,  -146,  -146,   159,   242,    97,  -146,    57,
     139,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,   125,
    -146,   102,   102,  -146,  -146,   303,   294,    14,    14,    14,
      14,    14,    14,   275,  -146,  -146,    71,   182,   140,   205,
    -146,  -146,   105,   105,   145,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,   129,   129,  -146,   146,  -146,   108,   129,  -146,
    -146,   129,    71,    71,  -146,    15,   256,   275,   153,  -146,
    -146,   115,   135,    15,  -146,  -146,  -146,  -146
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     6,     5,     1,     0,     0,     0,
       2,     0,     7,     9,     8,    51,     0,    10,     0,    17,
       0,     4,     0,     0,    23,    24,    25,     0,     0,    14,
      21,     0,     0,    20,     3,    50,     0,     0,    63,     0,
      54,    55,    56,    61,    62,    49,    15,    35,     0,    64,
      57,    60,    58,    52,     0,    51,    28,    34,     0,    32,
       0,    79,    16,    18,     0,    27,    19,    26,    11,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    13,    30,     0,    33,    63,
     101,    79,    79,    68,    78,    49,     0,     0,    69,    79,
       0,    73,    77,    74,    75,    76,    70,    71,    72,    34,
      59,    44,    45,    42,    43,    47,    46,    40,    41,    38,
      39,    36,    37,    48,    29,    31,   100,    49,     0,    49,
      95,    98,     0,     0,     0,    87,    88,    83,    84,    85,
      86,    82,     0,     0,    65,     0,    66,     0,     0,    93,
      94,     0,    81,    12,    67,     0,     0,    96,     0,    92,
      91,     0,    79,     0,    99,    97,    90,    89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,   137,  -146,  -146,  -146,   -52,  -146,  -146,   143,
    -146,  -146,  -146,  -146,   -12,  -146,  -146,   127,  -146,    76,
     -37,   -27,    -5,   119,  -146,  -146,  -146,  -146,  -146,  -146,
     -32,  -146,    69,   -87,  -146,  -146,  -146,  -146,  -146,  -145,
    -146,    18,  -146,  -146,  -146,  -146
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,    10,     3,     5,    11,    12,    13,    94,    17,
      14,    20,    62,    32,    57,    30,    66,    33,    58,    59,
      45,    96,    97,    47,    48,    49,    50,    51,    52,    53,
      98,    99,   100,   101,   102,   103,   104,   142,   105,   106,
     107,   132,   133,   134,   165,   108
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    46,    70,    18,   128,   131,    29,     1,    15,    93,
     160,    18,    22,     6,   -51,    37,    16,    35,   167,     7,
       8,    65,   -23,    86,    95,    91,    60,    85,     4,    61,
      71,    72,    73,    74,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,    93,    88,     9,
      22,    87,   109,    19,   127,   129,    24,    25,    26,    60,
     130,    89,    95,   126,    27,    90,     8,    91,    92,    39,
      21,    61,   144,    40,    41,   164,    55,    25,    26,    55,
      25,    26,    60,    42,    27,    56,    89,    27,   124,    28,
      15,    22,    43,    44,    39,   147,    61,    31,    40,    41,
     149,   150,    24,    25,    26,    24,    25,    26,    42,    36,
      27,   156,    83,    64,   157,   152,   153,    43,    44,    61,
      73,    74,    89,   159,   161,    95,    90,     8,    91,    92,
      39,   166,    61,    38,    40,    41,    54,    68,    69,    89,
     143,    39,   146,   148,    42,    40,    41,    39,   151,   154,
     155,    40,    41,    43,    44,    42,   162,   163,    34,    23,
      67,    42,   -80,   125,    43,    44,     0,    84,   145,   158,
      43,    44,     0,   -80,     0,    71,    72,    73,    74,     0,
       0,     0,     0,    75,    76,   -80,   135,   136,    77,    78,
      79,    80,    81,    82,     0,     0,    61,     0,    71,    72,
      73,    74,     0,     0,     0,     0,    75,    76,   -80,   135,
     136,    77,    78,    79,    80,    81,    82,     0,     0,   -96,
       0,    71,    72,    73,    74,     0,     0,     0,     0,    75,
      76,     0,   135,   136,    77,    78,    79,    80,    81,    82,
     110,     0,     0,    71,    72,    73,    74,     0,     0,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,   137,   138,   139,   140,     0,     0,     0,     0,
      61,     0,    71,    72,    73,    74,     0,     0,     0,   141,
      75,    76,     0,    83,     0,    77,    78,    79,    80,    81,
      82,    71,    72,    73,    74,     0,     0,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      71,    72,    73,    74,     0,     0,     0,     0,    75,    71,
      72,    73,    74,    77,    78,    79,    80,    81,    82,     0,
       0,     0,    77,    78,    79,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
      32,    28,    39,     8,    91,    92,    18,     7,     4,    61,
     155,    16,    41,     0,    43,    27,    12,    22,   163,     3,
       9,    33,    13,    13,    61,    10,    31,    54,     4,    14,
      16,    17,    18,    19,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    99,    60,    38,
      41,    41,    64,     4,    91,    92,     4,     5,     6,    64,
      92,     4,    99,    90,    12,     8,     9,    10,    11,    12,
       3,    14,    15,    16,    17,   162,     4,     5,     6,     4,
       5,     6,    87,    26,    12,    13,     4,    12,    13,    37,
       4,    41,    35,    36,    12,   127,    14,    12,    16,    17,
     132,   133,     4,     5,     6,     4,     5,     6,    26,     3,
      12,   148,    41,    12,   151,   142,   143,    35,    36,    14,
      18,    19,     4,   155,   156,   162,     8,     9,    10,    11,
      12,   163,    14,     4,    16,    17,    37,    13,    13,     4,
      43,    12,     3,     3,    26,    16,    17,    12,     3,     3,
      42,    16,    17,    35,    36,    26,     3,    42,    21,    16,
      33,    26,     3,    87,    35,    36,    -1,    48,    99,   151,
      35,    36,    -1,    14,    -1,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    24,    25,     3,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    14,    -1,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    24,    25,     3,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    14,
      -1,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      13,    -1,    -1,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      14,    -1,    16,    17,    18,    19,    -1,    -1,    -1,    37,
      24,    25,    -1,    41,    -1,    29,    30,    31,    32,    33,
      34,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    24,
      25,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    24,    16,
      17,    18,    19,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    46,    48,     4,    49,     0,     3,     9,    38,
      47,    50,    51,    52,    55,     4,    12,    54,    67,     4,
      56,     3,    41,    54,     4,     5,     6,    12,    37,    59,
      60,    12,    58,    62,    47,    67,     3,    59,     4,    12,
      16,    17,    26,    35,    36,    65,    66,    68,    69,    70,
      71,    72,    73,    74,    37,     4,    13,    59,    63,    64,
      67,    14,    57,    75,    12,    59,    61,    62,    13,    13,
      65,    16,    17,    18,    19,    24,    25,    29,    30,    31,
      32,    33,    34,    41,    68,    66,    13,    41,    59,     4,
       8,    10,    11,    51,    53,    65,    66,    67,    75,    76,
      77,    78,    79,    80,    81,    83,    84,    85,    90,    59,
      13,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    13,    64,    66,    65,    78,    65,
      75,    78,    86,    87,    88,    27,    28,    20,    21,    22,
      23,    37,    82,    43,    15,    77,     3,    75,     3,    75,
      75,     3,    66,    66,     3,    42,    65,    65,    86,    75,
      84,    75,     3,    42,    78,    89,    75,    84
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    49,    50,    50,    51,
      52,    52,    53,    54,    54,    54,    55,    56,    57,    58,
      58,    59,    59,    60,    60,    60,    61,    61,    62,    62,
      62,    63,    63,    64,    64,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    66,    66,
      67,    67,    68,    68,    69,    69,    69,    70,    70,    70,
      71,    72,    72,    73,    74,    75,    76,    76,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    78,    78,    79,
      80,    81,    82,    82,    82,    82,    82,    83,    83,    84,
      84,    84,    84,    85,    85,    85,    86,    87,    88,    89,
      90,    90
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     2,     2,     1,     1,     1,     1,
       2,     5,     3,     4,     2,     3,     4,     1,     1,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     2,     4,
       3,     3,     1,     2,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     1,     2,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     3,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     3,     1,     1,     1,     1,     1,     2,     2,     7,
       7,     5,     5,     3,     3,     2,     1,     5,     1,     1,
       2,     1
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
#line 23 "grammar.y"
                                                         {puts("packageclause SEMICOLON topleveldeclarations"); }
#line 1390 "grammar.tab.c"
    break;

  case 3: /* topleveldeclarations: topleveldecl SEMICOLON topleveldeclarations  */
#line 25 "grammar.y"
                                                                   {puts("topleveldecl SEMICOLON topleveldeclarations"); }
#line 1396 "grammar.tab.c"
    break;

  case 4: /* topleveldeclarations: topleveldecl SEMICOLON  */
#line 26 "grammar.y"
                                                                   {puts("topleveldecl SEMICOLON"); }
#line 1402 "grammar.tab.c"
    break;

  case 5: /* packageclause: PACKAGE packagename  */
#line 29 "grammar.y"
                                    {puts("PACKAGE packagename"); }
#line 1408 "grammar.tab.c"
    break;

  case 6: /* packagename: IDENTIFIER  */
#line 31 "grammar.y"
                        {puts("IDENTIFIER"); }
#line 1414 "grammar.tab.c"
    break;

  case 7: /* topleveldecl: declaration  */
#line 34 "grammar.y"
                                   {puts("declaration"); }
#line 1420 "grammar.tab.c"
    break;

  case 8: /* topleveldecl: functiondeclaration  */
#line 35 "grammar.y"
                                   {puts("functiondeclaration"); }
#line 1426 "grammar.tab.c"
    break;

  case 9: /* declaration: vardecl  */
#line 38 "grammar.y"
                         {puts("vardecl"); }
#line 1432 "grammar.tab.c"
    break;

  case 10: /* vardecl: VAR varspec  */
#line 41 "grammar.y"
                                                            {puts("VAR varspec"); }
#line 1438 "grammar.tab.c"
    break;

  case 11: /* vardecl: VAR LPAREN varspec SEMICOLON RPAREN  */
#line 42 "grammar.y"
                                                            {puts("VAR LPAREN varspec SEMICOLON RPAREN "); }
#line 1444 "grammar.tab.c"
    break;

  case 12: /* shortvardecl: identifierlist SHORTVARASSIGN expressionlist  */
#line 45 "grammar.y"
                                                            {puts("identifierlist SHORTVARASSIGN expressionlist"); }
#line 1450 "grammar.tab.c"
    break;

  case 13: /* varspec: identifierlist type ASSIGN expressionlist  */
#line 48 "grammar.y"
                                                        {puts("identifierlist type ASSIGN expressionlist"); }
#line 1456 "grammar.tab.c"
    break;

  case 14: /* varspec: identifierlist type  */
#line 49 "grammar.y"
                                                        {puts("identifierlist type"); }
#line 1462 "grammar.tab.c"
    break;

  case 15: /* varspec: identifierlist ASSIGN expressionlist  */
#line 50 "grammar.y"
                                                        {puts("identifierlist ASSIGN expressionlist "); }
#line 1468 "grammar.tab.c"
    break;

  case 16: /* functiondeclaration: FUNC functionname signature functionbody  */
#line 53 "grammar.y"
                                                              {puts("FUNC functionname signature functionbody"); }
#line 1474 "grammar.tab.c"
    break;

  case 17: /* functionname: IDENTIFIER  */
#line 55 "grammar.y"
                          {puts("IDENTIFIER"); }
#line 1480 "grammar.tab.c"
    break;

  case 18: /* functionbody: block  */
#line 57 "grammar.y"
                     {puts("block"); }
#line 1486 "grammar.tab.c"
    break;

  case 19: /* signature: parameters result  */
#line 59 "grammar.y"
                                {puts("parameters result"); }
#line 1492 "grammar.tab.c"
    break;

  case 20: /* signature: parameters  */
#line 60 "grammar.y"
                                {puts("parameters"); }
#line 1498 "grammar.tab.c"
    break;

  case 21: /* type: typename  */
#line 63 "grammar.y"
                                {puts("typename"); }
#line 1504 "grammar.tab.c"
    break;

  case 22: /* type: LPAREN type RPAREN  */
#line 64 "grammar.y"
                                {puts("LPAREN type RPAREN"); }
#line 1510 "grammar.tab.c"
    break;

  case 23: /* typename: IDENTIFIER  */
#line 67 "grammar.y"
                                {puts("IDENTIFIER"); }
#line 1516 "grammar.tab.c"
    break;

  case 24: /* typename: INTEGER  */
#line 68 "grammar.y"
                                {puts("INTEGER"); }
#line 1522 "grammar.tab.c"
    break;

  case 25: /* typename: BOOLEAN  */
#line 69 "grammar.y"
                                {puts("BOOLEAN"); }
#line 1528 "grammar.tab.c"
    break;

  case 26: /* result: parameters  */
#line 72 "grammar.y"
                                {puts("parameters"); }
#line 1534 "grammar.tab.c"
    break;

  case 27: /* result: type  */
#line 73 "grammar.y"
                                {puts("type"); }
#line 1540 "grammar.tab.c"
    break;

  case 29: /* parameters: LPAREN parameterlist COMMA RPAREN  */
#line 77 "grammar.y"
                                                  {puts("LPAREN parameterlist COMMA RPAREN"); }
#line 1546 "grammar.tab.c"
    break;

  case 30: /* parameters: LPAREN parameterlist RPAREN  */
#line 78 "grammar.y"
                                                 {puts("LPAREN parameterlist RPAREN  "); }
#line 1552 "grammar.tab.c"
    break;

  case 31: /* parameterlist: parameterlist COMMA parameterdecl  */
#line 81 "grammar.y"
                                                     {puts("parameterdecl COMMA parameterdecl"); }
#line 1558 "grammar.tab.c"
    break;

  case 32: /* parameterlist: parameterdecl  */
#line 82 "grammar.y"
                                                     {puts("parameterdecl"); }
#line 1564 "grammar.tab.c"
    break;

  case 33: /* parameterdecl: identifierlist type  */
#line 85 "grammar.y"
                                                {puts("identifierlist type"); }
#line 1570 "grammar.tab.c"
    break;

  case 34: /* parameterdecl: type  */
#line 86 "grammar.y"
                                                {puts("type"); }
#line 1576 "grammar.tab.c"
    break;

  case 35: /* expr: unaryexpr  */
#line 89 "grammar.y"
                                {puts("unaryexpr"); }
#line 1582 "grammar.tab.c"
    break;

  case 36: /* expr: expr EQ expr  */
#line 90 "grammar.y"
                                {puts("expr EQ expr"); }
#line 1588 "grammar.tab.c"
    break;

  case 37: /* expr: expr NE expr  */
#line 91 "grammar.y"
                                {puts("expr NE expr"); }
#line 1594 "grammar.tab.c"
    break;

  case 38: /* expr: expr LT expr  */
#line 92 "grammar.y"
                                {puts("expr LT expr"); }
#line 1600 "grammar.tab.c"
    break;

  case 39: /* expr: expr LE expr  */
#line 93 "grammar.y"
                                {puts("expr LE expr"); }
#line 1606 "grammar.tab.c"
    break;

  case 40: /* expr: expr GT expr  */
#line 94 "grammar.y"
                                {puts("expr GT expr"); }
#line 1612 "grammar.tab.c"
    break;

  case 41: /* expr: expr GE expr  */
#line 95 "grammar.y"
                                {puts("expr GE expr"); }
#line 1618 "grammar.tab.c"
    break;

  case 42: /* expr: expr MUL expr  */
#line 96 "grammar.y"
                                 {puts("expr MUL expr"); }
#line 1624 "grammar.tab.c"
    break;

  case 43: /* expr: expr DIV expr  */
#line 97 "grammar.y"
                                 {puts("expr DIV expr"); }
#line 1630 "grammar.tab.c"
    break;

  case 44: /* expr: expr PLUS expr  */
#line 98 "grammar.y"
                                {puts("expr PLUS expr"); }
#line 1636 "grammar.tab.c"
    break;

  case 45: /* expr: expr MIN expr  */
#line 99 "grammar.y"
                                {puts("expr MIN expr"); }
#line 1642 "grammar.tab.c"
    break;

  case 46: /* expr: expr OR expr  */
#line 100 "grammar.y"
                                {puts("expr OR expr"); }
#line 1648 "grammar.tab.c"
    break;

  case 47: /* expr: expr AND expr  */
#line 101 "grammar.y"
                                {puts("expr AND expr"); }
#line 1654 "grammar.tab.c"
    break;

  case 48: /* expressionlist: expressionlist COMMA expr  */
#line 104 "grammar.y"
                                                {puts("expressionlist COMMA expr"); }
#line 1660 "grammar.tab.c"
    break;

  case 49: /* expressionlist: expr  */
#line 105 "grammar.y"
                                                {puts("expr"); }
#line 1666 "grammar.tab.c"
    break;

  case 50: /* identifierlist: IDENTIFIER COMMA identifierlist  */
#line 108 "grammar.y"
                                                        {puts("IDENTIFIER COMMA identifierlist"); }
#line 1672 "grammar.tab.c"
    break;

  case 51: /* identifierlist: IDENTIFIER  */
#line 109 "grammar.y"
                                                        {puts("IDENTIFIER"); }
#line 1678 "grammar.tab.c"
    break;

  case 52: /* unaryexpr: primaryexpr  */
#line 112 "grammar.y"
                               {puts("primaryexpr"); }
#line 1684 "grammar.tab.c"
    break;

  case 53: /* unaryexpr: unary_op unaryexpr  */
#line 113 "grammar.y"
                               {puts("unary_op unaryexpr"); }
#line 1690 "grammar.tab.c"
    break;

  case 54: /* unary_op: PLUS  */
#line 116 "grammar.y"
                                {puts("PLUS"); }
#line 1696 "grammar.tab.c"
    break;

  case 55: /* unary_op: MIN  */
#line 117 "grammar.y"
                                {puts("MIN"); }
#line 1702 "grammar.tab.c"
    break;

  case 56: /* unary_op: NOT  */
#line 118 "grammar.y"
                                {puts("NOT"); }
#line 1708 "grammar.tab.c"
    break;

  case 57: /* operand: literal  */
#line 121 "grammar.y"
                                {puts("literal"); }
#line 1714 "grammar.tab.c"
    break;

  case 58: /* operand: operandname  */
#line 122 "grammar.y"
                                {puts("operandname"); }
#line 1720 "grammar.tab.c"
    break;

  case 59: /* operand: LPAREN expr RPAREN  */
#line 123 "grammar.y"
                                {puts("LPAREN expr RPAREN"); }
#line 1726 "grammar.tab.c"
    break;

  case 60: /* literal: basiclit  */
#line 126 "grammar.y"
                                {puts("basiclit"); }
#line 1732 "grammar.tab.c"
    break;

  case 61: /* basiclit: INTLITERAL  */
#line 129 "grammar.y"
                                {puts("INTLITERAL"); }
#line 1738 "grammar.tab.c"
    break;

  case 62: /* basiclit: BOOLLITERAL  */
#line 130 "grammar.y"
                                {puts("BOOLLITERAL"); }
#line 1744 "grammar.tab.c"
    break;

  case 63: /* operandname: IDENTIFIER  */
#line 133 "grammar.y"
                                {puts("IDENTIFIER"); }
#line 1750 "grammar.tab.c"
    break;

  case 64: /* primaryexpr: operand  */
#line 136 "grammar.y"
                                {puts("operand"); }
#line 1756 "grammar.tab.c"
    break;

  case 65: /* block: LBRACE statementlist RBRACE  */
#line 139 "grammar.y"
                                        {puts("LBRACE statementlist RBRACE"); }
#line 1762 "grammar.tab.c"
    break;

  case 66: /* statementlist: statement SEMICOLON  */
#line 142 "grammar.y"
                                                        {puts("statement SEMICOLON");}
#line 1768 "grammar.tab.c"
    break;

  case 67: /* statementlist: statementlist statement SEMICOLON  */
#line 143 "grammar.y"
                                                        {puts("statementlist statement SEMICOLON");}
#line 1774 "grammar.tab.c"
    break;

  case 68: /* statement: declaration  */
#line 146 "grammar.y"
                                         {puts("declaration");}
#line 1780 "grammar.tab.c"
    break;

  case 69: /* statement: block  */
#line 147 "grammar.y"
                                         {puts("block");}
#line 1786 "grammar.tab.c"
    break;

  case 70: /* statement: ifstatement  */
#line 148 "grammar.y"
                                         {puts("ifstatement");}
#line 1792 "grammar.tab.c"
    break;

  case 71: /* statement: forstatement  */
#line 149 "grammar.y"
                                         {puts("forstatement");}
#line 1798 "grammar.tab.c"
    break;

  case 72: /* statement: returnstatement  */
#line 150 "grammar.y"
                                         {puts("returnstatement");}
#line 1804 "grammar.tab.c"
    break;

  case 73: /* statement: simplestatement  */
#line 151 "grammar.y"
                                         {puts("simplestatement");}
#line 1810 "grammar.tab.c"
    break;

  case 74: /* simplestatement: expressionstatement  */
#line 154 "grammar.y"
                                         {puts("expressionstatement");}
#line 1816 "grammar.tab.c"
    break;

  case 75: /* simplestatement: assignment  */
#line 155 "grammar.y"
                                         {puts("assignment");}
#line 1822 "grammar.tab.c"
    break;

  case 76: /* simplestatement: incdecstatement  */
#line 156 "grammar.y"
                                         {puts("incdecstatement");}
#line 1828 "grammar.tab.c"
    break;

  case 77: /* simplestatement: emptystatement  */
#line 157 "grammar.y"
                                         {puts("emptystatement");}
#line 1834 "grammar.tab.c"
    break;

  case 78: /* simplestatement: shortvardecl  */
#line 158 "grammar.y"
                                         {puts("shortvardecl");}
#line 1840 "grammar.tab.c"
    break;

  case 79: /* emptystatement: %empty  */
#line 161 "grammar.y"
                {puts("nothing");}
#line 1846 "grammar.tab.c"
    break;

  case 80: /* expressionstatement: expr  */
#line 163 "grammar.y"
                          {puts("expr");}
#line 1852 "grammar.tab.c"
    break;

  case 81: /* assignment: expressionlist assign_op expressionlist  */
#line 165 "grammar.y"
                                                    {puts("expressionlist assign_op expressionlist");}
#line 1858 "grammar.tab.c"
    break;

  case 82: /* assign_op: ASSIGN  */
#line 167 "grammar.y"
                                                    {puts("ASSIGN");}
#line 1864 "grammar.tab.c"
    break;

  case 83: /* assign_op: PLUSASSIGN  */
#line 168 "grammar.y"
                                                    {puts("PLUSASSIGN");}
#line 1870 "grammar.tab.c"
    break;

  case 84: /* assign_op: MINASSIGN  */
#line 169 "grammar.y"
                                                    {puts("MINASSIGN");}
#line 1876 "grammar.tab.c"
    break;

  case 85: /* assign_op: MULASSIGN  */
#line 170 "grammar.y"
                                                    {puts("MULASSIGN");}
#line 1882 "grammar.tab.c"
    break;

  case 86: /* assign_op: DIVASSIGN  */
#line 171 "grammar.y"
                                                    {puts("DIVASSIGN");}
#line 1888 "grammar.tab.c"
    break;

  case 87: /* incdecstatement: expr INC  */
#line 174 "grammar.y"
                                                    {puts("expr INC");}
#line 1894 "grammar.tab.c"
    break;

  case 88: /* incdecstatement: expr DEC  */
#line 175 "grammar.y"
                                                    {puts("expr DEC");}
#line 1900 "grammar.tab.c"
    break;

  case 89: /* ifstatement: IF simplestatement SEMICOLON expr block ELSE ifstatement  */
#line 179 "grammar.y"
                                                                        {puts("IF simplestatement SEMICOLON expr block ELSE ifstatement"); }
#line 1906 "grammar.tab.c"
    break;

  case 90: /* ifstatement: IF simplestatement SEMICOLON expr block ELSE block  */
#line 180 "grammar.y"
                                                                        {puts("IF simplestatement SEMICOLON expr block ELSE block"); }
#line 1912 "grammar.tab.c"
    break;

  case 91: /* ifstatement: IF expr block ELSE ifstatement  */
#line 181 "grammar.y"
                                                                        {puts("IF expr block ELSE ifstatement"); }
#line 1918 "grammar.tab.c"
    break;

  case 92: /* ifstatement: IF expr block ELSE block  */
#line 182 "grammar.y"
                                                                        {puts("IF expr block ELSE block"); }
#line 1924 "grammar.tab.c"
    break;

  case 93: /* forstatement: FOR condition block  */
#line 185 "grammar.y"
                                        {puts("FOR condition block"); }
#line 1930 "grammar.tab.c"
    break;

  case 94: /* forstatement: FOR forclause block  */
#line 186 "grammar.y"
                                        {puts("FOR forclause block"); }
#line 1936 "grammar.tab.c"
    break;

  case 95: /* forstatement: FOR block  */
#line 187 "grammar.y"
                                        {puts("FOR block"); }
#line 1942 "grammar.tab.c"
    break;

  case 96: /* condition: expr  */
#line 190 "grammar.y"
                                        {puts("expr"); }
#line 1948 "grammar.tab.c"
    break;

  case 97: /* forclause: initstatement SEMICOLON condition SEMICOLON poststatement  */
#line 192 "grammar.y"
                                                                        {puts("initstatement SEMICOLON condition SEMICOLON poststatement"); }
#line 1954 "grammar.tab.c"
    break;

  case 98: /* initstatement: simplestatement  */
#line 195 "grammar.y"
                                {puts("simplestatement"); }
#line 1960 "grammar.tab.c"
    break;

  case 99: /* poststatement: simplestatement  */
#line 197 "grammar.y"
                                 {puts("simplestatement"); }
#line 1966 "grammar.tab.c"
    break;

  case 100: /* returnstatement: RETURN expressionlist  */
#line 199 "grammar.y"
                                         {puts("RETURN expressionlist"); }
#line 1972 "grammar.tab.c"
    break;

  case 101: /* returnstatement: RETURN  */
#line 200 "grammar.y"
                                         {puts("RETURN"); }
#line 1978 "grammar.tab.c"
    break;


#line 1982 "grammar.tab.c"

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

#line 203 "grammar.y"
