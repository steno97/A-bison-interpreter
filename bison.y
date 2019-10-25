%{
#include <stdio.h>
%}

/* declare tokens */
%token NUMBER
%token BYTE CHAR INT FLOAT DOUBLE VOID
%token ADD SUB MUL DIV ABS
%token SEMI
%token ALPHA
%token ASSIGN
%token VAR
%token LBRACE
%token RBRACE
%token EVENT
%token COMMAND
%token STATE
%token ACTION
%token NEWLINE
%token COMMA
%token CHANGESTATE
%token COMMENT

%%

elenco_ass: 
 | assegnazione SEMI
 | elenco_ass NEWLINE elenco_ass
;

assegnazione: 
	| type string ASSIGN string
	| type string ASSIGN term
;

type: BYTE 
	|CHAR 
	|INT 
	|FLOAT 
	|DOUBLE 
	|VOID
;

string: ALPHA
;

term: NUMBER
;

definition: VAR LBRACE end_ass RBRACE
;

elenco_ev_com:
	| string SEMI
	| elenco_ev_com NEWLINE elenco_ev_com
;

events: EVENT LBRACE elenco_ev_com RBRACE
;

commands: COMMAND LBRACE elenco_ev_com RBRACE
;

state: STATE LBRACE actions NEWLINE elenco_cambio RBRACE
	| STATE LBRACE actions NEWLINE elenco_cambio RBRACE
;

actions: ACTION LBRACE elenco_actions RBRACE SEMI
;

elenco_actions: 
	| string
	| elenco_actions COMMA elenco_actions
;

cambiostato: string CHANGESTATE string SEMI
	| CHANGESTATE string SEMI
;

elenco_cambio: cambiostato
	| cambiostato NEWLINE cambiostato
;

commenti: COMMENT string NEWLINE
	| COMMENT
;



%%

main(int argc, char **argv)
{
	yyparse();
}
yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}
