%{
/*
 * scan.l
 *
 * lex input file for pascal scanner
 *
 * extensions: two ways to spell "external" and "->" ok for "^".
 */

 #include <stdio.h>

#define   ARRAY      2
#define   DO      6
#define   ELSE      8
#define   END      9
#define   FUNCTION      13
#define   ID      14
#define   IF      15
#define   INTEGER 16
#define   NOT      17
#define   NUM      18
#define   OF       21
#define   PBEGIN      25
#define   PROCEDURE      27
#define   PROGRAM      28
#define   REAL      29
#define   STRCONST  30
#define   THEN      32
#define   VAR      36
#define   WHILE      37
#define   IDENTIFIER      39

#define   ASSIGNMENT      40
#define   CHARACTER_STRING      41
#define   COLON      42
#define   COMMA      43
#define   DIGSEQ      44
#define   DOT      45
#define   DOTDOT      46
#define   EQUAL      47
#define   GE      48
#define   GT      49
#define   LBRAC      50
#define   LE      51
#define   LPAREN      52
#define   LT      53
#define   MINUS      54
#define   NUMBER      55
#define   PLUS      56
#define   RBRAC      57
#define   REALNUMBER      58
#define   RPAREN      59
#define   SEMICOLON      60
#define   SLASH      61
#define   STAR      62
#define   STARSTAR      63
#define   UPARROW      64


#define   NOTEQUAL    65
#define   STRING      66

int line_no = 1;


%}

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]
ESC_EOL \\n
ESC_QUOTE \\\"
EOL \r?\n
SIGN [+\-]
INTEGER {SIGN}?([1-9][0-9]*|0)
FLOAT {INTEGER}"."[0-9]+
SCIENTIFIC ({INTEGER}|{FLOAT}){E}{INTEGER}

%%

{A}{R}{R}{A}{Y}              return(ARRAY);
{D}{O}                       return(DO);
{E}{L}{S}{E}                 return(ELSE);
{E}{N}{D}                    return(END);
{F}{U}{N}{C}{T}{I}{O}{N}     return(FUNCTION);
{I}{D}                       return(ID);
{I}{F}                       return(IF);
{I}{N}{T}{E}{G}{E}{R}        return(INTEGER);
{N}{O}{T}                    return(NOT);
{N}{U}{M}                    return(NUM);
{O}{F}                       return(OF); 
{B}{E}{G}{I}{N}              return(PBEGIN);
{P}{R}{O}{C}{E}{D}{U}{R}{E}  return(PROCEDURE);
{P}{R}{O}{G}{R}{A}{M}        return(PROGRAM);
{R}{E}{A}{L}                 return(REAL);
{S}{T}{R}{I}{N}{G}{C}{O}{N}{S}{T}  return(STRCONST);
{T}{H}{E}{N}                 return(THEN);
{V}{A}{R}                    return(VAR);
{W}{H}{I}{L}{E}              return(WHILE);
[a-zA-Z]([a-zA-Z0-9_])+       return(IDENTIFIER);
{INTEGER}    {return(NUMBER);}
{FLOAT}      {return(NUMBER);}
{SCIENTIFIC} {return(NUMBER);}

"//"    {
	int c;
	fprintf(stdout, "one-line comment on line %d: ", line_no);
	while((c = input())){
		if (c == '\n'){
			fprintf(stdout,"\n");
			line_no++;
			break;
		}
		else if (c == 0){
			fprintf(stdout,"\n");
			break;
		}
		else{
		fprintf(stdout,"%c",c);
		}
	}
}

"/*"    {
	int c;
	fprintf(stdout, "multi-line comment starts from line %d", line_no);
	while((c = input())){
		if (c == '\n')
			line_no++;
		else if (c == 0)
			fprintf(stdout, "unexpected EOF in multi-line comment in line %d\n",line_no);
		else if (c== '*'){
				if ((c=input()) == '/'){
					fprintf(stdout, " and ends at line %d\n", line_no);
					break;
				}
				else
					unput(c);
			}
		}
	}

\"([^\"\n]|{ESC_EOL}|{ESC_QUOTE}|{EOL})*\"                         return(STRING);

":="                         return(ASSIGNMENT);
":"                          return(COLON);
","                          return(COMMA);
[0-9]+                       return(DIGSEQ);
"."                          return(DOT);
".."                         return(DOTDOT);
"="                          return(EQUAL);
"!="                         return(NOTEQUAL);
">="                         return(GE);
">"                          return(GT);
"["                          return(LBRAC);
"<="                         return(LE);
"("                          return(LPAREN);
"<"                          return(LT);
"-"                          return(MINUS);
"+"                          return(PLUS);
"]"                          return(RBRAC);
[0-9]+"."[0-9]+              return(REALNUMBER);
")"                          return(RPAREN);
";"                          return(SEMICOLON);
"/"                          return(SLASH);
"*"                          return(STAR);


[ \t\f]    ;

\r         ;
\n    line_no++;

.    {fprintf(stderr,"Lexical analyzer error at line %d : %s\n",line_no,yytext);}

%%

int main(int argc, char** argv) {
  int i, tok;
  yyin = fopen("test.txt", "r");
  for (i = 0; 1==1; i ++) {
    tok = yylex();
    fprintf(stderr, "%3d-th token(type:%d) on line %d : %s\n", i, tok,line_no, yytext);
  }
  return(0);
} /* end of main */

yywrap() {
  fclose(yyin);
  exit(1);
}

