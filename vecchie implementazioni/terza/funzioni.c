#include <stdio.h>
#include "dichiarazioni.h"
#include <stdlib.h>

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

stato* new_stato4( String n,action* actions, elenco_cond* con){
	stato* s=(stato*) malloc(sizeof(stato));
	s->nome=n;
	s->azioni=actions;
	s->eventi=NULL;
	s->el_stati=NULL;
	s->el_cond=NULL;
	return s;
}
stato* new_stato2( String n,action* actions, cambio_stato* cs){
	stato* s=(stato*) malloc(sizeof(stato));
	s->nome=n;
	s->azioni=actions;
	s->eventi=cs->causa;
	s->el_stati=cs->effetto;
	s->el_cond=NULL;
	return s;
}
stato* new_stato3( String n, action* actions, event *ev, elenco_stati* prox){
	stato* s=(stato*) malloc(sizeof(stato));
	s->nome=n;
	s->azioni=actions;
	s->eventi=ev;
	s->el_stati=prox;
	s->el_cond=NULL;
	return s;
}
stato* new_stato1(String n){
	stato* s=(stato*) malloc(sizeof(stato));
	s->nome=n;
	s->azioni=NULL;
	s->eventi=NULL;
	s->el_stati=NULL;
	s->el_cond=NULL;
	return s;
}
	
action* new_action(azione* a, action* prox){
	action* az=(action*) malloc(sizeof(action));
	az->value=*a;
	az->next=prox;
	return az;
}
event* new_evento(evento* e, event* prox){
	event* ev=(event*) malloc(sizeof(event));
	ev->value=*e;
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

action* add_stato(action* a, action* prox){
	a->next=prox;
	return a;
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
	sec->next=prim;
	return sec;
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

cond* new_cond(assegnazioni* pr, assegnazioni* sec, int par, struct cambio_stato* stat){
	cond* con=(cond*) malloc(sizeof(cond));
	con->primo=pr;
	con->secondo=sec;
	con->paragone=par;
	con->s=stat;
	return con;
}
int free_cond(cond* condi){
	free_cambiostato(condi->s);
	free(condi);
	return 1;
}
