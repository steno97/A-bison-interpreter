/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "bison.y" /* yacc.c:337  */

#include <stdio.h>
#include <stdlib.h>
#line 11 "bison.y" /* yacc.c:337  */

#include "flex.lex.h"
#include "dichiarazioni.h"

#line 79 "bison.tab.c" /* yacc.c:337  */
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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "bison.tab.h".  */
#ifndef YY_YY_BISON_TAB_H_INCLUDED
# define YY_YY_BISON_TAB_H_INCLUDED
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
    NUMBER = 258,
    TYPE = 259,
    SEMI = 260,
    ALPHA = 261,
    ASSIGN = 262,
    VAR = 263,
    LBRACE = 264,
    RBRACE = 265,
    LPAREN = 266,
    RPAREN = 267,
    EVENT = 268,
    COMMAND = 269,
    STATE = 270,
    ACTION = 271,
    NEWLINE = 272,
    COMMA = 273,
    CHANGESTATE = 274,
    COMMENT = 275,
    SPACE = 276,
    IF = 277,
    ELSE = 278,
    ELIF = 279,
    CMP = 280,
    OPERATORE = 281,
    WHILE = 282,
    FOR = 283,
    PRINT = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYLAST   247

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  211

#define YYUNDEFTOK  2
#define YYMAXUTOK   284

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    66,    66,    69,    70,    71,    72,    73,    74,    75,
      76,    83,    84,    87,    88,    91,    98,    99,   102,   108,
     109,   112,   113,   114,   115,   116,   119,   120,   121,   122,
     125,   126,   135,   136,   139,   140,   143,   144,   147,   148,
     157,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   176,   177,   180,   181,   182,
     183,   184,   187,   188
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "TYPE", "SEMI", "ALPHA",
  "ASSIGN", "VAR", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "EVENT",
  "COMMAND", "STATE", "ACTION", "NEWLINE", "COMMA", "CHANGESTATE",
  "COMMENT", "SPACE", "IF", "ELSE", "ELIF", "CMP", "OPERATORE", "WHILE",
  "FOR", "PRINT", "$accept", "string", "operazioni", "elenco_ass",
  "assegnazione", "term", "elenco_ev_com", "events", "elenco_stati",
  "state", "elenchi", "elenco_operazioni", "actions", "elenco_actions",
  "cambiostato", "elenco_cambio", "main", "cicli", "metodo", "cond",
  "elenco_cond", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284
};
# endif

#define YYPACT_NINF -99

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-99)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,    12,    19,    44,    59,   -99,    62,     6,   -99,   -99,
      17,    61,    74,    68,   -99,   -99,   -99,    12,   -99,   100,
     112,    -3,    93,   109,   -99,   -99,    12,   107,   126,   160,
     170,   171,   172,   174,   -99,    27,    12,   173,   175,   -99,
     182,    17,    12,    17,   183,    32,   180,   126,   126,   -99,
     179,   176,   181,   177,   178,   -99,   -99,    32,   -99,   -99,
     -99,    12,   -99,    17,    17,    37,   184,   -99,   -99,   -99,
     -99,    24,   -99,    12,   -99,   186,   -99,   187,   188,    -2,
     192,    22,   185,   -99,   189,    47,   190,   191,    70,   195,
      72,    17,     4,    12,   -99,   -99,    72,   200,    -4,   -99,
       5,    17,   116,   -99,   116,   -99,    78,   193,   194,   196,
     202,   185,   189,    32,   197,   -99,    86,    89,   198,   199,
     -99,   -99,   -99,    17,    17,    17,   -99,   -99,   -99,   -99,
      17,    17,   201,   203,   205,   208,   204,   206,   209,   210,
     213,   214,   218,   219,   221,   223,    17,    12,   224,   225,
     226,   227,     5,     5,     5,     5,   220,   222,   228,    72,
      72,    72,    72,    97,    98,   115,   117,   125,   127,   133,
     141,    32,    32,    32,   142,   146,   147,   152,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   229,   230,   231,   -99,
     -99,   -99,   -99,   235,   236,   238,     5,     5,     5,   156,
     157,   158,   167,   168,   169,   -99,   -99,   -99,   -99,   -99,
     -99
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     0,     0,    11,     1,
       0,     0,     0,     0,    15,    13,    14,     0,    12,     0,
       0,     0,     0,     0,    16,    18,     0,     0,     0,     0,
       0,     0,    10,     0,    34,     0,     0,    40,     0,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,     0,    33,    35,     0,    20,    19,
       7,     0,     9,     0,     0,     0,     0,     3,     4,     5,
       6,     0,     8,     0,    55,     0,    56,     0,     0,     0,
       0,     0,    26,    38,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,    21,     0,     0,     0,    23,
       0,     0,     0,    22,     0,    37,     0,     0,     0,     0,
       0,    29,    28,     0,     0,    39,     0,     0,     0,     0,
      62,    63,    61,     0,     0,     0,    36,    31,    25,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    50,
      52,    48,    53,    49,    51,    47,     0,     0,     0,    60,
      59,    58,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,    43,    44,    41,    45,
      42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,    -1,   -24,   -99,    -6,    30,   -99,   -99,   -99,    57,
     -78,   113,   -99,   153,   114,   143,   -99,   -99,   -99,   -98,
     -87
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    79,    80,     2,     3,    16,    21,    13,    37,    38,
      81,    82,    23,    35,    83,    84,     4,    85,    86,    87,
      88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       6,    12,     5,    34,   120,    43,   121,    25,     1,    15,
       1,     5,   106,   117,    26,    73,    20,    93,     5,    11,
      14,    56,   116,     5,    73,    29,    33,    74,    75,    76,
       5,    31,    95,    34,    32,    46,     7,    44,     5,    96,
      50,    52,    53,    73,    33,    45,    74,    75,    76,     8,
      31,    77,    78,    32,    71,    45,    33,    99,    31,     9,
      66,    32,    67,    69,   100,   164,   166,   168,   170,    10,
      17,    51,    89,    54,   163,   165,   167,   169,     5,    18,
     103,   174,   175,   176,   177,    19,   109,   104,   122,   127,
     107,    73,   110,    68,    70,    96,   128,   114,    31,   129,
     118,    32,    27,    96,    58,    59,   104,   178,   179,   200,
     202,   204,    33,     5,    96,   104,    22,    24,   199,   201,
     203,   108,   132,   134,   136,   180,    28,   181,    30,   138,
     140,   119,    96,    31,   104,   182,    32,   183,    74,    75,
      76,    36,    96,   184,   104,   156,   158,   186,   187,   188,
      96,   185,   189,   133,   135,   137,   190,   191,   104,    96,
     139,   141,   192,    96,    96,    39,   205,   206,   207,    96,
      33,    33,    33,    96,   104,    96,   157,   208,   209,   210,
      40,    43,    41,    42,   104,    96,   104,    49,    55,    57,
      47,    60,    48,    62,    61,    90,    72,    94,    91,    92,
     105,   101,    97,    63,    64,   113,    98,   126,   102,   111,
      65,     0,   115,   142,   125,   143,    93,   144,   123,   124,
     145,   148,   149,   130,   131,   150,   151,   152,   153,   146,
     154,   147,   155,   159,   160,   161,   162,     0,   171,   112,
     172,   193,   194,   195,   196,   197,   173,   198
};

static const yytype_int16 yycheck[] =
{
       1,     7,     6,    27,   102,     7,   104,    10,     4,    10,
       4,     6,    90,   100,    17,    19,    17,    19,     6,    13,
       3,    45,   100,     6,    19,    26,    27,    22,    23,    24,
       6,    26,    10,    57,    29,    36,    17,    10,     6,    17,
      41,    42,    43,    19,    45,    18,    22,    23,    24,     5,
      26,    27,    28,    29,    17,    18,    57,    10,    26,     0,
      61,    29,    63,    64,    17,   152,   153,   154,   155,     7,
       9,    41,    73,    43,   152,   153,   154,   155,     6,     5,
      10,   159,   160,   161,   162,    17,    92,    17,    10,   113,
      91,    19,    93,    63,    64,    17,    10,    98,    26,    10,
     101,    29,     9,    17,    47,    48,    17,    10,    10,   196,
     197,   198,   113,     6,    17,    17,    16,     5,   196,   197,
     198,    91,   123,   124,   125,    10,    17,    10,    21,   130,
     131,   101,    17,    26,    17,    10,    29,    10,    22,    23,
      24,    15,    17,    10,    17,   146,   147,   171,   172,   173,
      17,    10,    10,   123,   124,   125,    10,    10,    17,    17,
     130,   131,    10,    17,    17,     5,    10,    10,    10,    17,
     171,   172,   173,    17,    17,    17,   146,    10,    10,    10,
      10,     7,    11,    11,    17,    17,    17,     5,     5,     9,
      17,    12,    17,    12,    18,     9,    12,     5,    11,    11,
       5,    11,    17,    26,    26,     5,    17,     5,    17,    96,
      57,    -1,    98,    12,    18,    12,    19,    12,    25,    25,
      12,    12,    12,    25,    25,    12,    12,     9,     9,    25,
       9,    25,     9,     9,     9,     9,     9,    -1,    18,    96,
      18,    12,    12,    12,     9,     9,    18,     9
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    33,    34,    46,     6,    31,    17,     5,     0,
       7,    13,    34,    37,     3,    31,    35,     9,     5,    17,
      31,    36,    16,    42,     5,    10,    17,     9,    17,    31,
      21,    26,    29,    31,    32,    43,    15,    38,    39,     5,
      10,    11,    11,     7,    10,    18,    31,    17,    17,     5,
      31,    35,    31,    31,    35,     5,    32,     9,    39,    39,
      12,    18,    12,    26,    26,    43,    31,    31,    35,    31,
      35,    17,    12,    19,    22,    23,    24,    27,    28,    31,
      32,    40,    41,    44,    45,    47,    48,    49,    50,    31,
       9,    11,    11,    19,     5,    10,    17,    17,    17,    10,
      17,    11,    17,    10,    17,     5,    40,    31,    35,    34,
      31,    41,    45,     5,    31,    44,    40,    50,    31,    35,
      49,    49,    10,    25,    25,    18,     5,    32,    10,    10,
      25,    25,    31,    35,    31,    35,    31,    35,    31,    35,
      31,    35,    12,    12,    12,    12,    25,    25,    12,    12,
      12,    12,     9,     9,     9,     9,    31,    35,    31,     9,
       9,     9,     9,    40,    50,    40,    50,    40,    50,    40,
      50,    18,    18,    18,    40,    40,    40,    40,    10,    10,
      10,    10,    10,    10,    10,    10,    32,    32,    32,    10,
      10,    10,    10,    12,    12,    12,     9,     9,     9,    40,
      50,    40,    50,    40,    50,    10,    10,    10,    10,    10,
      10
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    31,    32,    32,    32,    32,    32,    32,    32,
      32,    33,    33,    34,    34,    35,    36,    36,    37,    38,
      38,    39,    39,    39,    39,    39,    40,    40,    40,    40,
      41,    41,    42,    42,    43,    43,    44,    44,    45,    45,
      46,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    48,    48,    49,    49,    49,
      49,    49,    50,    50
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     5,     5,     5,     5,     4,     6,     4,
       1,     2,     4,     4,     4,     1,     2,     4,     4,     3,
       3,     7,     7,     7,     9,     9,     1,     1,     3,     3,
       2,     4,     5,     5,     1,     3,     4,     3,     1,     3,
       7,    13,    13,    13,    13,    13,    13,     9,     9,     9,
       9,     9,     9,     9,     9,     1,     1,     9,     9,     9,
       9,     4,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
        case 3:
#line 69 "bison.y" /* yacc.c:1652  */
    {(yyval.op)=new_operazione( new_assegnazioni( (yyvsp[-4].c), NULL, 15), new_assegnazioni( (yyvsp[-2].c), NULL, 15), new_assegnazioni( (yyvsp[0].c), NULL, 15), (yyvsp[-1].fn), -1);}
#line 1371 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 70 "bison.y" /* yacc.c:1652  */
    {(yyval.op)=new_operazione( new_assegnazioni( (yyvsp[-4].c), NULL, 15), new_assegnazioni( (yyvsp[-2].c), NULL, 15), new_assegnazioni( NULL, (void*) (yyvsp[0].fn), 11), (yyvsp[-1].fn), -1);}
#line 1377 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 71 "bison.y" /* yacc.c:1652  */
    {(yyval.op)=new_operazione( new_assegnazioni( (yyvsp[-4].c), NULL, 15), new_assegnazioni( NULL, (void*) (yyvsp[-2].fn), 11), new_assegnazioni( (yyvsp[0].c), NULL, 15), (yyvsp[-1].fn), -1);}
#line 1383 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 72 "bison.y" /* yacc.c:1652  */
    {(yyval.op)=new_operazione( new_assegnazioni( (yyvsp[-4].c), NULL, 15), new_assegnazioni(NULL, (void*) (yyvsp[-2].fn), 11), new_assegnazioni( NULL, (void*) (yyvsp[0].fn), 11), (yyvsp[-1].fn), -1);}
#line 1389 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 73 "bison.y" /* yacc.c:1652  */
    {(yyval.op)=new_operazione( new_assegnazioni( (yyvsp[-1].c), NULL, 15), NULL, NULL, (yyvsp[-3].fn), -1);}
#line 1395 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 74 "bison.y" /* yacc.c:1652  */
    {(yyval.op)=new_operazione( new_assegnazioni( (yyvsp[-1].c), NULL, 15), NULL, NULL, (yyvsp[-5].fn), (yyvsp[-3].fn));}
#line 1401 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 75 "bison.y" /* yacc.c:1652  */
    {(yyval.op)=new_operazione( new_assegnazioni( (yyvsp[-1].c), NULL, 15), NULL, NULL, (yyvsp[-3].fn), -1);}
#line 1407 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 76 "bison.y" /* yacc.c:1652  */
    {(yyval.op)=new_operazione(NULL, NULL, NULL, (yyvsp[0].fn), -1);}
#line 1413 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 84 "bison.y" /* yacc.c:1652  */
    {(yyval.as)= add_assegnazioni( (yyvsp[-3].as), (yyvsp[-1].as));}
#line 1419 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 87 "bison.y" /* yacc.c:1652  */
    {(yyval.as) = new_assegnazioni( (yyvsp[-2].c), (yyvsp[0].c), (yyvsp[-3].fn));}
#line 1425 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 88 "bison.y" /* yacc.c:1652  */
    {(yyval.as) = new_assegnazioni( (yyvsp[-2].c), (void*) (yyvsp[0].fn), (yyvsp[-3].fn));}
#line 1431 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 98 "bison.y" /* yacc.c:1652  */
    {(yyval.even) = new_evento((evento*) (yyvsp[-1].c),NULL);}
#line 1437 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 99 "bison.y" /* yacc.c:1652  */
    {(yyval.even)= add_evento((yyvsp[-3].even),new_evento((evento*) (yyvsp[-1].c),NULL));}
#line 1443 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 108 "bison.y" /* yacc.c:1652  */
    {(yyval.elen_stat)=new_el_stati((yyvsp[-2].stat), (yyvsp[0].stat));}
#line 1449 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 109 "bison.y" /* yacc.c:1652  */
    {(yyval.elen_stat)=add_el_stati((yyvsp[-2].elen_stat), (yyvsp[0].stat));}
#line 1455 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 112 "bison.y" /* yacc.c:1652  */
    {(yyval.stat)=new_stato2((yyvsp[-5].c),(yyvsp[-3].azione),(yyvsp[-1].elen));}
#line 1461 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 113 "bison.y" /* yacc.c:1652  */
    {(yyval.stat)=new_stato2((yyvsp[-5].c),(yyvsp[-3].azione),(yyvsp[-1].elen_con));}
#line 1467 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 114 "bison.y" /* yacc.c:1652  */
    {(yyval.stat)=new_stato5((yyvsp[-5].c),(yyvsp[-3].azione),NULL,NULL,(yyvsp[-1].cic));}
#line 1473 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 115 "bison.y" /* yacc.c:1652  */
    {(yyval.stat)=new_stato5((yyvsp[-7].c),(yyvsp[-5].azione),(yyvsp[-1].elen_con),NULL,(yyvsp[-3].cic));}
#line 1479 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 116 "bison.y" /* yacc.c:1652  */
    {(yyval.stat)=new_stato5((yyvsp[-7].c),(yyvsp[-5].azione),NULL,(yyvsp[-1].elen),(yyvsp[-3].cic));}
#line 1485 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 119 "bison.y" /* yacc.c:1652  */
    {(yyval.elen)= new_elenchi((yyvsp[0].azione), NULL);}
#line 1491 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 120 "bison.y" /* yacc.c:1652  */
    {(yyval.elen)= new_elenchi(NULL, (yyvsp[0].camb_stat));}
#line 1497 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 121 "bison.y" /* yacc.c:1652  */
    {(yyval.elen)= add_cambio_elenchi((yyvsp[-2].elen), (yyvsp[0].camb_stat));}
#line 1503 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 122 "bison.y" /* yacc.c:1652  */
    {(yyval.elen)= add_oper_elenchi((yyvsp[-2].elen), (yyvsp[0].azione));}
#line 1509 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 125 "bison.y" /* yacc.c:1652  */
    {(yyval.azione) = new_action((action) (yyvsp[-1].op),NULL);}
#line 1515 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 126 "bison.y" /* yacc.c:1652  */
    {(yyval.azione) = add_azione((yyvsp[-3].azione), new_action((action) (yyvsp[0].op), NULL));}
#line 1521 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 135 "bison.y" /* yacc.c:1652  */
    {(yyval.azione)= new_action(NULL, NULL);}
#line 1527 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 136 "bison.y" /* yacc.c:1652  */
    {(yyval.azione)= (yyvsp[-2].azione);}
#line 1533 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 139 "bison.y" /* yacc.c:1652  */
    {(yyval.azione) = new_action((azione) (yyvsp[0].op),NULL);}
#line 1539 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 140 "bison.y" /* yacc.c:1652  */
    {(yyval.azione) = add_azione((yyvsp[-2].azione), new_action((azione) (yyvsp[0].op), NULL));}
#line 1545 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 143 "bison.y" /* yacc.c:1652  */
    {(yyval.camb_stat)= new_cambiostato(new_evento((evento) (yyvsp[-3].c),NULL),new_el_stati1(new_stato1((yyvsp[-1].c))));}
#line 1551 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 144 "bison.y" /* yacc.c:1652  */
    {(yyval.camb_stat)= new_cambiostato(new_evento( (evento) "0",NULL),new_el_stati1(new_stato1((yyvsp[-1].c))));}
#line 1557 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 148 "bison.y" /* yacc.c:1652  */
    {(yyval.camb_stat)=add_cambiostato((yyvsp[-2].camb_stat),(yyvsp[0].camb_stat));}
#line 1563 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 157 "bison.y" /* yacc.c:1652  */
    {run((yyvsp[-6].as),(yyvsp[-4].even),(yyvsp[-2].azione),(yyvsp[0].elen_stat));}
#line 1569 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 160 "bison.y" /* yacc.c:1652  */
    {(yyval.cic)=new_cicli(1, (yyvsp[-10].as), (yyvsp[-1].elen_con), (yyvsp[-4].op), new_cond(new_assegnazioni(NULL, (yyvsp[-8].c),(int) 16),new_assegnazioni(NULL, (yyvsp[-6].fn),(int) 14) (yyvsp[-7].fn), NULL));}
#line 1575 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 161 "bison.y" /* yacc.c:1652  */
    {(yyval.cic)=new_cicli(1, (yyvsp[-10].as), (yyvsp[-1].elen_con), (yyvsp[-4].op), new_cond(new_assegnazioni(NULL, (yyvsp[-8].fn),(int) 14),new_assegnazioni(NULL, (yyvsp[-6].c),(int) 16) (yyvsp[-7].fn), NULL));}
#line 1581 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 162 "bison.y" /* yacc.c:1652  */
    {(yyval.cic)=new_cicli(1, (yyvsp[-10].as), (yyvsp[-1].elen_con), (yyvsp[-4].op), new_cond(new_assegnazioni(NULL, (yyvsp[-8].c),(int) 16),new_assegnazioni(NULL, (yyvsp[-6].c),(int) 16) (yyvsp[-7].fn), NULL));}
#line 1587 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 163 "bison.y" /* yacc.c:1652  */
    {(yyval.cic)=new_cicli1(1, (yyvsp[-10].as), (yyvsp[-1].elen), (yyvsp[-4].op), new_cond(new_assegnazioni(NULL, (yyvsp[-8].c),(int) 16),new_assegnazioni(NULL, (yyvsp[-6].fn),(int) 14) (yyvsp[-7].fn), NULL));}
#line 1593 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 164 "bison.y" /* yacc.c:1652  */
    {(yyval.cic)=new_cicli1(1, (yyvsp[-10].as), (yyvsp[-1].elen), (yyvsp[-4].op), new_cond(new_assegnazioni(NULL, (yyvsp[-8].fn),(int) 14),new_assegnazioni(NULL, (yyvsp[-6].c),(int) 16) (yyvsp[-7].fn), NULL));}
#line 1599 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 165 "bison.y" /* yacc.c:1652  */
    {(yyval.cic)=new_cicli1(1, (yyvsp[-10].as), (yyvsp[-1].elen), (yyvsp[-4].op), new_cond(new_assegnazioni(NULL, (yyvsp[-8].c),(int) 16),new_assegnazioni(NULL, (yyvsp[-6].c),(int) 16) (yyvsp[-7].fn), NULL));}
#line 1605 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 166 "bison.y" /* yacc.c:1652  */
    {(yyval.cic)=new_cicli(2, NULL, (yyvsp[-1].elen_con), NULL, new_cond(new_assegnazioni(NULL, (yyvsp[-6].fn),(int) 14),new_assegnazioni(NULL, (yyvsp[-4].fn),(int) 14) (yyvsp[-5].fn), NULL));}
#line 1611 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 167 "bison.y" /* yacc.c:1652  */
    {(yyval.cic)=new_cicli(2, NULL, (yyvsp[-1].elen_con), NULL, new_cond(new_assegnazioni(NULL, (yyvsp[-6].c),(int) 16),new_assegnazioni(NULL, (yyvsp[-4].fn),(int) 14) (yyvsp[-5].fn), NULL));}
#line 1617 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 168 "bison.y" /* yacc.c:1652  */
    {(yyval.cic)=new_cicli(2, NULL, (yyvsp[-1].elen_con), NULL, new_cond(new_assegnazioni(NULL, (yyvsp[-6].fn),(int) 14),new_assegnazioni(NULL, (yyvsp[-4].c),(int) 16) (yyvsp[-5].fn), NULL));}
#line 1623 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 169 "bison.y" /* yacc.c:1652  */
    {(yyval.cic)=new_cicli(2, NULL, (yyvsp[-1].elen_con), NULL, new_cond(new_assegnazioni(NULL, (yyvsp[-6].c),(int) 16),new_assegnazioni(NULL, (yyvsp[-4].c),(int) 16) (yyvsp[-5].fn), NULL));}
#line 1629 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 170 "bison.y" /* yacc.c:1652  */
    {(yyval.cic)=new_cicli1(2, NULL, (yyvsp[-1].elen), NULL, new_cond(new_assegnazioni(NULL, (yyvsp[-6].fn),(int) 14),new_assegnazioni(NULL, (yyvsp[-4].fn),(int) 14) (yyvsp[-5].fn), NULL));}
#line 1635 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 171 "bison.y" /* yacc.c:1652  */
    {(yyval.cic)=new_cicli1(2, NULL, (yyvsp[-1].elen), NULL, new_cond(new_assegnazioni(NULL, (yyvsp[-6].c),(int) 16),new_assegnazioni(NULL, (yyvsp[-4].fn),(int) 14) (yyvsp[-5].fn), NULL));}
#line 1641 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 172 "bison.y" /* yacc.c:1652  */
    {(yyval.cic)=new_cicli1(2, NULL, (yyvsp[-1].elen), NULL, new_cond(new_assegnazioni(NULL, (yyvsp[-6].fn),(int) 14),new_assegnazioni(NULL, (yyvsp[-4].c),(int) 16) (yyvsp[-5].fn), NULL));}
#line 1647 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 173 "bison.y" /* yacc.c:1652  */
    {(yyval.cic)=new_cicli1(2, NULL, (yyvsp[-1].elen), NULL, new_cond(new_assegnazioni(NULL, (yyvsp[-6].c),(int) 16),new_assegnazioni(NULL, (yyvsp[-4].c),(int) 16) (yyvsp[-5].fn), NULL));}
#line 1653 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 180 "bison.y" /* yacc.c:1652  */
    {(yyval.con)=new_cond(new_assegnazioni(NULL, (void *) (yyvsp[-6].fn), 14),new_assegnazioni(NULL,(void*) (yyvsp[-4].fn),(int) 14), (yyvsp[-5].fn), (yyvsp[-1].elen));}
#line 1659 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 181 "bison.y" /* yacc.c:1652  */
    {(yyval.con)=new_cond(new_assegnazioni(NULL,(void*) (yyvsp[-6].fn),(int) 14),new_assegnazioni(NULL, (yyvsp[-4].c),(int) 16), (yyvsp[-5].fn), (yyvsp[-1].elen));}
#line 1665 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 182 "bison.y" /* yacc.c:1652  */
    {(yyval.con)=new_cond(new_assegnazioni(NULL, (yyvsp[-6].c),(int) 16),new_assegnazioni(NULL,(void*) (yyvsp[-4].fn),(int) 14), (yyvsp[-5].fn), (yyvsp[-1].elen));}
#line 1671 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 183 "bison.y" /* yacc.c:1652  */
    {(yyval.con)=new_cond(new_assegnazioni(NULL, (yyvsp[-6].c),(int) 16),new_assegnazioni(NULL, (yyvsp[-4].c),(int) 16), (yyvsp[-5].fn), (yyvsp[-1].elen));}
#line 1677 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 184 "bison.y" /* yacc.c:1652  */
    {(yyval.con)=new_cond(NULL,NULL,0, (yyvsp[-1].elen));}
#line 1683 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 187 "bison.y" /* yacc.c:1652  */
    {(yyval.elen_con)=add_elencocond(new_elencocond((yyvsp[-2].con)),new_elencocond((yyvsp[0].con)));}
#line 1689 "bison.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 188 "bison.y" /* yacc.c:1652  */
    {(yyval.elen_con)=add_elencocond((yyvsp[-2].elen_con),new_elencocond((yyvsp[0].con)));}
#line 1695 "bison.tab.c" /* yacc.c:1652  */
    break;


#line 1699 "bison.tab.c" /* yacc.c:1652  */
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 191 "bison.y" /* yacc.c:1918  */

