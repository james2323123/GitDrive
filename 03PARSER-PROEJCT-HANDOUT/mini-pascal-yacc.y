%{
#include "lex.yy.c"
%}

%token AND OR ARRAY DO ELSE END FUNCTION ID IF INTEGER NOT NUM OF PBEGIN PROCEDURE PROGRAM 
%token REAL STRCONST STRING THEN VAR WHILE IDENTIFIER
%token ASSIGNMENT COLON COMMA DIGSEQ DOT DOTDOT EQUAL GE GT LBRAC
%token LE LPAREN LT MINUS NUMBER SIGNEDNUMBER PLUS RBRAC REALNUMBER SIGNEDREALNUMBER RPAREN SEMICOLON SLASH STAR STARSTAR 
%token UPARROW NOTEQUAL
%start prog

%%
prog : PROGRAM IDENTIFIER LPAREN identifier_list RPAREN SEMICOLON 
declarations 
subprogram_declarations 
compound_statement 
DOT
;


identifier_list : IDENTIFIER
| identifier_list COMMA IDENTIFIER
;

declarations : declarations VAR identifier_list COLON type SEMICOLON
|  
;

type : standard_type
| ARRAY LBRAC NUMBER DOTDOT NUMBER  RBRAC OF type
;



standard_type : INTEGER
| REAL
| STRCONST
;

subprogram_declarations : subprogram_declarations subprogram_declaration SEMICOLON
|  
;

subprogram_declaration : subprogram_head declarations 
subprogram_declarations compound_statement
;

subprogram_head : FUNCTION IDENTIFIER augments COLON standard_type SEMICOLON
| PROCEDURE IDENTIFIER augments SEMICOLON
;

augments : LPAREN parameter_list RPAREN
|  
;

parameter_list : optional_var identifier_list COLON type
| optional_var identifier_list COLON type SEMICOLON parameter_list 
;

optional_var : VAR
|
;

compound_statement : PBEGIN optional_statements END
;

optional_statements : statement_list
|  
;

statement_list : statement
| statement_list SEMICOLON statement
;

statement : variable ASSIGNMENT expression
| procedure_statement
| compound_statement
| IF expression THEN statement ELSE statement
| WHILE expression DO statement
|  
;

variable : IDENTIFIER tail
;

tail     : LBRAC expression RBRAC tail
|   


procedure_statement : IDENTIFIER
| IDENTIFIER LPAREN expression_list RPAREN


expression_list : expression
| expression_list COMMA expression

expression : bool_expression
| bool_expression AND bool_expression
| bool_expression OR  bool_expression

bool_expression : simple_expression
| simple_expression relop simple_expression

simple_expression : term
| simple_expression addop term
| simple_expression signed_num

signed_num : SIGNEDNUMBER
| SIGNEDREALNUMBER

term : factor
| term mulop factor


factor : IDENTIFIER tail
| IDENTIFIER LPAREN expression_list RPAREN
| NUMBER
| REALNUMBER
| STRING
| LPAREN expression RPAREN
| NOT factor
| signed_num

addop : PLUS | MINUS


mulop : STAR | SLASH



relop : LT
| GT
| EQUAL
| LE
| GE
| NOTEQUAL

%%

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
