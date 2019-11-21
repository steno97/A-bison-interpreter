%{
#include <stdio.h>
#include "dichiarazini.h"
%}

/* declare tokens */
%token NUMBER
%token TYPE
%token ADD SUB MUL DIV ABS
%token SEMI
%token ALPHA
%token ASSIGN
%token VAR
%token LBRACE	/*{*/
%token RBRACE	/*}*/
%token LPAREN	/*(*/
%token RPAREN	/*)*/
%token EVENT
%token COMMAND
%token STATE
%token ACTION
%token NEWLINE
%token COMMA
%token CHANGESTATE
%token COMMENT
%token SPACE
%token IF
%token ELSE
%token ELIF
%token CMP

%%

assignments: VAR LBRACE elenco_ass RBRACE {$$=$3;}
;

elenco_ass: assegnazione SEMI 
	| elenco_ass NEWLINE assegnazione SEMI [$$= add_assegnazioni( $1, $3);}
;

assegnazione: TYPE string ASSIGN string	{$$ = new_assegnazioni( $2, $4, $1);}
	| TYPE string ASSIGN term {$$ = new_assegnazioni( $2, $4, $1);}
;

string: ALPHA
;

term: NUMBER
;

definition: VAR LBRACE NEWLINE RBRACE
	| VAR LBRACE elenco_ass RBRACE
;

elenco_ev_com: string SEMI {$$ = new_evento((evento) $1,NULL);}
	| elenco_ev_com NEWLINE string SEMI {$$= add_evento($1,new_evento((evento) $3,NULL);}
;

events: EVENT LBRACE elenco_ev_com RBRACE
;

commands: COMMAND LBRACE elenco_ev_com RBRACE
;


elenco_stati:state NEWLINE state {$$=new_el_stati($1, $2);}
	| elenco_stati NEWLINE state {$$=add_el_stati($1, $2;}
;

state: STATE string LBRACE elenco_actions NEWLINE elenco_cambio RBRACE {$$=new_stato2($2,$4,$6); free(elenco_cambio);}
	|  STATE string LBRACE elenco_actions NEWLINE elenco_cond RBRACE {$$=new_stato4($2,$4,$6);}
;

azioni:string SEMI {$$ = new_action((azione) $1,NULL);}
	| azioni NEWLINE string SEMI {$$ = add_azione($1, new_action((azione) $3, NULL));}
;

actions: | ACTION LBRACE SPACE RBRACE SEMI	{$$= new_action(NULL, NULL);}
	| ACTION LBRACE azioni RBRACE SEMI  {$$= $3;}
;

elenco_actions: string {$$ = new_action((azione) $1,NULL);}
	| elenco_actions COMMA String {$$ = add_azione($1, new_action((azione) $3, NULL));}
;

cambiostato: string CHANGESTATE string SEMI {$$= new_cambiostato(new_evento((evento) $1,NULL),new_el_stati1(new_stato1($3));}
	| CHANGESTATE string SEMI {$$= new_cambiostato(new_evento( (evento) "0",NULL),new_el_stati1(new_stato1($2));}
;

elenco_cambio: cambiostato 
	| elenco_cambio NEWLINE cambiostato {$$=add_cambiostato($1,$2);}
;

commenti: COMMENT
	|COMMENT string NEWLINE
;

main: elenco_ass NEWLINE events NEWLINE actions NEWLINE elenco_stati {run($1,$3,$5,$7)}
;

metodo: IF
	| ELIF
;

cond: metodo LPAREN term CMP term RPAREN LBRACE elenco_cambio RBRACE		{$$=new_cond(new_assegnazioni(NULL, $3,(int) 14),new_assegnazioni(NULL, $5,(int) 14), $4, $8);}
	| metodo LPAREN term CMP string RPAREN LBRACE elenco_cambio RBRACE		{$$=new_cond(new_assegnazioni(NULL, $3,(int) 14),new_assegnazioni(NULL, $5,(int) 16), $4, $8);}
	| metodo LPAREN string CMP term  RPAREN LBRACE elenco_cambio RBRACE		{$$=new_cond(new_assegnazioni(NULL, $3,(int) 16),new_assegnazioni(NULL, $5,(int) 14), $4, $8);}
	| metodo LPAREN string CMP string RPAREN LBRACE elenco_cambio RBRACE	{$$=new_cond(new_assegnazioni(NULL, $3,(int) 16),new_assegnazioni(NULL, $5,(int) 16), $4, $8);}
	| ELSE LBRACE elenco_cambio RBRACE										{$$=new_cond(NULL,NULL,0, $3);}
;

elenco_cond: cond NEWLINE cond  {$$=add_elencocond(new_elencocond($1),new_elencocond($3);}
	| elenco_cond NEWLINE cond	{$$=add_elencocond($1,new_elencocond($3);}
;

%%
