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
#line 1 "alfa.y" /* yacc.c:339  */

        
        #include <stdio.h>
        #include <stdlib.h>
        #include <stdbool.h>
        #include <string.h>
        #include "alfa.h"
        #include "generacion.h"
        #include "hash.h"
        #include "y.tab.h"
        
        
        void yyerror(char const *str);
        extern int line, col, error;
        extern FILE *yyin;
	extern FILE *yyout;
        extern int yylex();
        extern int yyleng;

        int tipo_actual;
        int clase_actual;

        Hash_Table *global_simbols = NULL;
        Hash_Table *local_simbols = NULL;
        bool local_scope_open = false, is_in_local, declare_in_local, token_found;
        Hash_node *found = NULL;
        int value, len = 0;

        FILE *declarations_file = NULL;
        char nombre_variable[50];

#line 98 "y.tab.c" /* yacc.c:339  */

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
    TOK_MAIN = 258,
    TOK_INT = 259,
    TOK_BOOLEAN = 260,
    TOK_ARRAY = 261,
    TOK_FUNCTION = 262,
    TOK_IF = 263,
    TOK_ELSE = 264,
    TOK_WHILE = 265,
    TOK_SCANF = 266,
    TOK_PRINTF = 267,
    TOK_RETURN = 268,
    TOK_PUNTOYCOMA = 269,
    TOK_COMA = 270,
    TOK_PARENTESISIZQUIERDO = 271,
    TOK_PARENTESISDERECHO = 272,
    TOK_CORCHETEIZQUIERDO = 273,
    TOK_CORCHETEDERECHO = 274,
    TOK_LLAVEIZQUIERDA = 275,
    TOK_LLAVEDERECHA = 276,
    TOK_ASIGNACION = 277,
    TOK_MAS = 278,
    TOK_MENOS = 279,
    TOK_DIVISION = 280,
    TOK_ASTERISCO = 281,
    TOK_AND = 282,
    TOK_OR = 283,
    TOK_NOT = 284,
    TOK_IGUAL = 285,
    TOK_DISTINTO = 286,
    TOK_MENORIGUAL = 287,
    TOK_MAYORIGUAL = 288,
    TOK_MENOR = 289,
    TOK_MAYOR = 290,
    TOK_IDENTIFICADOR = 291,
    TOK_CONSTANTE_ENTERA = 292,
    TOK_TRUE = 293,
    TOK_FALSE = 294,
    TOK_ERROR = 295
  };
#endif
/* Tokens.  */
#define TOK_MAIN 258
#define TOK_INT 259
#define TOK_BOOLEAN 260
#define TOK_ARRAY 261
#define TOK_FUNCTION 262
#define TOK_IF 263
#define TOK_ELSE 264
#define TOK_WHILE 265
#define TOK_SCANF 266
#define TOK_PRINTF 267
#define TOK_RETURN 268
#define TOK_PUNTOYCOMA 269
#define TOK_COMA 270
#define TOK_PARENTESISIZQUIERDO 271
#define TOK_PARENTESISDERECHO 272
#define TOK_CORCHETEIZQUIERDO 273
#define TOK_CORCHETEDERECHO 274
#define TOK_LLAVEIZQUIERDA 275
#define TOK_LLAVEDERECHA 276
#define TOK_ASIGNACION 277
#define TOK_MAS 278
#define TOK_MENOS 279
#define TOK_DIVISION 280
#define TOK_ASTERISCO 281
#define TOK_AND 282
#define TOK_OR 283
#define TOK_NOT 284
#define TOK_IGUAL 285
#define TOK_DISTINTO 286
#define TOK_MENORIGUAL 287
#define TOK_MAYORIGUAL 288
#define TOK_MENOR 289
#define TOK_MAYOR 290
#define TOK_IDENTIFICADOR 291
#define TOK_CONSTANTE_ENTERA 292
#define TOK_TRUE 293
#define TOK_FALSE 294
#define TOK_ERROR 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 35 "alfa.y" /* yacc.c:355  */

        tipo_atributos atributos;

#line 219 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 236 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   123,   123,   127,   144,   149,   150,   152,   155,   156,
     158,   160,   162,   163,   165,   166,   168,   169,   171,   173,
     174,   176,   177,   179,   181,   182,   184,   185,   187,   188,
     190,   191,   192,   193,   195,   196,   198,   241,   243,   245,
     246,   248,   250,   252,   254,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   271,
     272,   274,   275,   277,   278,   279,   280,   281,   282,   284,
     285,   287,   288,   290,   300
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_MAIN", "TOK_INT", "TOK_BOOLEAN",
  "TOK_ARRAY", "TOK_FUNCTION", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_SCANF", "TOK_PRINTF", "TOK_RETURN", "TOK_PUNTOYCOMA", "TOK_COMA",
  "TOK_PARENTESISIZQUIERDO", "TOK_PARENTESISDERECHO",
  "TOK_CORCHETEIZQUIERDO", "TOK_CORCHETEDERECHO", "TOK_LLAVEIZQUIERDA",
  "TOK_LLAVEDERECHA", "TOK_ASIGNACION", "TOK_MAS", "TOK_MENOS",
  "TOK_DIVISION", "TOK_ASTERISCO", "TOK_AND", "TOK_OR", "TOK_NOT",
  "TOK_IGUAL", "TOK_DISTINTO", "TOK_MENORIGUAL", "TOK_MAYORIGUAL",
  "TOK_MENOR", "TOK_MAYOR", "TOK_IDENTIFICADOR", "TOK_CONSTANTE_ENTERA",
  "TOK_TRUE", "TOK_FALSE", "TOK_ERROR", "$accept", "programa",
  "escritura1", "escritura2", "declaraciones", "declaracion", "clase",
  "clase_escalar", "clase_vector", "tipo", "identificadores", "funciones",
  "funcion", "parametros_funcion", "resto_parametros_funcion",
  "parametro_funcion", "declaraciones_funcion", "sentencias", "sentencia",
  "sentencia_simple", "bloque", "asignacion", "elemento_vector",
  "condicional", "bucle", "lectura", "escritura", "retorno_funcion", "exp",
  "lista_expresiones", "resto_lista_expresiones", "comparacion",
  "constante", "constante_logica", "constante_entera", "identificador", YY_NULLPTR
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
     295
};
# endif

#define YYPACT_NINF -40

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-40)))

#define YYTABLE_NINF -75

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,    -3,    30,   100,   -40,   -40,   -40,     6,   -40,   100,
       1,   -40,   -40,   -40,    20,    50,   -40,   -40,    44,    57,
      56,     6,   -40,    50,   -40,     1,   -40,    62,     1,    -5,
     -40,   -40,   -40,    84,    93,    94,    75,     4,     4,    14,
      98,    -5,   113,   -40,   -40,   106,   -40,   -40,   -40,   -40,
     -40,     6,     4,     4,   -40,     4,     4,     4,    -2,   -40,
     -40,   -40,   115,   -40,   -40,   -40,   114,   115,     4,     4,
     -40,   -40,   -40,     4,     1,   112,   117,    71,   109,    90,
     127,     0,   -40,     4,     4,     4,     4,     4,     4,     4,
      37,   115,   115,   -40,   125,     6,   -40,   126,   128,   -40,
       4,     4,     4,     4,     4,     4,   -40,     0,     0,   -40,
     -40,    52,    21,    59,   130,   -40,   100,   117,    -5,    -5,
     115,   115,   115,   115,   115,   115,     4,   -40,   -40,   -40,
      -5,   -40,   129,   131,    59,   132,   140,   -40,   -40,   -40,
     134,    -5,   135,   -40
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    12,    13,     0,     3,     5,
       0,     8,     9,    10,     0,    17,     6,    74,     0,    14,
       0,     0,     4,    17,     7,     0,    73,     0,     0,     0,
      16,    15,    11,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    29,    30,     0,    34,    35,    31,    32,
      33,    20,     0,     0,    42,     0,     0,     0,    53,    71,
      72,    57,    43,    54,    69,    70,     0,    44,     0,     0,
       2,    27,    28,     0,     0,     0,    22,     0,     0,     0,
       0,    49,    52,     0,     0,     0,     0,     0,     0,    60,
       0,    36,    37,    23,     0,     0,    19,     0,     0,    55,
       0,     0,     0,     0,     0,     0,    56,    45,    46,    47,
      48,    50,    51,    62,     0,    38,    25,    22,     0,     0,
      63,    64,    65,    66,    67,    68,     0,    59,    58,    24,
       0,    21,     0,     0,    62,     0,    39,    41,    61,    18,
       0,     0,     0,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -40,   -40,   -40,   -40,    -8,   -40,   -40,   -40,   -40,     8,
     133,   136,   -40,   -40,    34,    60,   -40,   -39,   -40,   -40,
     -40,   -40,   -29,   -40,   -40,   -40,   -40,   -40,   -34,   -40,
      23,   -40,   -40,   -40,   141,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    15,    29,     8,     9,    10,    11,    12,    13,
      18,    22,    23,    75,    96,    76,   130,    40,    41,    42,
      43,    44,    61,    46,    47,    48,    49,    50,    62,   114,
     127,    80,    63,    64,    65,    66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    16,    71,    34,    67,    35,    36,    37,    38,    19,
       5,     6,    45,     1,   -74,    14,    68,     3,    77,    78,
      55,    79,    81,    82,    19,    85,    86,    33,    56,    28,
       4,    39,    68,    57,    90,    91,    69,    17,    20,    92,
      58,    26,    59,    60,    83,    84,    85,    86,    87,   107,
     108,   109,   110,   111,   112,   113,   115,    21,    24,    74,
      83,    84,    85,    86,    87,    88,   120,   121,   122,   123,
     124,   125,    25,    93,   126,    83,    84,    85,    86,   132,
     133,    32,    83,    84,    85,    86,    87,    88,    97,    45,
      45,   135,   134,    26,    83,    84,    85,    86,    87,    88,
      51,    45,   142,    74,     5,     6,     7,    99,   129,    52,
      53,    54,    45,    83,    84,    85,    86,    87,    88,    70,
     100,   101,   102,   103,   104,   105,    98,    72,    73,    94,
      89,    95,    83,    84,    85,    86,    87,    88,    83,    84,
      85,    86,    87,    88,   106,   116,   118,   128,   119,   140,
     136,   131,   137,   139,   141,   117,   143,   138,    31,    30,
       0,    27
};

static const yytype_int16 yycheck[] =
{
      29,     9,    41,     8,    38,    10,    11,    12,    13,    10,
       4,     5,    41,     3,    16,     7,    18,    20,    52,    53,
      16,    55,    56,    57,    25,    25,    26,    28,    24,    21,
       0,    36,    18,    29,    68,    69,    22,    36,    18,    73,
      36,    37,    38,    39,    23,    24,    25,    26,    27,    83,
      84,    85,    86,    87,    88,    89,    19,     7,    14,    51,
      23,    24,    25,    26,    27,    28,   100,   101,   102,   103,
     104,   105,    15,    74,    15,    23,    24,    25,    26,   118,
     119,    19,    23,    24,    25,    26,    27,    28,    17,   118,
     119,   130,   126,    37,    23,    24,    25,    26,    27,    28,
      16,   130,   141,    95,     4,     5,     6,    17,   116,    16,
      16,    36,   141,    23,    24,    25,    26,    27,    28,    21,
      30,    31,    32,    33,    34,    35,    17,    14,    22,    17,
      16,    14,    23,    24,    25,    26,    27,    28,    23,    24,
      25,    26,    27,    28,    17,    20,    20,    17,    20,     9,
      21,   117,    21,    21,    20,    95,    21,   134,    25,    23,
      -1,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    42,    20,     0,     4,     5,     6,    45,    46,
      47,    48,    49,    50,    50,    43,    45,    36,    51,    76,
      18,     7,    52,    53,    14,    15,    37,    75,    50,    44,
      52,    51,    19,    76,     8,    10,    11,    12,    13,    36,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    16,    16,    16,    36,    16,    24,    29,    36,    38,
      39,    63,    69,    73,    74,    75,    76,    69,    18,    22,
      21,    58,    14,    22,    50,    54,    56,    69,    69,    69,
      72,    69,    69,    23,    24,    25,    26,    27,    28,    16,
      69,    69,    69,    76,    17,    14,    55,    17,    17,    17,
      30,    31,    32,    33,    34,    35,    17,    69,    69,    69,
      69,    69,    69,    69,    70,    19,    20,    56,    20,    20,
      69,    69,    69,    69,    69,    69,    15,    71,    17,    45,
      57,    55,    58,    58,    69,    58,    21,    21,    71,    21,
       9,    20,    58,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    44,    45,    45,    46,    47,    47,
      48,    49,    50,    50,    51,    51,    52,    52,    53,    54,
      54,    55,    55,    56,    57,    57,    58,    58,    59,    59,
      60,    60,    60,    60,    61,    61,    62,    62,    63,    64,
      64,    65,    66,    67,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    70,
      70,    71,    71,    72,    72,    72,    72,    72,    72,    73,
      73,    74,    74,    75,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     0,     0,     1,     2,     3,     1,     1,
       1,     5,     1,     1,     1,     3,     2,     0,    10,     2,
       0,     3,     0,     2,     1,     0,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     4,     7,
      11,     7,     2,     2,     2,     3,     3,     3,     3,     2,
       3,     3,     2,     1,     1,     3,     3,     1,     4,     2,
       0,     3,     0,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1
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
#line 124 "alfa.y" /* yacc.c:1646  */
    { declarations_file = fopen("declarations_file.txt", "w"); global_simbols = creat_hash_table(); if(global_simbols == NULL){ error = -1; return -1;} fprintf(yyout, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n"); }
#line 1426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 127 "alfa.y" /* yacc.c:1646  */
    {
        clase_actual = 1;
        escribir_subseccion_data(yyout);
        escribir_cabecera_bss(yyout);
        /*declarar variables*/
        while(!feof(declarations_file)){
                fscanf(declarations_file,"%s", nombre_variable);
                
                if(!(get_value_from_hstable(global_simbols, nombre_variable, strlen(nombre_variable)))){
                        declarar_variable(yyout, nombre_variable, 0, 1);
                }
        }
        escribir_segmento_codigo(yyout);
        fclose (declarations_file);
}
#line 1446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 144 "alfa.y" /* yacc.c:1646  */
    {
        
        escribir_inicio_main(yyout);
}
#line 1455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 149 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R2:\t<declaraciones> ::= <declaracion>\n");}
#line 1461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 150 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 153 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n"); }
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 155 "alfa.y" /* yacc.c:1646  */
    { clase_actual = ESCALAR; fprintf(yyout, ";R5:\t<clase> ::= <clase_escalar>\n"); }
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 156 "alfa.y" /* yacc.c:1646  */
    { clase_actual = VECTOR; fprintf(yyout, ";R7:\t<clase> ::= <clase_vector>\n"); }
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 158 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R9:\t<clase_escalar> ::= <tipo>\n"); }
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 160 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R15:\t<clase_vector> ::= array <tipo> [<constante_entera>]\n"); }
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 162 "alfa.y" /* yacc.c:1646  */
    { clase_actual = INT; fprintf(yyout, ";R10:\t<tipo> ::= int\n"); }
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 163 "alfa.y" /* yacc.c:1646  */
    { clase_actual = BOOLEAN; fprintf(yyout, ";R11:\t<tipo> ::= boolean\n"); }
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 165 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R18:\t<identificadores> ::= <identificador>\n"); }
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 166 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n"); }
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 168 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R20:\t<funciones> ::= <funcion> <funciones>\n"); }
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 169 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R21:\t<funciones> ::= \n"); }
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 171 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R22:\t<funcion>::= function <tipo> <indentificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n"); }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 173 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n"); }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 174 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R24:\t<parametros_funcion> ::= \n"); }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 176 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R25:\t; <resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n"); }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 177 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R26:\t; <resto_parametros_funcion> ::= \n"); }
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 179 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n"); }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 181 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n"); }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 182 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R29:\t; <declaraciones_funcion> ::= \n"); }
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 184 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R30:\t<sentencias> ::= <sentencia>\n");}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 185 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 187 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 188 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R33:\t<sentencia> ::= <bloque>\n");}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 190 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R34:\t<sentencia_simple> ::= <asignacion>\n");}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 191 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R35:\t<sentencia_simple> ::= <lectura>\n");}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 192 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R36:\t<sentencia_simple> ::= <escritura>\n");}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 193 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 195 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R40:\t<bloque> ::= <condicional>\n"); }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 196 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R41:\t<bloque> ::= <bucle>\n"); }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 198 "alfa.y" /* yacc.c:1646  */
    {
        
        if(local_scope_open) {
                found = get_value_from_hstable(local_simbols, (yyvsp[-2].atributos).lexema, strlen((yyvsp[-2].atributos).lexema));
                if(!found) {
                        found = get_value_from_hstable(global_simbols, (yyvsp[-2].atributos).lexema, strlen((yyvsp[-2].atributos).lexema));
                        if(!found) {
                                fprintf(stdout, "Error asignacion(43) not in local or global table\n");
                        }     
                }          
        } else {
                found = get_value_from_hstable(global_simbols, (yyvsp[-2].atributos).lexema, strlen((yyvsp[-2].atributos).lexema));
                if(!found) {
                    fprintf(stdout, "Error asignacion(43) not in global table\n");
                }
        }

        if((yyvsp[-2].atributos).tipo == VARIABLE || (yyvsp[-2].atributos).tipo == PARAMETER || (yyvsp[-2].atributos).tipo == FUNCTION){
                fprintf(stdout, "Error asignacion(43): tipo == categoria\n");
        }
        if((yyvsp[-2].atributos).tipo == VECTOR){
                fprintf(stdout, "Error asignacion(43): la clase es vector\n");
        }
        if((yyvsp[-2].atributos).tipo != (yyvsp[0].atributos).tipo){ /* Does not check table type*/
                fprintf(stdout, "Error asignacion(43): types when asigned dont match\n");
        }
        
        /* Code for poping the right part of the statement */
        fprintf(yyout, "\tpop dword eax\n");

        /* Code for accessing to the memory for the correct value, if exp is an address */
        if((yyvsp[0].atributos).es_direccion == 1){
                fprintf(yyout, "\tmov dword eax, [eax]\n");
        }

        /* Code for making the assignment */
        fprintf(yyout, "\tmov dword [$1.lexema], eax\n");
       

        fprintf(yyout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n"); 
        
        }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 241 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n"); }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 243 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n"); }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 245 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R50\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 246 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R51\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 248 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R52:\t<bucle> ::= while( <exp> ) { <sentencias> }\n"); }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 250 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R54:\t<lectura> ::= scanf <identificador>\n");}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 252 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R56:\t<escritura> ::= printf <exp>\n");}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 254 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R61:\t<retorno_funcion> ::= return <exp>\n");}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 256 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R72:\t<exp> ::= <exp> + <exp>\n"); }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 257 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R73:\t<exp> ::= <exp> - <exp>\n"); }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 258 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R74:\t<exp> ::= <exp> / <exp>\n"); }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 259 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R75:\t<exp> ::= <exp> * <exp>\n"); }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 260 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R76:\t<exp> ::= - <exp>\n"); }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 261 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R77:\t<exp> ::= <exp> && <exp>\n"); }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 262 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R78:\t<exp> ::= <exp> || <exp>\n"); }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 263 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R79:\t<exp> ::= ! <exp>\n"); }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 264 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R80:\t<exp> ::= <identificador>\n"); }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 265 "alfa.y" /* yacc.c:1646  */
    { (yyval.atributos).tipo = (yyvsp[0].atributos).tipo; (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion; fprintf(yyout, ";R81:\t<exp> ::= <constante>\n"); }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 266 "alfa.y" /* yacc.c:1646  */
    { (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo; (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion; fprintf(yyout, ";R82:\t<exp> ::= ( <exp> )\n"); }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 267 "alfa.y" /* yacc.c:1646  */
    { (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo; (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion; fprintf(yyout, ";R83:\t<exp> ::= ( <comparacion> )\n"); }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 268 "alfa.y" /* yacc.c:1646  */
    { (yyval.atributos).tipo = (yyvsp[0].atributos).tipo; (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion; fprintf(yyout, ";R85:\t<exp> ::= <elemento_vector>\n"); }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 269 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R88:\t<exp> ::= <identicador> ( <lista_expresiones> )\n"); }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 271 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n"); }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 272 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R90:\t<lista_expresiones> ::= \n"); }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 274 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R91\t, <resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 275 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R92\t<resto_lista_expresiones> ::= \n"); }
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 277 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R93:\t<comparacion> ::= <exp> == <exp>\n"); }
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 278 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R94:\t<comparacion> ::= <exp> != <exp>\n"); }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 279 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R95:\t<comparacion> ::= <exp> <= <exp>\n"); }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 280 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R96:\t<comparacion> ::= <exp> >= <exp>\n"); }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 281 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R97:\t<comparacion> ::= <exp> < <exp>\n"); }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 282 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R98:\t<comparacion> ::= <exp> > <exp>\n"); }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 284 "alfa.y" /* yacc.c:1646  */
    { (yyval.atributos).tipo = (yyvsp[0].atributos).tipo; (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion; fprintf(yyout, ";R99:\t<constante> ::= <constante_logica>\n"); }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 285 "alfa.y" /* yacc.c:1646  */
    { (yyval.atributos).tipo = (yyvsp[0].atributos).tipo; (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion; fprintf(yyout, ";R100:\t<constante> ::= <constante_entera\n"); }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 287 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R102:\t<constante_logica> ::= true\n"); }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 288 "alfa.y" /* yacc.c:1646  */
    { fprintf(yyout, ";R103:\t<constante_logica> ::= false\n"); }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 290 "alfa.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = INT;
        (yyval.atributos).es_direccion = 0;
        (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
        
        /* escribe código con tu librería para meter en la pila la constante push dword $1.valor_entero */
        fprintf(yyout, "\tpush dword %d\n", (yyvsp[0].atributos).valor_entero);
        fprintf(yyout, ";R104:\t<constante_entera> ::= <numero>\n"); 
}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 300 "alfa.y" /* yacc.c:1646  */
    {
        Hash_node node;
        int len = 0;
        
        is_in_local = false;
        declare_in_local = false;

        init_hs_node(&node);
        strcpy(node.key, (yyvsp[0].atributos).lexema);
        

        value = (yyvsp[0].atributos).valor_entero;
        if(local_scope_open){
        
                found = get_value_from_hstable(local_simbols, (yyvsp[0].atributos).lexema, strlen((yyvsp[0].atributos).lexema));
                if (!found) {
                        len = strlen(node.key);
                        if(add_node2HashTable(local_simbols, &node, len) == -1){
                                fprintf(stdout, "Error inserting the node =(\n");
                                return -1;
                        }

                        /* Output: declaration correct*/
                        fprintf(stdout, "%s\n", (yyvsp[0].atributos).lexema);
                        declare_in_local = true;
                }
                else {
                        is_in_local = true;
                }
        }
        
        len = strlen((yyvsp[0].atributos).lexema);
        found = get_value_from_hstable(global_simbols, (yyvsp[0].atributos).lexema, len);

        if ((!found) && (declare_in_local == false)){ /*Declaration Successful*/
                if (value < 0) {

                        local_simbols = creat_hash_table();
                        if(!local_simbols) {
                                fprintf(stdout, "Error creating the local table.");
                                return -1;
                        }
                        local_scope_open = true;

                        if(add_node2HashTable(global_simbols, &node, len) == -1){
                                printf("Error inserting the node =(\n");
                                return -1;
                        }

                        if(add_node2HashTable(local_simbols, &node, len) == -1){
                                fprintf(stdout, "Error inserting the node =(\n");
                                return -1;
                        }
                }

                else {
                        len = strlen((yyvsp[0].atributos).lexema);
                        if(add_node2HashTable(global_simbols, &node, len) == -1){
                                fprintf(stdout, "Error inserting the node =(\n");
                                return -1;
                        }
                }
        
        /* Output: declaration correct*/
        fprintf(stdout, "%s\n", (yyvsp[0].atributos).lexema);

        
        } else if(is_in_local == true || (is_in_local == false && declare_in_local == false && !found)) { /* token found*/
        /* Output: declaration error*/
                fprintf(stdout, "-1\t%s\n", (yyvsp[0].atributos).lexema);
        }

        fprintf(yyout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n"); 
        
}
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2002 "y.tab.c" /* yacc.c:1646  */
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
#line 376 "alfa.y" /* yacc.c:1906  */


void yyerror (char const *str)
{
	if(error == 0)
		fprintf(stdout,"**** Error sintactico en [lin %d, col %d]\n",line,col);
	error = 0;
}
