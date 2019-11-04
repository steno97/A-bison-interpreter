%{
#include <stdio.h>
#include <dichiarazini.h>
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
%token SPACE

%%

elenco_ass: assegnazione SEMI
	| elenco_ass NEWLINE elenco_ass
;

assegnazione: type string ASSIGN string
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

definition: VAR LBRACE NEWLINE RBRACE
	| VAR LBRACE elenco_ass RBRACE
;

elenco_ev_com: string SEMI {$$ = (evento) $1;}
	| elenco_ev_com NEWLINE elenco_ev_com
;

events: EVENT LBRACE elenco_ev_com RBRACE
;

commands: COMMAND LBRACE elenco_ev_com RBRACE
;

/* è da implementare con gli if*/
new_el_stati(stato* statolista, stato* prox);

elenco_stati:state NEWLINE state {$$=new_el_stati($1, $2);}
	| elenco_stati NEWLINE satate {$$=add_el_stati($1, $2);
;

state: STATE string LBRACE elenco_actions NEWLINE elenco_cambio RBRACE {$$=new_state($2,$4,$6);
																			free(elenco_cambio);}
;

actions: | ACTION LBRACE SPACE RBRACE SEMI
	| ACTION LBRACE elenco_actions RBRACE SEMI
;

elenco_actions: string {$$ = new_action((azione) $1,NULL);}
	| elenco_actions COMMA String {$$ = add_azione($1, new_action((azione $1 NULL)));}
;

cambiostato: string CHANGESTATE string SEMI {$$= new_cambiostato(new_evento((evento) $1,NULL),new_el_stati(new_stato($2),NULL);}
	| CHANGESTATE string SEMI {$$= new_cambiostato(new_evento( NULL,NULL),new_stato($2));}
;

elenco_cambio: cambiostato 
	| elenco_cambio NEWLINE cambiostato {$$=add_cambiostato($1,$2);}
;

commenti: COMMENT
	|COMMENT string NEWLINE
;


%%
