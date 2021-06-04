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
#line 1 "mini_l.y" /* yacc.c:339  */

#define YY_NO_UNPUT
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string.h>
#include <vector>
void yyerror(const char* s);
int yylex();
  
extern int lineNum;
extern int lineCol;
extern char* yytext;
extern char* progName;
  
std::string newTemp();
std::string newLabel();

char empty[1] = "";

std::map<std::string, int> variables;

std::map<std::string, int> functions;
std::vector<std::string> reservedWords = {"FUNCTION", "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER",
    "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "FOREACH", "IN", "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", 
    "NOT", "TRUE", "FALSE", "RETURN", "SUB", "ADD", "MULT", "DIV", "MOD", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET",
    "R_SQUARE_BRACKET", "COLON", "SEMICOLON", "COMMA", "ASSIGN", "function", "Ident", "beginparams", "endparams", "beginlocals", "endlocals", "integer", 
    "beginbody", "endbody", "beginloop", "endloop", "if", "endif", "foreach", "continue", "while", "else", "read", "do", "write"};

#line 96 "mini_l.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "mini_l.tab.h".  */
#ifndef YY_YY_MINI_L_TAB_H_INCLUDED
# define YY_YY_MINI_L_TAB_H_INCLUDED
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
    IDENT = 258,
    NUMBER = 259,
    FUNCTION = 260,
    BEGIN_PARAMS = 261,
    END_PARAMS = 262,
    BEGIN_LOCALS = 263,
    END_LOCALS = 264,
    BEGIN_BODY = 265,
    END_BODY = 266,
    INTEGER = 267,
    ARRAY = 268,
    OF = 269,
    IF = 270,
    THEN = 271,
    ENDIF = 272,
    ELSE = 273,
    WHILE = 274,
    DO = 275,
    FOREACH = 276,
    IN = 277,
    BEGINLOOP = 278,
    ENDLOOP = 279,
    CONTINUE = 280,
    READ = 281,
    WRITE = 282,
    TRUE = 283,
    FALSE = 284,
    RETURN = 285,
    L_PAREN = 286,
    R_PAREN = 287,
    L_SQUARE_BRACKET = 288,
    R_SQUARE_BRACKET = 289,
    COLON = 290,
    SEMICOLON = 291,
    COMMA = 292,
    ASSIGN = 293,
    EQ = 294,
    NEQ = 295,
    LT = 296,
    GT = 297,
    LTE = 298,
    GTE = 299,
    ADD = 300,
    SUB = 301,
    MULT = 302,
    DIV = 303,
    MOD = 304,
    AND = 305,
    OR = 306,
    NOT = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 32 "mini_l.y" /* yacc.c:355  */

  char* ident_val;
  int num_val;
  struct E {
    char* place;
    char* code;
    bool array;
  } expr;

  struct S {
    char* code;
  } stat;
 

#line 204 "mini_l.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINI_L_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 221 "mini_l.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    80,    84,   116,   170,   222,   227,   237,
     242,   254,   262,   270,   304,   337,   377,   407,   509,   522,
     535,   540,   551,   555,   560,   583,   607,   622,   639,   644,
     664,   685,   690,   702,   715,   720,   740,   760,   782,   806,
     838,   843,   851,   856,   868,   893,   898,   921,   926,   949,
     968,   974,   995,  1001,  1007,  1013,  1019,  1025,  1031,  1037,
    1043,  1050,  1055,  1070
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "NUMBER", "FUNCTION",
  "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY",
  "END_BODY", "INTEGER", "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE",
  "WHILE", "DO", "FOREACH", "IN", "BEGINLOOP", "ENDLOOP", "CONTINUE",
  "READ", "WRITE", "TRUE", "FALSE", "RETURN", "L_PAREN", "R_PAREN",
  "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "COLON", "SEMICOLON", "COMMA",
  "ASSIGN", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "ADD", "SUB", "MULT",
  "DIV", "MOD", "AND", "OR", "NOT", "$accept", "Program", "Function",
  "Declaration", "Declarations", "Identifiers", "Statements", "Statement",
  "ElseStatement", "Var", "Vars", "Expression", "Expressions", "MultExp",
  "Term", "BoolExp", "RAExp", "RExp", "RExp1", "Comp", "Ident",
  "LocalIdent", "FunctionIdent", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF -40

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-40)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       5,    15,    21,     5,   -40,   -13,   -40,   -40,    19,    25,
     -40,     1,    27,    14,     9,    25,    48,    28,    25,   -40,
      25,   -40,    32,   -40,    51,    62,    59,    36,   112,    66,
      44,    44,    53,    79,   -40,    25,    25,    11,    73,    55,
      54,    60,    82,   -40,   -40,   -40,    44,     4,    97,   -40,
      67,    -2,   -16,    86,    47,    45,   -40,   -29,    80,   112,
     -40,    90,    77,   -40,   -40,    11,   -40,   -40,   112,    11,
      11,   -40,   108,    72,   -40,    11,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,    11,    11,    11,    11,    11,    11,
     112,    44,    44,    11,   112,    92,    25,    25,    88,   -40,
     -40,    84,   -40,   -40,    89,   -40,   -40,   -40,   -40,   -40,
     -40,   104,   -40,   -40,    87,    91,   105,   111,   113,   -40,
     -40,   -40,   112,   117,    11,   -40,   -40,    44,   112,   -40,
     -40,   -40,   -40,   120,   -40
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     2,    63,     0,     1,     3,     0,     7,
      61,     0,     0,     0,     9,     7,     0,     0,     0,     8,
       7,     5,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     0,     0,
       0,    25,     0,    40,    52,    53,     0,     0,     0,    38,
       0,    28,    34,     0,    45,    47,    50,    25,     0,     0,
      62,     0,    26,    18,    19,     0,    21,     4,    12,     0,
       0,     6,     0,     0,    41,     0,    39,    49,    55,    56,
      57,    58,    59,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,    11,
      13,     0,    42,    54,     0,    51,    29,    30,    35,    36,
      37,    22,    46,    48,    33,     0,     0,     0,     0,    27,
      24,    43,     0,     0,    31,    44,    15,     0,     0,    23,
      14,    32,    16,     0,    17
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -40,   132,   -40,   -40,     2,   123,   -39,   -40,   -40,   -23,
     -33,    -7,    22,   -35,   -40,   -30,    61,   -40,   106,   -40,
      -9,   -40,   -40
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    11,    12,    13,    38,    39,   123,    49,
      63,    50,   115,    51,    52,    53,    54,    55,    56,    84,
      57,    61,     5
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      14,    58,    93,    64,    70,    40,    14,    10,    74,    14,
       1,    14,    62,    62,    10,    43,    73,    19,     4,    41,
      95,     6,    24,     8,    76,     9,    41,    41,    10,    99,
      66,    87,    88,    89,    16,    75,    40,    15,    41,    72,
      21,    22,    65,    85,    86,    40,    18,    10,    43,    17,
      41,   111,   108,   109,   110,   116,    20,    47,    98,    41,
      26,   112,   100,   101,   119,    25,    27,    40,   104,    28,
      29,    40,    44,    45,    62,    46,    59,   105,   106,   107,
      42,    41,    60,   129,    67,    41,   114,   118,    41,   133,
      47,    68,    69,    70,    71,    92,    48,   132,    91,    40,
      10,    43,    90,    94,   103,    40,    78,    79,    80,    81,
      82,    83,    96,    41,    97,    10,   117,   114,   120,    41,
     102,   121,   122,   125,   124,    44,    45,    30,    46,   126,
     127,    31,    32,    33,   130,     7,   128,    34,    35,    36,
     102,    23,    37,    47,   134,     0,   131,    78,    79,    80,
      81,    82,    83,   113,    77
};

static const yytype_int16 yycheck[] =
{
       9,    31,    31,    36,    33,    28,    15,     3,     4,    18,
       5,    20,    35,    36,     3,     4,    46,    15,     3,    28,
      59,     0,    20,    36,    47,     6,    35,    36,     3,    68,
      37,    47,    48,    49,     7,    31,    59,    36,    47,    46,
      12,    13,    31,    45,    46,    68,    37,     3,     4,    35,
      59,    90,    87,    88,    89,    94,     8,    46,    65,    68,
       9,    91,    69,    70,    97,    33,     4,    90,    75,    10,
      34,    94,    28,    29,    97,    31,    23,    84,    85,    86,
      14,    90,     3,   122,    11,    94,    93,    96,    97,   128,
      46,    36,    38,    33,    12,    50,    52,   127,    51,   122,
       3,     4,    16,    23,    32,   128,    39,    40,    41,    42,
      43,    44,    22,   122,    37,     3,    24,   124,    34,   128,
      32,    32,    18,    32,    37,    28,    29,    15,    31,    24,
      19,    19,    20,    21,    17,     3,    23,    25,    26,    27,
      32,    18,    30,    46,    24,    -1,   124,    39,    40,    41,
      42,    43,    44,    92,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    54,    55,     3,    75,     0,    54,    36,     6,
       3,    56,    57,    58,    73,    36,     7,    35,    37,    57,
       8,    12,    13,    58,    57,    33,     9,     4,    10,    34,
      15,    19,    20,    21,    25,    26,    27,    30,    59,    60,
      62,    73,    14,     4,    28,    29,    31,    46,    52,    62,
      64,    66,    67,    68,    69,    70,    71,    73,    68,    23,
       3,    74,    62,    63,    63,    31,    64,    11,    36,    38,
      33,    12,    64,    68,     4,    31,    62,    71,    39,    40,
      41,    42,    43,    44,    72,    45,    46,    47,    48,    49,
      16,    51,    50,    31,    23,    59,    22,    37,    64,    59,
      64,    64,    32,    32,    64,    64,    64,    64,    66,    66,
      66,    59,    68,    69,    64,    65,    59,    24,    73,    63,
      34,    32,    18,    61,    37,    32,    24,    19,    23,    59,
      17,    65,    68,    59,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    62,    62,    63,    63,    64,    64,
      64,    65,    65,    65,    66,    66,    66,    66,    67,    67,
      67,    67,    67,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    71,    71,    72,    72,    72,    72,    72,
      72,    73,    74,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,    12,     3,     8,     0,     3,     1,
       3,     3,     2,     3,     6,     5,     6,     7,     2,     2,
       1,     2,     0,     2,     4,     1,     1,     3,     1,     3,
       3,     0,     3,     1,     1,     3,     3,     3,     1,     2,
       1,     2,     3,     4,     4,     1,     3,     1,     3,     2,
       1,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
#line 66 "mini_l.y" /* yacc.c:1646  */
    {
  std::string tempMain = "main";
  if ( functions.find(tempMain) == functions.end()) {
    char temp[128];
    snprintf(temp, 128, "Function main not declared");
    yyerror(temp);
  }
  
  if (variables.find(std::string(progName)) != variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Declared program name as variable.");
    yyerror(temp);
  }
}
#line 1410 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 81 "mini_l.y" /* yacc.c:1646  */
    {
}
#line 1417 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 85 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp = "func ";
  temp.append((yyvsp[-10].expr).place);
  temp.append("\n");
  temp.append((yyvsp[-10].expr).code);
  temp.append((yyvsp[-7].expr).code);
  
  std::string init_params = (yyvsp[-7].expr).code;
  int param_number = 0;
  while (init_params.find(".") != std::string::npos) {
    size_t pos = init_params.find(".");
    init_params.replace(pos, 1, "=");
    std::string param = ", $";
    param.append(std::to_string(param_number++));
    param.append("\n");
    init_params.replace(init_params.find("\n", pos), 1, param);
  }
  temp.append(init_params);
  temp.append((yyvsp[-4].expr).code);
  std::string statements((yyvsp[-1].stat).code);
  
  if (statements.find("continue") != std::string::npos) {
    printf("ERROR: Continue outside loop in function %s\n", (yyvsp[-10].expr).place);
  }
  temp.append(statements);
  temp.append("endfunc\n");
  
  printf("%s", temp.c_str());
}
#line 1451 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 117 "mini_l.y" /* yacc.c:1646  */
    {
  std::string vars((yyvsp[-2].expr).place);
  std::string temp;
  std::string variable;
  bool cont = true;

  
  size_t oldpos = 0;
  size_t pos = 0;
  bool isReserved = false;
  while (cont) {
    pos = vars.find("|", oldpos);
    if (pos == std::string::npos) {
      temp.append(". ");
      variable = vars.substr(oldpos,pos);
      temp.append(variable);
      temp.append("\n");
      cont = false;
    }
    else {
      size_t len = pos - oldpos;
      temp.append(". ");
      variable = vars.substr(oldpos, len);
      temp.append(variable);
      temp.append("\n");
    }
    
    for (unsigned int i = 0; i < reservedWords.size(); ++i) {
      if (reservedWords.at(i) == variable) {
        isReserved = true;
      }
    } 
    
    if (variables.find(variable) != variables.end()) {
      char temp[128];
      snprintf(temp, 128, "Redeclaration of variable %s", variable.c_str());
      yyerror(temp);
    }
    else if (isReserved){
      char temp[128];
      snprintf(temp, 128, "Invalid declaration of reserved words %s", variable.c_str());
      yyerror(temp);
    }
    else {
      variables.insert(std::pair<std::string,int>(variable,0));
    }
    
    oldpos = pos + 1;
  }
  
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).place = strdup(empty);	      
}
#line 1509 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 171 "mini_l.y" /* yacc.c:1646  */
    {
  if ((yyvsp[-3].num_val) <= 0) {
    char temp[128];
    snprintf(temp, 128, "Array size can't be less than 1");
    yyerror(temp);
  }
  
  std::string vars((yyvsp[-7].expr).place);
  std::string temp;
  std::string variable;
  bool cont = true;

  size_t oldpos = 0;
  size_t pos = 0;
  while (cont) {
    pos = vars.find("|", oldpos);
    if (pos == std::string::npos) {
      temp.append(".[] ");
      variable = vars.substr(oldpos, pos);
      temp.append(variable);
      temp.append(", ");
      temp.append(std::to_string((yyvsp[-3].num_val)));
      temp.append("\n");
      cont = false;
    }
    else {
      size_t len = pos - oldpos;
      temp.append(".[] ");
      variable = vars.substr(oldpos, len);
      temp.append(variable);
      temp.append(", ");
      temp.append(std::to_string((yyvsp[-3].num_val)));
      temp.append("\n");
    }
    
    if (variables.find(variable) != variables.end()) {
      char temp[128];
      snprintf(temp, 128, "Redeclaration of variable %s", variable.c_str());
      yyerror(temp);
    }
    else {
      variables.insert(std::pair<std::string,int>(variable,(yyvsp[-3].num_val)));
    }
      
    oldpos = pos + 1;
  }
  
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).place = strdup(empty);	      
}
#line 1564 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 223 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).code = strdup(empty);
  (yyval.expr).place = strdup(empty);
}
#line 1573 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 228 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp;
  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).place = strdup(empty);
}
#line 1586 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 238 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).place = strdup((yyvsp[0].expr).place);
  (yyval.expr).code = strdup(empty);
}
#line 1595 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 243 "mini_l.y" /* yacc.c:1646  */
    {

  std::string temp;
  temp.append((yyvsp[-2].expr).place);
  temp.append("|");
  temp.append((yyvsp[0].expr).place);
  
  (yyval.expr).place = strdup(temp.c_str());
  (yyval.expr).code = strdup(empty);
}
#line 1610 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 255 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp;
  temp.append((yyvsp[-2].stat).code);
  temp.append((yyvsp[0].stat).code);

  (yyval.stat).code = strdup(temp.c_str());
}
#line 1622 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 263 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp;
  temp.append((yyvsp[-1].stat).code);

  (yyval.stat).code = strdup(temp.c_str());
}
#line 1633 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 271 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp;
  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  std::string intermediate = (yyvsp[0].expr).place;
  if ((yyvsp[-2].expr).array && (yyvsp[0].expr).array) {
    intermediate = newTemp();
    temp.append(". ");
    temp.append(intermediate);
    temp.append("\n");
    temp.append("=[] ");
    temp.append(intermediate);
    temp.append(", ");
    temp.append((yyvsp[0].expr).place);
    temp.append("\n");
    temp.append("[]= ");
  }
  else if ((yyvsp[-2].expr).array) {
    temp.append("[]= ");
  }
  else if ((yyvsp[0].expr).array) {
    temp.append("=[] ");
  }
  else {
    temp.append("= ");
  }
  temp.append((yyvsp[-2].expr).place);
  temp.append(", ");
  temp.append(intermediate);
  temp.append("\n");

  (yyval.stat).code = strdup(temp.c_str());
}
#line 1671 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 305 "mini_l.y" /* yacc.c:1646  */
    {
  std::string then_begin = newLabel();
  std::string after = newLabel();
  std::string temp;


  temp.append((yyvsp[-4].expr).code);
  
  temp.append("?:= ");
  temp.append(then_begin);
  temp.append(", ");
  temp.append((yyvsp[-4].expr).place);
  temp.append("\n");
  
  temp.append((yyvsp[-1].stat).code);
  
  temp.append(":= ");
  temp.append(after);
  temp.append("\n");
  
  temp.append(": ");
  temp.append(then_begin);
  temp.append("\n");
  
  temp.append((yyvsp[-2].stat).code);
  
  temp.append(": ");
  temp.append(after);
  temp.append("\n");
  
  (yyval.stat).code = strdup(temp.c_str());
}
#line 1708 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 338 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp;
  std::string beginWhile = newLabel();
  std::string beginLoop = newLabel();
  std::string endLoop = newLabel();
  
  std::string statement = (yyvsp[-1].stat).code;
  std::string jump;
  jump.append(":= ");
  jump.append(beginWhile);
  while (statement.find("continue") != std::string::npos) {
    statement.replace(statement.find("continue"), 8, jump);
  }
  
  temp.append(": ");
  temp.append(beginWhile);
  temp.append("\n");
  temp.append((yyvsp[-3].expr).code);
  temp.append("?:= ");
  temp.append(beginLoop);
  temp.append(", ");
  temp.append((yyvsp[-3].expr).place);
  temp.append("\n");
  temp.append(":= ");
  temp.append(endLoop);
  temp.append("\n");
  temp.append(": ");
  temp.append(beginLoop);
  temp.append("\n");
  temp.append(statement);
  temp.append(":= ");
  temp.append(beginWhile);
  temp.append("\n");
  temp.append(": ");
  temp.append(endLoop);
  temp.append("\n");

  (yyval.stat).code = strdup(temp.c_str());
}
#line 1752 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 378 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp;
  std::string beginLoop = newLabel();
  std::string beginWhile = newLabel();
  
  std::string statement = (yyvsp[-3].stat).code;
  std::string jump;
  jump.append(":= ");
  jump.append(beginWhile);
  while (statement.find("continue") != std::string::npos) {
    statement.replace(statement.find("continue"), 8, jump);
  }
  
  temp.append(": ");
  temp.append(beginLoop);
  temp.append("\n");
  temp.append(statement);
  temp.append(": ");
  temp.append(beginWhile);
  temp.append("\n");
  temp.append((yyvsp[0].expr).code);
  temp.append("?:= ");
  temp.append(beginLoop);
  temp.append(", ");
  temp.append((yyvsp[0].expr).place);
  temp.append("\n");
  
  (yyval.stat).code = strdup(temp.c_str());
}
#line 1786 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 408 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp;
  std::string count = newTemp();
  std::string check = newTemp();
  std::string begin = newLabel();
  std::string beginLoop = newLabel();
  std::string increment = newLabel();
  std::string endLoop = newLabel();
  
  std::string statement = (yyvsp[-1].stat).code;
  std::string jump;
  jump.append(":= ");
  jump.append(increment);
  while (statement.find("continue") != std::string::npos) {
    statement.replace(statement.find("continue"), 8, jump);
  }
  
  if (variables.find(std::string((yyvsp[-3].expr).place)) == variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared variable %s", (yyvsp[-3].expr).place);
    yyerror(temp);
  }
  
  else if (variables.find(std::string((yyvsp[-3].expr).place))->second == 0) {
    char temp[128];
    snprintf(temp, 128, "Use of scalar variable %s in foreach", (yyvsp[-3].expr).place);
    yyerror(temp);
  }

  temp.append(". ");
  temp.append((yyvsp[-5].expr).place);
  temp.append("\n");

  temp.append(". ");
  temp.append(check);
  temp.append("\n");

  temp.append(". ");
  temp.append(count);
  temp.append("\n");

  temp.append("= ");
  temp.append(count);
  temp.append(", 0");
  temp.append("\n");
  
  temp.append(": ");
  temp.append(begin);
  temp.append("\n");

  temp.append("< ");
  temp.append(check);
  temp.append(", ");
  temp.append(count);
  temp.append(", ");
  temp.append(std::to_string(variables.find(std::string((yyvsp[-3].expr).place))->second));
  temp.append("\n");
 
  temp.append("?:= ");
  temp.append(beginLoop);
  temp.append(", ");
  temp.append(check);
  temp.append("\n");
  
  temp.append(":= ");
  temp.append(endLoop);
  temp.append("\n");
  
  temp.append(": ");
  temp.append(beginLoop);
  temp.append("\n");
  
  temp.append("=[] ");
  temp.append((yyvsp[-5].expr).place);
  temp.append(", ");
  temp.append((yyvsp[-3].expr).place);
  temp.append(", ");
  temp.append(count);
  temp.append("\n");
  
  temp.append(statement);
  temp.append(": ");
  temp.append(increment);
  temp.append("\n");

  temp.append("+ ");
  temp.append(count);
  temp.append(", ");
  temp.append(count);
  temp.append(", 1\n");
  
  temp.append(":= ");
  temp.append(begin);
  temp.append("\n");
 
  temp.append(": ");
  temp.append(endLoop);
  temp.append("\n");
  
  (yyval.stat).code = strdup(temp.c_str());
}
#line 1892 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 510 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp = (yyvsp[0].expr).code;
  size_t pos = 0;
  do {
    pos = temp.find("|", pos);
    if (pos == std::string::npos)
      break;
    temp.replace(pos, 1, "<");
  } while (true);

  (yyval.stat).code = strdup(temp.c_str());
}
#line 1909 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 523 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp = (yyvsp[0].expr).code;
  size_t pos = 0;
  do {
    pos = temp.find("|", pos);
    if (pos == std::string::npos)
      break;
    temp.replace(pos, 1, ">");
  } while (true);

  (yyval.stat).code = strdup(temp.c_str());
}
#line 1926 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 536 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp = "continue\n";
  (yyval.stat).code = strdup(temp.c_str());
}
#line 1935 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 541 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp;
  temp.append((yyvsp[0].expr).code);
  temp.append("ret ");
  temp.append((yyvsp[0].expr).place);
  temp.append("\n");
  (yyval.stat).code = strdup(temp.c_str());
}
#line 1948 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 552 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.stat).code = strdup(empty);
}
#line 1956 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 556 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.stat).code = strdup((yyvsp[0].stat).code);
}
#line 1964 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 561 "mini_l.y" /* yacc.c:1646  */
    {
  if (variables.find(std::string((yyvsp[-3].expr).place)) == variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared variable %s", (yyvsp[-3].expr).place);
    yyerror(temp);
  }
  
  else if (variables.find(std::string((yyvsp[-3].expr).place))->second == 0) {
    char temp[128];
    snprintf(temp, 128, "Indexing a non-array variable %s", (yyvsp[-3].expr).place);
    yyerror(temp);
  }

  std::string temp;
  temp.append((yyvsp[-3].expr).place);
  temp.append(", ");
  temp.append((yyvsp[-1].expr).place);

  (yyval.expr).code = strdup((yyvsp[-1].expr).code);
  (yyval.expr).place = strdup(temp.c_str());
  (yyval.expr).array = true;
}
#line 1991 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 584 "mini_l.y" /* yacc.c:1646  */
    {
  if (variables.find(std::string((yyvsp[0].expr).place)) == variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared variable %s", (yyvsp[0].expr).place);
    yyerror(temp);
  }
  
  else if (variables.find(std::string((yyvsp[0].expr).place))->second > 0) {
    char temp[128];
    snprintf(temp, 128, "Failed to provide index for array variable %s", (yyvsp[0].expr).place);
    yyerror(temp);
  }

  (yyval.expr).code = strdup(empty);
  (yyval.expr).place = strdup((yyvsp[0].expr).place);
  (yyval.expr).array = false;
}
#line 2013 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 608 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp;
  temp.append((yyvsp[0].expr).code);
  if ((yyvsp[0].expr).array)
    temp.append(".[]| ");
  else
    temp.append(".| ");
  
  temp.append((yyvsp[0].expr).place);
  temp.append("\n");

  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).place = strdup(empty);
}
#line 2032 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 623 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp;
  temp.append((yyvsp[-2].expr).code);
  if ((yyvsp[-2].expr).array)
    temp.append(".[]| ");
  else
    temp.append(".| ");
  
  temp.append((yyvsp[-2].expr).place);
  temp.append("\n");
  temp.append((yyvsp[0].expr).code);
  
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).place = strdup(empty);
}
#line 2052 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 640 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).code = strdup((yyvsp[0].expr).code);
  (yyval.expr).place = strdup((yyvsp[0].expr).place);
}
#line 2061 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 645 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).place = strdup(newTemp().c_str());
  
  std::string temp;
  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  temp.append(". ");
  temp.append((yyval.expr).place);
  temp.append("\n");
  temp.append("+ ");
  temp.append((yyval.expr).place);
  temp.append(", ");
  temp.append((yyvsp[-2].expr).place);
  temp.append(", ");
  temp.append((yyvsp[0].expr).place);
  temp.append("\n");

  (yyval.expr).code = strdup(temp.c_str());
}
#line 2085 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 665 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).place = strdup(newTemp().c_str());
  
  std::string temp;
  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  temp.append(". ");
  temp.append((yyval.expr).place);
  temp.append("\n");
  temp.append("- ");
  temp.append((yyval.expr).place);
  temp.append(", ");
  temp.append((yyvsp[-2].expr).place);
  temp.append(", ");
  temp.append((yyvsp[0].expr).place);
  temp.append("\n");

  (yyval.expr).code = strdup(temp.c_str());
}
#line 2109 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 686 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).code = strdup(empty);
  (yyval.expr).place = strdup(empty);
}
#line 2118 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 691 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp;
  temp.append((yyvsp[-2].expr).code);
  temp.append("param ");
  temp.append((yyvsp[-2].expr).place);
  temp.append("\n");
  temp.append((yyvsp[0].expr).code);

  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).place = strdup(empty);
}
#line 2134 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 703 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp;
  temp.append((yyvsp[0].expr).code);
  temp.append("param ");
  temp.append((yyvsp[0].expr).place);
  temp.append("\n");

  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).place = strdup(empty);
}
#line 2149 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 716 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).code = strdup((yyvsp[0].expr).code);
  (yyval.expr).place = strdup((yyvsp[0].expr).place);
}
#line 2158 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 721 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).place = strdup(newTemp().c_str());
  
  std::string temp;
  temp.append(". ");
  temp.append((yyval.expr).place);
  temp.append("\n");
  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  temp.append("* ");
  temp.append((yyval.expr).place);
  temp.append(", ");
  temp.append((yyvsp[-2].expr).place);
  temp.append(", ");
  temp.append((yyvsp[0].expr).place);
  temp.append("\n");

  (yyval.expr).code = strdup(temp.c_str());
}
#line 2182 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 741 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).place = strdup(newTemp().c_str());
  
  std::string temp;
  temp.append(". ");
  temp.append((yyval.expr).place);
  temp.append("\n");
  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  temp.append("/ ");
  temp.append((yyval.expr).place);
  temp.append(", ");
  temp.append((yyvsp[-2].expr).place);
  temp.append(", ");
  temp.append((yyvsp[0].expr).place);
  temp.append("\n");

  (yyval.expr).code = strdup(temp.c_str());
}
#line 2206 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 761 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).place = strdup(newTemp().c_str());
  
  std::string temp;
  temp.append(". ");
  temp.append((yyval.expr).place);
  temp.append("\n");
  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  temp.append("% ");
  temp.append((yyval.expr).place);
  temp.append(", ");
  temp.append((yyvsp[-2].expr).place);
  temp.append(", ");
  temp.append((yyvsp[0].expr).place);
  temp.append("\n");

  (yyval.expr).code = strdup(temp.c_str());
}
#line 2230 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 783 "mini_l.y" /* yacc.c:1646  */
    {
  
  if ((yyval.expr).array == true) {
    std::string temp;
    std::string intermediate = newTemp();
    temp.append((yyvsp[0].expr).code);
    temp.append(". ");
    temp.append(intermediate);
    temp.append("\n");
    temp.append("=[] ");
    temp.append(intermediate);
    temp.append(", ");
    temp.append((yyvsp[0].expr).place);
    temp.append("\n");
    (yyval.expr).code = strdup(temp.c_str());
    (yyval.expr).place = strdup(intermediate.c_str());
    (yyval.expr).array = false;
  }
  else {
    (yyval.expr).code = strdup((yyvsp[0].expr).code);
    (yyval.expr).place = strdup((yyvsp[0].expr).place);
  }
}
#line 2258 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 807 "mini_l.y" /* yacc.c:1646  */
    {
  
  (yyval.expr).place = strdup(newTemp().c_str());
  std::string temp;
  temp.append((yyvsp[0].expr).code);
  temp.append(". ");
  temp.append((yyval.expr).place);
  temp.append("\n");
  if ((yyvsp[0].expr).array) {
    temp.append("=[] ");
    temp.append((yyval.expr).place);
    temp.append(", ");
    temp.append((yyvsp[0].expr).place);
    temp.append("\n");
  }
  else {
    temp.append("= ");
    temp.append((yyval.expr).place);
    temp.append(", ");
    temp.append((yyvsp[0].expr).place);
    temp.append("\n");
  }
  temp.append("* ");
  temp.append((yyval.expr).place);
  temp.append(", ");
  temp.append((yyval.expr).place);
  temp.append(", -1\n");
  
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).array = false;
}
#line 2294 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 839 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).code = strdup(empty);
  (yyval.expr).place = strdup(std::to_string((yyvsp[0].num_val)).c_str());
}
#line 2303 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 844 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp;
  temp.append("-");
  temp.append(std::to_string((yyvsp[0].num_val)));
  (yyval.expr).code = strdup(empty);
  (yyval.expr).place = strdup(temp.c_str());
}
#line 2315 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 852 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).code = strdup((yyvsp[-1].expr).code);
  (yyval.expr).place = strdup((yyvsp[-1].expr).place);
}
#line 2324 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 857 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).place = strdup((yyvsp[-1].expr).place);
  std::string temp;
  temp.append((yyvsp[-1].expr).code);
  temp.append("* ");
  temp.append((yyvsp[-1].expr).place);
  temp.append(", ");
  temp.append((yyvsp[-1].expr).place);
  temp.append(", -1\n");
  (yyval.expr).code = strdup(temp.c_str());
}
#line 2340 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 869 "mini_l.y" /* yacc.c:1646  */
    {
   
  if (functions.find(std::string((yyvsp[-3].expr).place)) == functions.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared function %s", (yyvsp[-3].expr).place);
    yyerror(temp);
  }

  (yyval.expr).place = strdup(newTemp().c_str());

  std::string temp;
  temp.append((yyvsp[-1].expr).code);
  temp.append(". ");
  temp.append((yyval.expr).place);
  temp.append("\n");
  temp.append("call ");
  temp.append((yyvsp[-3].expr).place);
  temp.append(", ");
  temp.append((yyval.expr).place);
  temp.append("\n");
  
  (yyval.expr).code = strdup(temp.c_str());
}
#line 2368 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 894 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).place = strdup((yyvsp[0].expr).place);
  (yyval.expr).code = strdup((yyvsp[0].expr).code);
}
#line 2377 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 899 "mini_l.y" /* yacc.c:1646  */
    {
  std::string dest = newTemp();
  std::string temp;

  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  temp.append(". ");
  temp.append(dest);
  temp.append("\n");
  
  temp.append("|| ");
  temp.append(dest);
  temp.append(", ");
  temp.append((yyvsp[-2].expr).place);
  temp.append(", ");
  temp.append((yyvsp[0].expr).place);
  temp.append("\n");
  
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).place = strdup(dest.c_str());
}
#line 2403 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 922 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).place = strdup((yyvsp[0].expr).place);
  (yyval.expr).code = strdup((yyvsp[0].expr).code);
}
#line 2412 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 927 "mini_l.y" /* yacc.c:1646  */
    {
  std::string dest = newTemp();
  std::string temp;

  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  temp.append(". ");
  temp.append(dest);
  temp.append("\n");
  
  temp.append("&& ");
  temp.append(dest);
  temp.append(", ");
  temp.append((yyvsp[-2].expr).place);
  temp.append(", ");
  temp.append((yyvsp[0].expr).place);
  temp.append("\n");
  
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).place = strdup(dest.c_str());
}
#line 2438 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 950 "mini_l.y" /* yacc.c:1646  */
    {
  std::string dest = newTemp();
  std::string temp;

  temp.append((yyvsp[0].expr).code);
  temp.append(". ");
  temp.append(dest);
  temp.append("\n");
  
  temp.append("! ");
  temp.append(dest);
  temp.append(", ");
  temp.append((yyvsp[0].expr).place);
  temp.append("\n");
  
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).place = strdup(dest.c_str());
}
#line 2461 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 969 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).place = strdup((yyvsp[0].expr).place);
  (yyval.expr).code = strdup((yyvsp[0].expr).code);
}
#line 2470 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 975 "mini_l.y" /* yacc.c:1646  */
    {
  std::string dest = newTemp();
  std::string temp;  

  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  temp.append(". ");
  temp.append(dest);
  temp.append("\n");
  temp.append((yyvsp[-1].expr).place);
  temp.append(dest);
  temp.append(", ");
  temp.append((yyvsp[-2].expr).place);
  temp.append(", ");
  temp.append((yyvsp[0].expr).place);
  temp.append("\n");
  
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).place = strdup(dest.c_str());
}
#line 2495 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 996 "mini_l.y" /* yacc.c:1646  */
    {
  char temp[2] = "1";
  (yyval.expr).place = strdup(temp);
  (yyval.expr).code = strdup(empty);
}
#line 2505 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1002 "mini_l.y" /* yacc.c:1646  */
    {
  char temp[2] = "0";
  (yyval.expr).place = strdup(temp);
  (yyval.expr).code = strdup(empty);
}
#line 2515 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1008 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).place = strdup((yyvsp[-1].expr).place);
  (yyval.expr).code = strdup((yyvsp[-1].expr).code);
}
#line 2524 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1014 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp = "== ";
  (yyval.expr).place = strdup(temp.c_str());
  (yyval.expr).code = strdup(empty);
}
#line 2534 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1020 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp = "!= ";
  (yyval.expr).place = strdup(temp.c_str());
  (yyval.expr).code = strdup(empty);
}
#line 2544 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1026 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp = "< ";
  (yyval.expr).place = strdup(temp.c_str());
  (yyval.expr).code = strdup(empty);
}
#line 2554 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1032 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp = "> ";
  (yyval.expr).place = strdup(temp.c_str());
  (yyval.expr).code = strdup(empty);
}
#line 2564 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1038 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp = "<= ";
  (yyval.expr).place = strdup(temp.c_str());
  (yyval.expr).code = strdup(empty);
}
#line 2574 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1044 "mini_l.y" /* yacc.c:1646  */
    {
  std::string temp = ">= ";
  (yyval.expr).place = strdup(temp.c_str());
  (yyval.expr).code = strdup(empty);
}
#line 2584 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1051 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).place = strdup((yyvsp[0].ident_val));
  (yyval.expr).code = strdup(empty);;
}
#line 2593 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1056 "mini_l.y" /* yacc.c:1646  */
    {
  
  std::string variable((yyvsp[0].ident_val));
  if (variables.find(variable) != variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Redeclaration of variable %s", variable.c_str());
    yyerror(temp);
  }
  else {
    variables.insert(std::pair<std::string,int>(variable,0));
  }
  (yyval.expr).place = strdup((yyvsp[0].ident_val));
  (yyval.expr).code = strdup(empty);;
}
#line 2612 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1071 "mini_l.y" /* yacc.c:1646  */
    {
  if (functions.find(std::string((yyvsp[0].ident_val))) != functions.end()) {
    char temp[128];
    snprintf(temp, 128, "Redeclaration of function %s", (yyvsp[0].ident_val));
    yyerror(temp);
  }
  else {
    functions.insert(std::pair<std::string,int>((yyvsp[0].ident_val),0));
  }
  (yyval.expr).place = strdup((yyvsp[0].ident_val));
  (yyval.expr).code = strdup(empty);;
}
#line 2629 "mini_l.tab.c" /* yacc.c:1646  */
    break;


#line 2633 "mini_l.tab.c" /* yacc.c:1646  */
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
#line 1083 "mini_l.y" /* yacc.c:1906  */


void yyerror(const char* s) {
   printf("ERROR: %s at symbol \"%s\" on line %d, col %d\n", s, yytext, lineNum, lineCol);
}

std::string newTemp() {
  static int num = 0;
  std::string temp = "_t" + std::to_string(num++);
  return temp;
}

std::string newLabel() {
  static int num = 0;
  std::string temp = 'L' + std::to_string(num++);
  return temp;
}
