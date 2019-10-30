%{
/*
 * scan.l
 *
 * lex input file for pascal scanner
 *
 * extensions: two ways to spell "external" and "->" ok for "^".
 */
#include "y.tab.h"
#include <stdio.h>


int line_no = 1;


%}

%option yylineno
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

%%

{A}{N}{D}                    return(AND);
{O}{R}                       return(OR);
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
"-"                          return(MINUS);
"+"                          return(PLUS);
{V}{A}{R}                    return(VAR);
{W}{H}{I}{L}{E}              return(WHILE);
[a-zA-Z]([a-zA-Z0-9_])*      return(IDENTIFIER);

([1-9][0-9]*|0)       return(NUMBER);
([1-9][0-9]*|0)"."[0-9]+     return(REALNUMBER);
([1-9][0-9]*|0)("."[0-9]+)?{E}{SIGN}?([1-9][0-9]*|0) return(REALNUMBER);

{SIGN}([1-9][0-9]*|0)       return(SIGNEDNUMBER);
{SIGN}([1-9][0-9]*|0)"."[0-9]+     return(SIGNEDREALNUMBER);
{SIGN}([1-9][0-9]*|0)("."[0-9]+)?{E}{SIGN}?([1-9][0-9]*|0) return(SIGNEDREALNUMBER);
"//"    {
	int c;
	//fprintf(stdout, "one-line comment on line %d: ", line_no);
	while((c = input())){
		if (c == '\n'){
			//fprintf(stdout,"\n");
			yylineno++;
			break;
		}
		else if (c == 0){
			//fprintf(stdout,"\n");
			break;
		}
		else{
		;
		//fprintf(stdout,"%c",c);
		}
	}
}

"/*"    {
	int c;
	//fprintf(stdout, "multi-line comment starts from line %d:\n", line_no);
	while((c = input())){
		if (c == '\n'){
			yylineno++;
			//fprintf(stdout, "\n");
		}
		else if (c == 0){;}
			//fprintf(stdout, "unexpected EOF in multi-line comment in line %d\n",line_no);
		else if (c== '*'){
				if ((c=input()) == '/'){
					//fprintf(stdout, "\nand ends at line %d\n", line_no);
					break;
				}
				else
					//fprintf(stdout, "*");
					unput(c);
			}
		else {
			;
			//fprintf(stdout, "%c", c);
		}
	}
}

\"[a-zA-Z(\\n)(\\")(\\) ]*\"  return(STRING);
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
"]"                          return(RBRAC);
[0-9]+"."[0-9]+              return(REALNUMBER);
")"                          return(RPAREN);
";"                          return(SEMICOLON);
"/"                          return(SLASH);
"*"                          return(STAR);


[ \t\f]    ;

\r         ;
\n    yylineno++;

.    {fprintf(stdout,"Lexical analyzer error at line %d : %s\n",yylineno,yytext);}

%%


yywrap() {
  
  return 1;
}

