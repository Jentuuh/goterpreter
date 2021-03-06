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
  YYSYMBOL_PRINT = 41,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 42,                   /* PRINTLN  */
  YYSYMBOL_IDENTIFIER = 43,                /* IDENTIFIER  */
  YYSYMBOL_BOOLLITERAL = 44,               /* BOOLLITERAL  */
  YYSYMBOL_INTLITERAL = 45,                /* INTLITERAL  */
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
  YYSYMBOL_varspeclist = 56,               /* varspeclist  */
  YYSYMBOL_varspec = 57,                   /* varspec  */
  YYSYMBOL_functiondeclaration = 58,       /* functiondeclaration  */
  YYSYMBOL_functionname = 59,              /* functionname  */
  YYSYMBOL_functionbody = 60,              /* functionbody  */
  YYSYMBOL_signature = 61,                 /* signature  */
  YYSYMBOL_type = 62,                      /* type  */
  YYSYMBOL_typelist = 63,                  /* typelist  */
  YYSYMBOL_typename = 64,                  /* typename  */
  YYSYMBOL_result = 65,                    /* result  */
  YYSYMBOL_parameters = 66,                /* parameters  */
  YYSYMBOL_parameterlist = 67,             /* parameterlist  */
  YYSYMBOL_parameterdecl = 68,             /* parameterdecl  */
  YYSYMBOL_expr = 69,                      /* expr  */
  YYSYMBOL_expressionlist = 70,            /* expressionlist  */
  YYSYMBOL_identifierlist = 71,            /* identifierlist  */
  YYSYMBOL_identifier = 72,                /* identifier  */
  YYSYMBOL_unaryexpr = 73,                 /* unaryexpr  */
  YYSYMBOL_unary_op = 74,                  /* unary_op  */
  YYSYMBOL_operand = 75,                   /* operand  */
  YYSYMBOL_literal = 76,                   /* literal  */
  YYSYMBOL_basiclit = 77,                  /* basiclit  */
  YYSYMBOL_operandname = 78,               /* operandname  */
  YYSYMBOL_primaryexpr = 79,               /* primaryexpr  */
  YYSYMBOL_arguments = 80,                 /* arguments  */
  YYSYMBOL_block = 81,                     /* block  */
  YYSYMBOL_statementlist = 82,             /* statementlist  */
  YYSYMBOL_statement = 83,                 /* statement  */
  YYSYMBOL_simplestatement = 84,           /* simplestatement  */
  YYSYMBOL_emptystatement = 85,            /* emptystatement  */
  YYSYMBOL_expressionstatement = 86,       /* expressionstatement  */
  YYSYMBOL_assignment = 87,                /* assignment  */
  YYSYMBOL_assign_op = 88,                 /* assign_op  */
  YYSYMBOL_incdecstatement = 89,           /* incdecstatement  */
  YYSYMBOL_ifstatement = 90,               /* ifstatement  */
  YYSYMBOL_forstatement = 91,              /* forstatement  */
  YYSYMBOL_condition = 92,                 /* condition  */
  YYSYMBOL_forclause = 93,                 /* forclause  */
  YYSYMBOL_initstatement = 94,             /* initstatement  */
  YYSYMBOL_poststatement = 95,             /* poststatement  */
  YYSYMBOL_printstatement = 96,            /* printstatement  */
  YYSYMBOL_printlnstatement = 97,          /* printlnstatement  */
  YYSYMBOL_returnstatement = 98            /* returnstatement  */
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
#define YYLAST   362

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

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
       0,   135,   135,   144,   163,   164,   167,   169,   172,   173,
     176,   179,   180,   183,   184,   190,   191,   192,   195,   197,
     199,   201,   202,   203,   206,   207,   210,   211,   214,   215,
     218,   219,   222,   223,   224,   227,   228,   231,   232,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   250,   251,   254,   255,   258,   260,   261,   264,
     265,   266,   269,   270,   271,   274,   277,   278,   281,   284,
     285,   288,   289,   290,   294,   295,   298,   299,   302,   303,
     304,   305,   306,   307,   308,   309,   312,   313,   314,   315,
     319,   321,   323,   325,   326,   327,   328,   329,   332,   333,
     337,   338,   339,   340,   341,   344,   345,   346,   349,   350,
     352,   355,   357,   359,   360,   362,   363,   367,   368
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
  "IMPORT", "COMMA", "ELSE", "SHORTVARASSIGN", "PRINT", "PRINTLN",
  "IDENTIFIER", "BOOLLITERAL", "INTLITERAL", "RCOMMA", "UMINUS", "$accept",
  "sourcefile", "topleveldeclarations", "packageclause", "packagename",
  "topleveldecl", "declaration", "vardecl", "varspeclist", "varspec",
  "functiondeclaration", "functionname", "functionbody", "signature",
  "type", "typelist", "typename", "result", "parameters", "parameterlist",
  "parameterdecl", "expr", "expressionlist", "identifierlist",
  "identifier", "unaryexpr", "unary_op", "operand", "literal", "basiclit",
  "operandname", "primaryexpr", "arguments", "block", "statementlist",
  "statement", "simplestatement", "emptystatement", "expressionstatement",
  "assignment", "assign_op", "incdecstatement", "ifstatement",
  "forstatement", "condition", "forclause", "initstatement",
  "poststatement", "printstatement", "printlnstatement", "returnstatement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-161)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-109)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -28,    57,    14,  -161,  -161,  -161,    17,     3,    21,
    -161,    67,  -161,  -161,  -161,    41,  -161,  -161,    64,    55,
    -161,    90,    17,    91,    99,  -161,  -161,    83,    47,    85,
    -161,    41,     8,   113,   112,  -161,  -161,    41,   115,    47,
    -161,  -161,  -161,  -161,  -161,  -161,   310,    98,  -161,    47,
    -161,  -161,  -161,  -161,   118,    47,  -161,  -161,  -161,    36,
    -161,    83,   124,  -161,  -161,   141,  -161,  -161,  -161,   270,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,  -161,   139,  -161,    98,  -161,    18,  -161,
      47,    47,   145,  -161,   130,   137,  -161,   204,    86,  -161,
     143,   156,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,     8,   115,  -161,   125,   150,  -161,  -161,    10,
      10,  -161,  -161,   183,   329,   162,   162,   162,   162,   162,
     162,   310,  -161,     9,  -161,  -161,    98,   226,   170,   248,
    -161,  -161,   113,   113,   171,   160,   181,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,    47,  -161,    70,   115,    83,  -161,
    -161,   169,   147,    47,  -161,  -161,    47,  -161,    38,  -161,
      44,    98,  -161,  -161,  -161,  -161,    58,   291,   310,   184,
    -161,  -161,  -161,  -161,   152,    47,    58,  -161,  -161,  -161,
    -161
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     7,     6,     1,     3,     0,     0,
       2,     0,     8,    10,     9,     0,    56,    12,     0,    55,
      19,     0,     5,     0,    13,    28,    29,     0,     0,    16,
      24,     0,     0,     0,    23,     4,    11,     0,     0,     0,
      59,    60,    61,    68,    67,    66,    53,    17,    39,     0,
      69,    62,    65,    63,    57,     0,    54,    32,    38,     0,
      36,     0,    90,    18,    20,     0,    22,    14,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,    70,    15,    34,     0,    37,
     118,    90,    90,    75,     0,     0,    78,    53,     0,    79,
       0,     0,    83,    89,    86,    87,    88,    80,    81,    84,
      85,    82,     0,     0,    31,    24,     0,    30,    64,    48,
      49,    46,    47,    51,    50,    44,    45,    42,    43,    40,
      41,    52,    71,     0,    33,    35,   117,    53,     0,    53,
     107,   111,     0,     0,     0,     0,     0,    98,    99,    94,
      95,    96,    97,    93,     0,    74,    76,    38,     0,    21,
      72,     0,   104,     0,   105,   106,   109,   114,     0,   116,
       0,    92,    77,    26,    27,    73,     0,     0,   108,     0,
     113,   115,   103,   102,     0,    90,     0,   112,   110,   101,
     100
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,   172,  -161,  -161,  -161,   -59,  -161,   158,   194,
    -161,  -161,  -161,  -161,   -16,    50,   -58,  -161,   144,  -161,
     122,   -38,   -24,   -23,  -161,   174,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,   -33,    62,  -161,   -86,  -161,  -161,  -161,
    -161,  -161,  -160,  -161,    72,  -161,  -161,  -161,  -161,  -161,
    -161
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,    10,     3,     5,    11,    12,    13,    23,    24,
      14,    21,    63,    33,    58,   114,    30,   116,    34,    59,
      60,    46,    98,    18,    19,    48,    49,    50,    51,    52,
      53,    54,    85,    99,   100,   101,   102,   103,   104,   105,
     154,   106,   107,   108,   142,   143,   144,   188,   109,   110,
     111
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,    69,    29,    96,    47,   138,   141,   115,    56,    61,
       1,    38,    25,    26,    15,     4,   183,     7,    66,    27,
      57,   160,    25,    26,    97,     8,   190,    72,    73,    27,
     134,    86,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    89,    16,    82,    87,   113,
     180,    16,     9,   137,   139,   161,   181,     6,    39,   140,
     133,    16,    40,    41,    20,    61,   136,    91,    25,    26,
      22,    62,    42,   -90,    88,    27,    82,    90,     8,    91,
      92,    39,    82,    62,    16,    40,    41,    25,    26,    61,
      43,    44,    45,    31,    27,    42,   157,    96,    28,   187,
     115,    32,    37,    36,   162,   149,   150,   151,   152,   164,
     165,    94,    95,    43,    44,    45,    25,    26,    97,    55,
     153,   168,   170,    65,    82,   177,    62,    68,   178,    84,
     171,    90,     8,    91,    92,    39,    82,    62,    93,    40,
      41,   145,   173,   182,   184,    25,    26,    97,   146,    42,
      39,   132,   112,   189,    40,    41,    39,   155,    62,   156,
      40,    41,   159,   158,    42,    94,    95,    43,    44,    45,
      42,    39,   167,   163,   166,    40,    41,    70,    71,    72,
      73,   175,    43,    44,    45,    42,   176,   185,    43,    44,
      45,   186,    39,   169,    35,    67,    40,    41,    70,    71,
      72,    73,    17,    43,    44,    45,    42,   -91,   174,   117,
     135,    76,    77,    78,    79,    80,    81,   -91,   172,    70,
      71,    72,    73,    83,    43,    44,    45,    74,    75,   -91,
     147,   148,    76,    77,    78,    79,    80,    81,   179,    62,
       0,    70,    71,    72,    73,     0,     0,     0,     0,    74,
      75,   -91,   147,   148,    76,    77,    78,    79,    80,    81,
       0,  -108,     0,    70,    71,    72,    73,     0,     0,     0,
       0,    74,    75,     0,   147,   148,    76,    77,    78,    79,
      80,    81,   118,     0,     0,    70,    71,    72,    73,     0,
       0,     0,     0,    74,    75,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    62,     0,    70,    71,    72,    73,
       0,     0,     0,     0,    74,    75,     0,     0,     0,    76,
      77,    78,    79,    80,    81,    70,    71,    72,    73,     0,
       0,     0,     0,    74,    75,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    70,    71,    72,    73,     0,     0,
       0,     0,    74,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81
};

static const yytype_int16 yycheck[] =
{
      33,    39,    18,    62,    28,    91,    92,    65,    31,    32,
       6,    27,     4,     5,    11,    43,   176,     3,    34,    11,
      12,    12,     4,     5,    62,     8,   186,    17,    18,    11,
      12,    55,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    61,    43,    38,    12,    65,
      12,    43,    35,    91,    92,    46,    12,     0,    11,    92,
      84,    43,    15,    16,    43,    88,    90,     9,     4,     5,
       3,    13,    25,     3,    38,    11,    38,     7,     8,     9,
      10,    11,    38,    13,    43,    15,    16,     4,     5,   112,
      43,    44,    45,    38,    11,    25,   112,   156,    34,   185,
     158,    11,     3,    12,   137,    19,    20,    21,    22,   142,
     143,    41,    42,    43,    44,    45,     4,     5,   156,    34,
      34,   145,   146,    11,    38,   163,    13,    12,   166,    11,
     154,     7,     8,     9,    10,    11,    38,    13,    14,    15,
      16,    11,   158,   176,   177,     4,     5,   185,    11,    25,
      11,    12,    11,   186,    15,    16,    11,    14,    13,     3,
      15,    16,    12,    38,    25,    41,    42,    43,    44,    45,
      25,    11,    12,     3,     3,    15,    16,    15,    16,    17,
      18,    12,    43,    44,    45,    25,    39,     3,    43,    44,
      45,    39,    11,    12,    22,    37,    15,    16,    15,    16,
      17,    18,     8,    43,    44,    45,    25,     3,   158,    65,
      88,    28,    29,    30,    31,    32,    33,    13,   156,    15,
      16,    17,    18,    49,    43,    44,    45,    23,    24,     3,
      26,    27,    28,    29,    30,    31,    32,    33,   166,    13,
      -1,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,
      24,     3,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    13,    -1,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    12,    -1,    -1,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    13,    -1,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    49,    51,    43,    52,     0,     3,     8,    35,
      50,    53,    54,    55,    58,    11,    43,    57,    71,    72,
      43,    59,     3,    56,    57,     4,     5,    11,    34,    62,
      64,    38,    11,    61,    66,    50,    12,     3,    62,    11,
      15,    16,    25,    43,    44,    45,    69,    70,    73,    74,
      75,    76,    77,    78,    79,    34,    71,    12,    62,    67,
      68,    71,    13,    60,    81,    11,    62,    56,    12,    69,
      15,    16,    17,    18,    23,    24,    28,    29,    30,    31,
      32,    33,    38,    73,    11,    80,    70,    12,    38,    62,
       7,     9,    10,    14,    41,    42,    54,    69,    70,    81,
      82,    83,    84,    85,    86,    87,    89,    90,    91,    96,
      97,    98,    11,    62,    63,    64,    65,    66,    12,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    12,    70,    12,    68,    70,    69,    84,    69,
      81,    84,    92,    93,    94,    11,    11,    26,    27,    19,
      20,    21,    22,    34,    88,    14,     3,    62,    38,    12,
      12,    46,    81,     3,    81,    81,     3,    12,    70,    12,
      70,    70,    82,    62,    63,    12,    39,    69,    69,    92,
      12,    12,    81,    90,    81,     3,    39,    84,    95,    81,
      90
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    50,    50,    51,    52,    53,    53,
      54,    55,    55,    56,    56,    57,    57,    57,    58,    59,
      60,    61,    61,    61,    62,    62,    63,    63,    64,    64,
      65,    65,    66,    66,    66,    67,    67,    68,    68,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    70,    70,    71,    71,    72,    73,    73,    74,
      74,    74,    75,    75,    75,    76,    77,    77,    78,    79,
      79,    80,    80,    80,    81,    81,    82,    82,    83,    83,
      83,    83,    83,    83,    83,    83,    84,    84,    84,    84,
      85,    86,    87,    88,    88,    88,    88,    88,    89,    89,
      90,    90,    90,    90,    90,    91,    91,    91,    92,    92,
      93,    94,    95,    96,    96,    97,    97,    98,    98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     3,     2,     2,     1,     1,     1,
       1,     4,     2,     1,     3,     4,     2,     3,     4,     1,
       1,     4,     2,     1,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     4,     3,     3,     1,     2,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       2,     2,     3,     4,     3,     2,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     3,     1,     1,     1,     1,     1,     2,     2,
       7,     7,     5,     5,     3,     3,     3,     2,     1,     0,
       5,     1,     1,     4,     3,     4,     3,     2,     1
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
#line 135 "./parser/grammar.y"
                                                                        {(yyval.srcfile) = new SrcFile((yyvsp[-2].packageclause), nullptr, (yyvsp[0].decllist));
                                                                        ast = (yyval.srcfile);
                                                                        }
#line 1335 "./parser/parser.cpp"
    break;

  case 3: /* sourcefile: packageclause SEMICOLON  */
#line 144 "./parser/grammar.y"
                                                                        {(yyval.srcfile) = new SrcFile((yyvsp[-1].packageclause), nullptr, nullptr);
                                                                        ast = (yyval.srcfile);
                                                                        }
#line 1343 "./parser/parser.cpp"
    break;

  case 4: /* topleveldeclarations: topleveldecl SEMICOLON topleveldeclarations  */
#line 163 "./parser/grammar.y"
                                                                   {(yyval.decllist) = new PairDeclList((yyvsp[-2].toplvldecl), (yyvsp[0].decllist));}
#line 1349 "./parser/parser.cpp"
    break;

  case 5: /* topleveldeclarations: topleveldecl SEMICOLON  */
#line 164 "./parser/grammar.y"
                                                                   {(yyval.decllist) = new LastDeclList((yyvsp[-1].toplvldecl));}
#line 1355 "./parser/parser.cpp"
    break;

  case 6: /* packageclause: PACKAGE packagename  */
#line 167 "./parser/grammar.y"
                                    {(yyval.packageclause) = new PackageClause((yyvsp[0].identifier));}
#line 1361 "./parser/parser.cpp"
    break;

  case 7: /* packagename: IDENTIFIER  */
#line 169 "./parser/grammar.y"
                        {(yyval.identifier) = new Identifier((yyvsp[0].id));}
#line 1367 "./parser/parser.cpp"
    break;

  case 8: /* topleveldecl: declaration  */
#line 172 "./parser/grammar.y"
                                   {(yyval.toplvldecl) = (yyvsp[0].toplvldecl); }
#line 1373 "./parser/parser.cpp"
    break;

  case 9: /* topleveldecl: functiondeclaration  */
#line 173 "./parser/grammar.y"
                                   {(yyval.toplvldecl) = (yyvsp[0].toplvldecl); }
#line 1379 "./parser/parser.cpp"
    break;

  case 10: /* declaration: vardecl  */
#line 176 "./parser/grammar.y"
                         {(yyval.toplvldecl) = (yyvsp[0].toplvldecl); }
#line 1385 "./parser/parser.cpp"
    break;

  case 11: /* vardecl: VAR LPAREN varspeclist RPAREN  */
#line 179 "./parser/grammar.y"
                                                             {(yyval.toplvldecl) = new VarDecl((yyvsp[-1].varspeclist)); }
#line 1391 "./parser/parser.cpp"
    break;

  case 12: /* vardecl: VAR varspec  */
#line 180 "./parser/grammar.y"
                                                             {(yyval.toplvldecl) = new VarDecl(new LastVarSpecList((yyvsp[0].varspec))); }
#line 1397 "./parser/parser.cpp"
    break;

  case 13: /* varspeclist: varspec  */
#line 183 "./parser/grammar.y"
                                                             {(yyval.varspeclist) = new LastVarSpecList((yyvsp[0].varspec)); }
#line 1403 "./parser/parser.cpp"
    break;

  case 14: /* varspeclist: varspec SEMICOLON varspeclist  */
#line 184 "./parser/grammar.y"
                                                             {(yyval.varspeclist) = new PairVarSpecList((yyvsp[-2].varspec), (yyvsp[0].varspeclist)); }
#line 1409 "./parser/parser.cpp"
    break;

  case 15: /* varspec: identifierlist type ASSIGN expressionlist  */
#line 190 "./parser/grammar.y"
                                                        {(yyval.varspec) = new VarSpec((yyvsp[-3].identifierlist), (yyvsp[-2].type), (yyvsp[0].explist)); }
#line 1415 "./parser/parser.cpp"
    break;

  case 16: /* varspec: identifierlist type  */
#line 191 "./parser/grammar.y"
                                                        {(yyval.varspec) = new VarSpec((yyvsp[-1].identifierlist), (yyvsp[0].type), nullptr);}
#line 1421 "./parser/parser.cpp"
    break;

  case 17: /* varspec: identifierlist ASSIGN expressionlist  */
#line 192 "./parser/grammar.y"
                                                        {(yyval.varspec) = new VarSpec((yyvsp[-2].identifierlist), nullptr, (yyvsp[0].explist)); }
#line 1427 "./parser/parser.cpp"
    break;

  case 18: /* functiondeclaration: FUNC functionname signature functionbody  */
#line 195 "./parser/grammar.y"
                                                              {(yyval.toplvldecl) = new FunctionDecl((yyvsp[-2].identifier), (yyvsp[-1].signature), (yyvsp[0].block)); }
#line 1433 "./parser/parser.cpp"
    break;

  case 19: /* functionname: IDENTIFIER  */
#line 197 "./parser/grammar.y"
                          {(yyval.identifier) = new Identifier((yyvsp[0].id)); }
#line 1439 "./parser/parser.cpp"
    break;

  case 20: /* functionbody: block  */
#line 199 "./parser/grammar.y"
                     {(yyval.block) = (yyvsp[0].block); }
#line 1445 "./parser/parser.cpp"
    break;

  case 21: /* signature: parameters LPAREN result RPAREN  */
#line 201 "./parser/grammar.y"
                                             { (yyval.signature) = new Signature((yyvsp[-3].paramlist), (yyvsp[-1].result)); }
#line 1451 "./parser/parser.cpp"
    break;

  case 22: /* signature: parameters type  */
#line 202 "./parser/grammar.y"
                                             { (yyval.signature) = new Signature((yyvsp[-1].paramlist), new TypeResult(new LastTypeList((yyvsp[0].type)))); }
#line 1457 "./parser/parser.cpp"
    break;

  case 23: /* signature: parameters  */
#line 203 "./parser/grammar.y"
                                             { (yyval.signature) = new Signature((yyvsp[0].paramlist), nullptr); }
#line 1463 "./parser/parser.cpp"
    break;

  case 24: /* type: typename  */
#line 206 "./parser/grammar.y"
                                { (yyval.type) = (yyvsp[0].type); }
#line 1469 "./parser/parser.cpp"
    break;

  case 25: /* type: LPAREN type RPAREN  */
#line 207 "./parser/grammar.y"
                                { (yyval.type) = (yyvsp[-1].type); }
#line 1475 "./parser/parser.cpp"
    break;

  case 26: /* typelist: type  */
#line 210 "./parser/grammar.y"
                                                 {(yyval.typelist) = new LastTypeList((yyvsp[0].type)); }
#line 1481 "./parser/parser.cpp"
    break;

  case 27: /* typelist: typename COMMA typelist  */
#line 211 "./parser/grammar.y"
                                                 {(yyval.typelist) = new PairTypeList((yyvsp[-2].type), (yyvsp[0].typelist)); }
#line 1487 "./parser/parser.cpp"
    break;

  case 28: /* typename: INTEGER  */
#line 214 "./parser/grammar.y"
                                { (yyval.type) = new IntegerType(); }
#line 1493 "./parser/parser.cpp"
    break;

  case 29: /* typename: BOOLEAN  */
#line 215 "./parser/grammar.y"
                                { (yyval.type) = new BooleanType(); }
#line 1499 "./parser/parser.cpp"
    break;

  case 30: /* result: parameters  */
#line 218 "./parser/grammar.y"
                                    { (yyval.result) = new ParametersResult((yyvsp[0].paramlist)); }
#line 1505 "./parser/parser.cpp"
    break;

  case 31: /* result: typelist  */
#line 219 "./parser/grammar.y"
                                    { (yyval.result) = new TypeResult((yyvsp[0].typelist)); }
#line 1511 "./parser/parser.cpp"
    break;

  case 32: /* parameters: LPAREN RPAREN  */
#line 222 "./parser/grammar.y"
                                                  { (yyval.paramlist) = nullptr; }
#line 1517 "./parser/parser.cpp"
    break;

  case 33: /* parameters: LPAREN parameterlist COMMA RPAREN  */
#line 223 "./parser/grammar.y"
                                                  { (yyval.paramlist) = (yyvsp[-2].paramlist); }
#line 1523 "./parser/parser.cpp"
    break;

  case 34: /* parameters: LPAREN parameterlist RPAREN  */
#line 224 "./parser/grammar.y"
                                                  { (yyval.paramlist) = (yyvsp[-1].paramlist); }
#line 1529 "./parser/parser.cpp"
    break;

  case 35: /* parameterlist: parameterlist COMMA parameterdecl  */
#line 227 "./parser/grammar.y"
                                                     { (yyval.paramlist) = new PairParamList((yyvsp[0].paramdecl), (yyvsp[-2].paramlist)); }
#line 1535 "./parser/parser.cpp"
    break;

  case 36: /* parameterlist: parameterdecl  */
#line 228 "./parser/grammar.y"
                                                     { (yyval.paramlist) = new LastParamList((yyvsp[0].paramdecl)); }
#line 1541 "./parser/parser.cpp"
    break;

  case 37: /* parameterdecl: identifierlist type  */
#line 231 "./parser/grammar.y"
                                                { (yyval.paramdecl) = new ParameterDecl((yyvsp[0].type), (yyvsp[-1].identifierlist)); }
#line 1547 "./parser/parser.cpp"
    break;

  case 38: /* parameterdecl: type  */
#line 232 "./parser/grammar.y"
                                                { (yyval.paramdecl) = new ParameterDecl((yyvsp[0].type), nullptr); }
#line 1553 "./parser/parser.cpp"
    break;

  case 39: /* expr: unaryexpr  */
#line 235 "./parser/grammar.y"
                                { (yyval.exp) = (yyvsp[0].exp); }
#line 1559 "./parser/parser.cpp"
    break;

  case 40: /* expr: expr EQ expr  */
#line 236 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), EQ_BIN); }
#line 1565 "./parser/parser.cpp"
    break;

  case 41: /* expr: expr NE expr  */
#line 237 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), NE_BIN); }
#line 1571 "./parser/parser.cpp"
    break;

  case 42: /* expr: expr LT expr  */
#line 238 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), LT_BIN); }
#line 1577 "./parser/parser.cpp"
    break;

  case 43: /* expr: expr LE expr  */
#line 239 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), LE_BIN); }
#line 1583 "./parser/parser.cpp"
    break;

  case 44: /* expr: expr GT expr  */
#line 240 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), GT_BIN); }
#line 1589 "./parser/parser.cpp"
    break;

  case 45: /* expr: expr GE expr  */
#line 241 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), GE_BIN); }
#line 1595 "./parser/parser.cpp"
    break;

  case 46: /* expr: expr MUL expr  */
#line 242 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), MUL_BIN); }
#line 1601 "./parser/parser.cpp"
    break;

  case 47: /* expr: expr DIV expr  */
#line 243 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), DIV_BIN); }
#line 1607 "./parser/parser.cpp"
    break;

  case 48: /* expr: expr PLUS expr  */
#line 244 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), PLUS_BIN); }
#line 1613 "./parser/parser.cpp"
    break;

  case 49: /* expr: expr MIN expr  */
#line 245 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), MIN_BIN); }
#line 1619 "./parser/parser.cpp"
    break;

  case 50: /* expr: expr OR expr  */
#line 246 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), OR_BIN); }
#line 1625 "./parser/parser.cpp"
    break;

  case 51: /* expr: expr AND expr  */
#line 247 "./parser/grammar.y"
                                { (yyval.exp) = new BinaryExp((yyvsp[-2].exp), (yyvsp[0].exp), AND_BIN); }
#line 1631 "./parser/parser.cpp"
    break;

  case 52: /* expressionlist: expressionlist COMMA expr  */
#line 250 "./parser/grammar.y"
                                                { (yyval.explist) = new PairExpList((yyvsp[0].exp), (yyvsp[-2].explist)); }
#line 1637 "./parser/parser.cpp"
    break;

  case 53: /* expressionlist: expr  */
#line 251 "./parser/grammar.y"
                                                { (yyval.explist) = new LastExpList((yyvsp[0].exp)); }
#line 1643 "./parser/parser.cpp"
    break;

  case 54: /* identifierlist: identifier COMMA identifierlist  */
#line 254 "./parser/grammar.y"
                                                                    { (yyval.identifierlist) = new PairIdentifierList((yyvsp[-2].identifier), (yyvsp[0].identifierlist)); }
#line 1649 "./parser/parser.cpp"
    break;

  case 55: /* identifierlist: identifier  */
#line 255 "./parser/grammar.y"
                                                                    { (yyval.identifierlist) = new LastIdentifierList((yyvsp[0].identifier)); }
#line 1655 "./parser/parser.cpp"
    break;

  case 56: /* identifier: IDENTIFIER  */
#line 258 "./parser/grammar.y"
                               { (yyval.identifier) = new Identifier((yyvsp[0].id)); }
#line 1661 "./parser/parser.cpp"
    break;

  case 57: /* unaryexpr: primaryexpr  */
#line 260 "./parser/grammar.y"
                               { (yyval.exp) = (yyvsp[0].exp); }
#line 1667 "./parser/parser.cpp"
    break;

  case 58: /* unaryexpr: unary_op unaryexpr  */
#line 261 "./parser/grammar.y"
                               { (yyval.exp) = new UnaryExp((yyvsp[0].exp), (yyvsp[-1].unaryoperator)); }
#line 1673 "./parser/parser.cpp"
    break;

  case 59: /* unary_op: PLUS  */
#line 264 "./parser/grammar.y"
                                { (yyval.unaryoperator) = PLUS_UNARY; }
#line 1679 "./parser/parser.cpp"
    break;

  case 60: /* unary_op: MIN  */
#line 265 "./parser/grammar.y"
                                { (yyval.unaryoperator) = MIN_UNARY; }
#line 1685 "./parser/parser.cpp"
    break;

  case 61: /* unary_op: NOT  */
#line 266 "./parser/grammar.y"
                                { (yyval.unaryoperator) = NOT_UNARY; }
#line 1691 "./parser/parser.cpp"
    break;

  case 62: /* operand: literal  */
#line 269 "./parser/grammar.y"
                                { (yyval.operand) = new LiteralOperand((yyvsp[0].literal)); }
#line 1697 "./parser/parser.cpp"
    break;

  case 63: /* operand: operandname  */
#line 270 "./parser/grammar.y"
                                { (yyval.operand) = new VariableOperand((yyvsp[0].identifier)); }
#line 1703 "./parser/parser.cpp"
    break;

  case 64: /* operand: LPAREN expr RPAREN  */
#line 271 "./parser/grammar.y"
                                { (yyval.operand) = new ExprOperand((yyvsp[-1].exp)); }
#line 1709 "./parser/parser.cpp"
    break;

  case 65: /* literal: basiclit  */
#line 274 "./parser/grammar.y"
                                { (yyval.literal) = (yyvsp[0].literal); }
#line 1715 "./parser/parser.cpp"
    break;

  case 66: /* basiclit: INTLITERAL  */
#line 277 "./parser/grammar.y"
                                { (yyval.literal) = new IntLiteral(*(yyvsp[0].intlit)); }
#line 1721 "./parser/parser.cpp"
    break;

  case 67: /* basiclit: BOOLLITERAL  */
#line 278 "./parser/grammar.y"
                                { (yyval.literal) = new BoolLiteral(*(yyvsp[0].boollit)); }
#line 1727 "./parser/parser.cpp"
    break;

  case 68: /* operandname: IDENTIFIER  */
#line 281 "./parser/grammar.y"
                                { (yyval.identifier) = new Identifier((yyvsp[0].id)); }
#line 1733 "./parser/parser.cpp"
    break;

  case 69: /* primaryexpr: operand  */
#line 284 "./parser/grammar.y"
                                                  { (yyval.exp) = new OperandExp((yyvsp[0].operand)); }
#line 1739 "./parser/parser.cpp"
    break;

  case 70: /* primaryexpr: primaryexpr arguments  */
#line 285 "./parser/grammar.y"
                                                  { (yyval.exp) = new FunctionCall((yyvsp[-1].exp), (yyvsp[0].explist)); }
#line 1745 "./parser/parser.cpp"
    break;

  case 71: /* arguments: LPAREN RPAREN  */
#line 288 "./parser/grammar.y"
                                                                  { (yyval.explist) = nullptr; }
#line 1751 "./parser/parser.cpp"
    break;

  case 72: /* arguments: LPAREN expressionlist RPAREN  */
#line 289 "./parser/grammar.y"
                                                                  { (yyval.explist) = (yyvsp[-1].explist); }
#line 1757 "./parser/parser.cpp"
    break;

  case 73: /* arguments: LPAREN expressionlist RCOMMA RPAREN  */
#line 290 "./parser/grammar.y"
                                                                  { (yyval.explist) = (yyvsp[-2].explist); }
#line 1763 "./parser/parser.cpp"
    break;

  case 74: /* block: LBRACE statementlist RBRACE  */
#line 294 "./parser/grammar.y"
                                        { (yyval.block) = new Block((yyvsp[-1].stmlist)); }
#line 1769 "./parser/parser.cpp"
    break;

  case 75: /* block: LBRACE RBRACE  */
#line 295 "./parser/grammar.y"
                                         { (yyval.block) = new Block(nullptr); }
#line 1775 "./parser/parser.cpp"
    break;

  case 76: /* statementlist: statement SEMICOLON  */
#line 298 "./parser/grammar.y"
                                                        { (yyval.stmlist) = new LastStmList((yyvsp[-1].stm)); }
#line 1781 "./parser/parser.cpp"
    break;

  case 77: /* statementlist: statement SEMICOLON statementlist  */
#line 299 "./parser/grammar.y"
                                                        { (yyval.stmlist) = new PairStmList((yyvsp[-2].stm), (yyvsp[0].stmlist));}
#line 1787 "./parser/parser.cpp"
    break;

  case 78: /* statement: declaration  */
#line 302 "./parser/grammar.y"
                                         { (yyval.stm) = new DeclStm((yyvsp[0].toplvldecl)); }
#line 1793 "./parser/parser.cpp"
    break;

  case 79: /* statement: block  */
#line 303 "./parser/grammar.y"
                                         { (yyval.stm) = new BlockStm((yyvsp[0].block)); }
#line 1799 "./parser/parser.cpp"
    break;

  case 80: /* statement: ifstatement  */
#line 304 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1805 "./parser/parser.cpp"
    break;

  case 81: /* statement: forstatement  */
#line 305 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1811 "./parser/parser.cpp"
    break;

  case 82: /* statement: returnstatement  */
#line 306 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1817 "./parser/parser.cpp"
    break;

  case 83: /* statement: simplestatement  */
#line 307 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1823 "./parser/parser.cpp"
    break;

  case 84: /* statement: printstatement  */
#line 308 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1829 "./parser/parser.cpp"
    break;

  case 85: /* statement: printlnstatement  */
#line 309 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1835 "./parser/parser.cpp"
    break;

  case 86: /* simplestatement: expressionstatement  */
#line 312 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1841 "./parser/parser.cpp"
    break;

  case 87: /* simplestatement: assignment  */
#line 313 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1847 "./parser/parser.cpp"
    break;

  case 88: /* simplestatement: incdecstatement  */
#line 314 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1853 "./parser/parser.cpp"
    break;

  case 89: /* simplestatement: emptystatement  */
#line 315 "./parser/grammar.y"
                                         { (yyval.stm) = (yyvsp[0].stm); }
#line 1859 "./parser/parser.cpp"
    break;

  case 90: /* emptystatement: %empty  */
#line 319 "./parser/grammar.y"
                { (yyval.stm) = new EmptyStm();}
#line 1865 "./parser/parser.cpp"
    break;

  case 91: /* expressionstatement: expr  */
#line 321 "./parser/grammar.y"
                          { (yyval.stm) = new ExprStm((yyvsp[0].exp)); }
#line 1871 "./parser/parser.cpp"
    break;

  case 92: /* assignment: expressionlist assign_op expressionlist  */
#line 323 "./parser/grammar.y"
                                                    { (yyval.stm) = new AssignmentStm((yyvsp[-2].explist), (yyvsp[0].explist), (yyvsp[-1].assignoperator)); }
#line 1877 "./parser/parser.cpp"
    break;

  case 93: /* assign_op: ASSIGN  */
#line 325 "./parser/grammar.y"
                                                    { (yyval.assignoperator) = ASSIGN_OP;}
#line 1883 "./parser/parser.cpp"
    break;

  case 94: /* assign_op: PLUSASSIGN  */
#line 326 "./parser/grammar.y"
                                                    { (yyval.assignoperator) = PLUSASSIGN_OP; }
#line 1889 "./parser/parser.cpp"
    break;

  case 95: /* assign_op: MINASSIGN  */
#line 327 "./parser/grammar.y"
                                                    { (yyval.assignoperator) = MINASSIGN_OP; }
#line 1895 "./parser/parser.cpp"
    break;

  case 96: /* assign_op: MULASSIGN  */
#line 328 "./parser/grammar.y"
                                                    { (yyval.assignoperator) = MULASSIGN_OP; }
#line 1901 "./parser/parser.cpp"
    break;

  case 97: /* assign_op: DIVASSIGN  */
#line 329 "./parser/grammar.y"
                                                    { (yyval.assignoperator) = DIVASSIGN_OP;}
#line 1907 "./parser/parser.cpp"
    break;

  case 98: /* incdecstatement: expr INC  */
#line 332 "./parser/grammar.y"
                                                    { (yyval.stm) = new IncDecStm((yyvsp[-1].exp), PLUSPLUS); }
#line 1913 "./parser/parser.cpp"
    break;

  case 99: /* incdecstatement: expr DEC  */
#line 333 "./parser/grammar.y"
                                                    { (yyval.stm) = new IncDecStm((yyvsp[-1].exp), MINMIN); }
#line 1919 "./parser/parser.cpp"
    break;

  case 100: /* ifstatement: IF simplestatement SEMICOLON expr block ELSE ifstatement  */
#line 337 "./parser/grammar.y"
                                                                        { (yyval.stm) = new IfStm((yyvsp[-5].stm), (yyvsp[-3].exp), (yyvsp[-2].block), nullptr, (yyvsp[0].stm)); }
#line 1925 "./parser/parser.cpp"
    break;

  case 101: /* ifstatement: IF simplestatement SEMICOLON expr block ELSE block  */
#line 338 "./parser/grammar.y"
                                                                        { (yyval.stm) = new IfStm((yyvsp[-5].stm), (yyvsp[-3].exp), (yyvsp[-2].block), (yyvsp[0].block), nullptr); }
#line 1931 "./parser/parser.cpp"
    break;

  case 102: /* ifstatement: IF expr block ELSE ifstatement  */
#line 339 "./parser/grammar.y"
                                                                        { (yyval.stm) = new IfStm(nullptr, (yyvsp[-3].exp), (yyvsp[-2].block), nullptr, (yyvsp[0].stm)); }
#line 1937 "./parser/parser.cpp"
    break;

  case 103: /* ifstatement: IF expr block ELSE block  */
#line 340 "./parser/grammar.y"
                                                                        { (yyval.stm) = new IfStm(nullptr, (yyvsp[-3].exp), (yyvsp[-2].block), (yyvsp[0].block), nullptr); }
#line 1943 "./parser/parser.cpp"
    break;

  case 104: /* ifstatement: IF expr block  */
#line 341 "./parser/grammar.y"
                                                                        { (yyval.stm) = new IfStm(nullptr, (yyvsp[-1].exp), (yyvsp[0].block), nullptr, nullptr); }
#line 1949 "./parser/parser.cpp"
    break;

  case 105: /* forstatement: FOR condition block  */
#line 344 "./parser/grammar.y"
                                        { (yyval.stm) = new ForCondStm((yyvsp[-1].exp), (yyvsp[0].block)); }
#line 1955 "./parser/parser.cpp"
    break;

  case 106: /* forstatement: FOR forclause block  */
#line 345 "./parser/grammar.y"
                                        { (yyval.stm) = new ForClauseStm((yyvsp[-1].forclause), (yyvsp[0].block)); }
#line 1961 "./parser/parser.cpp"
    break;

  case 107: /* forstatement: FOR block  */
#line 346 "./parser/grammar.y"
                                        { (yyval.stm) = new ForStm((yyvsp[0].block)); }
#line 1967 "./parser/parser.cpp"
    break;

  case 108: /* condition: expr  */
#line 349 "./parser/grammar.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 1973 "./parser/parser.cpp"
    break;

  case 109: /* condition: %empty  */
#line 350 "./parser/grammar.y"
                                                { (yyval.exp) = nullptr; }
#line 1979 "./parser/parser.cpp"
    break;

  case 110: /* forclause: initstatement SEMICOLON condition SEMICOLON poststatement  */
#line 352 "./parser/grammar.y"
                                                                           { (yyval.forclause) = new ForClause((yyvsp[-4].stm), (yyvsp[-2].exp), (yyvsp[0].stm)); }
#line 1985 "./parser/parser.cpp"
    break;

  case 111: /* initstatement: simplestatement  */
#line 355 "./parser/grammar.y"
                                { (yyval.stm) = (yyvsp[0].stm); }
#line 1991 "./parser/parser.cpp"
    break;

  case 112: /* poststatement: simplestatement  */
#line 357 "./parser/grammar.y"
                                 { (yyval.stm) = (yyvsp[0].stm); }
#line 1997 "./parser/parser.cpp"
    break;

  case 113: /* printstatement: PRINT LPAREN expressionlist RPAREN  */
#line 359 "./parser/grammar.y"
                                                   { (yyval.stm) = new PrintStm((yyvsp[-1].explist)); }
#line 2003 "./parser/parser.cpp"
    break;

  case 114: /* printstatement: PRINT LPAREN RPAREN  */
#line 360 "./parser/grammar.y"
                                                   { (yyval.stm) = new PrintStm(nullptr); }
#line 2009 "./parser/parser.cpp"
    break;

  case 115: /* printlnstatement: PRINTLN LPAREN expressionlist RPAREN  */
#line 362 "./parser/grammar.y"
                                                       { (yyval.stm) = new PrintLnStm((yyvsp[-1].explist)); }
#line 2015 "./parser/parser.cpp"
    break;

  case 116: /* printlnstatement: PRINTLN LPAREN RPAREN  */
#line 363 "./parser/grammar.y"
                                                       { (yyval.stm) = new PrintLnStm(nullptr); }
#line 2021 "./parser/parser.cpp"
    break;

  case 117: /* returnstatement: RETURN expressionlist  */
#line 367 "./parser/grammar.y"
                                         { (yyval.stm) = new ReturnStm((yyvsp[0].explist)); }
#line 2027 "./parser/parser.cpp"
    break;

  case 118: /* returnstatement: RETURN  */
#line 368 "./parser/grammar.y"
                                         { (yyval.stm) = new ReturnStm(nullptr); }
#line 2033 "./parser/parser.cpp"
    break;


#line 2037 "./parser/parser.cpp"

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

#line 371 "./parser/grammar.y"
