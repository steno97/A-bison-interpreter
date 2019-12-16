#include <stdio.h>
#include "dichiarazioni.h"
#include <stdlib.h>

cicli* new_cicli(int t, assegnazioni* asse, elenco_cond* con, action* a, cond* co){
	cicli* cs=(cicli*) malloc(sizeof(cicli));
	cs->tipo=t;
	cs->as=asse;
	cs->condi=con;
	cs->az=a;
	cs->con=co;
	return cs;
}

cicli* new_cicli1(int t, assegnazioni* asse, elenchi* e, action* a, cond* co){
	cicli* cs=(cicli*) malloc(sizeof(cicli));
	cs->tipo=t;
	cs->as=asse;
	cs->el=e;
	cs->az=a;
	cs->con=co;
	return cs;
}

int free_cicli(cicli* c){
	free_assegnazioni(c->as);
	free_elencocond(c->condi);
	free_elenchi(c->el);
	free_action(c->az);
	free_cond(c->con);
	free(c);
	return 1;
}

elenchi* new_elenchi( action* opera, cambio_stato* cambios){
	elenchi* cs=(elenchi*) malloc(sizeof(elenchi));
	cs->oper=opera;
	cs->cambio=cambios;
	return cs;
}

operazioni* new_operazione( assegnazioni* pr, assegnazioni* sec, assegnazioni* ter, int type, int v){
	operazioni* cs=(operazioni*) malloc(sizeof(operazioni));
	cs->primo=pr;
	cs->secondo=sec;
	cs->terzo=ter;
	cs->operatore=type;
	cs->value=v;
	return cs;
}

int free_elenchi(elenchi* op){
	free_action(op->oper);
	free_cambiostato(op->cambio);
	return 1;
}
int free_operazioni(operazioni* op){
	free_assegnazioni(op->primo);
	free_assegnazioni(op->secondo);
	free_assegnazioni(op->terzo);
	free(op);
	return 1;
}

elenchi* add_cambio_elenchi( elenchi* el, cambio_stato* cambio){
		el->cambio=add_cambiostato(cambio, el->cambio);
		return el;
}
elenchi* add_oper_elenchi(elenchi* el, action* az){
		el->oper=add_azione(az, el->oper);
		return el;
}

cambio_stato* new_cambiostato(event* e, elenco_stati* es){
	cambio_stato* cs=(cambio_stato*) malloc(sizeof(cambio_stato));
	cs->causa=e;
	cs->effetto=es;
	return cs;
}
cambio_stato* add_cambiostato(cambio_stato* cs, cambio_stato* cs2){
	(cs2->causa)->next=cs->causa;
	(cs2->effetto)->next=cs->effetto;
	return cs2;
}
int free_cambiostato(cambio_stato* cs){
	free_evento(cs->causa);
	free_el_stati(cs->effetto);
	free(cs);	
	return 1;
}

stato* new_stato5( String n,action* actions,elenco_cond* el_con, elenchi* cs,cicli* c){
	stato* s=(stato*) malloc(sizeof(stato));
	s->nome=n;
	s->azioni=actions;
	if(cs!=NULL){
		s->eventi=(cs->cambio)->causa;
		s->el_stati=(cs->cambio)->effetto;
		s->azioni=add_azione(cs->oper, s->azioni);
	}
	else{
		s->eventi=NULL;
		s->el_stati=NULL;
	}
	s->el_cond=el_con;
	s->cic=c;
	return s;
}
stato* new_stato4( String n,action* actions, elenco_cond* con, elenchi* cs){
	stato* s=(stato*) malloc(sizeof(stato));
	s->nome=n;
	s->azioni=actions;
	s->eventi=(cs->cambio)->causa;
	s->el_stati=(cs->cambio)->effetto;
	s->azioni=add_azione(cs->oper, s->azioni);
	s->el_cond=con;
	s->cic=NULL;
	return s;
}
stato* new_stato2( String n,action* actions, elenchi* cs){
	stato* s=(stato*) malloc(sizeof(stato));
	s->nome=n;
	s->azioni=actions;
	s->eventi=(cs->cambio)->causa;
	s->el_stati=(cs->cambio)->effetto;
	s->azioni=add_azione(cs->oper, s->azioni);
	s->el_cond=NULL;
	s->cic=NULL;
	return s;
}
stato* new_stato3( String n, action* actions, event *ev, elenco_stati* prox){
	stato* s=(stato*) malloc(sizeof(stato));
	s->nome=n;
	s->azioni=actions;
	s->eventi=ev;
	s->el_stati=prox;
	s->el_cond=NULL;
	s->cic=NULL;
	return s;
}
stato* new_stato1(String n){
	stato* s=(stato*) malloc(sizeof(stato));
	s->nome=n;
	s->azioni=NULL;
	s->eventi=NULL;
	s->el_stati=NULL;
	s->el_cond=NULL;
	s->cic=NULL;
	return s;
}
	
action* new_action(operazioni* a, action* prox){
	action* az=(action*) malloc(sizeof(action));
	az->op=a;
	az->next=prox;
	return az;
}
event* new_evento(evento e, event* prox){
	event* ev=(event*) malloc(sizeof(event));
	ev->value=e;
	ev->next=prox;
	return ev;
}
elenco_stati* new_el_stati(stato* statolista, stato* prox){
	elenco_stati* el=(elenco_stati*) malloc(sizeof(elenco_stati));
	el->value=statolista;
	el->next=new_el_stati1(prox);
	return el;
}
elenco_stati* new_el_stati1(stato* statolista){
	elenco_stati* el=(elenco_stati*) malloc(sizeof(elenco_stati));
	el->value=statolista;
	el->next=NULL;
	return el;
}

action* add_azione(action* a, action* prox){
	action* b=prox;
	while(prox->next!=NULL){
		prox=prox->next;
	}
	prox->next=a;
	return b;
}
event* add_evento(event* e, event* prox){
	e->next=prox;
	return e;
}
elenco_stati* add_el_stati(elenco_stati* statolista, stato* prox){
	elenco_stati* t=new_el_stati(prox, NULL);
	t->next=statolista;
	return t;
}

int free_stato(stato* s){
	free_action(s->azioni);
	free_el_stati(s->el_stati);
	free_evento(s->eventi);
	free(s);
	return 1;
}
int free_action(action* a){
	action* a1=NULL;
	while(a->next!=NULL){
		a1=a->next;
		free(a);
		a=a1;
	}
	return 1;
}
int free_evento(event* e){
	event* a1=NULL;
	while(e->next!=NULL){
		a1=e->next;
		free(e);
		e=a1;
	}
	return 1;
}
int free_el_stati(elenco_stati* statolista){
	elenco_stati* a1=NULL;
	while(statolista->next!=NULL){
		a1=statolista->next;
		free(statolista);
		statolista=a1;
	}
	return 1;
}

assegnazioni* new_assegnazioni(String n,void* v, int tipo){
	assegnazioni* as=(assegnazioni*) malloc(sizeof(assegnazioni));
	as->type=tipo;
	as->nome=n;
	as->value=v;
	as->next=NULL;
	return as;
}
assegnazioni* add_assegnazioni(assegnazioni* as, assegnazioni*as2){
	as2->next=as;
	return as2;
}
int free_assegnazioni(assegnazioni* as){
	assegnazioni* a1=NULL;
	while(as->next!=NULL){
		a1=as->next;
		free(as);
		as=a1;
	}
	return 1;
}

elenco_cond* new_elencocond(cond* condi){
	elenco_cond* el=(elenco_cond*) malloc(sizeof(elenco_cond));
	el->value=condi;
	
	el->next=NULL;
	return el;
}
elenco_cond* add_elencocond(elenco_cond* prim, elenco_cond* sec){
	prim->next=sec;
	return prim;
}
int free_elencocond(elenco_cond* elen){
	elenco_cond* el=NULL;
	while(elen->next!=NULL){
		el=elen->next;
		free(elen);
		elen=el;
	}
	return 1;
}

cond* new_cond(assegnazioni* pr, assegnazioni* sec, int par, elenchi* stat){
	cond* con=(cond*) malloc(sizeof(cond));
	con->primo=pr;
	con->secondo=sec;
	con->paragone=par;
	if(stat!=NULL){
		con->s=stat->cambio;
		con->az=stat->oper;
	}
	else{
		con->s=NULL;
		con->az=NULL;
	}
	free(stat);
	return con;
}
int free_cond(cond* condi){
	free_cambiostato(condi->s);
	free(condi);
	return 1;
}



static unsigned symhash(char *sym){
	unsigned int hash = 0;
	unsigned c;
	while(c = *sym++) hash = hash*9 ^ c;
	return hash;
}

String lookup(char* sym){
	struct symbol *sp = &symtab[symhash(sym)%NHASH];
	int scount = NHASH;
	/* how many have we looked at */
	while(--scount >= 0) {
		if(sp->name && !strcmp(sp->name, sym)) { return strdup(sym); }
		if(!sp->name) {
			sp->name = strdup(sym);
			sp->value = 0;
			sp->func = NULL;
			sp->syms = NULL;
			return strdup(sym);
		}
	if(++sp >= symtab+NHASH) sp = symtab; /* try the next entry */
	}
	yyerror("symbol table overflow\n");
	abort(); /* tried them all, table is full */
}
