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
#line 1 "expr.y"

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
#include <variant>
#include <algorithm>
#include "IdList.h"
#include "FuncList.h"
#include "AST.h"
using namespace std;
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
class IdList ids;
class FuncList func;
class ExpressionEvaluator eval;

struct var_type{
     const char* name = "";
     const char* type = "";
     int value_i = 0;
     float value_f = 0.0;
     char value_c = '\0';
     bool value_b = 0;
     char* value_s = "";
     int linenr;
};

queue<var_type> main_q;
queue<var_type> global_q;
queue<var_type> add_var_q;
queue<var_type> update_var_q;
queue<var_type> var_domain_user_def;

queue<const char*> func_usage_args_q;
queue<pair<const char*, vector<const char*>>> func_usage_q;

// queue<pair<const char*, const char*>> var_domain;
// queue<pair<const char*, const char*>> var_domain_user_def;
queue<tuple<const char*, const char*, vector<FormalParam>>> func_domain;

vector<FormalParam> formal_param;

vector<variant<int,float, string>> expression_literals;
vector<string> expression_op;
string expression;
bool error = false;

// void error(const char* s, int linenr){
//      printf("error: %s at line:%d\n", s, linenr);
// }

#line 129 "expr.tab.c"

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

#include "expr.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BGIN = 3,                       /* BGIN  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_ASSIGN = 5,                     /* ASSIGN  */
  YYSYMBOL_ARRAY = 6,                      /* ARRAY  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_LESS = 11,                      /* LESS  */
  YYSYMBOL_GREATER = 12,                   /* GREATER  */
  YYSYMBOL_DIFFERENT = 13,                 /* DIFFERENT  */
  YYSYMBOL_EQUAL = 14,                     /* EQUAL  */
  YYSYMBOL_PLUS = 15,                      /* PLUS  */
  YYSYMBOL_MINUS = 16,                     /* MINUS  */
  YYSYMBOL_DIVIDE = 17,                    /* DIVIDE  */
  YYSYMBOL_MULTIPLY = 18,                  /* MULTIPLY  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_STRUCT = 22,                    /* STRUCT  */
  YYSYMBOL_CLASS = 23,                     /* CLASS  */
  YYSYMBOL_FN = 24,                        /* FN  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_POWER = 26,                     /* POWER  */
  YYSYMBOL_INT = 27,                       /* INT  */
  YYSYMBOL_FLOAT = 28,                     /* FLOAT  */
  YYSYMBOL_ID = 29,                        /* ID  */
  YYSYMBOL_TYPE = 30,                      /* TYPE  */
  YYSYMBOL_STRING = 31,                    /* STRING  */
  YYSYMBOL_TRUEE = 32,                     /* TRUEE  */
  YYSYMBOL_FALSEE = 33,                    /* FALSEE  */
  YYSYMBOL_CHAR = 34,                      /* CHAR  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* '{'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_aux = 48,                       /* aux  */
  YYSYMBOL_global_declarations = 49,       /* global_declarations  */
  YYSYMBOL_decl = 50,                      /* decl  */
  YYSYMBOL_values = 51,                    /* values  */
  YYSYMBOL_control_statements = 52,        /* control_statements  */
  YYSYMBOL_compare = 53,                   /* compare  */
  YYSYMBOL_math_op = 54,                   /* math_op  */
  YYSYMBOL_bool_op = 55,                   /* bool_op  */
  YYSYMBOL_bool_operand = 56,              /* bool_operand  */
  YYSYMBOL_bool_expr = 57,                 /* bool_expr  */
  YYSYMBOL_while = 58,                     /* while  */
  YYSYMBOL_if = 59,                        /* if  */
  YYSYMBOL_else = 60,                      /* else  */
  YYSYMBOL_for = 61,                       /* for  */
  YYSYMBOL_mainul = 62,                    /* mainul  */
  YYSYMBOL_user_def_data_types = 63,       /* user_def_data_types  */
  YYSYMBOL_user_def_data_types_decl = 64,  /* user_def_data_types_decl  */
  YYSYMBOL_global_functions = 65,          /* global_functions  */
  YYSYMBOL_function = 66,                  /* function  */
  YYSYMBOL_list_param = 67,                /* list_param  */
  YYSYMBOL_param = 68,                     /* param  */
  YYSYMBOL_list = 69,                      /* list  */
  YYSYMBOL_statement = 70,                 /* statement  */
  YYSYMBOL_initialization = 71,            /* initialization  */
  YYSYMBOL_math_expr = 72,                 /* math_expr  */
  YYSYMBOL_call_list = 73,                 /* call_list  */
  YYSYMBOL_values_func = 74                /* values_func  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   922

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  383

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
      40,    41,    37,    35,    44,    36,    45,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    75,    75,    76,    84,    85,    86,    89,    90,    93,
      94,   197,   225,   245,   246,   247,   248,   251,   252,   253,
     254,   257,   258,   259,   260,   263,   264,   265,   266,   267,
     270,   271,   272,   273,   276,   277,   278,   280,   281,   282,
     283,   286,   287,   288,   289,   290,   291,   292,   295,   296,
     297,   298,   299,   302,   303,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   318,   375,   410,   447,   466,
     467,   574,   575,   579,   596,   641,   683,   684,   687,   709,
     710,   711,   714,   715,   718,   734,   842,   956,   957,   958,
     960,   961,   962,   963,   974,   975,   976,   977,   978,   979,
     980,   981,   982,   983,   984,   985,   986,   987,   990,   991,
     992,  1095,  1200,  1207,  1214,  1215,  1220,  1221,  1228,  1229,
    1232,  1233,  1234,  1235,  1236,  1237,  1238,  1239
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
  "\"end of file\"", "error", "\"invalid token\"", "BGIN", "END",
  "ASSIGN", "ARRAY", "WHILE", "IF", "ELSE", "FOR", "LESS", "GREATER",
  "DIFFERENT", "EQUAL", "PLUS", "MINUS", "DIVIDE", "MULTIPLY", "AND", "OR",
  "NOT", "STRUCT", "CLASS", "FN", "RETURN", "POWER", "INT", "FLOAT", "ID",
  "TYPE", "STRING", "TRUEE", "FALSEE", "CHAR", "'+'", "'-'", "'*'", "'/'",
  "';'", "'('", "')'", "'{'", "'}'", "','", "'.'", "$accept", "program",
  "aux", "global_declarations", "decl", "values", "control_statements",
  "compare", "math_op", "bool_op", "bool_operand", "bool_expr", "while",
  "if", "else", "for", "mainul", "user_def_data_types",
  "user_def_data_types_decl", "global_functions", "function", "list_param",
  "param", "list", "statement", "initialization", "math_expr", "call_list",
  "values_func", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,   889,    16,    35,    -4,    44,    41,    12,    17,    45,
     -91,   -91,   -91,   -91,    60,    71,    78,   275,   104,   113,
     146,   114,   114,    13,   125,   -91,   -91,   -91,   187,   -91,
     -91,   164,   -91,   862,   -91,   132,   144,   156,   159,    11,
     -91,   -91,   169,   -91,    66,    87,     4,   114,   187,   -91,
     171,   173,   -91,   -91,   -91,   -91,   188,   -91,   -91,   -91,
     -91,   -91,   175,   175,   197,   215,    93,   202,   226,   175,
       5,   -91,   -91,   -91,   -91,   -91,     6,   -91,   -91,   -91,
     -91,   -91,   -91,   227,   116,   -91,   -91,   248,   248,   248,
     248,   248,   248,   277,   255,   -91,    17,    17,   -91,   -91,
     -91,   250,   256,   276,   287,   116,   -91,   -91,   323,   -91,
     -91,   -91,   -91,   -19,   -91,   326,   284,   328,   -91,   225,
      15,   -91,   889,   -91,    -3,    74,    38,   -91,   -91,   -91,
     -91,   -91,   -91,    62,   109,   206,   307,   318,   242,   265,
     248,    -6,    22,   -91,   -91,   -91,   -91,   296,   309,   175,
     314,    93,   116,   -91,   116,   319,   321,   324,   325,   116,
     -91,    53,   332,   -91,   -91,   -91,    -2,   333,   327,    18,
     -91,   334,   339,   344,   346,   347,   348,   350,   352,   353,
     354,   355,   359,   329,   351,   363,   282,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   368,   370,   377,   378,   -91,   -91,
     -91,   -91,   379,   381,   -91,     7,   175,    93,   360,   889,
     331,   122,   365,   373,   380,   385,   387,   392,   397,   399,
     400,   401,   402,   405,   338,   394,   416,   382,   409,   410,
     202,   202,   -91,   -91,   -91,   -91,   175,   411,   -91,   -91,
      25,   -91,    80,   889,   -91,   889,   889,   889,   889,   889,
     889,   889,   889,   889,   889,   889,   889,   248,   248,   248,
     425,   427,   432,   -91,   -91,   429,   -91,   -91,   -91,   162,
     189,   258,   322,   349,   376,   403,   430,   457,   484,   511,
     538,   565,    70,   139,   285,   461,   464,   465,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   433,   435,   436,   437,   438,   442,   444,   175,
     175,   175,   459,   466,   467,   468,   469,   470,   472,   452,
     462,   463,   497,   503,   505,   510,   515,   517,   518,   482,
     483,   486,   175,   175,   175,   175,   175,   175,   175,   889,
     889,   889,   485,   488,   489,   490,   494,   496,   501,   592,
     619,   646,   507,   508,   509,   513,   514,   516,   520,   -91,
     -91,   -91,   889,   889,   889,   889,   889,   889,   889,   673,
     700,   727,   754,   781,   808,   835,   -91,   -91,   -91,   -91,
     -91,   -91,   -91
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     5,     0,
       3,     4,     6,    73,     0,     0,     0,     0,     0,     0,
       0,   115,   117,   113,     0,    35,    36,   104,    39,   106,
      17,    18,    20,     0,    82,    34,     0,     0,     0,    12,
       1,     2,     0,     7,     0,     0,     0,   113,    40,    34,
       0,     0,    16,    13,    14,    15,     0,    25,    26,    27,
      28,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    32,    30,    31,    37,     0,    19,    65,    83,
     105,    72,    72,     0,     0,     9,     8,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,   107,   114,
     116,     0,     0,     0,     0,     0,   120,   121,   126,   125,
     122,   123,   124,     0,   118,     0,     0,     0,   112,     0,
       0,    84,     0,    53,     0,     0,     0,    11,    10,    21,
      22,    23,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    87,    88,    86,     0,     0,     0,
       0,     0,     0,   101,     0,     0,     0,     0,     0,     0,
      94,     0,     0,    66,    71,    67,     0,     0,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,   100,    96,
      95,   127,    93,   119,   108,   110,     0,     0,    92,    90,
      91,    85,     0,     0,    54,     0,     0,     0,    78,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   102,   103,    98,    97,     0,     0,    68,    81,
       0,    79,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,   111,     0,    69,    80,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    74,
      44,    43,    47,    46,    42,    45,    41,    50,    52,    49,
      51,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      64,    59,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    57,    63,    62,
      56,    61,    55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   540,   -91,    85,    -7,   -82,   -91,   -83,   278,   423,
     535,   -91,   -91,   477,   -91,   -91,   -91,   -91,   475,   -91,
     181,   -91,   358,   -90,   -33,    33,   -13,   357,   426
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,     9,    56,    27,   133,    69,    75,
      28,    29,    30,    31,    77,    32,    10,    11,   124,    12,
      13,   169,   170,    33,    34,   116,    35,   113,   114
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      79,    42,   127,   206,    49,   134,   135,   136,   137,   138,
     119,   120,   236,   237,    15,     1,    84,    85,    64,    65,
     159,     4,   150,   147,     5,   151,    38,   162,    57,    58,
      59,    60,   161,    93,     2,     3,     4,   187,   207,    61,
     163,    40,     5,    94,   121,    36,   238,     5,   122,    99,
     100,   104,     5,    66,   160,    67,   118,   186,    68,   210,
      14,    15,   211,    16,    37,   188,   267,   166,   167,   151,
     194,   128,   196,    39,    17,    18,    19,   202,    20,   168,
      21,    22,    23,    24,    43,    25,    26,    14,    15,   171,
      16,   172,   148,    87,    88,    89,   204,   302,     4,   303,
      44,    17,    18,    19,   162,    20,   158,    21,    22,    23,
      24,    45,    25,    26,    90,    91,    92,   165,    46,   242,
     106,   107,   108,   268,   109,   110,   111,   112,    79,    57,
      58,    59,    60,    50,    42,    42,   191,   173,   174,   195,
      61,   197,    51,    21,    22,    47,   203,    52,    53,    54,
      55,   166,   167,   269,    70,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   304,   305,    14,
      15,    80,    16,    76,   282,   283,   284,    52,    53,    54,
      55,   141,   142,    17,    18,    19,    81,    20,    83,    21,
      22,    23,    24,   239,    25,    26,    14,    15,    82,    16,
      71,    72,    21,    22,    47,   289,    73,    74,    86,    79,
      17,    18,    19,    96,    20,    97,    21,    22,    23,    24,
     105,    25,    26,   265,    21,    22,    47,    98,   101,   102,
     103,   115,   290,   175,   176,   177,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,   349,
     350,   351,    21,    22,    47,   117,   155,   156,   157,   129,
     130,   131,   132,   263,   264,    14,    15,   126,    16,   180,
     181,   182,   369,   370,   371,   372,   373,   374,   375,    17,
      18,    19,   139,    20,   140,    21,    22,    23,    24,   143,
      25,    26,   183,   184,   185,   144,   319,   320,   321,    62,
      63,   291,    21,    22,    47,   164,   164,    25,    26,   227,
     228,   229,   306,   307,   308,   145,    79,    79,    79,   342,
     343,   344,   345,   346,   347,   348,   146,   153,   149,    14,
      15,   152,    16,   154,   178,   189,    79,    79,    79,    79,
      79,    79,    79,    17,    18,    19,   179,    20,   190,    21,
      22,    23,    24,   192,    25,    26,    14,    15,   198,    16,
     199,   205,   208,   200,   201,   292,   241,   257,   224,   209,
      17,    18,    19,   243,    20,   212,    21,    22,    23,    24,
     213,    25,    26,    14,    15,   214,    16,   215,   216,   217,
     225,   218,   293,   219,   220,   221,   222,    17,    18,    19,
     223,    20,   226,    21,    22,    23,    24,   245,    25,    26,
      14,    15,   230,    16,   231,   246,   232,   233,   234,   294,
     235,   260,   247,   258,    17,    18,    19,   248,    20,   249,
      21,    22,    23,    24,   250,    25,    26,    14,    15,   251,
      16,   252,   253,   254,   255,   259,   295,   256,   261,   262,
     266,    17,    18,    19,   285,    20,   286,    21,    22,    23,
      24,   287,    25,    26,    14,    15,   309,    16,   288,   310,
     311,    95,   312,   296,   313,   314,   315,   316,    17,    18,
      19,   317,    20,   318,    21,    22,    23,    24,   322,    25,
      26,    14,    15,   329,    16,   323,   324,   325,   326,   327,
     297,   328,   332,   330,   331,    17,    18,    19,   333,    20,
     334,    21,    22,    23,    24,   335,    25,    26,    14,    15,
     336,    16,   337,   338,   339,   340,   352,   298,   341,   353,
     354,   355,    17,    18,    19,   356,    20,   357,    21,    22,
      23,    24,   358,    25,    26,    14,    15,    41,    16,   362,
     363,   364,    48,   123,   299,   365,   366,   125,   367,    17,
      18,    19,   368,    20,   240,    21,    22,    23,    24,   244,
      25,    26,    14,    15,     0,    16,     0,   193,     0,     0,
       0,   300,     0,     0,     0,     0,    17,    18,    19,     0,
      20,     0,    21,    22,    23,    24,     0,    25,    26,    14,
      15,     0,    16,     0,     0,     0,     0,     0,   301,     0,
       0,     0,     0,    17,    18,    19,     0,    20,     0,    21,
      22,    23,    24,     0,    25,    26,    14,    15,     0,    16,
       0,     0,     0,     0,     0,   359,     0,     0,     0,     0,
      17,    18,    19,     0,    20,     0,    21,    22,    23,    24,
       0,    25,    26,    14,    15,     0,    16,     0,     0,     0,
       0,     0,   360,     0,     0,     0,     0,    17,    18,    19,
       0,    20,     0,    21,    22,    23,    24,     0,    25,    26,
      14,    15,     0,    16,     0,     0,     0,     0,     0,   361,
       0,     0,     0,     0,    17,    18,    19,     0,    20,     0,
      21,    22,    23,    24,     0,    25,    26,    14,    15,     0,
      16,     0,     0,     0,     0,     0,   376,     0,     0,     0,
       0,    17,    18,    19,     0,    20,     0,    21,    22,    23,
      24,     0,    25,    26,    14,    15,     0,    16,     0,     0,
       0,     0,     0,   377,     0,     0,     0,     0,    17,    18,
      19,     0,    20,     0,    21,    22,    23,    24,     0,    25,
      26,    14,    15,     0,    16,     0,     0,     0,     0,     0,
     378,     0,     0,     0,     0,    17,    18,    19,     0,    20,
       0,    21,    22,    23,    24,     0,    25,    26,    14,    15,
       0,    16,     0,     0,     0,     0,     0,   379,     0,     0,
       0,     0,    17,    18,    19,     0,    20,     0,    21,    22,
      23,    24,     0,    25,    26,    14,    15,     0,    16,     0,
       0,     0,     0,     0,   380,     0,     0,     0,     0,    17,
      18,    19,     0,    20,     0,    21,    22,    23,    24,     0,
      25,    26,    14,    15,     0,    16,     0,     0,     0,     0,
       0,   381,     0,     0,     0,     0,    17,    18,    19,     0,
      20,     0,    21,    22,    23,    24,    78,    25,    26,    14,
      15,     0,    16,     0,     0,     0,     0,     0,   382,     0,
       0,     0,     0,    17,    18,    19,     0,    20,     0,    21,
      22,    23,    24,     0,    25,    26,    14,    15,     0,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    18,    19,     0,    20,     0,    21,    22,    23,    24,
       0,    25,    26
};

static const yytype_int16 yycheck[] =
{
      33,     8,    84,     5,    17,    88,    89,    90,    91,    92,
       5,     6,     5,     6,     8,     3,     5,     6,     5,     6,
       5,    24,    41,   105,    30,    44,    30,    30,    15,    16,
      17,    18,   122,    29,    22,    23,    24,    43,    40,    26,
      43,     0,    30,    39,    39,    29,    39,    30,    42,    62,
      63,    64,    30,    40,    39,    42,    69,   140,    45,    41,
       7,     8,    44,    10,    29,    43,    41,    29,    30,    44,
     152,    84,   154,    29,    21,    22,    23,   159,    25,    41,
      27,    28,    29,    30,    39,    32,    33,     7,     8,    27,
      10,    29,   105,    27,    28,    29,    43,    27,    24,    29,
      40,    21,    22,    23,    30,    25,   119,    27,    28,    29,
      30,    40,    32,    33,    27,    28,    29,    43,    40,   209,
      27,    28,    29,    43,    31,    32,    33,    34,   161,    15,
      16,    17,    18,    29,   141,   142,   149,    28,    29,   152,
      26,   154,    29,    27,    28,    29,   159,    31,    32,    33,
      34,    29,    30,   243,    29,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    28,    29,     7,
       8,    39,    10,     9,   257,   258,   259,    31,    32,    33,
      34,    96,    97,    21,    22,    23,    42,    25,    29,    27,
      28,    29,    30,   206,    32,    33,     7,     8,    42,    10,
      13,    14,    27,    28,    29,    43,    19,    20,    39,   242,
      21,    22,    23,    42,    25,    42,    27,    28,    29,    30,
       5,    32,    33,   236,    27,    28,    29,    39,    31,    32,
      33,    29,    43,    27,    28,    29,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   339,
     340,   341,    27,    28,    29,    29,    31,    32,    33,    11,
      12,    13,    14,   230,   231,     7,     8,    40,    10,    27,
      28,    29,   362,   363,   364,   365,   366,   367,   368,    21,
      22,    23,     5,    25,    29,    27,    28,    29,    30,    39,
      32,    33,    27,    28,    29,    39,   309,   310,   311,    21,
      22,    43,    27,    28,    29,   124,   125,    32,    33,    27,
      28,    29,    27,    28,    29,    39,   349,   350,   351,   332,
     333,   334,   335,   336,   337,   338,    39,    43,     5,     7,
       8,     5,    10,     5,    27,    39,   369,   370,   371,   372,
     373,   374,   375,    21,    22,    23,    28,    25,    39,    27,
      28,    29,    30,    39,    32,    33,     7,     8,    39,    10,
      39,    29,    29,    39,    39,    43,     6,    29,    39,    42,
      21,    22,    23,    42,    25,    41,    27,    28,    29,    30,
      41,    32,    33,     7,     8,    41,    10,    41,    41,    41,
      39,    41,    43,    41,    41,    41,    41,    21,    22,    23,
      41,    25,    39,    27,    28,    29,    30,    42,    32,    33,
       7,     8,    44,    10,    44,    42,    39,    39,    39,    43,
      39,    39,    42,    29,    21,    22,    23,    42,    25,    42,
      27,    28,    29,    30,    42,    32,    33,     7,     8,    42,
      10,    42,    42,    42,    42,    29,    43,    42,    39,    39,
      39,    21,    22,    23,    29,    25,    29,    27,    28,    29,
      30,    29,    32,    33,     7,     8,     5,    10,    39,     5,
       5,    48,    39,    43,    39,    39,    39,    39,    21,    22,
      23,    39,    25,    39,    27,    28,    29,    30,    29,    32,
      33,     7,     8,    41,    10,    29,    29,    29,    29,    29,
      43,    29,     5,    41,    41,    21,    22,    23,     5,    25,
       5,    27,    28,    29,    30,     5,    32,    33,     7,     8,
       5,    10,     5,     5,    42,    42,    41,    43,    42,    41,
      41,    41,    21,    22,    23,    41,    25,    41,    27,    28,
      29,    30,    41,    32,    33,     7,     8,     7,    10,    42,
      42,    42,    17,    76,    43,    42,    42,    82,    42,    21,
      22,    23,    42,    25,   207,    27,    28,    29,    30,   211,
      32,    33,     7,     8,    -1,    10,    -1,   151,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    21,    22,    23,    -1,
      25,    -1,    27,    28,    29,    30,    -1,    32,    33,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    21,    22,    23,    -1,    25,    -1,    27,
      28,    29,    30,    -1,    32,    33,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      21,    22,    23,    -1,    25,    -1,    27,    28,    29,    30,
      -1,    32,    33,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    21,    22,    23,
      -1,    25,    -1,    27,    28,    29,    30,    -1,    32,    33,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    21,    22,    23,    -1,    25,    -1,
      27,    28,    29,    30,    -1,    32,    33,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    21,    22,    23,    -1,    25,    -1,    27,    28,    29,
      30,    -1,    32,    33,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    21,    22,
      23,    -1,    25,    -1,    27,    28,    29,    30,    -1,    32,
      33,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    21,    22,    23,    -1,    25,
      -1,    27,    28,    29,    30,    -1,    32,    33,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    21,    22,    23,    -1,    25,    -1,    27,    28,
      29,    30,    -1,    32,    33,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    21,
      22,    23,    -1,    25,    -1,    27,    28,    29,    30,    -1,
      32,    33,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    21,    22,    23,    -1,
      25,    -1,    27,    28,    29,    30,     4,    32,    33,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    21,    22,    23,    -1,    25,    -1,    27,
      28,    29,    30,    -1,    32,    33,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    -1,    25,    -1,    27,    28,    29,    30,
      -1,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    22,    23,    24,    30,    47,    48,    49,    50,
      62,    63,    65,    66,     7,     8,    10,    21,    22,    23,
      25,    27,    28,    29,    30,    32,    33,    52,    56,    57,
      58,    59,    61,    69,    70,    72,    29,    29,    30,    29,
       0,    47,    50,    39,    40,    40,    40,    29,    56,    72,
      29,    29,    31,    32,    33,    34,    51,    15,    16,    17,
      18,    26,    54,    54,     5,     6,    40,    42,    45,    54,
      29,    13,    14,    19,    20,    55,     9,    60,     4,    70,
      39,    42,    42,    29,     5,     6,    39,    27,    28,    29,
      27,    28,    29,    29,    39,    55,    42,    42,    39,    72,
      72,    31,    32,    33,    72,     5,    27,    28,    29,    31,
      32,    33,    34,    73,    74,    29,    71,    29,    72,     5,
       6,    39,    42,    59,    64,    64,    40,    51,    72,    11,
      12,    13,    14,    53,    53,    53,    53,    53,    53,     5,
      29,    49,    49,    39,    39,    39,    39,    51,    72,     5,
      41,    44,     5,    43,     5,    31,    32,    33,    72,     5,
      39,    69,    30,    43,    66,    43,    29,    30,    41,    67,
      68,    27,    29,    28,    29,    27,    28,    29,    27,    28,
      27,    28,    29,    27,    28,    29,    53,    43,    43,    39,
      39,    72,    39,    74,    51,    72,    51,    72,    39,    39,
      39,    39,    51,    72,    43,    29,     5,    40,    29,    42,
      41,    44,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    39,    39,    39,    27,    28,    29,
      44,    44,    39,    39,    39,    39,     5,     6,    39,    72,
      73,     6,    69,    42,    68,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    29,    29,    29,
      39,    39,    39,    71,    71,    72,    39,    41,    43,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    53,    53,    53,    29,    29,    29,    39,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    27,    29,    28,    29,    27,    28,    29,     5,
       5,     5,    39,    39,    39,    39,    39,    39,    39,    72,
      72,    72,    29,    29,    29,    29,    29,    29,    29,    41,
      41,    41,     5,     5,     5,     5,     5,     5,     5,    42,
      42,    42,    72,    72,    72,    72,    72,    72,    72,    69,
      69,    69,    41,    41,    41,    41,    41,    41,    41,    43,
      43,    43,    42,    42,    42,    42,    42,    42,    42,    69,
      69,    69,    69,    69,    69,    69,    43,    43,    43,    43,
      43,    43,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    49,    49,    50,
      50,    50,    50,    51,    51,    51,    51,    52,    52,    52,
      52,    53,    53,    53,    53,    54,    54,    54,    54,    54,
      55,    55,    55,    55,    56,    56,    56,    57,    57,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      59,    59,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    62,    63,    63,    64,    64,
      64,    64,    64,    65,    66,    66,    67,    67,    68,    68,
      68,    68,    69,    69,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    71,    71,
      71,    71,    72,    72,    72,    72,    72,    72,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     2,     3,     3,
       4,     4,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       2,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     2,     4,    17,    17,    17,    17,    14,
      14,    17,    17,    17,    14,     3,     5,     5,     4,     5,
       6,     2,     0,     1,     9,     8,     1,     3,     2,     3,
       4,     3,     1,     2,     3,     5,     4,     4,     4,     4,
       5,     5,     5,     5,     4,     5,     5,     6,     6,     5,
       5,     4,     6,     6,     1,     2,     1,     3,     3,     5,
       3,     5,     3,     1,     3,     1,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3
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
  case 3: /* program: mainul  */
#line 76 "expr.y"
                 {
          if(!error)
               printf("This code is correct!\n");
          else 
               cout<<"\033[1;31mThis code has errors!\033[0m"<<endl;
          }
#line 1532 "expr.tab.c"
    break;

  case 10: /* decl: TYPE ID ASSIGN math_expr  */
#line 94 "expr.y"
                                {
               bool isInt;
               reverse(expression_literals.begin(), expression_literals.end());
               if(!expression_literals.empty()){
                    if (holds_alternative<int>(expression_literals[0])) {
                         isInt = true;
               }
               else if (holds_alternative<float>(expression_literals[0])) {
                    isInt = false;
               }else {
                    string var_name = get<string>(expression_literals[0]);
                    IdInfo var = ids.getVar(var_name.c_str());
                    if(var.type == "integer") 
                         isInt = true;
                    else if(var.type == "floatVal") 
                         isInt = false;
                    else {
                         error = true;
                         yyerror("The variable given in the expression is not an integer, not an floatVal!");
                    }
               }
                    for(int i = 0; i < expression_literals.size(); i++){
                         if(isInt == true){
                              if(holds_alternative<float>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         } else{
                              if(holds_alternative<int>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         }
                    }
                    if(error == false)
                    {
                    for(int i =0 ;i < expression_op.size(); i++){
                         if (holds_alternative<int>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }
                         else if (holds_alternative<float>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }else {
                              string var_name = get<string>(expression_literals[i]);
                              IdInfo var = ids.getVar(var_name.c_str());
                              expression += var.value;
                         }
                         expression += " ";
                         expression += expression_op[i];
                         expression += " ";
                    }
                    if(holds_alternative<int>(expression_literals[expression_literals.size() -1]))
                              expression += to_string(get<int>(expression_literals[expression_literals.size() -1]));
                    else if(holds_alternative<float>(expression_literals[expression_literals.size() -1])) 
                              expression += to_string(get<float>(expression_literals[expression_literals.size() -1]));
                    else {
                         string var_name = get<string>(expression_literals[expression_literals.size() -1]);
                         IdInfo var = ids.getVar(var_name.c_str());
                         expression += var.value;
                    }
                    }
                    if(error == false){
                         if(isInt){
                              int result = eval.evaluate(expression);
                              if(strcmp((yyvsp[-3].string), "integer") == 0)
                                   ids.addVar((yyvsp[-3].string), (yyvsp[-2].string), "global", result);
                              else 
                                   yyerror("Cannot assign integer to a anything other then integer");
                         }else{
                              float result = eval.evaluate(expression);
                              if(strcmp((yyvsp[-3].string), "floatVal") == 0)
                                   ids.addVar((yyvsp[-3].string), (yyvsp[-2].string), "global", result);
                              else 
                                   yyerror("Cannot assign floatVal to a anything other then floatVal");
                         }
                    }     
               }else {yyerror("there is no expression!");}
               expression_literals.clear();
               expression_op.clear();
               expression.clear();
         }
#line 1640 "expr.tab.c"
    break;

  case 11: /* decl: TYPE ID ASSIGN values  */
#line 197 "expr.y"
                             {
          while(!global_q.empty()){
               var_type aux = global_q.front();
               global_q.pop();

               if(!ids.existsVar(aux.name, "global")){
               if(aux.value_i != 0){
                    ids.addVar((yyvsp[-3].string), aux.name, "global", aux.value_i);
               }
               else if(aux.value_f != 0.0){
                    ids.addVar((yyvsp[-3].string), aux.name, "global", aux.value_f);
               }
               else if(aux.value_b != 0){
                    ids.addVar((yyvsp[-3].string), aux.name, "global", aux.value_b);
               }
               else if(aux.value_c != '\0'){
                    ids.addVar((yyvsp[-3].string), aux.name, "global", aux.value_c);
               }
               else if(aux.value_s != ""){
                    ids.addVar((yyvsp[-3].string), aux.name, "global", aux.value_s);
               } 
          }
          else{
               yyerror("Variable already declared!");
          }
     }

}
#line 1673 "expr.tab.c"
    break;

  case 12: /* decl: TYPE ID  */
#line 225 "expr.y"
               {if(!ids.existsVar((yyvsp[0].string), "global")){
          if(strcmp((yyvsp[-1].string), "integer") == 0){
               ids.addVar((yyvsp[-1].string), (yyvsp[0].string), "global", 0);
          } else if(strcmp((yyvsp[-1].string), "floatVal") == 0){
               ids.addVar((yyvsp[-1].string), (yyvsp[0].string), "global", 0.0f);
          }else if(strcmp((yyvsp[-1].string), "really") == 0){
               ids.addVar((yyvsp[-1].string), (yyvsp[0].string), "global", false);
          }else if(strcmp((yyvsp[-1].string), "character") == 0){
               ids.addVar((yyvsp[-1].string), (yyvsp[0].string), "global", '\0');
          }else if(strcmp((yyvsp[-1].string), "string") == 0){
               ids.addVar((yyvsp[-1].string), (yyvsp[0].string), "global", "");
          } 
     }
     else {
          yyerror("Variable already exists!");
          yynerrs++;
     } }
#line 1695 "expr.tab.c"
    break;

  case 13: /* values: TRUEE  */
#line 245 "expr.y"
               {var_type x; x.value_b = (yyvsp[0].string); global_q.push(x);}
#line 1701 "expr.tab.c"
    break;

  case 14: /* values: FALSEE  */
#line 246 "expr.y"
                {var_type x; x.value_b = (yyvsp[0].string); global_q.push(x);}
#line 1707 "expr.tab.c"
    break;

  case 16: /* values: STRING  */
#line 248 "expr.y"
                {var_type x; x.value_s = (yyvsp[0].string); global_q.push(x);}
#line 1713 "expr.tab.c"
    break;

  case 25: /* math_op: PLUS  */
#line 263 "expr.y"
               {expression_op.push_back("+");}
#line 1719 "expr.tab.c"
    break;

  case 26: /* math_op: MINUS  */
#line 264 "expr.y"
                {expression_op.push_back("-");}
#line 1725 "expr.tab.c"
    break;

  case 27: /* math_op: DIVIDE  */
#line 265 "expr.y"
                 {expression_op.push_back("/");}
#line 1731 "expr.tab.c"
    break;

  case 28: /* math_op: MULTIPLY  */
#line 266 "expr.y"
                   {expression_op.push_back("*");}
#line 1737 "expr.tab.c"
    break;

  case 29: /* math_op: POWER  */
#line 267 "expr.y"
                {expression_op.push_back("^");}
#line 1743 "expr.tab.c"
    break;

  case 65: /* mainul: BGIN list END  */
#line 318 "expr.y"
                       { 
     while(!add_var_q.empty()){
          var_type x = add_var_q.front();
          add_var_q.pop();

          if(!ids.existsVar(x.name, "main")){
               if(x.value_i != NULL)
                    ids.addVar(x.type, x.name, "main", x.value_i);
               else if (x.value_f != 0.0)
                         ids.addVar(x.type, x.name, "main", x.value_f);
               else if (x.value_b != 0)
                         ids.addVar(x.type, x.name, "main", x.value_b);
               else if (x.value_c != '\0')
                         ids.addVar(x.type, x.name, "main", x.value_c);
               else if (x.value_s != "")
                         ids.addVar(x.type, x.name, "main", x.value_s);
          }
          else
               yyerror("Variable already declared!\n");
     }

     while(!update_var_q.empty()){
          var_type x = update_var_q.front();
          update_var_q.pop();

          if(ids.existsVar(x.name, "main")){
               if(x.value_i != 0)
                    ids.updateVar(x.name, "main", x.value_i);
               else if (x.value_f != 0.0)
                         ids.updateVar(x.name, "main", x.value_f);
               else if (x.value_b != 0)
                         ids.updateVar(x.name, "main", x.value_b);
               else if (x.value_c != '\0')
                         ids.updateVar(x.name, "main", x.value_c);
               else if (x.value_s != "")
                         ids.updateVar(x.name, "main", x.value_s);
          }
          else
               yyerror("Variable not declared!\n");
     }

     while(!func_usage_q.empty()){
          const char* name = func_usage_q.front().first;
          vector<const char*> types = func_usage_q.front().second;
          func_usage_q.pop();

          if(func.existsFunc(name, "global")){
               if(func.check_param_types(name, "global", types) == 0)
                    yyerror("Wrong parameters type!\n");
          }
          else
               yyerror("Function never declared!\n");
     }

     }
#line 1803 "expr.tab.c"
    break;

  case 66: /* user_def_data_types: STRUCT ID '{' user_def_data_types_decl '}'  */
#line 375 "expr.y"
                                                                 { 
     while(!var_domain_user_def.empty()) {
     var_type x = var_domain_user_def.front();
     var_domain_user_def.pop();

    if(!ids.existsVar(x.name, (yyvsp[-3].string))){
          if(x.value_i != NULL)
                    ids.addVar(x.type, x.name, (yyvsp[-3].string), x.value_i);
               else if (x.value_f != 0.0)
                         ids.addVar(x.type, x.name, (yyvsp[-3].string), x.value_f);
               else if (x.value_b != 0)
                         ids.addVar(x.type, x.name, (yyvsp[-3].string), x.value_b);
               else if (x.value_c != '\0')
                         ids.addVar(x.type, x.name, (yyvsp[-3].string), x.value_c);
               else if (x.value_s != "")
                         ids.addVar(x.type, x.name, (yyvsp[-3].string), x.value_s);
          }
          else
               yyerror("Variable already declared!\n");
} 

     while(!func_domain.empty()){
          auto aux = func_domain.front();
          func_domain.pop();

          const char* name = get<0>(aux);
          const char* return_type = get<1>(aux);
          vector<FormalParam> vars = get<2>(aux);

          func.addFunc(name, return_type, vars, (yyvsp[-3].string));

          
     }

}
#line 1843 "expr.tab.c"
    break;

  case 67: /* user_def_data_types: CLASS ID '{' user_def_data_types_decl '}'  */
#line 410 "expr.y"
                                                                { 
     while(!var_domain_user_def.empty()) {
     var_type x = var_domain_user_def.front();
     var_domain_user_def.pop();

    if(!ids.existsVar(x.name, (yyvsp[-3].string))){
          if(x.value_i != NULL)
                    ids.addVar(x.type, x.name, (yyvsp[-3].string), x.value_i);
               else if (x.value_f != 0.0)
                         ids.addVar(x.type, x.name, (yyvsp[-3].string), x.value_f);
               else if (x.value_b != 0)
                         ids.addVar(x.type, x.name, (yyvsp[-3].string), x.value_b);
               else if (x.value_c != '\0')
                         ids.addVar(x.type, x.name, (yyvsp[-3].string), x.value_c);
               else if (x.value_s != "")
                         ids.addVar(x.type, x.name, (yyvsp[-3].string), x.value_s);
          }
          else
               yyerror("Variable already declared!\n");
     } 

     while(!func_domain.empty()){
          auto aux = func_domain.front();
          func_domain.pop();

          const char* name = get<0>(aux);
          const char* return_type = get<1>(aux);
          vector<FormalParam> vars = get<2>(aux);

          func.addFunc(name, return_type, vars, (yyvsp[-3].string));

          
     }

}
#line 1883 "expr.tab.c"
    break;

  case 68: /* user_def_data_types_decl: user_def_data_types_decl TYPE ID ';'  */
#line 447 "expr.y"
                                                                { 
     var_type x;
     if(strcmp((yyvsp[-2].string), "integer") == 0){
          x.value_i = -1;
     } else if(strcmp((yyvsp[-2].string), "floatVal") == 0){
          x.value_f = -1;
     }else if(strcmp((yyvsp[-2].string), "really") == 0){
          x.value_b = false;
     }else if(strcmp((yyvsp[-2].string), "character") == 0){
          x.value_c = -1;
     }else if(strcmp((yyvsp[-2].string), "string") == 0){
          x.value_s = "-1";
     } 
     x.name = (yyvsp[-1].string);
     x.type = (yyvsp[-2].string);
     x.linenr = yylineno;
     var_domain_user_def.push(x);

 }
#line 1907 "expr.tab.c"
    break;

  case 70: /* user_def_data_types_decl: user_def_data_types_decl TYPE ID ASSIGN math_expr ';'  */
#line 467 "expr.y"
                                                                                 {
               bool isInt;
               reverse(expression_literals.begin(), expression_literals.end());
               if(!expression_literals.empty()){
                    if (holds_alternative<int>(expression_literals[0])) {
                         isInt = true;
               }
               else if (holds_alternative<float>(expression_literals[0])) {
                    isInt = false;
               }else {
                    string var_name = get<string>(expression_literals[0]);
                    IdInfo var = ids.getVar(var_name.c_str());
                    if(var.type == "integer") 
                         isInt = true;
                    else if(var.type == "floatVal") 
                         isInt = false;
                    else {
                         error = true;
                         yyerror("The variable given in the expression is not an integer, not an floatVal!");
                    }
               }
                    for(int i = 0; i < expression_literals.size(); i++){
                         if(isInt == true){
                              if(holds_alternative<float>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         } else{
                              if(holds_alternative<int>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         }
                    }
                    if(error == false)
                    {
                    for(int i =0 ;i < expression_op.size(); i++){
                         if (holds_alternative<int>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }
                         else if (holds_alternative<float>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }else {
                              string var_name = get<string>(expression_literals[i]);
                              IdInfo var = ids.getVar(var_name.c_str());
                              expression += var.value;
                         }
                         expression += " ";
                         expression += expression_op[i];
                         expression += " ";
                    }
                    if(holds_alternative<int>(expression_literals[expression_literals.size() -1]))
                              expression += to_string(get<int>(expression_literals[expression_literals.size() -1]));
                    else if(holds_alternative<float>(expression_literals[expression_literals.size() -1])) 
                              expression += to_string(get<float>(expression_literals[expression_literals.size() -1]));
                    else {
                         string var_name = get<string>(expression_literals[expression_literals.size() -1]);
                         IdInfo var = ids.getVar(var_name.c_str());
                         expression += var.value;
                    }
                    }
                    if(error == false){
                         if(isInt){
                              int result = eval.evaluate(expression);
                              var_type x;
                              x.name = (yyvsp[-3].string);
                              x.type = (yyvsp[-4].string);
                              x.value_i = result;
                              x.linenr = yylineno;
                              var_domain_user_def.push(x);
                         }else{
                              float result = eval.evaluate(expression);
                              var_type x;
                              x.name = (yyvsp[-3].string);
                              x.type = (yyvsp[-4].string);
                              x.value_f = result;
                              x.linenr = yylineno;
                              var_domain_user_def.push(x);
                         }
                    }     
               }else {yyerror("there is no expression!");}
               expression_literals.clear();
               expression_op.clear();
               expression.clear();
         }
#line 2019 "expr.tab.c"
    break;

  case 73: /* global_functions: function  */
#line 579 "expr.y"
                            {

     while(!func_domain.empty()){
          auto aux = func_domain.front();
          func_domain.pop();

          const char* name = get<0>(aux);
          const char* return_type = get<1>(aux);
          vector<FormalParam> vars = get<2>(aux);

          func.addFunc(name, return_type, vars, "global");

          
     }
}
#line 2039 "expr.tab.c"
    break;

  case 74: /* function: FN TYPE ID '(' list_param ')' '{' list '}'  */
#line 596 "expr.y"
                                                      { 
     while(!add_var_q.empty()){
          var_type x = add_var_q.front();
          add_var_q.pop();

          if(!ids.existsVar(x.name, (yyvsp[-6].string))){
               if(x.value_i != 0)
                    ids.addVar(x.type, x.name, (yyvsp[-6].string), x.value_i);
               else if (x.value_f != 0.0)
                         ids.addVar(x.type, x.name, (yyvsp[-6].string), x.value_f);
               else if (x.value_b != 0)
                         ids.addVar(x.type, x.name, (yyvsp[-6].string), x.value_b);
               else if (x.value_c != '\0')
                         ids.addVar(x.type, x.name, (yyvsp[-6].string), x.value_c);
               else if (x.value_s != "")
                         ids.addVar(x.type, x.name, (yyvsp[-6].string), x.value_s);
          }
          else
               yyerror("Variable already declared!\n");
     }

     while(!update_var_q.empty()){
          var_type x = update_var_q.front();
          update_var_q.pop();

          if(ids.existsVar(x.name, (yyvsp[-6].string))){
               if(x.value_i != 0)
                    ids.updateVar(x.name, (yyvsp[-6].string), x.value_i);
               else if (x.value_f != 0.0)
                         ids.updateVar(x.name, (yyvsp[-6].string), x.value_f);
               else if (x.value_b != 0)
                         ids.updateVar(x.name, (yyvsp[-6].string), x.value_b);
               else if (x.value_c != '\0')
                         ids.updateVar(x.name, (yyvsp[-6].string), x.value_c);
               else if (x.value_s != "")
                         ids.updateVar(x.name, (yyvsp[-6].string), x.value_s);
          }
          else
               yyerror("Variable not declared!\n");
     }

     func_domain.push(make_tuple((yyvsp[-6].string), (yyvsp[-7].string), formal_param));
     formal_param.clear();
}
#line 2088 "expr.tab.c"
    break;

  case 75: /* function: FN TYPE ID '(' ')' '{' list '}'  */
#line 641 "expr.y"
                                                   {
                    while(!add_var_q.empty()){
          var_type x = add_var_q.front();
          add_var_q.pop();

          if(!ids.existsVar(x.name, (yyvsp[-5].string))){
               if(x.value_i != 0)
                    ids.addVar(x.type, x.name, (yyvsp[-5].string), x.value_i);
               else if (x.value_f != 0.0)
                         ids.addVar(x.type, x.name, (yyvsp[-5].string), x.value_f);
               else if (x.value_b != 0)
                         ids.addVar(x.type, x.name, (yyvsp[-5].string), x.value_b);
               else if (x.value_c != '\0')
                         ids.addVar(x.type, x.name, (yyvsp[-5].string), x.value_c);
               else if (x.value_s != "")
                         ids.addVar(x.type, x.name, (yyvsp[-5].string), x.value_s);
          }
          else
               yyerror("Variable already declared!\n");
     }

     while(!update_var_q.empty()){
          var_type x = update_var_q.front();
          update_var_q.pop();

          if(ids.existsVar(x.name, (yyvsp[-5].string))){
               if(x.value_i != 0)
                    ids.updateVar(x.name, (yyvsp[-5].string), x.value_i);
               else if (x.value_f != 0.0)
                         ids.updateVar(x.name, (yyvsp[-5].string), x.value_f);
               else if (x.value_b != 0)
                         ids.updateVar(x.name, (yyvsp[-5].string), x.value_b);
               else if (x.value_c != '\0')
                         ids.updateVar(x.name, (yyvsp[-5].string), x.value_c);
               else if (x.value_s != "")
                         ids.updateVar(x.name, (yyvsp[-5].string), x.value_s);
          }
          else
               yyerror("Variable not declared!\n");
     }                 }
#line 2133 "expr.tab.c"
    break;

  case 78: /* param: TYPE ID  */
#line 687 "expr.y"
                { var_type x;
               if(strcmp((yyvsp[-1].string), "integer") == 0){
                    x.value_i = -1;
               } else if(strcmp((yyvsp[-1].string), "floatVal") == 0){
                    x.value_f = -1;
               }else if(strcmp((yyvsp[-1].string), "really") == 0){
                    x.value_b = false;
               }else if(strcmp((yyvsp[-1].string), "character") == 0){
                    x.value_c = -1;
               }else if(strcmp((yyvsp[-1].string), "string") == 0){
                    x.value_s = "-1";
               } 
               x.name = (yyvsp[0].string);
               x.type = (yyvsp[-1].string);
               x.linenr = yylineno;
               add_var_q.push(x);

     FormalParam y;
     y.name = (yyvsp[0].string);
     y.type = (yyvsp[-1].string);
     formal_param.push_back(y);
}
#line 2160 "expr.tab.c"
    break;

  case 84: /* statement: TYPE ID ';'  */
#line 718 "expr.y"
                       { var_type x;
               if(strcmp((yyvsp[-2].string), "integer") == 0){
                    x.value_i = -1;
               } else if(strcmp((yyvsp[-2].string), "floatVal") == 0){
                    x.value_f = -1;
               }else if(strcmp((yyvsp[-2].string), "really") == 0){
                    x.value_b = false;
               }else if(strcmp((yyvsp[-2].string), "character") == 0){
                    x.value_c = -1;
               }else if(strcmp((yyvsp[-2].string), "string") == 0){
                    x.value_s = "-1";
               } 
               x.linenr = yylineno;
               x.name = (yyvsp[-1].string);
               x.type = (yyvsp[-2].string);
               add_var_q.push(x); }
#line 2181 "expr.tab.c"
    break;

  case 85: /* statement: TYPE ID ASSIGN math_expr ';'  */
#line 734 "expr.y"
                                        {
               bool isInt;
               reverse(expression_literals.begin(), expression_literals.end());
               if(!expression_literals.empty()){
                    if (holds_alternative<int>(expression_literals[0])) {
                         isInt = true;
               }
               else if (holds_alternative<float>(expression_literals[0])) {
                    isInt = false;
               }else {
                    string var_name = get<string>(expression_literals[0]);
                    IdInfo var = ids.getVar(var_name.c_str());
                    if(var.type == "integer") 
                         isInt = true;
                    else if(var.type == "floatVal") 
                         isInt = false;
                    else {
                         error = true;
                         yyerror("The variable given in the expression is not an integer, not an floatVal!");
                    }
               }
                    for(int i = 0; i < expression_literals.size(); i++){
                         if(isInt == true){
                              if(holds_alternative<float>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         } else{
                              if(holds_alternative<int>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         }
                    }
                    if(error == false)
                    {
                    for(int i =0 ;i < expression_op.size(); i++){
                         if (holds_alternative<int>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }
                         else if (holds_alternative<float>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }else {
                              string var_name = get<string>(expression_literals[i]);
                              IdInfo var = ids.getVar(var_name.c_str());
                              expression += var.value;
                         }
                         expression += " ";
                         expression += expression_op[i];
                         expression += " ";
                    }
                    if(holds_alternative<int>(expression_literals[expression_literals.size() -1]))
                              expression += to_string(get<int>(expression_literals[expression_literals.size() -1]));
                    else if(holds_alternative<float>(expression_literals[expression_literals.size() -1])) 
                              expression += to_string(get<float>(expression_literals[expression_literals.size() -1]));
                    else {
                         string var_name = get<string>(expression_literals[expression_literals.size() -1]);
                         IdInfo var = ids.getVar(var_name.c_str());
                         expression += var.value;
                    }
                    }
                    if(error == false){
                         if(isInt){
                              int result = eval.evaluate(expression);
                              var_type x;
                              x.name = (yyvsp[-3].string);
                              x.type = (yyvsp[-4].string);
                              x.value_i = result;
                              x.linenr = yylineno;
                              add_var_q.push(x);

                         }else{
                              float result = eval.evaluate(expression);
                              var_type x;
                              x.name = (yyvsp[-3].string);
                              x.type = (yyvsp[-4].string);
                              x.value_f = result;
                              x.linenr = yylineno;
                              add_var_q.push(x);
                         }
                    }     
               }else {yyerror("there is no expression!");}
               expression_literals.clear();
               expression_op.clear();
               expression.clear();
         }
#line 2294 "expr.tab.c"
    break;

  case 86: /* statement: ID ASSIGN math_expr ';'  */
#line 842 "expr.y"
                                         {
               bool isInt;
               reverse(expression_literals.begin(), expression_literals.end());
               if(!expression_literals.empty()){
                    if (holds_alternative<int>(expression_literals[0])) {
                         isInt = true;
               }
               else if (holds_alternative<float>(expression_literals[0])) {
                    isInt = false;
               }else {
                    string var_name = get<string>(expression_literals[0]);
                    IdInfo var = ids.getVar(var_name.c_str());
                    if(var.type == "integer") 
                         isInt = true;
                    else if(var.type == "floatVal") 
                         isInt = false;
                    else {
                         error = true;
                         yyerror("The variable given in the expression is not an integer, not an floatVal!");
                    }
               }
                    for(int i = 0; i < expression_literals.size(); i++){
                         if(isInt == true){
                              if(holds_alternative<float>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         } else{
                              if(holds_alternative<int>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         }
                    }
                    if(error == false)
                    {
                    for(int i =0 ;i < expression_op.size(); i++){
                         if (holds_alternative<int>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }
                         else if (holds_alternative<float>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }else {
                              string var_name = get<string>(expression_literals[i]);
                              IdInfo var = ids.getVar(var_name.c_str());
                              expression += var.value;
                         }
                         expression += " ";
                         expression += expression_op[i];
                         expression += " ";
                    }
                    if(holds_alternative<int>(expression_literals[expression_literals.size() -1]))
                              expression += to_string(get<int>(expression_literals[expression_literals.size() -1]));
                    else if(holds_alternative<float>(expression_literals[expression_literals.size() -1])) 
                              expression += to_string(get<float>(expression_literals[expression_literals.size() -1]));
                    else {
                         string var_name = get<string>(expression_literals[expression_literals.size() -1]);
                         IdInfo var = ids.getVar(var_name.c_str());
                         expression += var.value;
                    }
                    }
                    if(error == false){
                         if(isInt){
                              int result = eval.evaluate(expression);
                              // if(ids.existsVar($1, "main"))
                              //      ids.updateVar($1, "main", result);
                              // else
                              //      yyerror("Variable never delcared!");
                              var_type x;
                              x.linenr = yylineno;
                              x.name = (yyvsp[-3].string);
                              x.value_i = result;
                              update_var_q.push(x);
                         }else{
                              float result = eval.evaluate(expression);
                              // if(ids.existsVar($1, "main"))
                              //      ids.addVar("floatVal", $1, "main", result);
                              // else
                              //      yyerror("Variable never delcared!");
                              var_type x;
                              x.linenr = yylineno;
                              x.name = (yyvsp[-3].string);
                              x.value_f = result;
                              update_var_q.push(x);
                         }
                    }     
               }else {yyerror("there is no expression!");}
               expression_literals.clear();
               expression_op.clear();
               expression.clear();
         }
#line 2412 "expr.tab.c"
    break;

  case 87: /* statement: ID ASSIGN TRUEE ';'  */
#line 956 "expr.y"
                              {var_type x; x.linenr = yylineno; x.name = (yyvsp[-3].string); x.value_b = (yyvsp[-1].string); update_var_q.push(x);}
#line 2418 "expr.tab.c"
    break;

  case 88: /* statement: ID ASSIGN FALSEE ';'  */
#line 957 "expr.y"
                               {var_type x; x.linenr = yylineno; x.name = (yyvsp[-3].string); x.value_b = (yyvsp[-1].string); update_var_q.push(x);}
#line 2424 "expr.tab.c"
    break;

  case 89: /* statement: ID ASSIGN STRING ';'  */
#line 958 "expr.y"
                               {var_type x; x.linenr = yylineno; x.name = (yyvsp[-3].string); x.value_s = (yyvsp[-1].string); update_var_q.push(x);}
#line 2430 "expr.tab.c"
    break;

  case 90: /* statement: TYPE ID ASSIGN TRUEE ';'  */
#line 960 "expr.y"
                                   {var_type x; x.linenr = yylineno; x.name = (yyvsp[-3].string); x.type = (yyvsp[-4].string); x.value_b = (yyvsp[-1].string); add_var_q.push(x);}
#line 2436 "expr.tab.c"
    break;

  case 91: /* statement: TYPE ID ASSIGN FALSEE ';'  */
#line 961 "expr.y"
                                    {var_type x; x.linenr = yylineno; x.name = (yyvsp[-3].string); x.type = (yyvsp[-4].string); x.value_b = (yyvsp[-1].string); add_var_q.push(x);}
#line 2442 "expr.tab.c"
    break;

  case 92: /* statement: TYPE ID ASSIGN STRING ';'  */
#line 962 "expr.y"
                                    {var_type x; x.linenr = yylineno; x.name = (yyvsp[-3].string); x.type = (yyvsp[-4].string); x.value_s = (yyvsp[-1].string); add_var_q.push(x);}
#line 2448 "expr.tab.c"
    break;

  case 93: /* statement: ID '(' call_list ')' ';'  */
#line 963 "expr.y"
                                    { 
          vector<const char*> types;
          while(!func_usage_args_q.empty())
          {
               const char* type = func_usage_args_q.front();
               func_usage_args_q.pop();
               types.push_back(type);
          }

          func_usage_q.push(make_pair((yyvsp[-4].string), types));
     }
#line 2464 "expr.tab.c"
    break;

  case 110: /* initialization: ID ASSIGN math_expr  */
#line 992 "expr.y"
                                     {
               bool isInt;
               reverse(expression_literals.begin(), expression_literals.end());
               if(!expression_literals.empty()){
                    if (holds_alternative<int>(expression_literals[0])) {
                         isInt = true;
               }
               else if (holds_alternative<float>(expression_literals[0])) {
                    isInt = false;
               }else {
                    string var_name = get<string>(expression_literals[0]);
                    IdInfo var = ids.getVar(var_name.c_str());
                    if(var.type == "integer") 
                         isInt = true;
                    else if(var.type == "floatVal") 
                         isInt = false;
                    else {
                         error = true;
                         yyerror("The variable given in the expression is not an integer, not an floatVal!");
                    }
               }
                    for(int i = 0; i < expression_literals.size(); i++){
                         if(isInt == true){
                              if(holds_alternative<float>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         } else{
                              if(holds_alternative<int>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         }
                    }
                    if(error == false)
                    {
                    for(int i =0 ;i < expression_op.size(); i++){
                         if (holds_alternative<int>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }
                         else if (holds_alternative<float>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }else {
                              string var_name = get<string>(expression_literals[i]);
                              IdInfo var = ids.getVar(var_name.c_str());
                              expression += var.value;
                         }
                         expression += " ";
                         expression += expression_op[i];
                         expression += " ";
                    }
                    if(holds_alternative<int>(expression_literals[expression_literals.size() -1]))
                              expression += to_string(get<int>(expression_literals[expression_literals.size() -1]));
                    else if(holds_alternative<float>(expression_literals[expression_literals.size() -1])) 
                              expression += to_string(get<float>(expression_literals[expression_literals.size() -1]));
                    else {
                         string var_name = get<string>(expression_literals[expression_literals.size() -1]);
                         IdInfo var = ids.getVar(var_name.c_str());
                         expression += var.value;
                    }
                    }
                    if(error == false){
                         if(isInt){
                              int result = eval.evaluate(expression);
                              if(strcmp((yyvsp[-2].string), "integer") == 0)
                                   ids.addVar("integer", (yyvsp[-2].string), "main", result);
                              else 
                                   yyerror("Cannot assign integer to a anything other then integer");
                         }else{
                              float result = eval.evaluate(expression);
                              if(strcmp((yyvsp[-2].string), "floatVal") == 0)
                                   ids.addVar("floatVal", (yyvsp[-2].string), "main", result);
                              else 
                                   yyerror("Cannot assign floatVal to a anything other then floatVal");
                         }
                    }  
               }else {yyerror("there is no expression!");}
               expression_literals.clear();
               expression_op.clear();
               expression.clear();
         }
#line 2572 "expr.tab.c"
    break;

  case 111: /* initialization: ID ASSIGN math_expr ',' initialization  */
#line 1095 "expr.y"
                                                        {
               bool isInt;
               reverse(expression_literals.begin(), expression_literals.end());
               if(!expression_literals.empty()){
                    if (holds_alternative<int>(expression_literals[0])) {
                         isInt = true;
               }
               else if (holds_alternative<float>(expression_literals[0])) {
                    isInt = false;
               }else {
                    string var_name = get<string>(expression_literals[0]);
                    IdInfo var = ids.getVar(var_name.c_str());
                    if(var.type == "integer") 
                         isInt = true;
                    else if(var.type == "floatVal") 
                         isInt = false;
                    else {
                         error = true;
                         yyerror("The variable given in the expression is not an integer, not an floatVal!");
                    }
               }
                    for(int i = 0; i < expression_literals.size(); i++){
                         if(isInt == true){
                              if(holds_alternative<float>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         } else{
                              if(holds_alternative<int>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         }
                    }
                    if(error == false)
                    {
                    for(int i =0 ;i < expression_op.size(); i++){
                         if (holds_alternative<int>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }
                         else if (holds_alternative<float>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }else {
                              string var_name = get<string>(expression_literals[i]);
                              IdInfo var = ids.getVar(var_name.c_str());
                              expression += var.value;
                         }
                         expression += " ";
                         expression += expression_op[i];
                         expression += " ";
                    }
                    if(holds_alternative<int>(expression_literals[expression_literals.size() -1]))
                              expression += to_string(get<int>(expression_literals[expression_literals.size() -1]));
                    else if(holds_alternative<float>(expression_literals[expression_literals.size() -1])) 
                              expression += to_string(get<float>(expression_literals[expression_literals.size() -1]));
                    else {
                         string var_name = get<string>(expression_literals[expression_literals.size() -1]);
                         IdInfo var = ids.getVar(var_name.c_str());
                         expression += var.value;
                    }
                    }
                    if(error == false){
                         if(isInt){
                              int result = eval.evaluate(expression);
                              if(strcmp((yyvsp[-4].string), "integer") == 0)
                                   ids.addVar("integer", (yyvsp[-4].string), "main", result);
                              else 
                                   yyerror("Cannot assign integer to a anything other then integer");
                         }else{
                              float result = eval.evaluate(expression);
                              if(strcmp((yyvsp[-4].string), "floatVal") == 0)
                                   ids.addVar("floatVal", (yyvsp[-4].string), "main", result);
                              else 
                                   yyerror("Cannot assign floatVal to a anything other then floatVal");
                         }
                    }   
               }else {yyerror("there is no expression!");}
               expression_literals.clear();
               expression_op.clear();
               expression.clear();
         }
#line 2680 "expr.tab.c"
    break;

  case 112: /* math_expr: ID math_op math_expr  */
#line 1200 "expr.y"
                                 {
     IdInfo v = ids.getVar((yyvsp[-2].string)); 
     if(v.type != "null") 
          expression_literals.push_back((yyvsp[-2].string)); 
     else 
          yyerror("The variable is not defined!");
     }
#line 2692 "expr.tab.c"
    break;

  case 113: /* math_expr: ID  */
#line 1207 "expr.y"
               {
     IdInfo v = ids.getVar((yyvsp[0].string)); 
     if(v.type != "null") 
          expression_literals.push_back((yyvsp[0].string)); 
     else 
          yyerror("The variable is not defined!");
     }
#line 2704 "expr.tab.c"
    break;

  case 114: /* math_expr: INT math_op math_expr  */
#line 1214 "expr.y"
                                  {expression_literals.push_back((yyvsp[-2].integer));}
#line 2710 "expr.tab.c"
    break;

  case 115: /* math_expr: INT  */
#line 1215 "expr.y"
                {
               var_type x; 
               x.value_i = (yyvsp[0].integer);
               main_q.push(x);
               expression_literals.push_back((yyvsp[0].integer));}
#line 2720 "expr.tab.c"
    break;

  case 116: /* math_expr: FLOAT math_op math_expr  */
#line 1220 "expr.y"
                                    {expression_literals.push_back((yyvsp[-2].floatVal));}
#line 2726 "expr.tab.c"
    break;

  case 117: /* math_expr: FLOAT  */
#line 1221 "expr.y"
                  {
               var_type x;
               x.value_f = (yyvsp[0].floatVal);
               main_q.push(x);
               expression_literals.push_back((yyvsp[0].floatVal));}
#line 2736 "expr.tab.c"
    break;

  case 120: /* values_func: INT  */
#line 1232 "expr.y"
                  {func_usage_args_q.push("integer");}
#line 2742 "expr.tab.c"
    break;

  case 121: /* values_func: FLOAT  */
#line 1233 "expr.y"
                    {func_usage_args_q.push("floatVal");}
#line 2748 "expr.tab.c"
    break;

  case 122: /* values_func: TRUEE  */
#line 1234 "expr.y"
                    {func_usage_args_q.push("really");}
#line 2754 "expr.tab.c"
    break;

  case 123: /* values_func: FALSEE  */
#line 1235 "expr.y"
                     {func_usage_args_q.push("really");}
#line 2760 "expr.tab.c"
    break;

  case 124: /* values_func: CHAR  */
#line 1236 "expr.y"
                   {func_usage_args_q.push("character");}
#line 2766 "expr.tab.c"
    break;

  case 125: /* values_func: STRING  */
#line 1237 "expr.y"
                     {func_usage_args_q.push("string");}
#line 2772 "expr.tab.c"
    break;

  case 126: /* values_func: ID  */
#line 1238 "expr.y"
                 {func_usage_args_q.push((yyvsp[0].string));}
#line 2778 "expr.tab.c"
    break;


#line 2782 "expr.tab.c"

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

#line 1241 "expr.y"

void yyerror(const char * s){
printf("error: %s at line:%d\n",s,yylineno);
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
     cout << "Variables: " << '\n';
     ids.printVars();
     cout << '\n';
     cout << "Functions: " << '\n';
     func.printFunc();
} 
