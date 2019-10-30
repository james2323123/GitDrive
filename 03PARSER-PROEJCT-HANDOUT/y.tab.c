#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "mini-pascal-yacc.y"
#include "lex.yy.c"
#line 21 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define AND 257
#define OR 258
#define ARRAY 259
#define DO 260
#define ELSE 261
#define END 262
#define FUNCTION 263
#define ID 264
#define IF 265
#define INTEGER 266
#define NOT 267
#define NUM 268
#define OF 269
#define PBEGIN 270
#define PROCEDURE 271
#define PROGRAM 272
#define REAL 273
#define STRCONST 274
#define STRING 275
#define THEN 276
#define VAR 277
#define WHILE 278
#define IDENTIFIER 279
#define ASSIGNMENT 280
#define COLON 281
#define COMMA 282
#define DIGSEQ 283
#define DOT 284
#define DOTDOT 285
#define EQUAL 286
#define GE 287
#define GT 288
#define LBRAC 289
#define LE 290
#define LPAREN 291
#define LT 292
#define MINUS 293
#define NUMBER 294
#define SIGNEDNUMBER 295
#define PLUS 296
#define RBRAC 297
#define REALNUMBER 298
#define SIGNEDREALNUMBER 299
#define RPAREN 300
#define SEMICOLON 301
#define SLASH 302
#define STAR 303
#define STARSTAR 304
#define UPARROW 305
#define NOTEQUAL 306
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    5,    5,    6,    6,    6,
    3,    3,    7,    8,    8,    9,    9,   10,   10,   11,
   11,    4,   12,   12,   13,   13,   14,   14,   14,   14,
   14,   14,   15,   18,   18,   17,   17,   19,   19,   16,
   16,   16,   20,   20,   21,   21,   21,   25,   25,   23,
   23,   26,   26,   26,   26,   26,   26,   26,   26,   24,
   24,   27,   27,   22,   22,   22,   22,   22,   22,
};
static const short yylen[] = {                            2,
   10,    1,    3,    6,    0,    1,    8,    1,    1,    1,
    3,    0,    4,    6,    4,    3,    0,    4,    6,    1,
    0,    3,    1,    0,    1,    3,    3,    1,    1,    6,
    4,    0,    2,    4,    0,    1,    4,    1,    3,    1,
    3,    3,    1,    3,    1,    3,    2,    1,    1,    1,
    3,    2,    4,    1,    1,    1,    3,    2,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    2,    0,    0,    0,    3,    5,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    5,
    0,    0,    0,    0,    0,   29,    0,    0,   25,    0,
   28,    0,    1,   11,    0,    0,    8,    9,   10,    0,
    6,    0,    0,    0,   56,    0,    0,   54,   48,   55,
   49,    0,    0,    0,    0,   59,   50,    0,    0,    0,
   33,   22,    0,    0,    0,    0,    0,    4,   20,    0,
    0,    0,   58,    0,   52,    0,    0,    0,    0,   66,
   68,   65,   67,   64,   61,   60,   69,    0,    0,   47,
   63,   62,    0,    0,    0,   38,    0,   26,   27,   15,
   13,    0,   16,    0,    0,    0,   57,    0,   41,   42,
    0,    0,   51,   31,    0,    0,   37,    0,    0,   14,
   53,    0,   34,   39,    0,    0,   30,    0,    0,    0,
   19,    7,
};
static const short yydgoto[] = {                          2,
    6,   11,   13,   26,   40,   41,   19,   20,   43,   70,
   71,   27,   28,   29,   30,   96,   31,   61,   97,   53,
   54,   88,   55,   89,   56,   57,   93,
};
static const short yysindex[] = {                      -247,
 -244,    0, -241, -235,    0, -262, -219, -227,    0,    0,
 -200, -235, -240, -225, -198, -187, -190, -185, -204,    0,
  -94, -189,  -13,  -13, -216,    0, -156, -183,    0, -158,
    0, -189,    0,    0, -200, -165,    0,    0,    0, -171,
    0, -144, -141,  -13,    0, -153,  -13,    0,    0,    0,
    0, -132,  -91, -167, -134,    0,    0, -114,  -13,  -13,
    0,    0, -187,  -13, -152, -240, -119,    0,    0, -147,
 -235, -194,    0,  -13,    0, -124, -187,  -13,  -13,    0,
    0,    0,    0,    0,    0,    0,    0,  -13,  -13,    0,
    0,    0,  -13, -187, -120,    0, -261,    0,    0,    0,
    0, -104,    0, -111, -118, -260,    0,  -79,    0,    0,
 -267, -134,    0,    0, -103,  -13,    0, -109,  -94,    0,
    0, -187,    0,    0, -110, -108,    0,  -78, -144,  -94,
    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -136,    0,    0,    0,    0, -252,    0,    0,    0,    0,
    0,  -85,    0,    0, -243,    0,    0,  -62,    0,    0,
    0,  -97,    0,    0, -136,    0,    0,    0,    0,    0,
    0,  -74,    0,    0,    0, -145,    0,    0,    0,    0,
    0,    0,   -9, -249,  -98,    0,    0,    0,    0,    0,
    0,    0, -248,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -49,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -246,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -215,  -51,    0,    0, -192,    0,    0,    0,    0,    0,
    0, -246,    0,    0,    0,  -87,    0,    0,  -74,    0,
    0,    0,
};
static const short yygindex[] = {                         0,
   -8,  194,  180,   -7,  -43,  144,    0,    0,  185,   89,
    0,    0,    0,  -60,    0,  -23,    0,  -44,  145,   95,
  132,    0,  133,    0,  -47,  -39,    0,
};
#define YYTABLESIZE 292
static const short yytable[] = {                         52,
   58,   75,   98,   14,   73,   18,   90,   43,   43,   24,
   43,   43,   43,   32,   32,   32,  108,   36,   36,    7,
  116,  116,   15,   76,    1,   85,   43,   49,   86,   16,
   17,   51,   43,  114,    3,   95,   35,    8,  117,  121,
   99,   44,   44,    5,   44,   44,   44,   43,   32,    4,
   43,   43,   32,  113,   32,   21,    7,   36,  101,    9,
   44,  127,  104,   90,   35,   35,   44,   35,   35,   35,
  123,   37,   59,   10,   60,  126,   12,   23,   38,   39,
   22,   44,   16,   35,   44,   44,  132,   35,   32,   35,
   24,   25,  124,   35,   35,   35,   34,   35,   33,   35,
   35,   42,   35,   35,   35,   62,   35,   35,   35,   35,
   35,   35,   35,   35,   35,   35,   35,   63,   80,   81,
   82,   64,   83,   67,   84,   85,   12,   49,   86,   68,
   35,   51,   69,   12,   12,   59,   35,   74,   87,   72,
   35,   35,   35,   77,   35,   94,   35,   35,  100,   35,
   35,   35,  103,   35,   35,   35,   35,   35,   45,   45,
   35,   45,   45,   45,   36,   78,   79,   91,   92,  119,
    7,   37,  109,  110,  102,  107,  115,   45,   38,   39,
  118,  122,  120,   45,  125,   59,  128,   45,   45,   45,
  130,   45,  129,   45,   45,   17,   45,   45,   45,   23,
   45,   45,   45,   17,   21,   46,   46,   45,   46,   46,
   46,   32,   18,   35,   66,  105,   65,  131,  106,  111,
    0,  112,    0,    0,   46,    0,    0,    0,    0,    0,
   46,    0,    0,    0,   46,   46,   46,    0,   46,    0,
   46,   46,    0,   46,   46,   46,    0,   46,   46,   46,
   40,   40,   40,   44,   46,    0,    0,    0,    0,    0,
    0,   45,    0,    0,    0,   46,   40,    0,    0,    0,
    0,    0,   40,    0,    0,    0,    0,   47,    0,    0,
   48,   49,    0,    0,   50,   51,    0,   40,    0,    0,
   40,   40,
};
static const short yycheck[] = {                         23,
   24,   46,   63,   12,   44,   13,   54,  257,  258,  262,
  260,  261,  262,  262,  261,  262,   77,  261,  262,  282,
  282,  282,  263,   47,  272,  293,  276,  295,  296,  270,
  271,  299,  282,   94,  279,   59,  280,  300,  300,  300,
   64,  257,  258,  279,  260,  261,  262,  297,  301,  291,
  300,  301,  301,   93,  301,  281,  282,  301,   66,  279,
  276,  122,   71,  111,  257,  258,  282,  260,  261,  262,
  115,  266,  289,  301,  291,  119,  277,  265,  273,  274,
  279,  297,  270,  276,  300,  301,  130,  280,  279,  282,
  278,  279,  116,  286,  287,  288,  301,  290,  284,  292,
  293,  291,  295,  296,  297,  262,  299,  300,  301,  302,
  303,  257,  258,  306,  260,  261,  262,  301,  286,  287,
  288,  280,  290,  289,  292,  293,  263,  295,  296,  301,
  276,  299,  277,  270,  271,  289,  282,  291,  306,  281,
  286,  287,  288,  276,  290,  260,  292,  293,  301,  295,
  296,  297,  300,  299,  300,  301,  302,  303,  257,  258,
  306,  260,  261,  262,  259,  257,  258,  302,  303,  281,
  282,  266,   78,   79,  294,  300,  297,  276,  273,  274,
  285,  261,  301,  282,  294,  289,  297,  286,  287,  288,
  269,  290,  301,  292,  293,  281,  295,  296,  297,  262,
  299,  300,  301,  301,  279,  257,  258,  306,  260,  261,
  262,  261,  300,   20,   35,   72,   32,  129,   74,   88,
   -1,   89,   -1,   -1,  276,   -1,   -1,   -1,   -1,   -1,
  282,   -1,   -1,   -1,  286,  287,  288,   -1,  290,   -1,
  292,  293,   -1,  295,  296,  297,   -1,  299,  300,  301,
  260,  261,  262,  267,  306,   -1,   -1,   -1,   -1,   -1,
   -1,  275,   -1,   -1,   -1,  279,  276,   -1,   -1,   -1,
   -1,   -1,  282,   -1,   -1,   -1,   -1,  291,   -1,   -1,
  294,  295,   -1,   -1,  298,  299,   -1,  297,   -1,   -1,
  300,  301,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 306
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"AND","OR","ARRAY","DO","ELSE",
"END","FUNCTION","ID","IF","INTEGER","NOT","NUM","OF","PBEGIN","PROCEDURE",
"PROGRAM","REAL","STRCONST","STRING","THEN","VAR","WHILE","IDENTIFIER",
"ASSIGNMENT","COLON","COMMA","DIGSEQ","DOT","DOTDOT","EQUAL","GE","GT","LBRAC",
"LE","LPAREN","LT","MINUS","NUMBER","SIGNEDNUMBER","PLUS","RBRAC","REALNUMBER",
"SIGNEDREALNUMBER","RPAREN","SEMICOLON","SLASH","STAR","STARSTAR","UPARROW",
"NOTEQUAL",
};
static const char *yyrule[] = {
"$accept : prog",
"prog : PROGRAM IDENTIFIER LPAREN identifier_list RPAREN SEMICOLON declarations subprogram_declarations compound_statement DOT",
"identifier_list : IDENTIFIER",
"identifier_list : identifier_list COMMA IDENTIFIER",
"declarations : declarations VAR identifier_list COLON type SEMICOLON",
"declarations :",
"type : standard_type",
"type : ARRAY LBRAC NUMBER DOTDOT NUMBER RBRAC OF type",
"standard_type : INTEGER",
"standard_type : REAL",
"standard_type : STRCONST",
"subprogram_declarations : subprogram_declarations subprogram_declaration SEMICOLON",
"subprogram_declarations :",
"subprogram_declaration : subprogram_head declarations subprogram_declarations compound_statement",
"subprogram_head : FUNCTION IDENTIFIER augments COLON standard_type SEMICOLON",
"subprogram_head : PROCEDURE IDENTIFIER augments SEMICOLON",
"augments : LPAREN parameter_list RPAREN",
"augments :",
"parameter_list : optional_var identifier_list COLON type",
"parameter_list : optional_var identifier_list COLON type SEMICOLON parameter_list",
"optional_var : VAR",
"optional_var :",
"compound_statement : PBEGIN optional_statements END",
"optional_statements : statement_list",
"optional_statements :",
"statement_list : statement",
"statement_list : statement_list SEMICOLON statement",
"statement : variable ASSIGNMENT expression",
"statement : procedure_statement",
"statement : compound_statement",
"statement : IF expression THEN statement ELSE statement",
"statement : WHILE expression DO statement",
"statement :",
"variable : IDENTIFIER tail",
"tail : LBRAC expression RBRAC tail",
"tail :",
"procedure_statement : IDENTIFIER",
"procedure_statement : IDENTIFIER LPAREN expression_list RPAREN",
"expression_list : expression",
"expression_list : expression_list COMMA expression",
"expression : bool_expression",
"expression : bool_expression AND bool_expression",
"expression : bool_expression OR bool_expression",
"bool_expression : simple_expression",
"bool_expression : simple_expression relop simple_expression",
"simple_expression : term",
"simple_expression : simple_expression addop term",
"simple_expression : simple_expression signed_num",
"signed_num : SIGNEDNUMBER",
"signed_num : SIGNEDREALNUMBER",
"term : factor",
"term : term mulop factor",
"factor : IDENTIFIER tail",
"factor : IDENTIFIER LPAREN expression_list RPAREN",
"factor : NUMBER",
"factor : REALNUMBER",
"factor : STRING",
"factor : LPAREN expression RPAREN",
"factor : NOT factor",
"factor : signed_num",
"addop : PLUS",
"addop : MINUS",
"mulop : STAR",
"mulop : SLASH",
"relop : LT",
"relop : GT",
"relop : EQUAL",
"relop : LE",
"relop : GE",
"relop : NOTEQUAL",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 139 "mini-pascal-yacc.y"

int main(){

	yyparse();
	printf("OK!!!!!!\n");	
	/*
	int i, t;
	yyin = fopen("test.txt", "r");
	for (i = 0; 1==1; i ++) {
		t = yylex();
		fprintf(stderr,"%3d-th token(type:%d) on line %d : %s\n",i,t,yylineno,yytext);
	}
*/
	return(0);

}

int yyerror(char* msg){
	
	printf("error: %s in line %d\n", msg, yylineno);
	exit(1);
}
#line 403 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
