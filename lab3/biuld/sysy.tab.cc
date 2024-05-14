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
#line 1 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"

#include <stdio.h>
#include <ast/ast.h>
#include <string>
#include <fmt/core.h>
void yyerror(const char *s);
extern int yylex(void);
extern NodePtr root;

#line 81 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"

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

#include "sysy.tab.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_VOID = 4,                       /* VOID  */
  YYSYMBOL_NUM = 5,                        /* NUM  */
  YYSYMBOL_ADD = 6,                        /* ADD  */
  YYSYMBOL_SUB = 7,                        /* SUB  */
  YYSYMBOL_MUL = 8,                        /* MUL  */
  YYSYMBOL_DIV = 9,                        /* DIV  */
  YYSYMBOL_AND = 10,                       /* AND  */
  YYSYMBOL_NOT = 11,                       /* NOT  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_MOD = 13,                       /* MOD  */
  YYSYMBOL_RP = 14,                        /* RP  */
  YYSYMBOL_LP = 15,                        /* LP  */
  YYSYMBOL_RB = 16,                        /* RB  */
  YYSYMBOL_LB = 17,                        /* LB  */
  YYSYMBOL_RC = 18,                        /* RC  */
  YYSYMBOL_LC = 19,                        /* LC  */
  YYSYMBOL_SEMI = 20,                      /* SEMI  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_IF = 22,                        /* IF  */
  YYSYMBOL_ELSE = 23,                      /* ELSE  */
  YYSYMBOL_WHILE = 24,                     /* WHILE  */
  YYSYMBOL_BREAK = 25,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 26,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 27,                    /* RETURN  */
  YYSYMBOL_LT = 28,                        /* LT  */
  YYSYMBOL_LE = 29,                        /* LE  */
  YYSYMBOL_GT = 30,                        /* GT  */
  YYSYMBOL_GE = 31,                        /* GE  */
  YYSYMBOL_EQ = 32,                        /* EQ  */
  YYSYMBOL_NE = 33,                        /* NE  */
  YYSYMBOL_ASSIGNOP = 34,                  /* ASSIGNOP  */
  YYSYMBOL_IDENT = 35,                     /* IDENT  */
  YYSYMBOL_comment = 36,                   /* comment  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_CompUnit = 38,                  /* CompUnit  */
  YYSYMBOL_CompUnit_ = 39,                 /* CompUnit_  */
  YYSYMBOL_Ident = 40,                     /* Ident  */
  YYSYMBOL_Number = 41,                    /* Number  */
  YYSYMBOL_Decl = 42,                      /* Decl  */
  YYSYMBOL_VarDecl = 43,                   /* VarDecl  */
  YYSYMBOL_VarDef_ = 44,                   /* VarDef_  */
  YYSYMBOL_VarDef = 45,                    /* VarDef  */
  YYSYMBOL_ArryList = 46,                  /* ArryList  */
  YYSYMBOL_InitVal = 47,                   /* InitVal  */
  YYSYMBOL_FuncDef = 48,                   /* FuncDef  */
  YYSYMBOL_FuncParams = 49,                /* FuncParams  */
  YYSYMBOL_FuncParam = 50,                 /* FuncParam  */
  YYSYMBOL_FuncParam_ = 51,                /* FuncParam_  */
  YYSYMBOL_Block = 52,                     /* Block  */
  YYSYMBOL_BlockItems = 53,                /* BlockItems  */
  YYSYMBOL_BlockItem = 54,                 /* BlockItem  */
  YYSYMBOL_Stmt = 55,                      /* Stmt  */
  YYSYMBOL_IFStmt = 56,                    /* IFStmt  */
  YYSYMBOL_Exp = 57,                       /* Exp  */
  YYSYMBOL_LOrExp = 58,                    /* LOrExp  */
  YYSYMBOL_LAndExp = 59,                   /* LAndExp  */
  YYSYMBOL_EqExp = 60,                     /* EqExp  */
  YYSYMBOL_RelExp = 61,                    /* RelExp  */
  YYSYMBOL_AddExp = 62,                    /* AddExp  */
  YYSYMBOL_MulExp = 63,                    /* MulExp  */
  YYSYMBOL_UnaryExp = 64,                  /* UnaryExp  */
  YYSYMBOL_PirmaryExp = 65,                /* PirmaryExp  */
  YYSYMBOL_LVal = 66,                      /* LVal  */
  YYSYMBOL_LValList = 67,                  /* LValList  */
  YYSYMBOL_FuncRParams = 68,               /* FuncRParams  */
  YYSYMBOL_FuncRP_ = 69                    /* FuncRP_  */
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    82,    89,    90,   104,   108,   112,   116,
     123,   124,   129,   130,   135,   136,   139,   145,   147,   148,
     150,   154,   161,   162,   165,   166,   170,   174,   175,   179,
     180,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     196,   197,   201,   205,   206,   210,   211,   215,   216,   217,
     221,   222,   223,   224,   225,   229,   230,   231,   235,   236,
     237,   238,   242,   243,   244,   245,   246,   247,   252,   253,
     254,   259,   263,   264,   268,   276,   277
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "VOID", "NUM",
  "ADD", "SUB", "MUL", "DIV", "AND", "NOT", "OR", "MOD", "RP", "LP", "RB",
  "LB", "RC", "LC", "SEMI", "COMMA", "IF", "ELSE", "WHILE", "BREAK",
  "CONTINUE", "RETURN", "LT", "LE", "GT", "GE", "EQ", "NE", "ASSIGNOP",
  "IDENT", "comment", "$accept", "CompUnit", "CompUnit_", "Ident",
  "Number", "Decl", "VarDecl", "VarDef_", "VarDef", "ArryList", "InitVal",
  "FuncDef", "FuncParams", "FuncParam", "FuncParam_", "Block",
  "BlockItems", "BlockItem", "Stmt", "IFStmt", "Exp", "LOrExp", "LAndExp",
  "EqExp", "RelExp", "AddExp", "MulExp", "UnaryExp", "PirmaryExp", "LVal",
  "LValList", "FuncRParams", "FuncRP_", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-119)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      33,   -27,   -27,    53,  -119,  -119,  -119,  -119,  -119,    -5,
    -119,     9,  -119,  -119,     6,   113,    -2,    31,     8,   -27,
      11,    18,  -119,  -119,   113,   113,   113,   113,    19,  -119,
    -119,  -119,    29,    44,    27,   101,    64,     5,  -119,  -119,
    -119,    62,  -119,   -27,    11,    67,    55,  -119,  -119,    11,
      68,  -119,  -119,  -119,    76,    81,    59,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
      78,    63,  -119,  -119,    11,    82,    20,  -119,    96,  -119,
    -119,  -119,    87,   113,    44,    27,   101,   101,    64,    64,
      64,    64,     5,     5,  -119,  -119,  -119,  -119,  -119,  -119,
     -27,  -119,    88,    91,    90,    94,   102,  -119,  -119,  -119,
    -119,  -119,    95,    89,  -119,   100,  -119,    86,    -2,   113,
     113,  -119,  -119,  -119,   105,  -119,   113,   113,  -119,   112,
     124,  -119,   107,  -119,    58,    58,  -119,   116,  -119,    58,
    -119
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     3,     4,     8,     5,     6,    14,
      10,     0,     1,     2,     0,     0,    13,     0,     0,     0,
       0,     0,    24,     7,     0,     0,     0,     0,    72,    70,
      12,    16,    42,    43,    45,    47,    50,    55,    58,    62,
      69,     0,     9,     0,     0,     0,    22,    27,    18,     0,
      21,    65,    66,    67,     0,     0,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,    11,    20,     0,     0,     0,    17,     0,    68,
      64,    75,     0,     0,    44,    46,    48,    49,    51,    52,
      53,    54,    56,    57,    59,    60,    61,    15,    19,    14,
       0,    26,     0,     0,     0,     0,     0,    29,    33,    28,
      30,    34,     0,    69,    25,    74,    63,     0,    23,     0,
       0,    36,    37,    39,     0,    32,     0,     0,    73,     0,
       0,    38,     0,    76,     0,     0,    31,    40,    35,     0,
      41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,   137,     0,   103,    65,  -119,  -119,    99,    46,
    -119,  -119,   125,    69,  -119,   -16,  -119,  -119,  -118,  -119,
     -15,  -119,    92,    93,    15,    72,    13,   -19,  -119,   -73,
    -119,  -119,  -119
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,    28,    29,     5,     6,    17,    10,    16,
      30,     7,    21,    22,    50,   108,    76,   109,   110,   111,
     112,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      56,    82,   115
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,     9,    11,   113,    48,    51,    52,    53,     8,    19,
      14,    19,    54,    67,    68,    41,   137,   138,    69,    46,
      20,   140,    44,   100,    18,    23,    24,    25,    73,    15,
      47,    26,    49,    77,    55,    27,     1,     2,   101,    47,
      81,    57,   102,    71,   103,   104,   105,   106,    94,    95,
      96,    42,    43,    12,    58,     8,     1,     2,    98,    59,
      60,   113,   113,    23,    24,    25,   113,    23,   117,    26,
      65,    66,    75,    27,    86,    87,    83,    47,    92,    93,
     102,    74,   103,   104,   105,   106,    23,    24,    25,    78,
      79,   124,    26,     8,    97,    80,    27,    15,    99,    19,
      71,   116,   128,   119,   129,   130,   120,    23,    24,    25,
     121,   132,   133,    26,   122,   125,     8,    27,    23,    24,
      25,   127,   123,   126,    26,   131,   134,   136,    27,    61,
      62,    63,    64,    88,    89,    90,    91,     8,   135,   139,
      13,   107,    72,    45,    70,   118,     0,   114,     8,    84,
       0,    85
};

static const yytype_int16 yycheck[] =
{
      15,     1,     2,    76,    20,    24,    25,    26,    35,     3,
      15,     3,    27,     8,     9,    17,   134,   135,    13,    19,
      14,   139,    14,     3,    15,     5,     6,     7,    44,    34,
      19,    11,    14,    49,    15,    15,     3,     4,    18,    19,
      55,    12,    22,    43,    24,    25,    26,    27,    67,    68,
      69,    20,    21,     0,    10,    35,     3,     4,    74,    32,
      33,   134,   135,     5,     6,     7,   139,     5,    83,    11,
       6,     7,    17,    15,    59,    60,    17,    19,    65,    66,
      22,    14,    24,    25,    26,    27,     5,     6,     7,    21,
      14,   106,    11,    35,    16,    14,    15,    34,    16,     3,
     100,    14,    16,    15,   119,   120,    15,     5,     6,     7,
      20,   126,   127,    11,    20,    20,    35,    15,     5,     6,
       7,    21,    20,    34,    11,    20,    14,    20,    15,    28,
      29,    30,    31,    61,    62,    63,    64,    35,    14,    23,
       3,    76,    43,    18,    41,    99,    -1,    78,    35,    57,
      -1,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    38,    39,    42,    43,    48,    35,    40,
      45,    40,     0,    39,    15,    34,    46,    44,    15,     3,
      14,    49,    50,     5,     6,     7,    11,    15,    40,    41,
      47,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    17,    20,    21,    14,    49,    40,    19,    52,    14,
      51,    64,    64,    64,    57,    15,    67,    12,    10,    32,
      33,    28,    29,    30,    31,     6,     7,     8,     9,    13,
      41,    40,    45,    52,    14,    17,    53,    52,    21,    14,
      14,    57,    68,    17,    59,    60,    61,    61,    62,    62,
      62,    62,    63,    63,    64,    64,    64,    16,    52,    16,
       3,    18,    22,    24,    25,    26,    27,    42,    52,    54,
      55,    56,    57,    66,    50,    69,    14,    57,    46,    15,
      15,    20,    20,    20,    57,    20,    34,    21,    16,    57,
      57,    20,    57,    57,    14,    14,    20,    55,    55,    23,
      55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    40,    41,    42,    43,
      44,    44,    45,    45,    46,    46,    47,    48,    48,    48,
      48,    49,    50,    50,    51,    51,    52,    53,    53,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    57,    58,    58,    59,    59,    60,    60,    60,
      61,    61,    61,    61,    61,    62,    62,    62,    63,    63,
      63,    63,    64,    64,    64,    64,    64,    64,    65,    65,
      65,    66,    67,    67,    68,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     4,
       0,     3,     3,     2,     0,     4,     1,     6,     5,     6,
       5,     2,     2,     5,     0,     3,     3,     0,     2,     1,
       1,     4,     2,     1,     1,     5,     2,     2,     3,     2,
       5,     7,     1,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     4,     3,     2,     2,     2,     3,     1,
       1,     2,     0,     4,     2,     0,     3
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
  case 2: /* CompUnit: CompUnit CompUnit_  */
#line 81 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            { (yyval.comp) = (yyvsp[-1].comp); (yyval.comp)->child->push_back((yyvsp[0].stmt)); root = (yyval.comp);}
#line 1234 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 3: /* CompUnit: CompUnit_  */
#line 82 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            { auto *tmp = new std::vector<TreeStmt*>();
                                                tmp->push_back((yyvsp[0].stmt));
                                              (yyval.comp) = new CompUnit(tmp);
                                                root = (yyval.comp);
                                            }
#line 1244 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 4: /* CompUnit_: Decl  */
#line 89 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            { (yyval.stmt) = (yyvsp[0].stmt);}
#line 1250 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 5: /* CompUnit_: FuncDef  */
#line 90 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            { (yyval.stmt) = (yyvsp[0].stmt);}
#line 1256 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 6: /* Ident: IDENT  */
#line 104 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            { (yyval.ident) = yyval.ident;}
#line 1262 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 7: /* Number: NUM  */
#line 108 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            { (yyval.integer) = yyval.integer; }
#line 1268 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 8: /* Decl: VarDecl  */
#line 112 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            { (yyval.stmt) = (yyvsp[0].varDecl);}
#line 1274 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 9: /* VarDecl: INT VarDef VarDef_ SEMI  */
#line 116 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                          {     auto *tmp = new std::vector<TreeVarDef*>();
                                                tmp->push_back((yyvsp[-2].varDef));
                                                (yyval.varDecl) = new TreeVarDecl(new TreeType(1), tmp);
                                                for (auto& def : *(yyvsp[-1].vecTreeVarDef)) (yyval.varDecl)->varDef->push_back(def);
                                            }
#line 1284 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 10: /* VarDef_: %empty  */
#line 123 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.vecTreeVarDef) = new std::vector<TreeVarDef*>();}
#line 1290 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 11: /* VarDef_: VarDef_ COMMA VarDef  */
#line 124 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyvsp[-2].vecTreeVarDef)->push_back((yyvsp[0].varDef)); (yyval.vecTreeVarDef) = (yyvsp[-2].vecTreeVarDef);}
#line 1296 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 12: /* VarDef: Ident ASSIGNOP InitVal  */
#line 129 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.varDef) = new TreeVarDef((yyvsp[-2].ident), false, nullptr, (yyvsp[0].expr));}
#line 1302 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 13: /* VarDef: Ident ArryList  */
#line 130 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.varDef) = new TreeVarDef((yyvsp[-1].ident), true, (yyvsp[0].vecTreeInt), nullptr);}
#line 1308 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 14: /* ArryList: %empty  */
#line 135 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.vecTreeInt) = new std::vector<TreeIntegerLiteral*>();}
#line 1314 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 15: /* ArryList: ArryList LB Number RB  */
#line 136 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyvsp[-3].vecTreeInt)->push_back((yyvsp[-1].integer)); (yyval.vecTreeInt) = (yyvsp[-3].vecTreeInt);}
#line 1320 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 16: /* InitVal: Exp  */
#line 139 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = (yyvsp[0].expr);}
#line 1326 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 17: /* FuncDef: INT Ident LP FuncParams RP Block  */
#line 146 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            { (yyval.stmt) = new TreeFuncDef(new TreeType(1), (yyvsp[-4].ident), (yyvsp[-2].funcPs), (yyvsp[0].stmt));}
#line 1332 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 18: /* FuncDef: INT Ident LP RP Block  */
#line 147 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            { (yyval.stmt) = new TreeFuncDef(new TreeType(1), (yyvsp[-3].ident), nullptr, (yyvsp[0].stmt));}
#line 1338 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 19: /* FuncDef: VOID Ident LP FuncParams RP Block  */
#line 149 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            { (yyval.stmt) = new TreeFuncDef(new TreeType(0), (yyvsp[-4].ident), (yyvsp[-2].funcPs), (yyvsp[0].stmt));}
#line 1344 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 20: /* FuncDef: VOID Ident LP RP Block  */
#line 150 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            { (yyval.stmt) = new TreeFuncDef(new TreeType(0), (yyvsp[-3].ident), nullptr, (yyvsp[0].stmt));}
#line 1350 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 21: /* FuncParams: FuncParam FuncParam_  */
#line 154 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            { auto *tmp = new std::vector<TreeFuncParam*> ();
                                              tmp->push_back((yyvsp[-1].funcP));
                                              (yyval.funcPs) = new TreeFuncParams(tmp);
                                              for (auto& param : *(yyvsp[0].vecFuncParam)) (yyval.funcPs)->child->push_back(param);
                                            }
#line 1360 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 22: /* FuncParam: INT Ident  */
#line 161 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                          { (yyval.funcP) = new TreeFuncParam(new TreeType(1), (yyvsp[0].ident), false, nullptr);}
#line 1366 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 23: /* FuncParam: INT Ident LB RB ArryList  */
#line 162 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                          { (yyval.funcP) = new TreeFuncParam(new TreeType(1), (yyvsp[-3].ident), true, (yyvsp[0].vecTreeInt));}
#line 1372 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 24: /* FuncParam_: %empty  */
#line 165 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            { (yyval.vecFuncParam) = new std::vector<TreeFuncParam*>();}
#line 1378 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 25: /* FuncParam_: FuncParam_ COMMA FuncParam  */
#line 166 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            { (yyval.vecFuncParam) = (yyvsp[-2].vecFuncParam); (yyval.vecFuncParam)->push_back((yyvsp[0].funcP));}
#line 1384 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 26: /* Block: LC BlockItems RC  */
#line 170 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.stmt) = new TreeBlock((yyvsp[-1].vecStmt));}
#line 1390 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 27: /* BlockItems: %empty  */
#line 174 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.vecStmt) = new std::vector<TreeStmt*>();}
#line 1396 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 28: /* BlockItems: BlockItems BlockItem  */
#line 175 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.vecStmt) = (yyvsp[-1].vecStmt); (yyvsp[-1].vecStmt)->push_back((yyvsp[0].stmt));}
#line 1402 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 29: /* BlockItem: Decl  */
#line 179 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1408 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 30: /* BlockItem: Stmt  */
#line 180 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1414 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 31: /* Stmt: LVal ASSIGNOP Exp SEMI  */
#line 184 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.stmt) = new TreeLvalEqStmt((yyvsp[-3].lVal), (yyvsp[-1].expr));}
#line 1420 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 32: /* Stmt: Exp SEMI  */
#line 185 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.stmt) = (yyvsp[-1].expr);}
#line 1426 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 33: /* Stmt: Block  */
#line 186 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1432 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 34: /* Stmt: IFStmt  */
#line 187 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1438 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 35: /* Stmt: WHILE LP Exp RP Stmt  */
#line 188 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.stmt) = new TreeWhileStmt((yyvsp[-2].expr), (yyvsp[0].stmt));}
#line 1444 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 36: /* Stmt: BREAK SEMI  */
#line 189 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.stmt) = new TreeBreakStmt();}
#line 1450 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 37: /* Stmt: CONTINUE SEMI  */
#line 190 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.stmt) = new TreeContinueStmt();}
#line 1456 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 38: /* Stmt: RETURN Exp SEMI  */
#line 191 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.stmt) = new TreeReturnStmt((yyvsp[-1].expr));}
#line 1462 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 39: /* Stmt: RETURN SEMI  */
#line 192 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.stmt) = new TreeReturnStmt(nullptr);}
#line 1468 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 40: /* IFStmt: IF LP Exp RP Stmt  */
#line 196 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.stmt) = new TreeIfStmt((yyvsp[-2].expr), (yyvsp[0].stmt), nullptr, false);}
#line 1474 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 41: /* IFStmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 197 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.stmt) = new TreeIfStmt((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt), true);}
#line 1480 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 42: /* Exp: LOrExp  */
#line 201 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = (yyvsp[0].expr);}
#line 1486 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 43: /* LOrExp: LAndExp  */
#line 205 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = (yyvsp[0].expr);}
#line 1492 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 44: /* LOrExp: LOrExp OR LAndExp  */
#line 206 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = new TreeBinaryExpr(OpType::OP_Lor, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1498 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 45: /* LAndExp: EqExp  */
#line 210 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = (yyvsp[0].expr);}
#line 1504 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 46: /* LAndExp: LAndExp AND EqExp  */
#line 211 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = new TreeBinaryExpr(OpType::OP_Land, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1510 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 47: /* EqExp: RelExp  */
#line 215 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = (yyvsp[0].expr);}
#line 1516 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 48: /* EqExp: EqExp EQ RelExp  */
#line 216 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = new TreeBinaryExpr(OpType::OP_Eq, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1522 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 49: /* EqExp: EqExp NE RelExp  */
#line 217 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = new TreeBinaryExpr(OpType::OP_Ne, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1528 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 50: /* RelExp: AddExp  */
#line 221 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = (yyvsp[0].expr);}
#line 1534 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 51: /* RelExp: RelExp LT AddExp  */
#line 222 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = new TreeBinaryExpr(OpType::OP_Lt, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1540 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 52: /* RelExp: RelExp LE AddExp  */
#line 223 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = new TreeBinaryExpr(OpType::OP_Le, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1546 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 53: /* RelExp: RelExp GT AddExp  */
#line 224 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = new TreeBinaryExpr(OpType::OP_Gt, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1552 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 54: /* RelExp: RelExp GE AddExp  */
#line 225 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = new TreeBinaryExpr(OpType::OP_Ge, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1558 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 55: /* AddExp: MulExp  */
#line 229 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = (yyvsp[0].expr);}
#line 1564 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 56: /* AddExp: AddExp ADD MulExp  */
#line 230 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = new TreeBinaryExpr(OpType::OP_Add, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1570 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 57: /* AddExp: AddExp SUB MulExp  */
#line 231 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = new TreeBinaryExpr(OpType::OP_Sub, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1576 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 58: /* MulExp: UnaryExp  */
#line 235 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = (yyvsp[0].expr);}
#line 1582 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 59: /* MulExp: MulExp MUL UnaryExp  */
#line 236 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = new TreeBinaryExpr(OpType::OP_Mul, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1588 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 60: /* MulExp: MulExp DIV UnaryExp  */
#line 237 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = new TreeBinaryExpr(OpType::OP_Div, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1594 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 61: /* MulExp: MulExp MOD UnaryExp  */
#line 238 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = new TreeBinaryExpr(OpType::OP_Mod, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1600 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 62: /* UnaryExp: PirmaryExp  */
#line 242 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = (yyvsp[0].expr);}
#line 1606 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 63: /* UnaryExp: Ident LP FuncRParams RP  */
#line 243 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = new TreeUnaryExpr(OpType::OP_Func, (yyvsp[-1].funcRP), (yyvsp[-3].ident));}
#line 1612 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 64: /* UnaryExp: Ident LP RP  */
#line 244 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = new TreeUnaryExpr(OpType::OP_Func, nullptr, (yyvsp[-2].ident));}
#line 1618 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 65: /* UnaryExp: ADD UnaryExp  */
#line 245 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = new TreeUnaryExpr(OpType::OP_Pos, (yyvsp[0].expr));}
#line 1624 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 66: /* UnaryExp: SUB UnaryExp  */
#line 246 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = new TreeUnaryExpr(OpType::OP_Neg, (yyvsp[0].expr));}
#line 1630 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 67: /* UnaryExp: NOT UnaryExp  */
#line 247 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = new TreeUnaryExpr(OpType::OP_Lnot, (yyvsp[0].expr));}
#line 1636 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 68: /* PirmaryExp: LP Exp RP  */
#line 252 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = (yyvsp[-1].expr);}
#line 1642 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 69: /* PirmaryExp: LVal  */
#line 253 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = (yyvsp[0].lVal);}
#line 1648 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 70: /* PirmaryExp: Number  */
#line 254 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.expr) = (yyvsp[0].integer);}
#line 1654 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 71: /* LVal: Ident LValList  */
#line 259 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.lVal) = new TreeLVal((yyvsp[-1].ident), (yyvsp[0].vecTreeExpr));}
#line 1660 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 72: /* LValList: %empty  */
#line 263 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.vecTreeExpr) = new std::vector<TreeExpr*>();}
#line 1666 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 73: /* LValList: LValList LB Exp RB  */
#line 264 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.vecTreeExpr) = (yyvsp[-3].vecTreeExpr); (yyval.vecTreeExpr)->push_back((yyvsp[-1].expr));}
#line 1672 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 74: /* FuncRParams: Exp FuncRP_  */
#line 268 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {auto *tmp = new std::vector<TreeExpr*>();
                                                tmp->push_back((yyvsp[-1].expr));
                                             (yyval.funcRP) = new TreeFuncRParams(tmp);
                                             for (auto& t : *(yyvsp[0].vecTreeExpr)) (yyval.funcRP)->child->push_back(t);   
                                            }
#line 1682 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 75: /* FuncRP_: %empty  */
#line 276 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.vecTreeExpr) = new std::vector<TreeExpr*>();}
#line 1688 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;

  case 76: /* FuncRP_: FuncRP_ COMMA Exp  */
#line 277 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"
                                            {(yyval.vecTreeExpr) = (yyvsp[-2].vecTreeExpr); (yyval.vecTreeExpr)->push_back((yyvsp[0].expr));}
#line 1694 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"
    break;


#line 1698 "/home/lll/MyC/accipit-main/lab3/biuld/sysy.tab.cc"

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

#line 281 "/home/lll/MyC/accipit-main/lab3/src/sysy.y"


void yyerror(const char *s) {
    printf("error: %s\n", s);
}
