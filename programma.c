//ho scrtto solo la logica da seguire

#include <stdio.h>
#include "dichiarazioni.h"
#include "bison.tab.h"
#include "flex.lex.h"
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
FILE * fp;
char * line = NULL;
size_t len = 0;
ssize_t read;
int end_of_file=0;


/*dubbi e perplessita
 * qualche volta dovrò alloracare spazio alle strutture contenute in altre strutture dati!!! ATTENZIONE
 * gli IF sono implementati solo al primo livello
*/

//interruzione del "clock", tempo fittizio ideato da noi
//handler timer 
void timer_handler(int signum){
	if (interruzioni==1){
		return;
	}
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

void evento_handler(int signum){
	if (interruzioni==1 || end_of_file){
		return;
	}
	interruzioni=1;
	if((read = getline(&line, &len, fp)) == -1) {
        interruzioni=0;
        end_of_file=1;
        return;
    }   
	while(eventi!=NULL){
		if(strcmp(eventi->value, line)==0){
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

//funzione che esegue le azioni (da fare)
int do_(operazioni* v){
	switch (v->operatore){
		case 40:{
			if(v->primo!=NULL){
				printf("%s\n",(v->primo)->nome);
				}
			else{ printf("%s",errore);}
			break;
			}
		case 20:{
			assegnazioni* x=as;
			while (x!=NULL){
				if(v->primo->nome==x->nome){
					x->value=(int)tipo(v->secondo)+(int)tipo(v->terzo);
					break;
					}
				x=x->next;
				}
			}	
		case 21:{
			assegnazioni* x=as;
			while (x!=NULL){
				if(v->primo->nome==x->nome){
					x->value=(int)tipo(v->secondo)-(int)tipo(v->terzo);
					break;
					}
				x=x->next;
				}
			}	
		case 22:{
			assegnazioni* x=as;
			while (x!=NULL){
				if(v->primo->nome==x->nome){
					x->value=(int)tipo(v->secondo)*(int)tipo(v->terzo);
					break;
					}
				x=x->next;
				}
			}	
		case 23:{
			assegnazioni* x=as;
			while (x!=NULL){
				if(v->primo->nome==x->nome){
					x->value=(int)tipo(v->secondo)/(int)tipo(v->terzo);
					break;
					}
				x=x->next;
				}
			}	
		
		case 24: {
			assegnazioni* x=as;
			while (x!=NULL){
				if(v->primo->nome==x->nome){
					x->value=x->value+1;
					break;
					}
				x=x->next;
				}
			}	
		case 25:{
			assegnazioni* x=as;
			while (x!=NULL){
				if(v->primo->nome==x->nome){
					x->value=x->value-1;
					break;
					}
				x=x->next;
				}
			}
		case 26:{
			assegnazioni* x=as;
			while (x!=NULL){
				if(v->primo->nome==x->nome){
					x->value=v->value;
					break;
					}
				x=x->next;
				}
			}
	}
	return 1;
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
		do_(az->op);
		az=az->next;
		}

	//analisi dei cicli
	cicli* cicl=s->cic;
	if(cicl!=NULL){
		if(cicl->tipo==1){
			add_assegnazioni(cicl->as, as);
		}
		while(confronto(cicl->con)){
			az=cicl->az;
			while(az!=NULL){
				do_(az->op);
				az=az->next;
			}
			
			
		condi=cicl->condi;
		while(condi!=NULL){
			if(confronto(condi->value)){
				az=(condi->value)->az;
				while(az!=NULL){
					do_(az->op);
					az=az->next;
				}
				eventi=((condi->value)->s)->causa;
				status=((condi->value)->s)->effetto;
				while(interruzioni==0){
					}
				trovato=1;
				break;
				}
			condi=condi->next;
		}
		if(cicl->el!=NULL && !(trovato)){
			eventi=((cicl->el)->cambio)->causa;
			status=((cicl->el)->cambio)->effetto;
			while(interruzioni==0){
			}
		}
	}
	
	
	condi=s->el_cond;
	while(condi!=NULL){
		if(confronto(condi->value)){
			az=(condi->value)->az;
			while(az!=NULL){
				do_(az->op);
				az=az->next;
			}
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
		
	////////////////////////////////////////////////////////////////////
	//inizializzazione lettura file
    fp = fopen("eventi.txt", "r");
    if (fp == NULL){
        printf("errore nell'apertura file");
	}
    	
	////////////////////////////////////////////////////////////////////	
	// 1° interrupt	
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


	///////////////////////////////////////////////////////////////////
	//2° interrupt
	struct sigaction sa1;
	struct itimerval timer1;

	/* Install timer_handler as the signal handler for SIGVTALRM. */
	memset (&sa1, 0, sizeof (sa1));
	sa1.sa_handler = &evento_handler;
	sigaction (SIGVTALRM, &sa1, NULL);

	/* Configure the timer to expire after 500 msec... */
	timer1.it_value.tv_sec = 0;
	timer1.it_value.tv_usec = 50000;
	/* ... and every 500 msec after that. */
	timer1.it_interval.tv_sec = 0;
	timer1.it_interval.tv_usec = 500000;
	/* Start a virtual timer. It counts down whenever this process is
	executing. */
	setitimer (ITIMER_VIRTUAL, &timer1, NULL);
	
	////////////////////////////////////////////////////////////////////
	int flag=0;
	flag = yyparse();
    fclose(yyin);
    fclose(fp);
    if (line){
        free(line);
	}
    return flag;
}




