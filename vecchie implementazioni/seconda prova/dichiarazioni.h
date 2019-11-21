
extern int yylineno; /* from lexer */
void yyerror(char *s, ...);

typedef char*  String;
typedef String evento;
typedef String azione;

typedef struct stato{
	String nome;
	struct action* azioni;
	struct event* eventi;
	struct elenco_stati* el_stati;  
}stato;

typedef struct elenco_stati{
	struct stato* value;
	struct elenco_stati* next;
}elenco_stati;

typedef struct cambio_stato{
	struct event* causa;
	struct elenco_stati* effetto;
}cambio_stato;

typedef struct action{
	azione value;
	struct action* next;
}action;

typedef struct event{
	evento value;
	struct event* next;
}event;

stato* new_stato1(String n);
stato* new_stato2( String n,action* actions, cambio_stato* cs);
stato* new_stato3( String n,action* actions, event *ev, elenco_stati* prox);
action* new_action(azione* a, action* prox);
event* new_evento(evento* e, event* prox);
elenco_stati* new_el_stati(stato* statolista, stato* prox);
elenco_stati* new_el_stati1(stato* statolista);

cambio_stato* new_cambiostato(event* e, elenco_stati* es);
cambio_stato* add_cambiostato(cambio_stato* cs, cambio_stato* cs2);
int free_cambiostato(cambio_stato* cs);



action* add_stato(action* a, action* prox);
event* add_evento(event* e, event* prox);
elenco_stati* add_el_stati(elenco_stati* statolista, stato* prox);


int free_stato(stato* s);
int free_action(action* a);
int free_evento(event* e);
int free_el_stati(elenco_stati* statolista);

/*
devo crere delle funzioni per esaminare il controllo eventi, stati, azioni....
da implementare dopo
*/
