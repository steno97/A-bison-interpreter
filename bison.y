%define api.pure
%define api.value.type {union YYSTYPE}
%pure-parser

%{
#include <stdio.h>
#include <stdlib.h>
%}


%{
#include "flex.lex.h"
#include "dichiarazioni.h"
%}


/* declare tokens */
%token NUMBER
%token <fn> TYPE
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
%token <fn> CMP
%token <fn> OPERATORE
%token WHILE
%token FOR
%token <fn> PRINT

%type <fn> term NUMBER
%type <op> operazioni
%type <c> ALPHA string
%type <as> elenco_ass assegnazione
%type <even> elenco_ev_com events commands EVENT COMMAND
%type <elen_stat> elenco_stati
%type <stat> state
%type <elen> elenchi
%type <azione> elenco_actions actions elenco_operazioni
%type <elen_con> elenco_cond
%type <cic> cicli
%type <camb_stat> elenco_cambio cambiostato
%type <con> cond
//%useless commenti


%start main

%%

string: ALPHA 
;

operazioni: string ASSIGN string OPERATORE string {$$=new_operazione( new_assegnazioni( $1, NULL, 15), new_assegnazioni( $3, NULL, 15), new_assegnazioni( $5, NULL, 15), $4, -1);}
	| string ASSIGN string OPERATORE term {$$=new_operazione( new_assegnazioni( $1, NULL, 15), new_assegnazioni( $3, NULL, 15), new_assegnazioni( $5, NULL, 11), $4, -1);}
	| string ASSIGN term OPERATORE string {$$=new_operazione( new_assegnazioni( $1, NULL, 15), new_assegnazioni( NULL, (void*) $3, 11), new_assegnazioni( $5, NULL, 15), $4, -1);}
	| string ASSIGN term OPERATORE term {$$=new_operazione( new_assegnazioni( $1, NULL, 15), new_assegnazioni(NULL, (void*) $3, 11), new_assegnazioni( NULL, (void*) $5, 11), $4, -1);}
	| OPERATORE LPAREN string RPAREN {$$=new_operazione( new_assegnazioni( $3, NULL, 15), NULL, NULL, $1, -1);}
	| OPERATORE LPAREN term COMMA string RPAREN {$$=new_operazione( new_assegnazioni( $5, NULL, 15), NULL, NULL, $1, $3);}
	| PRINT LPAREN string RPAREN {$$=new_operazione( new_assegnazioni( $3, NULL, NULL), NULL, NULL, $1, -1);}
	| PRINT {$$=new_operazione(NULL, NULL, NULL, $1, -1);}
;

/*
assignments: VAR LBRACE elenco_ass RBRACE {$$=$3;}
;*/

elenco_ass: assegnazione SEMI 
	| elenco_ass NEWLINE assegnazione SEMI {$$= add_assegnazioni( $1, $3);}
;

assegnazione: TYPE string ASSIGN string	{$$ = new_assegnazioni( $2, $4, $1);}
	| TYPE string ASSIGN term {$$ = new_assegnazioni( $2, $4, $1);}
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

elenco_stati:state NEWLINE state {$$=new_el_stati($1, $3);}
	| elenco_stati NEWLINE state {$$=add_el_stati($1, $3;}
;

state: STATE string LBRACE elenco_actions NEWLINE elenchi RBRACE {$$=new_stato2($2,$4,$6);}
	| STATE string LBRACE elenco_actions NEWLINE elenco_cond RBRACE {$$=new_stato5($2,$4,$6);}
	| STATE string LBRACE elenco_actions NEWLINE cicli RBRACE {$$=new_stato5($2,$4,NULL,NULL,$6);}
	| STATE string LBRACE elenco_actions NEWLINE cicli NEWLINE elenco_cond RBRACE {$$=new_stato5($2,$4,$8,NULL,$6);}
	| STATE string LBRACE elenco_actions NEWLINE cicli NEWLINE elenchi RBRACE {$$=new_stato5($2,$4,NULL $8,$6);}
;

elenchi: elenco_operazioni					{$$= new_elenchi($1, NULL);}
	| elenco_cambio							{$$= new_elenchi(NULL, $1);}
	| elenchi NEWLINE elenco_cambio			{$$= add_cambio_elenchi($1, $3);}
	| elenchi NEWLINE elenco_operazioni		{$$= add_oper_elenchi($1, $3);}
; 

elenco_operazioni: operazioni SEMI{$$ = new_action((azione) $1,NULL);}
	| elenco_operazioni NEWLINE SEMI operazioni {$$ = add_azione($1, new_action((azione) $4, NULL));}
;

/*
azioni:string SEMI {$$ = new_action((azione) $1,NULL);}
	| azioni NEWLINE string SEMI {$$ = add_azione($1, new_action((azione) $3, NULL));}
;
*/

actions: ACTION LBRACE SPACE RBRACE SEMI	{$$= new_action(NULL, NULL);}
	| ACTION LBRACE elenco_actions RBRACE SEMI  {$$= $3;}
;

elenco_actions: operazioni {$$ = new_action((azione) $1,NULL);}
	| elenco_actions COMMA operazioni {$$ = add_azione($1, new_action((azione) $3, NULL));}
;

cambiostato: string CHANGESTATE string SEMI {$$= new_cambiostato(new_evento((evento) $1,NULL),new_el_stati1(new_stato1($3));}
	| CHANGESTATE string SEMI {$$= new_cambiostato(new_evento( (evento) "0",NULL),new_el_stati1(new_stato1($2));}
;

elenco_cambio: cambiostato 
	| elenco_cambio NEWLINE cambiostato {$$=add_cambiostato($1,$3);}
;


commenti: COMMENT
	|COMMENT string NEWLINE
;


main: elenco_ass NEWLINE events NEWLINE actions NEWLINE elenco_stati {run($1,$3,$5,$7);}
;

cicli: FOR LPAREN assegnazione COMMA string CMP term COMMA operazioni RPAREN LBRACE elenco_cond RBRACE  {$$=new_cicli(1, $3, $12, $9, new_cond(new_assegnazioni(NULL, $5,(int) 16),new_assegnazioni(NULL, $7,(int) 14) $6, NULL));}
	| FOR LPAREN assegnazione COMMA term CMP string COMMA operazioni RPAREN LBRACE elenco_cond RBRACE 	{$$=new_cicli(1, $3, $12, $9, new_cond(new_assegnazioni(NULL, $5,(int) 14),new_assegnazioni(NULL, $7,(int) 16) $6, NULL));} 
	| FOR LPAREN assegnazione COMMA string CMP string COMMA operazioni RPAREN LBRACE elenco_cond RBRACE	{$$=new_cicli(1, $3, $12, $9, new_cond(new_assegnazioni(NULL, $5,(int) 16),new_assegnazioni(NULL, $7,(int) 16) $6, NULL));}
	| FOR LPAREN assegnazione COMMA string CMP term COMMA operazioni RPAREN LBRACE elenchi RBRACE		{$$=new_cicli1(1, $3, $12, $9, new_cond(new_assegnazioni(NULL, $5,(int) 16),new_assegnazioni(NULL, $7,(int) 14) $6, NULL));}
	| FOR LPAREN assegnazione COMMA term CMP string COMMA operazioni RPAREN LBRACE elenchi RBRACE		{$$=new_cicli1(1, $3, $12, $9, new_cond(new_assegnazioni(NULL, $5,(int) 14),new_assegnazioni(NULL, $7,(int) 16) $6, NULL));}
	| FOR LPAREN assegnazione COMMA string CMP string COMMA operazioni RPAREN LBRACE elenchi RBRACE		{$$=new_cicli1(1, $3, $12, $9, new_cond(new_assegnazioni(NULL, $5,(int) 16),new_assegnazioni(NULL, $7,(int) 16) $6, NULL));}
	| WHILE LPAREN term CMP term RPAREN LBRACE elenco_cond RBRACE	{$$=new_cicli(2, NULL, $8, NULL, new_cond(new_assegnazioni(NULL, $3,(int) 14),new_assegnazioni(NULL, $5,(int) 14) $4, NULL));}
	| WHILE LPAREN string CMP term RPAREN LBRACE elenco_cond RBRACE	{$$=new_cicli(2, NULL, $8, NULL, new_cond(new_assegnazioni(NULL, $3,(int) 16),new_assegnazioni(NULL, $5,(int) 14) $4, NULL));}
	| WHILE LPAREN term CMP string RPAREN LBRACE elenco_cond RBRACE	{$$=new_cicli(2, NULL, $8, NULL, new_cond(new_assegnazioni(NULL, $3,(int) 14),new_assegnazioni(NULL, $5,(int) 16) $4, NULL));}
	| WHILE LPAREN string CMP string RPAREN LBRACE elenco_cond RBRACE	{$$=new_cicli(2, NULL, $8, NULL, new_cond(new_assegnazioni(NULL, $3,(int) 16),new_assegnazioni(NULL, $5,(int) 16) $4, NULL));}
	| WHILE LPAREN term CMP term RPAREN LBRACE elenchi RBRACE	{$$=new_cicli1(2, NULL, $8, NULL, new_cond(new_assegnazioni(NULL, $3,(int) 14),new_assegnazioni(NULL, $5,(int) 14) $4, NULL));}
	| WHILE LPAREN string CMP term RPAREN LBRACE elenchi RBRACE	{$$=new_cicli1(2, NULL, $8, NULL, new_cond(new_assegnazioni(NULL, $3,(int) 16),new_assegnazioni(NULL, $5,(int) 14) $4, NULL));}
	| WHILE LPAREN term CMP string RPAREN LBRACE elenchi RBRACE	{$$=new_cicli1(2, NULL, $8, NULL, new_cond(new_assegnazioni(NULL, $3,(int) 14),new_assegnazioni(NULL, $5,(int) 16) $4, NULL));}
	| WHILE LPAREN string CMP string RPAREN LBRACE elenchi RBRACE	{$$=new_cicli1(2, NULL, $8, NULL, new_cond(new_assegnazioni(NULL, $3,(int) 16),new_assegnazioni(NULL, $5,(int) 16) $4, NULL));}
;

metodo: IF
	| ELIF
;

cond: metodo LPAREN term CMP term RPAREN LBRACE elenchi RBRACE			{$$=new_cond(new_assegnazioni(NULL, (void *) $3, 14),new_assegnazioni(NULL,(void*) $5,(int) 14), $4, $8);}
	| metodo LPAREN term CMP string RPAREN LBRACE elenchi RBRACE		{$$=new_cond(new_assegnazioni(NULL,(void*) $3,(int) 14),new_assegnazioni(NULL, $5,(int) 16), $4, $8);}
	| metodo LPAREN string CMP term  RPAREN LBRACE elenchi RBRACE		{$$=new_cond(new_assegnazioni(NULL, $3,(int) 16),new_assegnazioni(NULL,(void*) $5,(int) 14), $4, $8);}
	| metodo LPAREN string CMP string RPAREN LBRACE elenchi RBRACE		{$$=new_cond(new_assegnazioni(NULL, $3,(int) 16),new_assegnazioni(NULL, $5,(int) 16), $4, $8);}
	| ELSE LBRACE elenchi RBRACE										{$$=new_cond(NULL,NULL,0, $3);}
;

elenco_cond: cond NEWLINE cond  {$$=add_elencocond(new_elencocond($1),new_elencocond($3));}
	| elenco_cond NEWLINE cond	{$$=add_elencocond($1,new_elencocond($3));}
;

%%
