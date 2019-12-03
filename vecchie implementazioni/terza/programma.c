//ho scrtto solo la logica da seguire

#include <stdio.h>
#include "dichiarazioni.h"
#include <stdlib.h>
#include <stdarg.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>

int trovato=0;
int variabile=0;
elenco_cond* condi=NULL;
assegnazioni* as=NULL;
elenco_stati* elenco=NULL;
action* az=NULL;
event* eventi=NULL;
//event* interrupt=NULL;
int interruzioni=0;
elenco_stati* status=NULL;
stato* stato0=NULL;
String errore="evento non valido per lo stato corrente\n";


/*dubbi e perplessita
 * come creo gli interrupt e come li gestisco 
 * le azioni come le svolgo? creo una funzione per ogni azione possibile e immaginabile?
 * lettura da file fatto ma non so se va bene!?!
 * gestite le condizioni
 * corretti alcuni errori (sicuramente ce ne sono altri)
 * 
*/

//interruzione del "clock", tempo fittizio ideato da noi
//handler timer 
void timer_handler(int signum){
	interruzioni=1;
	while(eventi!=NULL){
		if(eventi->value=="0"){
			stato0=status->value;
			break;
			}
		eventi=eventi->next;
		status=status->next;
		}
}

void evento_handler(void* e){
	interruzioni=0;
	while(eventi!=NULL){
		if(eventi->value==e){
			stato0=status->value;
			break;
			}
		eventi=eventi->next;
		status=status->next;
		}
		if(eventi==NULL){
			printf("errore evento non presente per tale stato");
		}
}

//funzione che esegue le azioni (da fare)
int do_(azione v){
	return 0;
	//ci sara una chiamata a funzioni già preisposte
}

void* tipo(assegnazioni* a){
	switch (a->type){
		case 1: return (char*) a->value;
		case 2: return (int*) a->value;
		case 3: return (float*) a->value;
		case 4: return (double*) a->value;
		case 5: return a->value;
		case 6:{
			assegnazioni* at=as;
			while(at!=NULL && !variabile){
				if(at->nome==((String)a->value))
				{
					variabile=1;
					return tipo(at);
				 }
				 at=at->next;
			}
			return (String) a->value;
		}
	}
}

int confronto(cond* c){
	switch (c->paragone){
		case 1: return tipo(c->primo)> tipo(c->secondo);
		case 2: return tipo(c->primo)< tipo(c->secondo);
		case 3: return tipo(c->primo)!= tipo(c->secondo);
		case 4: return tipo(c->primo)== tipo(c->secondo);
		case 5: return tipo(c->primo)>= tipo(c->secondo);
		case 6:	return tipo(c->primo)<= tipo(c->secondo);
		case 7:	return tipo(c->primo)&& tipo(c->secondo);
		case 8:	return tipo(c->primo)|| tipo(c->secondo);
	}
}

//fatta
stato* analisi(stato* s){
	trovato=0;
	variabile=0;
	interruzioni=0;
	action* az=s->azioni;
	while(az!=NULL){
		do_(az->value);
		az=az->next;
		}
	condi=s->el_cond;
	while(condi!=NULL){
		if(confronto(condi->value)){
			eventi=((condi->value)->s)->causa;
			status=((condi->value)->s)->effetto;
			while(interruzioni==0){
			}
			trovato=1;
			break;
		}
		condi=condi->next;
	}
	if(s->el_stati!=NULL && !(trovato)){
		eventi=s->eventi;
		status=s->el_stati;
		while(interruzioni==0){
		}
	/* se è stata ricevuta un'interruzione da un evento stato0 muta e diventa il nuovo evento,
	 * se l'interruzione è data dallo scadere del tempo allora si possono verificare due situazioni:
	 * 		- o era previsto un cambio di stato allo scadere del tempo e allora stato0 cambierà
	 * 		- o stato0 non muta e si ricomincerà con analisi dello stato0
	 * */
	//cerco in elenco lo stato con il nome uguale a quello che sta in stato0
	//perchè elenco ha una struttura dati completa mentre stato0 possiede solo il nome dello stato
	}
	elenco_stati* el=elenco;	
	while(el!=NULL){
		if((el->value)->nome==stato0->nome){
			stato0=el->value;
			break;
		}
		el=el->next;
	}	
	return stato0;
}


int run(assegnazioni* ass,event* evv,action* azz,elenco_stati* el){
	as=ass;
	elenco=el;	
	while(el!=NULL){
		if((el->value)->nome=="idle"){
			stato0=el->value;
			break;
		}
		el=el->next;
	}	
	while(1){
		stato0=analisi(stato0);
	}
	return 1;
}

//analisi errori bison
void yyerror(char *s, ...){
	va_list ap;
	va_start(ap, s);
	fprintf(stderr, "%d: error: ", yylineno);
	vfprintf(stderr, s, ap);
	fprintf(stderr, "\n");
}

//programma principale e configurazione handler
int main(int argc, char **argv){
	if(argc > 1){    
		if(!(yyin = fopen(argv[1], "r"))) {      
			perror(argv[1]);      
			return (1);    
			}  
		}
	struct sigaction sa;
	struct itimerval timer;

	/* Install timer_handler as the signal handler for SIGVTALRM. */
	memset (&sa, 0, sizeof (sa));
	sa.sa_handler = &timer_handler;
	sigaction (SIGVTALRM, &sa, NULL);

	/* Configure the timer to expire after 500 msec... */
	timer.it_value.tv_sec = 0;
	timer.it_value.tv_usec = 90000;
	/* ... and every 500 msec after that. */
	timer.it_interval.tv_sec = 0;
	timer.it_interval.tv_usec = 900000;
	/* Start a virtual timer. It counts down whenever this process is
	executing. */
	setitimer (ITIMER_VIRTUAL, &timer, NULL);
	int flag=0;
	flag = yyparse();
    fclose(yyin);
    
    return flag;
}
