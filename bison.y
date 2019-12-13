//%define api.pure
%define api.value.type {union YYSTYPE}
//%pure-parser
%define parse.error verbose


%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
%}


%{
#include "flex.lex.h"
#include "dichiarazioni.h"
%}


/* declare tokens */
%token NUMBER
//%token <fn> TYPE
%token TYPE
%token SEMI
%token ALPHA
%token ASSIGN
%token VAR
%token LBRACE	/*{*/
%token RBRACE	/*}*/
%token LPAREN	/*(*/
%token RPAREN	/*)*/
%token EVENT
%token ACTION
%token COMMAND
%token STATE
%token COMMA
%token CHANGESTATE
%token COMMENT
//%token SPACE
%token IF
%token ELSE
%token ELIF
%token <fn> CMP
%token <fn> OPERATORE
%token WHILE
%token FOR
%token <fn> PRINT

%type <fn> term NUMBER TYPE
%type <op> operazioni
%type <c> ALPHA string 
%type <as> elenco_ass assegnazione definition
%type <even> elenco_ev_com events  commands
%type <elen_stat> elenco_stati
%type <stat> state
%type <elen> elenchi
%type <azione> elenco_actions elenco_operazioni actions
%type <elen_con> elenco_cond
%type <cic> cicli
%type <camb_stat> elenco_cambio cambiostato
%type <con> cond
//%useless commenti


%start main

%%

main: definition events commands elenco_stati {run($1,$2,$3,$4);printf("stai runnando??\n");}
;

definition: VAR LBRACE RBRACE {$$=add_assegnazioni(NULL,new_assegnazioni(NULL,NULL,11));}
	| VAR LBRACE elenco_ass RBRACE {$$=$3;}
;

elenco_ass: assegnazione SEMI 
	| elenco_ass assegnazione SEMI {$$= add_assegnazioni( $1, $2);}
;

assegnazione: TYPE string ASSIGN string	{$$ = new_assegnazioni($2, $4, $1);}
	| TYPE string ASSIGN term {$$ = new_assegnazioni($2, (void*) $4, $1);}
;
// per risolvere le avvertenze di cast uso la & al posto del cast


string: ALPHA {$$=$1;}
;

operazioni: string ASSIGN string OPERATORE string {$$=new_operazione( new_assegnazioni( $1, NULL, 15), new_assegnazioni( NULL, (void*)$3, 15), new_assegnazioni(NULL, (void*)$5, 15), $4, -1);}
	| string ASSIGN string OPERATORE term {$$=new_operazione( new_assegnazioni( $1, NULL, 15), new_assegnazioni( NULL, (void*)$3, 15), new_assegnazioni( NULL, (void*)$5, 11), $4, -1);}
	| string ASSIGN term OPERATORE string {$$=new_operazione( new_assegnazioni( $1, NULL, 15), new_assegnazioni( NULL, (void*) $3, 11), new_assegnazioni( NULL, (void*)$5, 15), $4, -1);}
	| string ASSIGN term OPERATORE term {$$=new_operazione( new_assegnazioni( $1, NULL, 15), new_assegnazioni(NULL, (void*) $3, 11), new_assegnazioni( NULL, (void*) $5, 11), $4, -1);}
	| OPERATORE LPAREN string RPAREN {$$=new_operazione( new_assegnazioni( $3, NULL, 15), NULL, NULL, $1, -1);}
	| OPERATORE LPAREN term COMMA string RPAREN {$$=new_operazione( new_assegnazioni( $5, NULL, 15), NULL, NULL, $1, $3);}
	| PRINT LPAREN string RPAREN {$$=new_operazione( new_assegnazioni( $3, NULL, 15), NULL, NULL, $1, -1);}
	| PRINT {$$=new_operazione(NULL, NULL, NULL, $1, -1);}
;


/*
assignments: VAR LBRACE elenco_ass RBRACE {$$=$3;}
;*/

term: NUMBER
;

events: EVENT LBRACE elenco_ev_com RBRACE {$$=$3;}
;

elenco_ev_com: string SEMI {$$= new_evento((evento) $1,NULL);}
	| elenco_ev_com string SEMI {$$= add_evento($1,new_evento((evento) $2,NULL));}
;

elenco_stati:state {$$=new_el_stati1($1);}
	| elenco_stati state {$$=add_el_stati($1, $2);}
;

state: STATE string LBRACE actions elenchi RBRACE {$$=new_stato2($2,$4,$5);}
	| STATE string LBRACE actions elenco_cond elenchi RBRACE {$$=new_stato4($2,$4,$5,$6);}
	| STATE string LBRACE actions cicli RBRACE {$$=new_stato5($2,$4,NULL,NULL,$5);}
	| STATE string LBRACE actions cicli elenco_cond RBRACE {$$=new_stato5($2,$4,$6,NULL,$5);}
	| STATE string LBRACE actions cicli elenchi RBRACE {$$=new_stato5($2,$4,NULL,$6,$5);}
;

elenchi: elenco_operazioni					{$$= new_elenchi($1, NULL);}
	| elenco_cambio							{$$= new_elenchi(NULL, $1);}
	| elenchi elenco_cambio			{$$= add_cambio_elenchi($1, $2);}
	| elenchi elenco_operazioni		{$$= add_oper_elenchi($1, $2);}
; 

elenco_operazioni: operazioni SEMI {$$ = new_action((operazioni*) $1,NULL);;}
	| elenco_operazioni SEMI operazioni {$$ = add_azione($1, new_action((operazioni*) $3, NULL));}
;

/*
azioni:string SEMI {$$ = new_action((operazioni*) $1,NULL);}
	| azioni string SEMI {$$ = add_azione($1, new_action((operazioni*) $2, NULL));}
;
*/

actions: ACTION LBRACE RBRACE SEMI	{$$= new_action(NULL, NULL);}
	| ACTION LBRACE elenco_actions RBRACE SEMI  {$$= $3;}
;

commands: COMMAND LBRACE elenco_ev_com RBRACE {$$=$3;}
;

elenco_actions: operazioni {$$ = new_action((operazioni*) $1,NULL);}
	| elenco_actions COMMA operazioni {$$ = add_azione($1, new_action((operazioni*) $3, NULL));}
;

cambiostato: string CHANGESTATE string SEMI {$$= new_cambiostato(new_evento((evento*) $1,NULL),new_el_stati1(new_stato1($3)));}
	| CHANGESTATE string SEMI {$$= new_cambiostato(new_evento( (evento*) "0",NULL),new_el_stati1(new_stato1($2)));}
;

elenco_cambio: cambiostato 
	| elenco_cambio cambiostato {$$=add_cambiostato($1,$2);}
;


commenti: COMMENT
	|COMMENT string
;

cicli: FOR LPAREN assegnazione COMMA string CMP term COMMA operazioni RPAREN LBRACE elenco_cond RBRACE  {$$=new_cicli(1, $3, $12, new_action((operazioni*) $9,NULL), new_cond(new_assegnazioni(NULL,(void*) $5,15),new_assegnazioni(NULL,(void*) $7,11), $6, NULL));}
	| FOR LPAREN assegnazione COMMA term CMP string COMMA operazioni RPAREN LBRACE elenco_cond RBRACE 	{$$=new_cicli(1, $3, $12, new_action((operazioni*) $9,NULL), new_cond(new_assegnazioni(NULL,(void *) $5, 11),new_assegnazioni(NULL,(void *) $7, 15), $6, NULL));} 
	| FOR LPAREN assegnazione COMMA string CMP string COMMA operazioni RPAREN LBRACE elenco_cond RBRACE	{$$=new_cicli(1, $3, $12, new_action((operazioni*) $9,NULL), new_cond(new_assegnazioni(NULL,(void *) $5, 15),new_assegnazioni(NULL,(void *) $7, 15), $6, NULL));}
	| FOR LPAREN assegnazione COMMA string CMP term COMMA operazioni RPAREN LBRACE elenchi RBRACE		{$$=new_cicli1(1, $3, $12, new_action((operazioni*) $9,NULL), new_cond(new_assegnazioni(NULL,(void *) $5, 11),new_assegnazioni(NULL,(void*) $7, 15), $6, NULL));}
	| FOR LPAREN assegnazione COMMA term CMP string COMMA operazioni RPAREN LBRACE elenchi RBRACE		{$$=new_cicli1(1, $3, $12, new_action((operazioni*) $9,NULL), new_cond(new_assegnazioni(NULL,(void*) $5, 15),new_assegnazioni(NULL,(void *) $7, 11), $6, NULL));}
	| FOR LPAREN assegnazione COMMA string CMP string COMMA operazioni RPAREN LBRACE elenchi RBRACE		{$$=new_cicli1(1, $3, $12, new_action((operazioni*) $9,NULL), new_cond(new_assegnazioni(NULL,(void *) $5, 11),new_assegnazioni(NULL,(void *) $7, 15), $6, NULL));}
	| WHILE LPAREN term CMP term RPAREN LBRACE elenco_cond RBRACE	{$$=new_cicli(2, NULL, $8, NULL, new_cond(new_assegnazioni(NULL,(void *) $3, 11),new_assegnazioni(NULL,(void *) $5,11), $4, NULL));}
	| WHILE LPAREN string CMP term RPAREN LBRACE elenco_cond RBRACE	{$$=new_cicli(2, NULL, $8, NULL, new_cond(new_assegnazioni(NULL,(void *) $3, 15),new_assegnazioni(NULL,(void *) $5, 11), $4, NULL));}
	| WHILE LPAREN term CMP string RPAREN LBRACE elenco_cond RBRACE	{$$=new_cicli(2, NULL, $8, NULL, new_cond(new_assegnazioni(NULL,(void *) $3,11),new_assegnazioni(NULL,(void *) $5,15), $4, NULL));}
	| WHILE LPAREN string CMP string RPAREN LBRACE elenco_cond RBRACE	{$$=new_cicli(2, NULL, $8, NULL, new_cond(new_assegnazioni(NULL,(void *) $3, 15),new_assegnazioni(NULL,(void *) $5,15), $4, NULL));}
	| WHILE LPAREN term CMP term RPAREN LBRACE elenchi RBRACE	{$$=new_cicli1(2, NULL, $8, NULL, new_cond(new_assegnazioni(NULL,(void *) $3, 11),new_assegnazioni(NULL,(void *) $5,11), $4, NULL));}
	| WHILE LPAREN string CMP term RPAREN LBRACE elenchi RBRACE	{$$=new_cicli1(2, NULL, $8, NULL, new_cond(new_assegnazioni(NULL,(void *) $3, 11),new_assegnazioni(NULL,(void *) $5, 11), $4, NULL));}
	| WHILE LPAREN term CMP string RPAREN LBRACE elenchi RBRACE	{$$=new_cicli1(2, NULL, $8, NULL, new_cond(new_assegnazioni(NULL,(void *) $3,11),new_assegnazioni(NULL, (void *) $5,15), $4, NULL));}
	| WHILE LPAREN string CMP string RPAREN LBRACE elenchi RBRACE	{$$=new_cicli1(2, NULL, $8, NULL, new_cond(new_assegnazioni(NULL,(void *) $3, 15),new_assegnazioni(NULL,(void *) $5,15), $4, NULL));}
;

metodo: IF
	| ELIF
;

cond: metodo LPAREN term CMP term RPAREN LBRACE elenchi RBRACE			{$$=new_cond(new_assegnazioni(NULL, (void *) $3, 11),new_assegnazioni(NULL,(void*) $5, 11), $4, $8);}
	| metodo LPAREN term CMP string RPAREN LBRACE elenchi RBRACE		{$$=new_cond(new_assegnazioni(NULL,(void*) $3, 11),new_assegnazioni(NULL, $5,15), $4, $8);}
	| metodo LPAREN string CMP term  RPAREN LBRACE elenchi RBRACE		{$$=new_cond(new_assegnazioni(NULL,(void *) $3,15),new_assegnazioni(NULL,(void*) $5, 11), $4, $8);}
	| metodo LPAREN string CMP string RPAREN LBRACE elenchi RBRACE		{$$=new_cond(new_assegnazioni(NULL,(void *) $3, 15),new_assegnazioni(NULL,(void *) $5, 15), $4, $8);}
	| ELSE LBRACE elenchi RBRACE										{$$=new_cond(NULL,NULL,0, $3);}
;

elenco_cond: cond {$$=add_elencocond(new_elencocond($1),NULL);}
	| elenco_cond cond	{$$=add_elencocond($1,new_elencocond($2));}
;

%%
