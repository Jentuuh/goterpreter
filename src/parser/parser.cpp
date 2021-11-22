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

#include "parser.hpp"
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
  YYSYMBOL_IDENTIFIER = 41,                /* IDENTIFIER  */
  YYSYMBOL_BOOLLITERAL = 42,               /* BOOLLITERAL  */
  YYSYMBOL_INTLITERAL = 43,                /* INTLITERAL  */
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
#define YYLAST   342

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

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
static const yytype_int16 yyrline[] =
{
       0,   126,   126,   135,   154,   155,   158,   160,   163,   164,
     167,   170,   171,   174,   177,   178,   179,   182,   184,   186,
     188,   189,   192,   193,   196,   197,   198,   201,   202,   205,
     206,   207,   210,   211,   214,   215,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   233,
     234,   237,   238,   241,   242,   245,   246,   247,   250,   251,
     252,   255,   258,   259,   262,   265,   268,   271,   272,   275,
     276,   277,   278,   279,   280,   283,   284,   285,   286,   287,
     290,   292,   294,   296,   297,   298,   299,   300,   303,   304,
     308,   309,   310,   311,   312,   315,   316,   317,   320,   322,
     325,   327,   329,   330
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
  "IMPORT", "COMMA", "ELSE", "SHORTVARASSIGN", "IDENTIFIER", "BOOLLITERAL",
  "INTLITERAL", "UMINUS", "$accept", "sourcefile", "topleveldeclarations",
  "packageclause", "packagename", "topleveldecl", "declaration", "vardecl",
  "shortvardecl", "varspec", "functiondeclaration", "functionname",
  "functionbody", "signature", "type", "typename", "result", "parameters",
  "parameterlist", "parameterdecl", "expr", "expressionlist",
  "identifierlist", "unaryexpr", "unary_op", "operand", "literal",
  "basiclit", "operandname", "primaryexpr", "block", "statementlist",
  "statement", "simplestatement", "emptystatement", "expressionstatement",
  "assignment", "assign_op", "incdecstatement", "ifstatement",
  "forstatement", "condition", "forclause", "initstatement",
  "poststatement", "returnstatement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-147)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-99)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -29,    15,    20,  -147,  -147,  -147,    22,     6,   -15,
    -147,    64,  -147,  -147,  -147,    29,    36,  -147,    17,  -147,
      70,    22,    79,    29,  -147,  -147,     9,   138,  -147,    54,
    -147,    57,    77,    44,  -147,    81,  -147,    82,   138,  -147,
    -147,  -147,  -147,  -147,  -147,   281,    53,  -147,   138,  -147,
    -147,  -147,  -147,  -147,   138,  -147,    -5,  -147,    51,  -147,
       9,   118,  -147,  -147,    57,  -147,  -147,  -147,  -147,  -147,
     241,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,  -147,    53,  -147,    61,  -147,   138,
     143,   131,    46,  -147,  -147,   175,    58,    72,  -147,    83,
     111,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,    82,
    -147,    14,    14,  -147,  -147,   309,   300,   149,   149,   149,
     149,   149,   149,   281,  -147,  -147,    53,   197,   112,   219,
    -147,  -147,    77,    77,   113,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,   138,   138,  -147,    96,    80,   138,  -147,  -147,
     138,    53,    53,  -147,    62,   262,   281,   117,  -147,  -147,
      93,   143,    62,  -147,  -147,  -147,  -147
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     7,     6,     1,     3,     0,     0,
       2,     0,     8,    10,     9,     0,    52,    11,     0,    18,
       0,     5,     0,     0,    25,    26,     0,     0,    24,    15,
      22,     0,     0,    21,     4,     0,    51,     0,     0,    55,
      57,    64,    63,    62,    56,    50,    16,    36,     0,    65,
      58,    61,    59,    53,     0,    29,    52,    35,     0,    33,
       0,    80,    17,    19,     0,    28,    20,    27,    12,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,    14,    31,     0,    34,   103,
      80,    80,    64,    69,    79,    50,     0,     0,    70,     0,
       0,    74,    78,    75,    76,    77,    71,    72,    73,    35,
      60,    45,    46,    43,    44,    48,    47,    41,    42,    39,
      40,    37,    38,    49,    30,    32,   102,    50,     0,    50,
      97,   100,     0,     0,     0,    88,    89,    84,    85,    86,
      87,    83,     0,     0,    66,    67,    94,     0,    95,    96,
       0,    82,    13,    68,     0,     0,    98,     0,    93,    92,
       0,    80,     0,   101,    99,    91,    90
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,   114,  -147,  -147,  -147,   -58,  -147,  -147,   119,
    -147,  -147,  -147,  -147,    -8,  -147,  -147,   103,  -147,    60,
     -37,   -25,    -4,    97,  -147,  -147,  -147,  -147,  -147,  -147,
     -32,     5,  -147,   -85,  -147,  -147,  -147,  -147,  -147,  -146,
    -147,    -9,  -147,  -147,  -147,  -147
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,    10,     3,     5,    11,    12,    13,    94,    17,
      14,    20,    62,    32,    57,    30,    66,    33,    58,    59,
      45,    96,    97,    47,    48,    49,    50,    51,    52,    53,
      98,    99,   100,   101,   102,   103,   104,   142,   105,   106,
     107,   132,   133,   134,   164,   108
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    70,    46,    93,    18,   128,   131,   -24,   159,     1,
      29,    18,     4,    24,    25,     6,   166,    15,    37,    36,
      26,    24,    25,     7,    95,    65,    19,    60,    26,    85,
       8,    73,    74,    23,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,    16,    24,    25,
      28,    27,    88,   127,   129,    64,   109,     9,    28,   130,
      60,    24,    25,    86,   126,    24,    25,    21,    26,    55,
      16,    90,    26,   124,    23,    61,   163,   137,   138,   139,
     140,    31,    35,    60,    23,    28,   -52,    93,    54,    87,
      61,    83,   141,    68,    69,   146,    83,   144,    56,   -80,
     148,   149,    56,    89,     8,    90,    91,    38,    95,    61,
     155,    39,   143,   156,   145,   147,   150,   151,   152,   154,
     161,    40,   158,   160,    95,    89,     8,    90,    91,    38,
     165,    61,   162,    39,    22,    34,    67,    92,    42,    43,
      44,   157,    38,    40,    61,    84,    39,   125,     0,    38,
     153,     0,     0,    39,    38,     0,    40,     0,    39,    92,
      42,    43,    44,    40,    71,    72,    73,    74,    40,     0,
       0,     0,    92,    42,    43,    44,     0,     0,   -81,    41,
      42,    43,    44,     0,    92,    42,    43,    44,   -81,     0,
      71,    72,    73,    74,     0,     0,     0,     0,    75,    76,
     -81,   135,   136,    77,    78,    79,    80,    81,    82,     0,
      61,     0,    71,    72,    73,    74,     0,     0,     0,     0,
      75,    76,   -81,   135,   136,    77,    78,    79,    80,    81,
      82,     0,   -98,     0,    71,    72,    73,    74,     0,     0,
       0,     0,    75,    76,     0,   135,   136,    77,    78,    79,
      80,    81,    82,   110,     0,     0,    71,    72,    73,    74,
       0,     0,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    61,     0,    71,    72,    73,
      74,     0,     0,     0,     0,    75,    76,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    71,    72,    73,    74,
       0,     0,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    71,    72,    73,    74,     0,
       0,     0,     0,    75,    71,    72,    73,    74,    77,    78,
      79,    80,    81,    82,     0,     0,     0,    77,    78,    79,
      80,    81,    82
};

static const yytype_int16 yycheck[] =
{
      32,    38,    27,    61,     8,    90,    91,    12,   154,     6,
      18,    15,    41,     4,     5,     0,   162,    11,    26,    23,
      11,     4,     5,     3,    61,    33,    41,    31,    11,    54,
       8,    17,    18,    38,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    41,     4,     5,
      41,    34,    60,    90,    91,    11,    64,    35,    41,    91,
      64,     4,     5,    12,    89,     4,     5,     3,    11,    12,
      41,     9,    11,    12,    38,    13,   161,    19,    20,    21,
      22,    11,     3,    87,    38,    41,    40,   145,    34,    38,
      13,    38,    34,    12,    12,   127,    38,    14,    41,     3,
     132,   133,    41,     7,     8,     9,    10,    11,   145,    13,
     147,    15,    40,   150,     3,     3,     3,   142,   143,    39,
       3,    25,   154,   155,   161,     7,     8,     9,    10,    11,
     162,    13,    39,    15,    15,    21,    33,    41,    42,    43,
      44,   150,    11,    25,    13,    48,    15,    87,    -1,    11,
     145,    -1,    -1,    15,    11,    -1,    25,    -1,    15,    41,
      42,    43,    44,    25,    15,    16,    17,    18,    25,    -1,
      -1,    -1,    41,    42,    43,    44,    -1,    -1,     3,    41,
      42,    43,    44,    -1,    41,    42,    43,    44,    13,    -1,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
       3,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      13,    -1,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      23,    24,     3,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    13,    -1,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    12,    -1,    -1,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    13,    -1,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    23,    15,    16,    17,    18,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    46,    48,    41,    49,     0,     3,     8,    35,
      47,    50,    51,    52,    55,    11,    41,    54,    67,    41,
      56,     3,    54,    38,     4,     5,    11,    34,    41,    59,
      60,    11,    58,    62,    47,     3,    67,    59,    11,    15,
      25,    41,    42,    43,    44,    65,    66,    68,    69,    70,
      71,    72,    73,    74,    34,    12,    41,    59,    63,    64,
      67,    13,    57,    75,    11,    59,    61,    62,    12,    12,
      65,    15,    16,    17,    18,    23,    24,    28,    29,    30,
      31,    32,    33,    38,    68,    66,    12,    38,    59,     7,
       9,    10,    41,    51,    53,    65,    66,    67,    75,    76,
      77,    78,    79,    80,    81,    83,    84,    85,    90,    59,
      12,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    12,    64,    66,    65,    78,    65,
      75,    78,    86,    87,    88,    26,    27,    19,    20,    21,
      22,    34,    82,    40,    14,     3,    75,     3,    75,    75,
       3,    66,    66,    76,    39,    65,    65,    86,    75,    84,
      75,     3,    39,    78,    89,    75,    84
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    48,    49,    50,    50,
      51,    52,    52,    53,    54,    54,    54,    55,    56,    57,
      58,    58,    59,    59,    60,    60,    60,    61,    61,    62,
      62,    62,    63,    63,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    69,    70,    70,
      70,    71,    72,    72,    73,    74,    75,    76,    76,    77,
      77,    77,    77,    77,    77,    78,    78,    78,    78,    78,
      79,    80,    81,    82,    82,    82,    82,    82,    83,    83,
      84,    84,    84,    84,    84,    85,    85,    85,    86,    87,
      88,    89,    90,    90
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     3,     2,     2,     1,     1,     1,
       1,     2,     5,     3,     4,     2,     3,     4,     1,     1,
       2,     1,     1,     3,     1,     1,     1,     1,     1,     2,
       4,     3,     3,     1,     2,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     1,     1,     2,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     3,     1,     1,     1,     1,     1,     2,     2,
       7,     7,     5,     5,     3,     3,     3,     2,     1,     5,
       1,     1,     2,     1
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
#line 126 "./parser/grammar.y"
                                                                        {(yyval.srcfile) = new SrcFile((yyvsp[-2].packageclause), nullptr, (yyvsp[0].decllist));
                                                                        ast = (yyval.srcfile);
                                                                        }
#line 1307 "./parser/parser.cpp"
    break;

  case 3: /* sourcefile: packageclause SEMICOLON  */
#line 135 "./parser/grammar.y"
                                                                        {(yyval.srcfile) = new SrcFile((yyvsp[-1].packageclause), nullptr, nullptr);
                                                                        ast = (yyval.srcfile);
                                                                        }
#line 1315 "./parser/parser.cpp"
    break;

  case 4: /* topleveldeclarations: topleveldecl SEMICOLON topleveldeclarations  */
#line 154 "./parser/grammar.y"
                                                                   {(yyval.decllist) = new PairDeclList((yyvsp[-2].toplvldecl), (yyvsp[0].decllist));}
#line 1321 "./parser/parser.cpp"
    break;

  case 5: /* topleveldeclarations: topleveldecl SEMICOLON  */
#line 155 "./parser/grammar.y"
                                                                   {(yyval.decllist) = new LastDeclList((yyvsp[-1].toplvldecl));}
#line 1327 "./parser/parser.cpp"
    break;

  case 6: /* packageclause: PACKAGE packagename  */
#line 158 "./parser/grammar.y"
                                    {(yyval.packageclause) = new PackageClause((yyvsp[0].identifier));}
#line 1333 "./parser/parser.cpp"
    break;

  case 7: /* packagename: IDENTIFIER  */
#line 160 "./parser/grammar.y"
                        {(yyval.identifier) = new Identifier((yyvsp[0].id));}
#line 1339 "./parser/parser.cpp"
    break;

  case 8: /* topleveldecl: declaration  */
#line 163 "./parser/grammar.y"
                                   {(yyval.toplvldecl) = (yyvsp[0].toplvldecl); }
#line 1345 "./parser/parser.cpp"
    break;

  case 9: /* topleveldecl: functiondeclaration  */
#line 164 "./parser/grammar.y"
                                   {(yyval.toplvldecl) = (yyvsp[0].toplvldecl); }
#line 1351 "./parser/parser.cpp"
    break;

  case 10: /* declaration: vardecl  */
#line 167 "./parser/grammar.y"
                         {(yyval.toplvldecl) = (yyvsp[0].toplvldecl); }
#line 1357 "./parser/parser.cpp"
    break;

  case 11: /* vardecl: VAR varspec  */
#line 170 "./parser/grammar.y"
                                                            {(yyval.toplvldecl) = new VarDecl((yyvsp[0].varspec)); }
#line 1363 "./parser/parser.cpp"
    break;

  case 12: /* vardecl: VAR LPAREN varspec SEMICOLON RPAREN  */
#line 171 "./parser/grammar.y"
                                                            {(yyval.toplvldecl) = new VarDecl((yyvsp[-2].varspec)); }
#line 1369 "./parser/parser.cpp"
    break;

  case 13: /* shortvardecl: identifierlist SHORTVARASSIGN expressionlist  */
#line 174 "./parser/grammar.y"
                                                            {puts("identifierlist SHORTVARASSIGN expressionlist"); }
#line 1375 "./parser/parser.cpp"
    break;

  case 14: /* varspec: identifierlist type ASSIGN expressionlist  */
#line 177 "./parser/grammar.y"
                                                        {(yyval.varspec) = new VarSpec((yyvsp[-3].identifierlist), (yyvsp[-2].type), (yyvsp[0].explist)); }
#line 1381 "./parser/parser.cpp"
    break;

  case 15: /* varspec: identifierlist type  */
#line 178 "./parser/grammar.y"
                                                        {(yyval.varspec) = new VarSpec((yyvsp[-1].identifierlist), (yyvsp[0].type), nullptr);}
#line 1387 "./parser/parser.cpp"
    break;

  case 16: /* varspec: identifierlist ASSIGN expressionlist  */
#line 179 "./parser/grammar.y"
                                                        {(yyval.varspec) = new VarSpec((yyvsp[-2].identifierlist), nullptr, (yyvsp[0].explist)); }
#line 1393 "./parser/parser.cpp"
    break;

  case 17: /* functiondeclaration: FUNC functionname signature functionbody  */
#line 182 "./parser/grammar.y"
                                                              {(yyval.toplvldecl) = new FunctionDecl((yyvsp[-2].identifier), (yyvsp[-1].signature), (yyvsp[0].block)); }
#line 1399 "./parser/parser.cpp"
    break;

  case 18: /* functionname: IDENTIFIER  */
#line 184 "./parser/grammar.y"
                          {(yyval.identifier) = new Identifier((yyvsp[0].id)); }
#line 1405 "./parser/parser.cpp"
    break;

  case 19: /* functionbody: block  */
#line 186 "./parser/grammar.y"
                     {(yyval.block) = (yyvsp[0].block); }
#line 1411 "./parser/parser.cpp"
    break;

  case 20: /* signature: parameters result  */
#line 188 "./parser/grammar.y"
                                { (yyval.signature) = new Signature((yyvsp[-1].paramlist), (yyvsp[0].result)); }
#line 1417 "./parser/parser.cpp"
    break;

  case 21: /* signature: parameters  */
#line 189 "./parser/grammar.y"
                                { (yyval.signature) = new Signature((yyvsp[0].paramlist), nullptr); }
#line 1423 "./parser/parser.cpp"
    break;

  case 22: /* type: typename  */
#line 192 "./parser/grammar.y"
                                { (yyval.type) = (yyvsp[0].type); }
#line 1429 "./parser/parser.cpp"
    break;

  case 23: /* type: LPAREN type RPAREN  */
#line 193 "./parser/grammar.y"
                                { (yyval.type) = (yyvsp[-1].type); }
#line 1435 "./parser/parser.cpp"
    break;

  case 24: /* typename: IDENTIFIER  */
#line 196 "./parser/grammar.y"
                                { puts("IDENTIFIER"); }
#line 1441 "./parser/parser.cpp"
    break;

  case 25: /* typename: INTEGER  */
#line 197 "./parser/grammar.y"
                                { (yyval.type) = new IntegerType(); }
#line 1447 "./parser/parser.cpp"
    break;

  case 26: /* typename: BOOLEAN  */
#line 198 "./parser/grammar.y"
                                { (yyval.type) = new BooleanType(); }
#line 1453 "./parser/parser.cpp"
    break;

  case 27: /* result: parameters  */
#line 201 "./parser/grammar.y"
                                { (yyval.result) = new ParametersResult((yyvsp[0].paramlist)); }
#line 1459 "./parser/parser.cpp"
    break;

  case 28: /* result: type  */
#line 202 "./parser/grammar.y"
                                { (yyval.result) = new TypeResult((yyvsp[0].type)); }
#line 1465 "./parser/parser.cpp"
    break;

  case 29: /* parameters: LPAREN RPAREN  */
#line 205 "./parser/grammar.y"
                                                  { (yyval.paramlist) = nullptr; }
#line 1471 "./parser/parser.cpp"
    break;

  case 30: /* parameters: LPAREN parameterlist COMMA RPAREN  */
#line 206 "./parser/grammar.y"
                                                  { (yyval.paramlist) = (yyvsp[-2].paramlist); }
#line 1477 "./parser/parser.cpp"
    break;

  case 31: /* parameters: LPAREN parameterlist RPAREN  */
#line 207 "./parser/grammar.y"
                                                  { (yyval.paramlist) = (yyvsp[-1].paramlist); }
#line 1483 "./parser/parser.cpp"
    break;

  case 32: /* parameterlist: parameterlist COMMA parameterdecl  */
#line 210 "./parser/grammar.y"
                                                     { (yyval.paramlist) = new PairParamList((yyvsp[0].paramdecl), (yyvsp[-2].paramlist)); }
#line 1489 "./parser/parser.cpp"
    break;

  case 33: /* parameterlist: parameterdecl  */
#line 211 "./parser/grammar.y"
                                                     { (yyval.paramlist) = new LastParamList((yyvsp[0].paramdecl)); }
#line 1495 "./parser/parser.cpp"
    break;

  case 34: /* parameterdecl: identifierlist type  */
#line 214 "./parser/grammar.y"
                                                { (yyval.paramdecl) = new ParameterDecl((yyvsp[0].type), (yyvsp[-1].identifierlist)); }
#line 1501 "./parser/parser.cpp"
    break;

  case 35: /* parameterdecl: type  */
#line 215 "./parser/grammar.y"
                                                { (yyval.paramdecl) = new ParameterDecl((yyvsp[0].type), nullptr); }
#line 1507 "./parser/parser.cpp"
    break;

  case 36: /* expr: unaryexpr  */
#line 218 "./parser/grammar.y"
                                { (yyval.exp) = (yyvsp[0].exp); }
#line 1513 "./parser/parser.cpp"
    break;

  case 37: /* expr: expr EQ expr  */
#line 219 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), EQ_BIN); }
#line 1519 "./parser/parser.cpp"
    break;

  case 38: /* expr: expr NE expr  */
#line 220 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), NE_BIN); }
#line 1525 "./parser/parser.cpp"
    break;

  case 39: /* expr: expr LT expr  */
#line 221 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), LT_BIN); }
#line 1531 "./parser/parser.cpp"
    break;

  case 40: /* expr: expr LE expr  */
#line 222 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), LE_BIN); }
#line 1537 "./parser/parser.cpp"
    break;

  case 41: /* expr: expr GT expr  */
#line 223 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), GT_BIN); }
#line 1543 "./parser/parser.cpp"
    break;

  case 42: /* expr: expr GE expr  */
#line 224 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), GE_BIN); }
#line 1549 "./parser/parser.cpp"
    break;

  case 43: /* expr: expr MUL expr  */
#line 225 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), MUL_BIN); }
#line 1555 "./parser/parser.cpp"
    break;

  case 44: /* expr: expr DIV expr  */
#line 226 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), DIV_BIN); }
#line 1561 "./parser/parser.cpp"
    break;

  case 45: /* expr: expr PLUS expr  */
#line 227 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), PLUS_BIN); }
#line 1567 "./parser/parser.cpp"
    break;

  case 46: /* expr: expr MIN expr  */
#line 228 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), MIN_BIN); }
#line 1573 "./parser/parser.cpp"
    break;

  case 47: /* expr: expr OR expr  */
#line 229 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), OR_BIN); }
#line 1579 "./parser/parser.cpp"
    break;

  case 48: /* expr: expr AND expr  */
#line 230 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), AND_BIN); }
#line 1585 "./parser/parser.cpp"
    break;

  case 49: /* expressionlist: expressionlist COMMA expr  */
#line 233 "./parser/grammar.y"
                                                { (yyval.explist) = new PairExpList((yyvsp[0].exp), (yyvsp[-2].explist)); }
#line 1591 "./parser/parser.cpp"
    break;

  case 50: /* expressionlist: expr  */
#line 234 "./parser/grammar.y"
                                                { (yyval.explist) = new LastExpList((yyvsp[0].exp)); }
#line 1597 "./parser/parser.cpp"
    break;

  case 51: /* identifierlist: IDENTIFIER COMMA identifierlist  */
#line 237 "./parser/grammar.y"
                                                        { (yyval.identifierlist) = new PairIdentifierList(new Identifier((yyvsp[-2].id)), (yyvsp[0].identifierlist)); }
#line 1603 "./parser/parser.cpp"
    break;

  case 52: /* identifierlist: IDENTIFIER  */
#line 238 "./parser/grammar.y"
                                                        { (yyval.identifierlist) = new LastIdentifierList(new Identifier((yyvsp[0].id))); }
#line 1609 "./parser/parser.cpp"
    break;

  case 53: /* unaryexpr: primaryexpr  */
#line 241 "./parser/grammar.y"
                               { (yyval.exp) = (yyvsp[0].exp); }
#line 1615 "./parser/parser.cpp"
    break;

  case 54: /* unaryexpr: unary_op unaryexpr  */
#line 242 "./parser/grammar.y"
                               { (yyval.exp) = new UnaryExp((yyvsp[0].exp), (yyvsp[-1].unaryoperator)); }
#line 1621 "./parser/parser.cpp"
    break;

  case 55: /* unary_op: PLUS  */
#line 245 "./parser/grammar.y"
                                { (yyval.unaryoperator) = PLUS_UNARY; }
#line 1627 "./parser/parser.cpp"
    break;

  case 56: /* unary_op: UMINUS  */
#line 246 "./parser/grammar.y"
                                { (yyval.unaryoperator) = MIN_UNARY; }
#line 1633 "./parser/parser.cpp"
    break;

  case 57: /* unary_op: NOT  */
#line 247 "./parser/grammar.y"
                                { (yyval.unaryoperator) = NOT_UNARY; }
#line 1639 "./parser/parser.cpp"
    break;

  case 58: /* operand: literal  */
#line 250 "./parser/grammar.y"
                                { (yyval.operand) = new LiteralOperand((yyvsp[0].literal)); }
#line 1645 "./parser/parser.cpp"
    break;

  case 59: /* operand: operandname  */
#line 251 "./parser/grammar.y"
                                { (yyval.operand) = new VariableOperand((yyvsp[0].identifier)); }
#line 1651 "./parser/parser.cpp"
    break;

  case 60: /* operand: LPAREN expr RPAREN  */
#line 252 "./parser/grammar.y"
                                { (yyval.operand) = new ExprOperand((yyvsp[-1].exp)); }
#line 1657 "./parser/parser.cpp"
    break;

  case 61: /* literal: basiclit  */
#line 255 "./parser/grammar.y"
                                { (yyval.literal) = (yyvsp[0].literal); }
#line 1663 "./parser/parser.cpp"
    break;

  case 62: /* basiclit: INTLITERAL  */
#line 258 "./parser/grammar.y"
                                { (yyval.literal) = new IntLiteral(*(yyvsp[0].intlit)); }
#line 1669 "./parser/parser.cpp"
    break;

  case 63: /* basiclit: BOOLLITERAL  */
#line 259 "./parser/grammar.y"
                                { (yyval.literal) = new BoolLiteral(*(yyvsp[0].boollit)); }
#line 1675 "./parser/parser.cpp"
    break;

  case 64: /* operandname: IDENTIFIER  */
#line 262 "./parser/grammar.y"
                                { (yyval.identifier) = new Identifier((yyvsp[0].id)); }
#line 1681 "./parser/parser.cpp"
    break;

  case 65: /* primaryexpr: operand  */
#line 265 "./parser/grammar.y"
                                { (yyval.exp) = new PrimaryExp((yyvsp[0].operand)); }
#line 1687 "./parser/parser.cpp"
    break;

  case 66: /* block: LBRACE statementlist RBRACE  */
#line 268 "./parser/grammar.y"
                                        { (yyval.block) = new Block((yyvsp[-1].stmlist)); }
#line 1693 "./parser/parser.cpp"
    break;

  case 67: /* statementlist: statement SEMICOLON  */
#line 271 "./parser/grammar.y"
                                                        { (yyval.stmlist) = new LastStmList((yyvsp[-1].stm)); }
#line 1699 "./parser/parser.cpp"
    break;

  case 68: /* statementlist: statement SEMICOLON statementlist  */
#line 272 "./parser/grammar.y"
                                                        { (yyval.stmlist) = new PairStmList((yyvsp[-2].stm), (yyvsp[0].stmlist));}
#line 1705 "./parser/parser.cpp"
    break;

  case 69: /* statement: declaration  */
#line 275 "./parser/grammar.y"
                                         { (yyval.stm) = new DeclStm((yyvsp[0].toplvldecl)); }
#line 1711 "./parser/parser.cpp"
    break;

  case 70: /* statement: block  */
#line 276 "./parser/grammar.y"
                                         { (yyval.stm) = new BlockStm((yyvsp[0].block)); }
#line 1717 "./parser/parser.cpp"
    break;

  case 71: /* statement: ifstatement  */
#line 277 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1723 "./parser/parser.cpp"
    break;

  case 72: /* statement: forstatement  */
#line 278 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1729 "./parser/parser.cpp"
    break;

  case 73: /* statement: returnstatement  */
#line 279 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1735 "./parser/parser.cpp"
    break;

  case 74: /* statement: simplestatement  */
#line 280 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1741 "./parser/parser.cpp"
    break;

  case 75: /* simplestatement: expressionstatement  */
#line 283 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1747 "./parser/parser.cpp"
    break;

  case 76: /* simplestatement: assignment  */
#line 284 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1753 "./parser/parser.cpp"
    break;

  case 77: /* simplestatement: incdecstatement  */
#line 285 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1759 "./parser/parser.cpp"
    break;

  case 78: /* simplestatement: emptystatement  */
#line 286 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1765 "./parser/parser.cpp"
    break;

  case 79: /* simplestatement: shortvardecl  */
#line 287 "./parser/grammar.y"
                                         {puts("shortvardecl");}
#line 1771 "./parser/parser.cpp"
    break;

  case 80: /* emptystatement: %empty  */
#line 290 "./parser/grammar.y"
                { (yyval.stm) = new EmptyStm();}
#line 1777 "./parser/parser.cpp"
    break;

  case 81: /* expressionstatement: expr  */
#line 292 "./parser/grammar.y"
                          { (yyval.stm) = new ExprStm((yyvsp[0].exp)); }
#line 1783 "./parser/parser.cpp"
    break;

  case 82: /* assignment: expressionlist assign_op expressionlist  */
#line 294 "./parser/grammar.y"
                                                    { (yyval.stm) = new AssignmentStm((yyvsp[-2].explist), (yyvsp[0].explist), (yyvsp[-1].assignoperator)); }
#line 1789 "./parser/parser.cpp"
    break;

  case 83: /* assign_op: ASSIGN  */
#line 296 "./parser/grammar.y"
                                                    { (yyval.assignoperator) = ASSIGN_OP;}
#line 1795 "./parser/parser.cpp"
    break;

  case 84: /* assign_op: PLUSASSIGN  */
#line 297 "./parser/grammar.y"
                                                    { (yyval.assignoperator) = PLUSASSIGN_OP; }
#line 1801 "./parser/parser.cpp"
    break;

  case 85: /* assign_op: MINASSIGN  */
#line 298 "./parser/grammar.y"
                                                    { (yyval.assignoperator) = MINASSIGN_OP; }
#line 1807 "./parser/parser.cpp"
    break;

  case 86: /* assign_op: MULASSIGN  */
#line 299 "./parser/grammar.y"
                                                    { (yyval.assignoperator) = MULASSIGN_OP; }
#line 1813 "./parser/parser.cpp"
    break;

  case 87: /* assign_op: DIVASSIGN  */
#line 300 "./parser/grammar.y"
                                                    { (yyval.assignoperator) = DIVASSIGN_OP;}
#line 1819 "./parser/parser.cpp"
    break;

  case 88: /* incdecstatement: expr INC  */
#line 303 "./parser/grammar.y"
                                                    { (yyval.stm) = new IncDecStm((yyvsp[-1].exp), PLUSPLUS); }
#line 1825 "./parser/parser.cpp"
    break;

  case 89: /* incdecstatement: expr DEC  */
#line 304 "./parser/grammar.y"
                                                    { (yyval.stm) = new IncDecStm((yyvsp[-1].exp), MINMIN); }
#line 1831 "./parser/parser.cpp"
    break;

  case 90: /* ifstatement: IF simplestatement SEMICOLON expr block ELSE ifstatement  */
#line 308 "./parser/grammar.y"
                                                                        { (yyval.stm) = new IfStm((yyvsp[-5].stm), (yyvsp[-3].exp), (yyvsp[-2].block), nullptr, (yyvsp[0].stm)); }
#line 1837 "./parser/parser.cpp"
    break;

  case 91: /* ifstatement: IF simplestatement SEMICOLON expr block ELSE block  */
#line 309 "./parser/grammar.y"
                                                                        { (yyval.stm) = new IfStm((yyvsp[-5].stm), (yyvsp[-3].exp), (yyvsp[-2].block), (yyvsp[0].block), nullptr); }
#line 1843 "./parser/parser.cpp"
    break;

  case 92: /* ifstatement: IF expr block ELSE ifstatement  */
#line 310 "./parser/grammar.y"
                                                                        { (yyval.stm) = new IfStm(nullptr, (yyvsp[-3].exp), (yyvsp[-2].block), nullptr, (yyvsp[0].stm)); }
#line 1849 "./parser/parser.cpp"
    break;

  case 93: /* ifstatement: IF expr block ELSE block  */
#line 311 "./parser/grammar.y"
                                                                        { (yyval.stm) = new IfStm(nullptr, (yyvsp[-3].exp), (yyvsp[-2].block), (yyvsp[0].block), nullptr); }
#line 1855 "./parser/parser.cpp"
    break;

  case 94: /* ifstatement: IF expr block  */
#line 312 "./parser/grammar.y"
                                                                        { (yyval.stm) = new IfStm(nullptr, (yyvsp[-1].exp), (yyvsp[0].block), nullptr, nullptr); }
#line 1861 "./parser/parser.cpp"
    break;

  case 95: /* forstatement: FOR condition block  */
#line 315 "./parser/grammar.y"
                                        { (yyval.stm) = new ForCondStm((yyvsp[-1].exp), (yyvsp[0].block)); }
#line 1867 "./parser/parser.cpp"
    break;

  case 96: /* forstatement: FOR forclause block  */
#line 316 "./parser/grammar.y"
                                        { (yyval.stm) = new ForClauseStm((yyvsp[-1].forclause), (yyvsp[0].block)); }
#line 1873 "./parser/parser.cpp"
    break;

  case 97: /* forstatement: FOR block  */
#line 317 "./parser/grammar.y"
                                        { (yyval.stm) = new ForStm((yyvsp[0].block)); }
#line 1879 "./parser/parser.cpp"
    break;

  case 98: /* condition: expr  */
#line 320 "./parser/grammar.y"
                                        { (yyval.exp) = (yyvsp[0].exp); }
#line 1885 "./parser/parser.cpp"
    break;

  case 99: /* forclause: initstatement SEMICOLON condition SEMICOLON poststatement  */
#line 322 "./parser/grammar.y"
                                                                        { (yyval.forclause) = new ForClause((yyvsp[-4].stm), (yyvsp[-2].exp), (yyvsp[0].stm)); }
#line 1891 "./parser/parser.cpp"
    break;

  case 100: /* initstatement: simplestatement  */
#line 325 "./parser/grammar.y"
                                { (yyval.stm) = (yyvsp[0].stm); }
#line 1897 "./parser/parser.cpp"
    break;

  case 101: /* poststatement: simplestatement  */
#line 327 "./parser/grammar.y"
                                 { (yyval.stm) = (yyvsp[0].stm); }
#line 1903 "./parser/parser.cpp"
    break;

  case 102: /* returnstatement: RETURN expressionlist  */
#line 329 "./parser/grammar.y"
                                         { (yyval.stm) = new ReturnStm((yyvsp[0].explist)); }
#line 1909 "./parser/parser.cpp"
    break;

  case 103: /* returnstatement: RETURN  */
#line 330 "./parser/grammar.y"
                                         { (yyval.stm) = new ReturnStm(nullptr); }
#line 1915 "./parser/parser.cpp"
    break;


#line 1919 "./parser/parser.cpp"

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

#line 333 "./parser/grammar.y"
