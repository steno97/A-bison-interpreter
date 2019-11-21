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

//definisco un elenco assegnazioni
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

//definisco un elenco di eventi o comandi
elenco_ev_com:
	| string SEMI
	| elenco_ev_com NEWLINE elenco_ev_com
;

/definisco il campo eventi
events: EVENT LBRACE elenco_ev_com RBRACE
;

//definisco il campo comandi
commands: COMMAND LBRACE elenco_ev_com RBRACE
;

//definisco il campo stato
state: STATE LBRACE actions NEWLINE elenco_cambio RBRACE
	| STATE LBRACE actions NEWLINE elenco_cambio RBRACE
;

//definisco le azioni svolte 
actions: ACTION LBRACE elenco_actions RBRACE SEMI
;

//definisco un elenco di azioni svolte nello stato
elenco_actions: 
	| string
	| elenco_actions COMMA elenco_actions
;

//definisco il cambio stato
cambiostato: string CHANGESTATE string SEMI
	| CHANGESTATE string SEMI
;

//definisco un elenco di cambiostato
elenco_cambio: cambiostato
	| cambiostato NEWLINE cambiostato
;

//definisco il commento
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
