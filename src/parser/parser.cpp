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
  YYSYMBOL_RCOMMA = 44,                    /* RCOMMA  */
  YYSYMBOL_UMINUS = 45,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_sourcefile = 47,                /* sourcefile  */
  YYSYMBOL_topleveldeclarations = 48,      /* topleveldeclarations  */
  YYSYMBOL_packageclause = 49,             /* packageclause  */
  YYSYMBOL_packagename = 50,               /* packagename  */
  YYSYMBOL_topleveldecl = 51,              /* topleveldecl  */
  YYSYMBOL_declaration = 52,               /* declaration  */
  YYSYMBOL_vardecl = 53,                   /* vardecl  */
  YYSYMBOL_shortvardecl = 54,              /* shortvardecl  */
  YYSYMBOL_varspec = 55,                   /* varspec  */
  YYSYMBOL_functiondeclaration = 56,       /* functiondeclaration  */
  YYSYMBOL_functionname = 57,              /* functionname  */
  YYSYMBOL_functionbody = 58,              /* functionbody  */
  YYSYMBOL_signature = 59,                 /* signature  */
  YYSYMBOL_type = 60,                      /* type  */
  YYSYMBOL_typename = 61,                  /* typename  */
  YYSYMBOL_result = 62,                    /* result  */
  YYSYMBOL_parameters = 63,                /* parameters  */
  YYSYMBOL_parameterlist = 64,             /* parameterlist  */
  YYSYMBOL_parameterdecl = 65,             /* parameterdecl  */
  YYSYMBOL_expr = 66,                      /* expr  */
  YYSYMBOL_expressionlist = 67,            /* expressionlist  */
  YYSYMBOL_identifierlist = 68,            /* identifierlist  */
  YYSYMBOL_unaryexpr = 69,                 /* unaryexpr  */
  YYSYMBOL_unary_op = 70,                  /* unary_op  */
  YYSYMBOL_operand = 71,                   /* operand  */
  YYSYMBOL_literal = 72,                   /* literal  */
  YYSYMBOL_basiclit = 73,                  /* basiclit  */
  YYSYMBOL_operandname = 74,               /* operandname  */
  YYSYMBOL_primaryexpr = 75,               /* primaryexpr  */
  YYSYMBOL_arguments = 76,                 /* arguments  */
  YYSYMBOL_block = 77,                     /* block  */
  YYSYMBOL_statementlist = 78,             /* statementlist  */
  YYSYMBOL_statement = 79,                 /* statement  */
  YYSYMBOL_simplestatement = 80,           /* simplestatement  */
  YYSYMBOL_emptystatement = 81,            /* emptystatement  */
  YYSYMBOL_expressionstatement = 82,       /* expressionstatement  */
  YYSYMBOL_assignment = 83,                /* assignment  */
  YYSYMBOL_assign_op = 84,                 /* assign_op  */
  YYSYMBOL_incdecstatement = 85,           /* incdecstatement  */
  YYSYMBOL_ifstatement = 86,               /* ifstatement  */
  YYSYMBOL_forstatement = 87,              /* forstatement  */
  YYSYMBOL_condition = 88,                 /* condition  */
  YYSYMBOL_forclause = 89,                 /* forclause  */
  YYSYMBOL_initstatement = 90,             /* initstatement  */
  YYSYMBOL_poststatement = 91,             /* poststatement  */
  YYSYMBOL_returnstatement = 92            /* returnstatement  */
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
#define YYLAST   356

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


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
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   128,   128,   137,   156,   157,   160,   162,   165,   166,
     169,   173,   174,   177,   180,   181,   182,   185,   187,   189,
     191,   192,   195,   196,   199,   200,   201,   204,   205,   208,
     209,   210,   213,   214,   217,   218,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   236,
     237,   240,   241,   244,   245,   248,   249,   250,   253,   254,
     255,   258,   261,   262,   265,   268,   269,   272,   273,   274,
     278,   281,   282,   285,   286,   287,   288,   289,   290,   293,
     294,   295,   296,   297,   300,   302,   304,   306,   307,   308,
     309,   310,   313,   314,   318,   319,   320,   321,   322,   325,
     326,   327,   330,   332,   335,   337,   339,   340
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
  "INTLITERAL", "RCOMMA", "UMINUS", "$accept", "sourcefile",
  "topleveldeclarations", "packageclause", "packagename", "topleveldecl",
  "declaration", "vardecl", "shortvardecl", "varspec",
  "functiondeclaration", "functionname", "functionbody", "signature",
  "type", "typename", "result", "parameters", "parameterlist",
  "parameterdecl", "expr", "expressionlist", "identifierlist", "unaryexpr",
  "unary_op", "operand", "literal", "basiclit", "operandname",
  "primaryexpr", "arguments", "block", "statementlist", "statement",
  "simplestatement", "emptystatement", "expressionstatement", "assignment",
  "assign_op", "incdecstatement", "ifstatement", "forstatement",
  "condition", "forclause", "initstatement", "poststatement",
  "returnstatement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-98)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-103)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -26,    27,    25,   -98,   -98,   -98,    -2,    10,     7,
     -98,    55,   -98,   -98,   -98,    28,    32,   -98,    63,   -98,
      75,    -2,    88,    28,   -98,   -98,    21,   137,   -98,    53,
     -98,     6,    80,    48,   -98,    86,   -98,    89,   137,   -98,
     -98,   -98,   -98,   -98,   -98,   295,    70,   -98,   137,   -98,
     -98,   -98,   -98,    96,   137,   -98,    19,   -98,    52,   -98,
      21,   126,   -98,   -98,     6,   -98,   -98,   -98,   -98,   -98,
     247,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   -98,    84,   112,    70,   -98,     8,
     -98,   137,   150,   131,    45,   -98,   -98,   181,   283,    76,
     -98,   104,   116,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,    89,   -98,    85,    85,   -98,   -98,   323,   314,   142,
     142,   142,   142,   142,   142,   295,   -98,   109,   -98,   -98,
     -98,    70,   203,   121,   225,   -98,   -98,    80,    80,   125,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   137,   137,   -98,
      69,   -98,   128,   106,   137,   -98,   -98,   137,    70,    70,
     -98,   -98,    62,   268,   295,   140,   -98,   -98,   110,   150,
      62,   -98,   -98,   -98,   -98
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
       0,    84,    17,    19,     0,    28,    20,    27,    12,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,     0,     0,    14,    31,     0,
      34,   107,    84,    84,    64,    73,    83,    50,     0,     0,
      74,     0,     0,    78,    82,    79,    80,    81,    75,    76,
      77,    35,    60,    45,    46,    43,    44,    48,    47,    41,
      42,    39,    40,    37,    38,    49,    67,     0,    66,    30,
      32,   106,    50,     0,    50,   101,   104,     0,     0,     0,
      92,    93,    88,    89,    90,    91,    87,     0,     0,    70,
      71,    68,     0,    98,     0,    99,   100,     0,    86,    13,
      72,    69,     0,     0,   102,     0,    97,    96,     0,    84,
       0,   105,   103,    95,    94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -98,   -98,   129,   -98,   -98,   -98,   -58,   -98,   -98,   139,
     -98,   -98,   -98,   -98,   -10,   -98,   -98,   122,   -98,    74,
     -37,   -25,    -1,   118,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -32,    14,   -98,   -88,   -98,   -98,   -98,   -98,   -98,
     -97,   -98,    13,   -98,   -98,   -98,   -98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,    10,     3,     5,    11,    12,    13,    96,    17,
      14,    20,    62,    32,    57,    30,    66,    33,    58,    59,
      45,    98,    99,    47,    48,    49,    50,    51,    52,    53,
      86,   100,   101,   102,   103,   104,   105,   106,   147,   107,
     108,   109,   137,   138,   139,   172,   110
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    70,    46,    95,   133,   136,     8,    18,    29,     1,
      24,    25,    24,    25,    18,     4,    37,    26,    55,    26,
     129,    15,    36,    65,    97,    24,    25,     6,     7,    87,
      60,   -24,    26,     9,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    56,    19,    56,
      90,    16,    24,    25,   111,   132,   134,    23,    21,    64,
     127,   135,    28,    60,    88,   167,   131,    24,    25,    16,
      23,    92,   -84,   174,    26,    61,    91,     8,    92,    93,
      38,   171,    61,    23,    39,   -52,    31,    54,    60,    28,
      89,    35,    95,    61,    40,    38,   126,    27,    68,    39,
     153,    69,    73,    74,    28,   155,   156,    85,    83,    40,
      94,    42,    43,    97,    44,   128,   148,   163,   149,   150,
     164,   151,   158,   159,   154,    41,    42,    43,   157,    44,
     166,   168,    97,    91,     8,    92,    93,    38,   173,    61,
     161,    39,    38,   169,    61,   162,    39,    83,    38,   170,
      34,    40,    39,   152,    22,    67,    40,    71,    72,    73,
      74,    38,    40,   130,   160,    39,    84,    94,    42,    43,
     165,    44,    94,    42,    43,    40,    44,     0,    41,    42,
      43,     0,    44,     0,   -85,     0,     0,     0,     0,     0,
       0,    94,    42,    43,   -85,    44,    71,    72,    73,    74,
       0,     0,     0,     0,    75,    76,   -85,   140,   141,    77,
      78,    79,    80,    81,    82,     0,    61,     0,    71,    72,
      73,    74,     0,     0,     0,     0,    75,    76,   -85,   140,
     141,    77,    78,    79,    80,    81,    82,     0,  -102,     0,
      71,    72,    73,    74,     0,     0,     0,     0,    75,    76,
       0,   140,   141,    77,    78,    79,    80,    81,    82,   112,
       0,     0,    71,    72,    73,    74,     0,     0,     0,     0,
      75,    76,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    61,     0,    71,    72,    73,    74,     0,     0,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,   142,   143,   144,   145,     0,     0,     0,     0,
      71,    72,    73,    74,     0,     0,     0,   146,    75,    76,
       0,    83,     0,    77,    78,    79,    80,    81,    82,    71,
      72,    73,    74,     0,     0,     0,     0,    75,    71,    72,
      73,    74,    77,    78,    79,    80,    81,    82,     0,     0,
       0,    77,    78,    79,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
      32,    38,    27,    61,    92,    93,     8,     8,    18,     6,
       4,     5,     4,     5,    15,    41,    26,    11,    12,    11,
      12,    11,    23,    33,    61,     4,     5,     0,     3,    54,
      31,    12,    11,    35,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    41,    41,    41,
      60,    41,     4,     5,    64,    92,    93,    38,     3,    11,
      85,    93,    41,    64,    12,   162,    91,     4,     5,    41,
      38,     9,     3,   170,    11,    13,     7,     8,     9,    10,
      11,   169,    13,    38,    15,    40,    11,    34,    89,    41,
      38,     3,   150,    13,    25,    11,    12,    34,    12,    15,
     132,    12,    17,    18,    41,   137,   138,    11,    38,    25,
      41,    42,    43,   150,    45,     3,    40,   154,    14,     3,
     157,    12,   147,   148,     3,    41,    42,    43,     3,    45,
     162,   163,   169,     7,     8,     9,    10,    11,   170,    13,
      12,    15,    11,     3,    13,    39,    15,    38,    11,    39,
      21,    25,    15,    44,    15,    33,    25,    15,    16,    17,
      18,    11,    25,    89,   150,    15,    48,    41,    42,    43,
     157,    45,    41,    42,    43,    25,    45,    -1,    41,    42,
      43,    -1,    45,    -1,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    13,    45,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    23,    24,     3,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    23,    24,     3,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    13,    -1,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    12,
      -1,    -1,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      23,    24,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    13,    -1,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    23,    24,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    -1,    -1,    -1,    34,    23,    24,
      -1,    38,    -1,    28,    29,    30,    31,    32,    33,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    23,    15,    16,
      17,    18,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    47,    49,    41,    50,     0,     3,     8,    35,
      48,    51,    52,    53,    56,    11,    41,    55,    68,    41,
      57,     3,    55,    38,     4,     5,    11,    34,    41,    60,
      61,    11,    59,    63,    48,     3,    68,    60,    11,    15,
      25,    41,    42,    43,    45,    66,    67,    69,    70,    71,
      72,    73,    74,    75,    34,    12,    41,    60,    64,    65,
      68,    13,    58,    77,    11,    60,    62,    63,    12,    12,
      66,    15,    16,    17,    18,    23,    24,    28,    29,    30,
      31,    32,    33,    38,    69,    11,    76,    67,    12,    38,
      60,     7,     9,    10,    41,    52,    54,    66,    67,    68,
      77,    78,    79,    80,    81,    82,    83,    85,    86,    87,
      92,    60,    12,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    12,    67,     3,    12,
      65,    67,    66,    80,    66,    77,    80,    88,    89,    90,
      26,    27,    19,    20,    21,    22,    34,    84,    40,    14,
       3,    12,    44,    77,     3,    77,    77,     3,    67,    67,
      78,    12,    39,    66,    66,    88,    77,    86,    77,     3,
      39,    80,    91,    77,    86
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    49,    50,    51,    51,
      52,    53,    53,    54,    55,    55,    55,    56,    57,    58,
      59,    59,    60,    60,    61,    61,    61,    62,    62,    63,
      63,    63,    64,    64,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    70,    71,    71,
      71,    72,    73,    73,    74,    75,    75,    76,    76,    76,
      77,    78,    78,    79,    79,    79,    79,    79,    79,    80,
      80,    80,    80,    80,    81,    82,    83,    84,    84,    84,
      84,    84,    85,    85,    86,    86,    86,    86,    86,    87,
      87,    87,    88,    89,    90,    91,    92,    92
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
       3,     1,     1,     1,     1,     1,     3,     2,     3,     4,
       3,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     3,     1,     1,     1,
       1,     1,     2,     2,     7,     7,     5,     5,     3,     3,
       3,     2,     1,     5,     1,     1,     2,     1
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
#line 128 "./parser/grammar.y"
                                                                        {(yyval.srcfile) = new SrcFile((yyvsp[-2].packageclause), nullptr, (yyvsp[0].decllist));
                                                                        ast = (yyval.srcfile);
                                                                        }
#line 1316 "./parser/parser.cpp"
    break;

  case 3: /* sourcefile: packageclause SEMICOLON  */
#line 137 "./parser/grammar.y"
                                                                        {(yyval.srcfile) = new SrcFile((yyvsp[-1].packageclause), nullptr, nullptr);
                                                                        ast = (yyval.srcfile);
                                                                        }
#line 1324 "./parser/parser.cpp"
    break;

  case 4: /* topleveldeclarations: topleveldecl SEMICOLON topleveldeclarations  */
#line 156 "./parser/grammar.y"
                                                                   {(yyval.decllist) = new PairDeclList((yyvsp[-2].toplvldecl), (yyvsp[0].decllist));}
#line 1330 "./parser/parser.cpp"
    break;

  case 5: /* topleveldeclarations: topleveldecl SEMICOLON  */
#line 157 "./parser/grammar.y"
                                                                   {(yyval.decllist) = new LastDeclList((yyvsp[-1].toplvldecl));}
#line 1336 "./parser/parser.cpp"
    break;

  case 6: /* packageclause: PACKAGE packagename  */
#line 160 "./parser/grammar.y"
                                    {(yyval.packageclause) = new PackageClause((yyvsp[0].identifier));}
#line 1342 "./parser/parser.cpp"
    break;

  case 7: /* packagename: IDENTIFIER  */
#line 162 "./parser/grammar.y"
                        {(yyval.identifier) = new Identifier((yyvsp[0].id));}
#line 1348 "./parser/parser.cpp"
    break;

  case 8: /* topleveldecl: declaration  */
#line 165 "./parser/grammar.y"
                                   {(yyval.toplvldecl) = (yyvsp[0].toplvldecl); }
#line 1354 "./parser/parser.cpp"
    break;

  case 9: /* topleveldecl: functiondeclaration  */
#line 166 "./parser/grammar.y"
                                   {(yyval.toplvldecl) = (yyvsp[0].toplvldecl); }
#line 1360 "./parser/parser.cpp"
    break;

  case 10: /* declaration: vardecl  */
#line 169 "./parser/grammar.y"
                         {(yyval.toplvldecl) = (yyvsp[0].toplvldecl); }
#line 1366 "./parser/parser.cpp"
    break;

  case 11: /* vardecl: VAR varspec  */
#line 173 "./parser/grammar.y"
                                                            {(yyval.toplvldecl) = new VarDecl((yyvsp[0].varspec)); }
#line 1372 "./parser/parser.cpp"
    break;

  case 12: /* vardecl: VAR LPAREN varspec SEMICOLON RPAREN  */
#line 174 "./parser/grammar.y"
                                                            {(yyval.toplvldecl) = new VarDecl((yyvsp[-2].varspec)); }
#line 1378 "./parser/parser.cpp"
    break;

  case 13: /* shortvardecl: identifierlist SHORTVARASSIGN expressionlist  */
#line 177 "./parser/grammar.y"
                                                            {puts("identifierlist SHORTVARASSIGN expressionlist"); }
#line 1384 "./parser/parser.cpp"
    break;

  case 14: /* varspec: identifierlist type ASSIGN expressionlist  */
#line 180 "./parser/grammar.y"
                                                        {(yyval.varspec) = new VarSpec((yyvsp[-3].identifierlist), (yyvsp[-2].type), (yyvsp[0].explist)); }
#line 1390 "./parser/parser.cpp"
    break;

  case 15: /* varspec: identifierlist type  */
#line 181 "./parser/grammar.y"
                                                        {(yyval.varspec) = new VarSpec((yyvsp[-1].identifierlist), (yyvsp[0].type), nullptr);}
#line 1396 "./parser/parser.cpp"
    break;

  case 16: /* varspec: identifierlist ASSIGN expressionlist  */
#line 182 "./parser/grammar.y"
                                                        {(yyval.varspec) = new VarSpec((yyvsp[-2].identifierlist), nullptr, (yyvsp[0].explist)); }
#line 1402 "./parser/parser.cpp"
    break;

  case 17: /* functiondeclaration: FUNC functionname signature functionbody  */
#line 185 "./parser/grammar.y"
                                                              {(yyval.toplvldecl) = new FunctionDecl((yyvsp[-2].identifier), (yyvsp[-1].signature), (yyvsp[0].block)); }
#line 1408 "./parser/parser.cpp"
    break;

  case 18: /* functionname: IDENTIFIER  */
#line 187 "./parser/grammar.y"
                          {(yyval.identifier) = new Identifier((yyvsp[0].id)); }
#line 1414 "./parser/parser.cpp"
    break;

  case 19: /* functionbody: block  */
#line 189 "./parser/grammar.y"
                     {(yyval.block) = (yyvsp[0].block); }
#line 1420 "./parser/parser.cpp"
    break;

  case 20: /* signature: parameters result  */
#line 191 "./parser/grammar.y"
                                { (yyval.signature) = new Signature((yyvsp[-1].paramlist), (yyvsp[0].result)); }
#line 1426 "./parser/parser.cpp"
    break;

  case 21: /* signature: parameters  */
#line 192 "./parser/grammar.y"
                                { (yyval.signature) = new Signature((yyvsp[0].paramlist), nullptr); }
#line 1432 "./parser/parser.cpp"
    break;

  case 22: /* type: typename  */
#line 195 "./parser/grammar.y"
                                { (yyval.type) = (yyvsp[0].type); }
#line 1438 "./parser/parser.cpp"
    break;

  case 23: /* type: LPAREN type RPAREN  */
#line 196 "./parser/grammar.y"
                                { (yyval.type) = (yyvsp[-1].type); }
#line 1444 "./parser/parser.cpp"
    break;

  case 24: /* typename: IDENTIFIER  */
#line 199 "./parser/grammar.y"
                                { puts("IDENTIFIER"); }
#line 1450 "./parser/parser.cpp"
    break;

  case 25: /* typename: INTEGER  */
#line 200 "./parser/grammar.y"
                                { (yyval.type) = new IntegerType(); }
#line 1456 "./parser/parser.cpp"
    break;

  case 26: /* typename: BOOLEAN  */
#line 201 "./parser/grammar.y"
                                { (yyval.type) = new BooleanType(); }
#line 1462 "./parser/parser.cpp"
    break;

  case 27: /* result: parameters  */
#line 204 "./parser/grammar.y"
                                { (yyval.result) = new ParametersResult((yyvsp[0].paramlist)); }
#line 1468 "./parser/parser.cpp"
    break;

  case 28: /* result: type  */
#line 205 "./parser/grammar.y"
                                { (yyval.result) = new TypeResult((yyvsp[0].type)); }
#line 1474 "./parser/parser.cpp"
    break;

  case 29: /* parameters: LPAREN RPAREN  */
#line 208 "./parser/grammar.y"
                                                  { (yyval.paramlist) = nullptr; }
#line 1480 "./parser/parser.cpp"
    break;

  case 30: /* parameters: LPAREN parameterlist COMMA RPAREN  */
#line 209 "./parser/grammar.y"
                                                  { (yyval.paramlist) = (yyvsp[-2].paramlist); }
#line 1486 "./parser/parser.cpp"
    break;

  case 31: /* parameters: LPAREN parameterlist RPAREN  */
#line 210 "./parser/grammar.y"
                                                  { (yyval.paramlist) = (yyvsp[-1].paramlist); }
#line 1492 "./parser/parser.cpp"
    break;

  case 32: /* parameterlist: parameterlist COMMA parameterdecl  */
#line 213 "./parser/grammar.y"
                                                     { (yyval.paramlist) = new PairParamList((yyvsp[0].paramdecl), (yyvsp[-2].paramlist)); }
#line 1498 "./parser/parser.cpp"
    break;

  case 33: /* parameterlist: parameterdecl  */
#line 214 "./parser/grammar.y"
                                                     { (yyval.paramlist) = new LastParamList((yyvsp[0].paramdecl)); }
#line 1504 "./parser/parser.cpp"
    break;

  case 34: /* parameterdecl: identifierlist type  */
#line 217 "./parser/grammar.y"
                                                { (yyval.paramdecl) = new ParameterDecl((yyvsp[0].type), (yyvsp[-1].identifierlist)); }
#line 1510 "./parser/parser.cpp"
    break;

  case 35: /* parameterdecl: type  */
#line 218 "./parser/grammar.y"
                                                { (yyval.paramdecl) = new ParameterDecl((yyvsp[0].type), nullptr); }
#line 1516 "./parser/parser.cpp"
    break;

  case 36: /* expr: unaryexpr  */
#line 221 "./parser/grammar.y"
                                { (yyval.exp) = (yyvsp[0].exp); }
#line 1522 "./parser/parser.cpp"
    break;

  case 37: /* expr: expr EQ expr  */
#line 222 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), EQ_BIN); }
#line 1528 "./parser/parser.cpp"
    break;

  case 38: /* expr: expr NE expr  */
#line 223 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), NE_BIN); }
#line 1534 "./parser/parser.cpp"
    break;

  case 39: /* expr: expr LT expr  */
#line 224 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), LT_BIN); }
#line 1540 "./parser/parser.cpp"
    break;

  case 40: /* expr: expr LE expr  */
#line 225 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), LE_BIN); }
#line 1546 "./parser/parser.cpp"
    break;

  case 41: /* expr: expr GT expr  */
#line 226 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), GT_BIN); }
#line 1552 "./parser/parser.cpp"
    break;

  case 42: /* expr: expr GE expr  */
#line 227 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), GE_BIN); }
#line 1558 "./parser/parser.cpp"
    break;

  case 43: /* expr: expr MUL expr  */
#line 228 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), MUL_BIN); }
#line 1564 "./parser/parser.cpp"
    break;

  case 44: /* expr: expr DIV expr  */
#line 229 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), DIV_BIN); }
#line 1570 "./parser/parser.cpp"
    break;

  case 45: /* expr: expr PLUS expr  */
#line 230 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), PLUS_BIN); }
#line 1576 "./parser/parser.cpp"
    break;

  case 46: /* expr: expr MIN expr  */
#line 231 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), MIN_BIN); }
#line 1582 "./parser/parser.cpp"
    break;

  case 47: /* expr: expr OR expr  */
#line 232 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), OR_BIN); }
#line 1588 "./parser/parser.cpp"
    break;

  case 48: /* expr: expr AND expr  */
#line 233 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), AND_BIN); }
#line 1594 "./parser/parser.cpp"
    break;

  case 49: /* expressionlist: expressionlist COMMA expr  */
#line 236 "./parser/grammar.y"
                                                { (yyval.explist) = new PairExpList((yyvsp[0].exp), (yyvsp[-2].explist)); }
#line 1600 "./parser/parser.cpp"
    break;

  case 50: /* expressionlist: expr  */
#line 237 "./parser/grammar.y"
                                                { (yyval.explist) = new LastExpList((yyvsp[0].exp)); }
#line 1606 "./parser/parser.cpp"
    break;

  case 51: /* identifierlist: IDENTIFIER COMMA identifierlist  */
#line 240 "./parser/grammar.y"
                                                        { (yyval.identifierlist) = new PairIdentifierList(new Identifier((yyvsp[-2].id)), (yyvsp[0].identifierlist)); }
#line 1612 "./parser/parser.cpp"
    break;

  case 52: /* identifierlist: IDENTIFIER  */
#line 241 "./parser/grammar.y"
                                                        { (yyval.identifierlist) = new LastIdentifierList(new Identifier((yyvsp[0].id))); }
#line 1618 "./parser/parser.cpp"
    break;

  case 53: /* unaryexpr: primaryexpr  */
#line 244 "./parser/grammar.y"
                               { (yyval.exp) = (yyvsp[0].exp); }
#line 1624 "./parser/parser.cpp"
    break;

  case 54: /* unaryexpr: unary_op unaryexpr  */
#line 245 "./parser/grammar.y"
                               { (yyval.exp) = new UnaryExp((yyvsp[0].exp), (yyvsp[-1].unaryoperator)); }
#line 1630 "./parser/parser.cpp"
    break;

  case 55: /* unary_op: PLUS  */
#line 248 "./parser/grammar.y"
                                { (yyval.unaryoperator) = PLUS_UNARY; }
#line 1636 "./parser/parser.cpp"
    break;

  case 56: /* unary_op: UMINUS  */
#line 249 "./parser/grammar.y"
                                { (yyval.unaryoperator) = MIN_UNARY; }
#line 1642 "./parser/parser.cpp"
    break;

  case 57: /* unary_op: NOT  */
#line 250 "./parser/grammar.y"
                                { (yyval.unaryoperator) = NOT_UNARY; }
#line 1648 "./parser/parser.cpp"
    break;

  case 58: /* operand: literal  */
#line 253 "./parser/grammar.y"
                                { (yyval.operand) = new LiteralOperand((yyvsp[0].literal)); }
#line 1654 "./parser/parser.cpp"
    break;

  case 59: /* operand: operandname  */
#line 254 "./parser/grammar.y"
                                { (yyval.operand) = new VariableOperand((yyvsp[0].identifier)); }
#line 1660 "./parser/parser.cpp"
    break;

  case 60: /* operand: LPAREN expr RPAREN  */
#line 255 "./parser/grammar.y"
                                { (yyval.operand) = new ExprOperand((yyvsp[-1].exp)); }
#line 1666 "./parser/parser.cpp"
    break;

  case 61: /* literal: basiclit  */
#line 258 "./parser/grammar.y"
                                { (yyval.literal) = (yyvsp[0].literal); }
#line 1672 "./parser/parser.cpp"
    break;

  case 62: /* basiclit: INTLITERAL  */
#line 261 "./parser/grammar.y"
                                { (yyval.literal) = new IntLiteral(*(yyvsp[0].intlit)); }
#line 1678 "./parser/parser.cpp"
    break;

  case 63: /* basiclit: BOOLLITERAL  */
#line 262 "./parser/grammar.y"
                                { (yyval.literal) = new BoolLiteral(*(yyvsp[0].boollit)); }
#line 1684 "./parser/parser.cpp"
    break;

  case 64: /* operandname: IDENTIFIER  */
#line 265 "./parser/grammar.y"
                                { (yyval.identifier) = new Identifier((yyvsp[0].id)); }
#line 1690 "./parser/parser.cpp"
    break;

  case 65: /* primaryexpr: operand  */
#line 268 "./parser/grammar.y"
                                                  { (yyval.exp) = new OperandExp((yyvsp[0].operand)); }
#line 1696 "./parser/parser.cpp"
    break;

  case 66: /* primaryexpr: primaryexpr arguments SEMICOLON  */
#line 269 "./parser/grammar.y"
                                                  { (yyval.exp) = new FunctionCall((yyvsp[-2].exp), (yyvsp[-1].explist)); }
#line 1702 "./parser/parser.cpp"
    break;

  case 67: /* arguments: LPAREN RPAREN  */
#line 272 "./parser/grammar.y"
                                                                  { (yyval.explist) = nullptr; }
#line 1708 "./parser/parser.cpp"
    break;

  case 68: /* arguments: LPAREN expressionlist RPAREN  */
#line 273 "./parser/grammar.y"
                                                                  { (yyval.explist) = (yyvsp[-1].explist); }
#line 1714 "./parser/parser.cpp"
    break;

  case 69: /* arguments: LPAREN expressionlist RCOMMA RPAREN  */
#line 274 "./parser/grammar.y"
                                                                  { (yyval.explist) = (yyvsp[-2].explist); }
#line 1720 "./parser/parser.cpp"
    break;

  case 70: /* block: LBRACE statementlist RBRACE  */
#line 278 "./parser/grammar.y"
                                        { (yyval.block) = new Block((yyvsp[-1].stmlist)); }
#line 1726 "./parser/parser.cpp"
    break;

  case 71: /* statementlist: statement SEMICOLON  */
#line 281 "./parser/grammar.y"
                                                        { (yyval.stmlist) = new LastStmList((yyvsp[-1].stm)); }
#line 1732 "./parser/parser.cpp"
    break;

  case 72: /* statementlist: statement SEMICOLON statementlist  */
#line 282 "./parser/grammar.y"
                                                        { (yyval.stmlist) = new PairStmList((yyvsp[-2].stm), (yyvsp[0].stmlist));}
#line 1738 "./parser/parser.cpp"
    break;

  case 73: /* statement: declaration  */
#line 285 "./parser/grammar.y"
                                         { (yyval.stm) = new DeclStm((yyvsp[0].toplvldecl)); }
#line 1744 "./parser/parser.cpp"
    break;

  case 74: /* statement: block  */
#line 286 "./parser/grammar.y"
                                         { (yyval.stm) = new BlockStm((yyvsp[0].block)); }
#line 1750 "./parser/parser.cpp"
    break;

  case 75: /* statement: ifstatement  */
#line 287 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1756 "./parser/parser.cpp"
    break;

  case 76: /* statement: forstatement  */
#line 288 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1762 "./parser/parser.cpp"
    break;

  case 77: /* statement: returnstatement  */
#line 289 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1768 "./parser/parser.cpp"
    break;

  case 78: /* statement: simplestatement  */
#line 290 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1774 "./parser/parser.cpp"
    break;

  case 79: /* simplestatement: expressionstatement  */
#line 293 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1780 "./parser/parser.cpp"
    break;

  case 80: /* simplestatement: assignment  */
#line 294 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1786 "./parser/parser.cpp"
    break;

  case 81: /* simplestatement: incdecstatement  */
#line 295 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1792 "./parser/parser.cpp"
    break;

  case 82: /* simplestatement: emptystatement  */
#line 296 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1798 "./parser/parser.cpp"
    break;

  case 83: /* simplestatement: shortvardecl  */
#line 297 "./parser/grammar.y"
                                         {puts("shortvardecl");}
#line 1804 "./parser/parser.cpp"
    break;

  case 84: /* emptystatement: %empty  */
#line 300 "./parser/grammar.y"
                { (yyval.stm) = new EmptyStm();}
#line 1810 "./parser/parser.cpp"
    break;

  case 85: /* expressionstatement: expr  */
#line 302 "./parser/grammar.y"
                          { (yyval.stm) = new ExprStm((yyvsp[0].exp)); }
#line 1816 "./parser/parser.cpp"
    break;

  case 86: /* assignment: expressionlist assign_op expressionlist  */
#line 304 "./parser/grammar.y"
                                                    { (yyval.stm) = new AssignmentStm((yyvsp[-2].explist), (yyvsp[0].explist), (yyvsp[-1].assignoperator)); }
#line 1822 "./parser/parser.cpp"
    break;

  case 87: /* assign_op: ASSIGN  */
#line 306 "./parser/grammar.y"
                                                    { (yyval.assignoperator) = ASSIGN_OP;}
#line 1828 "./parser/parser.cpp"
    break;

  case 88: /* assign_op: PLUSASSIGN  */
#line 307 "./parser/grammar.y"
                                                    { (yyval.assignoperator) = PLUSASSIGN_OP; }
#line 1834 "./parser/parser.cpp"
    break;

  case 89: /* assign_op: MINASSIGN  */
#line 308 "./parser/grammar.y"
                                                    { (yyval.assignoperator) = MINASSIGN_OP; }
#line 1840 "./parser/parser.cpp"
    break;

  case 90: /* assign_op: MULASSIGN  */
#line 309 "./parser/grammar.y"
                                                    { (yyval.assignoperator) = MULASSIGN_OP; }
#line 1846 "./parser/parser.cpp"
    break;

  case 91: /* assign_op: DIVASSIGN  */
#line 310 "./parser/grammar.y"
                                                    { (yyval.assignoperator) = DIVASSIGN_OP;}
#line 1852 "./parser/parser.cpp"
    break;

  case 92: /* incdecstatement: expr INC  */
#line 313 "./parser/grammar.y"
                                                    { (yyval.stm) = new IncDecStm((yyvsp[-1].exp), PLUSPLUS); }
#line 1858 "./parser/parser.cpp"
    break;

  case 93: /* incdecstatement: expr DEC  */
#line 314 "./parser/grammar.y"
                                                    { (yyval.stm) = new IncDecStm((yyvsp[-1].exp), MINMIN); }
#line 1864 "./parser/parser.cpp"
    break;

  case 94: /* ifstatement: IF simplestatement SEMICOLON expr block ELSE ifstatement  */
#line 318 "./parser/grammar.y"
                                                                        { (yyval.stm) = new IfStm((yyvsp[-5].stm), (yyvsp[-3].exp), (yyvsp[-2].block), nullptr, (yyvsp[0].stm)); }
#line 1870 "./parser/parser.cpp"
    break;

  case 95: /* ifstatement: IF simplestatement SEMICOLON expr block ELSE block  */
#line 319 "./parser/grammar.y"
                                                                        { (yyval.stm) = new IfStm((yyvsp[-5].stm), (yyvsp[-3].exp), (yyvsp[-2].block), (yyvsp[0].block), nullptr); }
#line 1876 "./parser/parser.cpp"
    break;

  case 96: /* ifstatement: IF expr block ELSE ifstatement  */
#line 320 "./parser/grammar.y"
                                                                        { (yyval.stm) = new IfStm(nullptr, (yyvsp[-3].exp), (yyvsp[-2].block), nullptr, (yyvsp[0].stm)); }
#line 1882 "./parser/parser.cpp"
    break;

  case 97: /* ifstatement: IF expr block ELSE block  */
#line 321 "./parser/grammar.y"
                                                                        { (yyval.stm) = new IfStm(nullptr, (yyvsp[-3].exp), (yyvsp[-2].block), (yyvsp[0].block), nullptr); }
#line 1888 "./parser/parser.cpp"
    break;

  case 98: /* ifstatement: IF expr block  */
#line 322 "./parser/grammar.y"
                                                                        { (yyval.stm) = new IfStm(nullptr, (yyvsp[-1].exp), (yyvsp[0].block), nullptr, nullptr); }
#line 1894 "./parser/parser.cpp"
    break;

  case 99: /* forstatement: FOR condition block  */
#line 325 "./parser/grammar.y"
                                        { (yyval.stm) = new ForCondStm((yyvsp[-1].exp), (yyvsp[0].block)); }
#line 1900 "./parser/parser.cpp"
    break;

  case 100: /* forstatement: FOR forclause block  */
#line 326 "./parser/grammar.y"
                                        { (yyval.stm) = new ForClauseStm((yyvsp[-1].forclause), (yyvsp[0].block)); }
#line 1906 "./parser/parser.cpp"
    break;

  case 101: /* forstatement: FOR block  */
#line 327 "./parser/grammar.y"
                                        { (yyval.stm) = new ForStm((yyvsp[0].block)); }
#line 1912 "./parser/parser.cpp"
    break;

  case 102: /* condition: expr  */
#line 330 "./parser/grammar.y"
                                        { (yyval.exp) = (yyvsp[0].exp); }
#line 1918 "./parser/parser.cpp"
    break;

  case 103: /* forclause: initstatement SEMICOLON condition SEMICOLON poststatement  */
#line 332 "./parser/grammar.y"
                                                                        { (yyval.forclause) = new ForClause((yyvsp[-4].stm), (yyvsp[-2].exp), (yyvsp[0].stm)); }
#line 1924 "./parser/parser.cpp"
    break;

  case 104: /* initstatement: simplestatement  */
#line 335 "./parser/grammar.y"
                                { (yyval.stm) = (yyvsp[0].stm); }
#line 1930 "./parser/parser.cpp"
    break;

  case 105: /* poststatement: simplestatement  */
#line 337 "./parser/grammar.y"
                                 { (yyval.stm) = (yyvsp[0].stm); }
#line 1936 "./parser/parser.cpp"
    break;

  case 106: /* returnstatement: RETURN expressionlist  */
#line 339 "./parser/grammar.y"
                                         { (yyval.stm) = new ReturnStm((yyvsp[0].explist)); }
#line 1942 "./parser/parser.cpp"
    break;

  case 107: /* returnstatement: RETURN  */
#line 340 "./parser/grammar.y"
                                         { (yyval.stm) = new ReturnStm(nullptr); }
#line 1948 "./parser/parser.cpp"
    break;


#line 1952 "./parser/parser.cpp"

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

#line 343 "./parser/grammar.y"
