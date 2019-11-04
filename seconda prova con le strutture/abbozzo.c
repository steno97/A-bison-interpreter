//ho scrtto solo la logica da seguire

#include <stdio.h>
#include "dichiarazioni.h"
#include <stdlib.h>
#include <stdarg.h>

elenco_stati* elenco=NULL;
action* az=NULL;
event* eventi=NULL;
event* interrupt=NULL;
elenco_stati* status=NULL;
stato stato0*=NULL;


//funzione che esegue le azioni
int do(){
	//ci sara una chiamata a funzioni già preisposte
}
	
int run(elenco_stati* el){
	*elenco=*el;	
	while(el!=NULL){
		if((el->value)->nome==idle){
			stato0=el->value;
			break;
		}
		el=el->next;
	}	
	while{
		stato0=analisi(stato0);
	}
	return 1;
}


stato* analisi(stato* s){
	action* az=s->azioni;
	while(az->value!=NULL){
		do(az->value);
		az=az->next;
		}
	eventi=s->eventi;
	status=s->el_stati;
	while(eventi!=NULL){
		if(eventi->value==interrupt->value){
			break;
			}
		eventi=eventi->next;
		status=status->next;
		}
	return status->value;
}

void yyerror(char *s, ...){
	va_list ap;
	va_start(ap, s);
	fprintf(stderr, "%d: error: ", yylineno);
	vfprintf(stderr, s, ap);
	fprintf(stderr, "\n");
}

int main(){
	return yyparse();
}
