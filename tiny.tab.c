/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "tiny.y" /* yacc.c:339  */

#define YYPARSER /* distinguishes Yacc output from other code files */



#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h" 
#include <string.h>

#define YYSTYPE TreeNode *

static char global[] = "global";
static char * savedName; /* for use in assignments */
static char * savedFunction; //For saving function name.
static char * savedScope = global; //for saving scope info
static int savedValue; //for saving array size or constant value
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */




#line 91 "tiny.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "tiny.tab.h".  */
#ifndef YY_YY_TINY_TAB_H_INCLUDED
# define YY_YY_TINY_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    INT = 260,
    RETURN = 261,
    VOID = 262,
    WHILE = 263,
    SYS_INPUT = 264,
    SYS_OUTPUT = 265,
    SYS_KILL = 266,
    SYS_RUN = 267,
    SYS_SAVE = 268,
    ID = 269,
    NUM = 270,
    PLUS = 271,
    MINUS = 272,
    TIMES = 273,
    OVER = 274,
    LT = 275,
    LTE = 276,
    GT = 277,
    GTE = 278,
    ASSIGN = 279,
    EQ = 280,
    NEQ = 281,
    SEMI = 282,
    COMMA = 283,
    LPAREN = 284,
    RPAREN = 285,
    LSQR = 286,
    RSQR = 287,
    LCURLY = 288,
    RCURLY = 289,
    ERROR = 290,
    LOWER_THAN_ELSE = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TINY_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 179 "tiny.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   122

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
static const yytype_uint16 yyrline[] =
{
       0,    44,    44,    50,    62,    68,    73,    80,    80,   104,
     104,   104,   139,   146,   154,   153,   188,   193,   200,   215,
     222,   236,   235,   251,   264,   277,   282,   294,   299,   304,
     309,   314,   319,   325,   330,   336,   344,   353,   361,   366,
     372,   379,   385,   395,   394,   410,   419,   426,   432,   438,
     444,   450,   456,   463,   474,   480,   487,   494,   505,   512,
     519,   527,   532,   537,   542,   551,   561,   568,   575,   582,
     589,   596,   604,   613,   618,   625,   634
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "INT", "RETURN", "VOID",
  "WHILE", "SYS_INPUT", "SYS_OUTPUT", "SYS_KILL", "SYS_RUN", "SYS_SAVE",
  "ID", "NUM", "PLUS", "MINUS", "TIMES", "OVER", "LT", "LTE", "GT", "GTE",
  "ASSIGN", "EQ", "NEQ", "SEMI", "COMMA", "LPAREN", "RPAREN", "LSQR",
  "RSQR", "LCURLY", "RCURLY", "ERROR", "LOWER_THAN_ELSE", "$accept",
  "programa", "decl_lista", "decl", "var_decl", "$@1", "$@2", "$@3",
  "tipo", "fun_decl", "$@4", "params", "params_lista", "param", "$@5",
  "comp_decl", "decl_local", "stmt_lista", "stmt", "exp_decl",
  "selecao_decl", "iteracao_decl", "retorno_decl", "exp", "var", "$@6",
  "exp_simp", "relacional", "exp_soma", "soma", "termo", "mult", "fator",
  "ativacao", "chamada_sistema", "id", "args", "list_args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF -62

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-62)))

#define YYTABLE_NINF -73

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      44,   -62,   -62,     1,    44,   -62,   -62,    -3,   -62,   -62,
     -62,    34,     4,    -8,    -1,   -62,    30,    74,   -62,    24,
      22,    45,    36,   -62,    51,   -62,    59,    60,    44,    67,
      64,   -62,   -62,   -62,   -62,    65,    44,   -62,   -62,    82,
       6,    68,    69,    58,    71,   -62,   -62,   -62,   -62,   -62,
      53,   -62,   -62,    -7,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,    76,    77,   -62,    21,    70,   -62,   -62,   -62,    73,
      -7,   -62,    78,    -7,    79,    81,   -62,    -7,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,    -7,    -7,   -62,   -62,
      -7,    -7,    83,   -62,    84,    -7,   -62,   -62,   -62,    75,
      70,   -62,   -62,    85,    80,    47,    47,    72,   -62,    -7,
     102,   -62,   -62,   -62,    47,   -62
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    13,     0,     2,     4,     5,     0,     6,     1,
       3,     7,     0,     0,     0,     8,     0,     0,    10,    13,
       0,     0,    16,    19,     0,    72,    20,     0,     0,     0,
       0,    25,    15,    18,    11,     0,    27,    22,    24,     0,
       0,     7,     0,     0,     0,    67,    68,    69,    70,    71,
      42,    64,    34,     0,    23,    29,    26,    28,    30,    31,
      32,     0,    62,    41,    46,    54,    58,    63,    66,     0,
       0,    38,     0,     0,     0,     0,    33,     0,    55,    56,
      48,    47,    49,    50,    51,    52,     0,     0,    59,    60,
       0,    74,     0,    39,     0,     0,    61,    40,    62,    45,
      53,    57,    76,     0,    73,     0,     0,     0,    65,     0,
      35,    37,    44,    75,     0,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -62,   -62,   -62,   103,    86,   -62,   -62,   -62,    -4,   -62,
     -62,   -62,   -62,    88,   -62,    90,   -62,   -62,   -28,   -62,
     -62,   -62,   -62,   -43,   -61,   -62,   -62,   -62,    23,   -62,
      25,   -62,    28,   -62,   -62,    99,   -62,   -62
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    12,    13,    24,     7,     8,
      14,    21,    22,    23,    30,    55,    36,    40,    56,    57,
      58,    59,    60,    61,    62,    74,    63,    86,    64,    87,
      65,    90,    66,    67,    68,    69,   103,   104
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      72,     9,    45,    46,    47,    48,    49,    50,    51,    42,
      75,    11,    43,    20,    44,    45,    46,    47,    48,    49,
      50,    51,    53,    16,    20,    98,    98,    92,    17,    98,
      94,    15,    39,    52,    97,    53,    25,    78,    79,    31,
      54,    80,    81,    82,    83,    18,    84,    85,   102,     1,
      42,     2,   107,    43,   -17,    44,    45,    46,    47,    48,
      49,    50,    51,   -14,    28,    -9,   113,    45,    46,    47,
      48,    49,    50,    51,    52,    27,    53,   110,   111,     1,
      31,    19,   -72,    29,   -43,    71,   115,    53,    88,    89,
     -21,    78,    79,    31,    34,    35,    41,    37,    70,    -9,
      73,    77,    91,    76,   112,    93,   114,    10,   109,    99,
      95,    96,   100,   105,   106,   108,    33,    32,   101,    26,
       0,     0,    38
};

static const yytype_int8 yycheck[] =
{
      43,     0,     9,    10,    11,    12,    13,    14,    15,     3,
      53,    14,     6,    17,     8,     9,    10,    11,    12,    13,
      14,    15,    29,    31,    28,    86,    87,    70,    29,    90,
      73,    27,    36,    27,    77,    29,    14,    16,    17,    33,
      34,    20,    21,    22,    23,    15,    25,    26,    91,     5,
       3,     7,    95,     6,    30,     8,     9,    10,    11,    12,
      13,    14,    15,    29,    28,    31,   109,     9,    10,    11,
      12,    13,    14,    15,    27,    30,    29,   105,   106,     5,
      33,     7,    29,    32,    31,    27,   114,    29,    18,    19,
      31,    16,    17,    33,    27,    31,    14,    32,    29,    31,
      29,    24,    29,    27,    32,    27,     4,     4,    28,    86,
      31,    30,    87,    30,    30,    30,    28,    27,    90,    20,
      -1,    -1,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     7,    38,    39,    40,    41,    45,    46,     0,
      40,    14,    42,    43,    47,    27,    31,    29,    15,     7,
      45,    48,    49,    50,    44,    14,    72,    30,    28,    32,
      51,    33,    52,    50,    27,    31,    53,    32,    41,    45,
      54,    14,     3,     6,     8,     9,    10,    11,    12,    13,
      14,    15,    27,    29,    34,    52,    55,    56,    57,    58,
      59,    60,    61,    63,    65,    67,    69,    70,    71,    72,
      29,    27,    60,    29,    62,    60,    27,    24,    16,    17,
      20,    21,    22,    23,    25,    26,    64,    66,    18,    19,
      68,    29,    60,    27,    60,    31,    30,    60,    61,    65,
      67,    69,    60,    73,    74,    30,    30,    60,    30,    28,
      55,    55,    32,    60,     4,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    42,    41,    43,
      44,    41,    45,    45,    47,    46,    48,    48,    49,    49,
      50,    51,    50,    52,    53,    53,    54,    54,    55,    55,
      55,    55,    55,    56,    56,    57,    57,    58,    59,    59,
      60,    60,    61,    62,    61,    63,    63,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    69,    69,    69,    69,    70,    70,    71,    71,    71,
      71,    71,    72,    73,    73,    74,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     0,     4,     0,
       0,     8,     1,     1,     0,     7,     1,     1,     3,     1,
       2,     0,     5,     4,     2,     0,     2,     0,     1,     1,
       1,     1,     1,     2,     1,     5,     7,     5,     2,     3,
       3,     1,     1,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 45 "tiny.y" /* yacc.c:1646  */
    { 
					if(SintaxDebug)printf("programa -> decl_lista\n");
					savedTree = (yyvsp[0]);
				}
#line 1347 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 51 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("decl_lista -> decl_lista decl\n");
					TreeNode * t = (yyvsp[-1]);
					if (t != NULL)
					{ 
						while (t->sibling != NULL)
							t = t->sibling;
						t->sibling = (yyvsp[0]);
						(yyval) = (yyvsp[-1]); 
					} else (yyval) = (yyvsp[0]);
                 }
#line 1363 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 63 "tiny.y" /* yacc.c:1646  */
    { 
					if(SintaxDebug)printf("decl_lista -> decl\n");
					(yyval) = (yyvsp[0]); 
				}
#line 1372 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 69 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("decl -> var_decl\n");
					(yyval) = (yyvsp[0]); 
				}
#line 1381 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 74 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("decl -> var_decl\n");
					(yyval) = (yyvsp[0]); 
				}
#line 1390 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 80 "tiny.y" /* yacc.c:1646  */
    { savedName = copyString(tokenString); savedLineNo = lineno;}
#line 1396 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 81 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("var_decl -> tipo ID SEMI\n");
					TreeNode * t;
					t = newDeclNode(VarK);
					t->attr.name = savedName;
					t->lineno = savedLineNo;
					t->kind.decl = VarK;
					
					t->Type = (yyval)->Type;
					
					t->scope = savedScope;
					
					t->sibling = (yyval)->sibling;
					t->child[0] = (yyval)->child[0];
					t->child[1] = (yyval)->child[1];
					t->child[2] = (yyval)->child[2];
					(yyval) = (yyvsp[-3]);
					(yyval)->sibling = NULL;
					(yyval)->child[0] = t;
					(yyval)->child[1] = NULL;
					(yyval)->child[2] = NULL;
					(yyval)->child[0]->Type = (yyval)->Type;
				}
#line 1424 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 104 "tiny.y" /* yacc.c:1646  */
    { savedName = copyString(tokenString); savedLineNo = lineno; }
#line 1430 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 104 "tiny.y" /* yacc.c:1646  */
    {savedValue = atoi(tokenString);}
#line 1436 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 105 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("var_decl -> tipo ID LSQR NUM RSQR SEMI\n");
					// if(SintaxDebug) printf("\n*******************\nnome:%s linha:%d valor:%d\n*******************\n", savedName, savedLineNo, savedValue);
					TreeNode * t;
					TreeNode * r;
					t = newDeclNode(ArrayK);  
					t->attr.name = savedName; 
					t->lineno = savedLineNo;
					t->kind.decl = ArrayK;
					t->Type = (yyvsp[-7])->Type;
					t->scope = savedScope;
					
					r = newDeclNode(SizeK);
					r->attr.val = savedValue;
					r->lineno = savedLineNo;
					r->kind.decl = SizeK;
					r->scope = t->scope;
					r->Type = Integer;
					t->sibling = (yyval)->sibling;
					t->child[0] = r;
					t->child[1] = NULL;
					t->child[2] = NULL;
					r->child[0] = (yyval)->child[0];
					r->child[1] = (yyval)->child[1];
					r->child[2] = (yyval)->child[2];		
					
					(yyval) = (yyvsp[-7]);
					(yyval)->sibling = NULL;
					(yyval)->child[0] = t;
					(yyval)->child[1] = NULL;
					(yyval)->child[2] = NULL;
					(yyval)->child[0]->Type = (yyval)->Type;
				}
#line 1474 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 140 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("tipo -> INT\n");
					(yyval) = newTypeNode(Integer);
					(yyval)->kind.type = Integer;
					(yyval)->Type = Integer;
				}
#line 1485 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 147 "tiny.y" /* yacc.c:1646  */
    {if(SintaxDebug)printf("tipo_especificador -> void\n");
					(yyval) = newTypeNode(Void);
					(yyval)->kind.type = Void;
					(yyval)->Type = Void;
				}
#line 1495 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 154 "tiny.y" /* yacc.c:1646  */
    { /*toda vez que le um ID ou NUM precisa guardar o nome dele*/
					savedName = copyString(tokenString);
					savedLineNo = lineno;
					savedFunction = savedName;
					savedScope = savedFunction;
				}
#line 1506 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 160 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("fun_decl -> tipo_especificador ID LPARE params RPARE comp_decl\n");
					TreeNode * t;
					t = newDeclNode(FunK);     
					t->attr.name = savedFunction; 
					t->lineno = savedLineNo; 
					t->kind.decl = FunK;
					
					
					t->scope = savedScope;
					

					t->sibling = (yyval)->sibling;
					t->child[0] = (yyvsp[-2]);
					t->child[1] = (yyvsp[0]);
					t->child[2] = NULL;					
					(yyval) = (yyvsp[-6]);
					(yyval)->sibling = NULL;
					(yyval)->child[0] = t;
					(yyval)->child[1] = NULL;
					(yyval)->child[2] = NULL;
					(yyval)->child[0]->Type = (yyval)->Type;
					

					
					
				}
#line 1538 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 189 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug) printf("params -> params_lista\n");
					(yyval) = (yyvsp[0]);
				}
#line 1547 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 194 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("params -> VOID\n");
					(yyval) = NULL;
					
				}
#line 1557 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 201 "tiny.y" /* yacc.c:1646  */
    {	
					if(SintaxDebug)printf("params_lista -> params_lista COMMA param\n");
					TreeNode * t = (yyvsp[-2]);
					if (t!=NULL)
					{
						while(t->sibling != NULL) t = t->sibling;
						t->sibling = (yyvsp[0]);
						(yyval) = (yyvsp[-2]);
					}else
					{
						(yyval) = (yyvsp[0]);
					}
					
				}
#line 1576 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 216 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("params_lista -> param\n");
					(yyval) = (yyvsp[0]);
					
				}
#line 1586 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 223 "tiny.y" /* yacc.c:1646  */
    { /*toda vez que le um ID ou NUM precisa guardar o nome dele*/
					if(SintaxDebug) printf("param -> tipo_especificador ID\n");
					(yyval) = (yyvsp[-1]);
					(yyval)->child[0] = newDeclNode(VarParK);
					(yyval)->child[0]->kind.decl = VarParK;
					(yyval)->child[0]->attr.name = (yyvsp[0])->attr.name;
					(yyval)->child[0]->lineno = (yyvsp[0])->lineno;
					(yyval)->child[0]->scope = savedScope;
					(yyval)->child[0]->Type = (yyval)->Type;
					
					
				}
#line 1603 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 236 "tiny.y" /* yacc.c:1646  */
    { /*toda vez que le um ID ou NUM precisa guardar o nome dele*/
					savedName = copyString(tokenString);
				}
#line 1611 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 240 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("param -> tipo_especificador ID LSQRBRA RSQRBRA\n");
					TreeNode * t = newDeclNode(ArrayParK);
					t->attr.name = savedName;
					t->lineno = savedLineNo;
					(yyval)=(yyvsp[-4]);
					(yyval)->child[0] = (yyvsp[-3]);
					(yyval)->child[0]->scope = savedScope;
					(yyval)->child[0]->Type = (yyval)->Type;
				}
#line 1626 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 252 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("comp_decl -> LCURBRA decl_local stmt_lista RCURBRA\n");
					TreeNode * t = (yyvsp[-2]);
					if (t!=NULL){
						while(t->sibling != NULL) t = t->sibling;
						t->sibling = (yyvsp[-1]);
						(yyval) = (yyvsp[-2]);
					}else{
						(yyval) = (yyvsp[-1]);
					}	
				}
#line 1642 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 265 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("decl_local -> decl_local var_decl\n");
					TreeNode * t = (yyvsp[-1]);
					if (t!=NULL){
						while(t->sibling != NULL) t = t->sibling;
						t->sibling = (yyvsp[0]);
						(yyval) = (yyvsp[-1]);
					}else{
						(yyval) = (yyvsp[0]);
					}				
					
				}
#line 1659 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 277 "tiny.y" /* yacc.c:1646  */
    {	
					if(SintaxDebug) printf("decl_local-> vazio .\n");
					(yyval) = NULL;
				}
#line 1668 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 283 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("stmt_lista -> stmt_lista stmt\n");
					TreeNode * t = (yyvsp[-1]);
					if (t!=NULL){
						while(t->sibling != NULL) t = t->sibling;
						t->sibling = (yyvsp[0]);
						(yyval) = (yyvsp[-1]);
					}else{
						(yyval) = (yyvsp[0]);
					}	
				}
#line 1684 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 294 "tiny.y" /* yacc.c:1646  */
    {	
					if(SintaxDebug) printf("local_declaracoes-> vazio .\n");
					(yyval) = NULL;
				}
#line 1693 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 300 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("stmt -> exp_decl\n");
					(yyval) = (yyvsp[0]);
				}
#line 1702 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 305 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("stmt -> comp_decl\n");
					(yyval) = (yyvsp[0]);
				}
#line 1711 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 310 "tiny.y" /* yacc.c:1646  */
    {
					(yyval) = (yyvsp[0]);
					if(SintaxDebug)printf("stmt -> selecao_decl\n");
				}
#line 1720 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 315 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("stmt -> iteracao_decl\n");
					(yyval) = (yyvsp[0]);
				}
#line 1729 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 320 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("stmt -> retorno_decl\n");
					(yyval) = (yyvsp[0]);
				}
#line 1738 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 326 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("exp_decl -> exp SEMICOLON\n");
					(yyval) = (yyvsp[-1]);
				}
#line 1747 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 331 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("exp_decl -> SEMICOLON\n");
					(yyval) = (yyvsp[0]);
				}
#line 1756 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 337 "tiny.y" /* yacc.c:1646  */
    {	
					if(SintaxDebug)printf("selecao_decl -> IF LPARE exp RPARE stmt\n");
					(yyval) = newStmtNode(IfK);
					(yyval)->child[0] = (yyvsp[-2]);
					(yyval)->child[1] = (yyvsp[0]);
					
				}
#line 1768 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 345 "tiny.y" /* yacc.c:1646  */
    {
					(yyval) = newStmtNode(IfK);
					(yyval)->child[0] = (yyvsp[-4]);
					(yyval)->child[1] = (yyvsp[-2]);
					(yyval)->child[2] = (yyvsp[0]);
					if(SintaxDebug) printf("selecao_decl -> IF LPARE exp RPARE stmt ELSE stmt\n");
				}
#line 1780 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 354 "tiny.y" /* yacc.c:1646  */
    {if(SintaxDebug)printf("iteracao_decl -> WHILE LPARE exp RPARE stmt\n");
					(yyval) = newStmtNode(WhileK);
					(yyval)->child[0] = (yyvsp[-2]);
					(yyval)->child[1] = (yyvsp[0]);
					
				}
#line 1791 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 362 "tiny.y" /* yacc.c:1646  */
    {if(SintaxDebug)printf("retorno_decl -> RETURN SEMICOLON\n");
					(yyval) = newStmtNode(ReturnK);
					(yyval)->child[0] = NULL;
				}
#line 1800 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 367 "tiny.y" /* yacc.c:1646  */
    {if(SintaxDebug)printf("retorno_decl -> RETURN exp SEMICOLON\n");
					(yyval) = newStmtNode(ReturnK);
					(yyval)->child[0] = (yyvsp[-1]);
				}
#line 1809 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 373 "tiny.y" /* yacc.c:1646  */
    {if(SintaxDebug)printf("exp -> var ASSIGN exp\n");
					(yyval) = newStmtNode(AssignK);
					(yyval)->child[0] = (yyvsp[-2]);
					(yyval)->child[1] = (yyvsp[0]);
					(yyval)->Type = (yyvsp[-2])->Type;
				}
#line 1820 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 380 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("exp -> exp_simp\n");	
					(yyval) = (yyvsp[0]);
				}
#line 1829 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 386 "tiny.y" /* yacc.c:1646  */
    { /*toda vez que le um ID ou NUM precisa guardar o nome dele*/
					if(SintaxDebug) printf("var -> ID\n");
					(yyval) = newExpNode(IdK);
					(yyval)->kind.exp = IdK;
					(yyval)->attr.name = copyString(tokenString);	
					(yyval)->scope = savedScope;
					(yyval)->Type = Integer;
				}
#line 1842 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 395 "tiny.y" /* yacc.c:1646  */
    { /*toda vez que le um ID ou NUM precisa guardar o nome dele*/
					savedName = copyString(tokenString);
					savedLineNo = lineno;
				}
#line 1851 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 399 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("var -> ID LSQRBRA exp RSQRBRA\n");
					(yyval) = newExpNode(IdArrayK);
					(yyval)->kind.exp = IdArrayK;
					(yyval)->attr.name = savedName;
					(yyval)->lineno = savedLineNo;
					(yyval)->child[0] = (yyvsp[-1]);
					(yyval)->scope = savedScope;
					(yyval)->Type = Integer;
				}
#line 1866 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 411 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("exp_simp -> exp_soma relacional exp_soma\n");
					(yyval) = newExpNode(OpK);
					(yyval)->attr.op = (yyvsp[-1])->attr.op;	
					(yyval)->child[0] = (yyvsp[-2]);
					(yyval)->child[1] = (yyvsp[0]);
					
				}
#line 1879 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 420 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("exp_simp -> exp_soma\n");
					(yyval) = (yyvsp[0]);
					
				}
#line 1889 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 427 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("relacional -> LESSEQ\n");
					(yyval) = newExpNode(OpK);
					(yyval)->attr.op = LTE;
				}
#line 1899 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 433 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("relacional -> LESS\n");
					(yyval) = newExpNode(OpK);
					(yyval)->attr.op = LT;
				}
#line 1909 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 439 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("relacional -> GREAT\n");
					(yyval) = newExpNode(OpK);
					(yyval)->attr.op = GT;
				}
#line 1919 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 445 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("relacional -> GREATEQ\n");
					(yyval) = newExpNode(OpK);
					(yyval)->attr.op = GTE;
				}
#line 1929 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 451 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("relacional -> EQ\n");
					(yyval) = newExpNode(OpK);
					(yyval)->attr.op = EQ;
				}
#line 1939 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 457 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("relacional -> NEQ\n");
					(yyval) = newExpNode(OpK);
					(yyval)->attr.op = NEQ;
				}
#line 1949 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 464 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("exp_soma -> exp_soma soma termo\n");
					(yyval) = (yyvsp[-1]);
					// if($1->kind.type == Integer && $3->kind.type == Integer)
					// {
						// $2->kind.type = Integer;
					// }
					(yyval)->child[0] = (yyvsp[-2]);
					(yyval)->child[1] = (yyvsp[0]);
				}
#line 1964 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 475 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug) printf("exp_soma -> termo\n");
					(yyval) = (yyvsp[0]);
				}
#line 1973 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 481 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug) printf("soma -> PLUS\n");
					(yyval) = newExpNode(OpK);
					(yyval)->attr.op = PLUS;	
					
				}
#line 1984 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 488 "tiny.y" /* yacc.c:1646  */
    {
					(yyval) = newExpNode(OpK);
					if(SintaxDebug)printf("soma -> PLUS\n");
					(yyval)->attr.op = MINUS;
				}
#line 1994 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 495 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("termo -> termo mult fator\n");
					(yyval) = (yyvsp[-1]);
					// if($1->kind.type == Integer && $3->kind.type == Integer)
					// {
						// $2->kind.type = Integer;
					// }
					(yyval)->child[0] = (yyvsp[-2]);
					(yyval)->child[1] = (yyvsp[0]);
				}
#line 2009 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 506 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug) printf("termo -> fator\n");
					(yyval) = (yyvsp[0]);
					
				}
#line 2019 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 513 "tiny.y" /* yacc.c:1646  */
    {
					(yyval) = newExpNode(OpK);
					if(SintaxDebug)printf("mult -> MULT\n");
					(yyval)->attr.op = TIMES;
					
				}
#line 2030 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 520 "tiny.y" /* yacc.c:1646  */
    {
					(yyval) = newExpNode(OpK);
					if(SintaxDebug)printf("mult -> DIV\n");
					(yyval)->attr.op = OVER;
					
				}
#line 2041 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 528 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("fator -> LPARE exp RPARE\n");
					(yyval) = (yyvsp[-1]);
				}
#line 2050 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 533 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("fator -> var\n");
					(yyval) = (yyvsp[0]);
				}
#line 2059 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 538 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("fator -> ativacao\n");
					(yyval) = (yyvsp[0]);
				}
#line 2068 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 543 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("fator -> NUM\n");
					(yyval) = newExpNode(ConstK);
					(yyval)->kind.exp = ConstK;
					(yyval)->Type = Integer;
					(yyval)->attr.val = atoi(tokenString);
				}
#line 2080 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 552 "tiny.y" /* yacc.c:1646  */
    {	
					if(SintaxDebug) printf("ativacao -> ID LPARE args RPARE\n");
					(yyval) = newExpNode(IdK);
					(yyval)->kind.exp = FunIdK;
					(yyval)->attr.name = (yyvsp[-3])->attr.name;
					(yyval)->lineno = (yyvsp[-3])->lineno;
					(yyval)->child[0] = (yyvsp[-1]);
					(yyval)->scope = savedScope;
				}
#line 2094 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 562 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug) printf("ativacao -> chamada_sistema\n");
					(yyval) = (yyvsp[0]);
				}
#line 2103 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 569 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug) printf("chamada_sistema -> SYS_INPUT\n");
					(yyval) = newSysNode(InputK);
					(yyval)->attr.name = "input";
					(yyval)->lineno = lineno;
				}
#line 2114 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 576 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug) printf("chamada_sistema -> SYS_OUTPUT\n");
					(yyval) = newSysNode(OutputK);
					(yyval)->attr.name = "output";
					(yyval)->lineno = lineno;
				}
#line 2125 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 583 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug) printf("chamada_sistema -> SYS_KILL\n");
					(yyval) = newSysNode(KillK);
					(yyval)->attr.name = "kill";
					(yyval)->lineno = lineno;
				}
#line 2136 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 590 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug) printf("chamada_sistema -> SYS_RUN\n");
					(yyval) = newSysNode(RunK);
					(yyval)->attr.name = "run";
					(yyval)->lineno = lineno;
				}
#line 2147 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 597 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug) printf("chamada_sistema -> SYS_SAVE\n");
					(yyval) = newSysNode(SaveK);
					(yyval)->attr.name = "save";
					(yyval)->lineno = lineno;
				}
#line 2158 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 605 "tiny.y" /* yacc.c:1646  */
    {
				(yyval) = newExpNode(IdK);
				(yyval)->attr.name = copyString(tokenString);
				savedName = copyString(tokenString);
				(yyval)->lineno = lineno;
				(yyval)->scope = savedScope;
			}
#line 2170 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 614 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("args -> list_args\n");
					(yyval) = (yyvsp[0]);
				}
#line 2179 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 618 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug) printf("args -> vazio");
					(yyval) = NULL;
				}
#line 2188 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 626 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("list_args -> list_args COMMA exp\n");
					TreeNode * t = (yyvsp[0]);
					t->sibling = (yyval)->sibling;
					(yyval) = (yyvsp[-2]);
					(yyval)->sibling = t;
					
				}
#line 2201 "tiny.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 635 "tiny.y" /* yacc.c:1646  */
    {
					if(SintaxDebug)printf("list_args -> exp\n");
					(yyval) = (yyvsp[0]);
				}
#line 2210 "tiny.tab.c" /* yacc.c:1646  */
    break;


#line 2214 "tiny.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 641 "tiny.y" /* yacc.c:1906  */


int yyerror(char * message)
{ 
	fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
	fprintf(listing,"Current token: ");
	printToken(yychar,tokenString);
	Error = TRUE;
	return 0;
}


 
TreeNode * parse(void)
{ 
	yyparse();
	return savedTree;
}



