
extern int yylineno; /* from lexer */
void yyerror(char *s, ...);
extern int yyparse();
extern FILE *yyin;
extern int yylex();

typedef char*  String;
typedef String evento;
typedef String azione;

typedef struct assegnazioni{
	int type;
	String nome;
	void* value;
	struct assegnazioni* next;
}assegnazioni;

typedef struct cond{
	assegnazioni* primo;
	assegnazioni* secondo;
	int paragone;
	struct cambio_stato* s;
}cond;

typedef struct elenco_cond{
	struct cond* value;
	struct elenco_cond* next;
}elenco_cond;

typedef struct stato{
	String nome;
	struct action* azioni;
	struct event* eventi;
	struct elenco_cond* el_cond;
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



assegnazioni* new_assegnazioni( String n, void* v, int tipo);
assegnazioni* add_assegnazioni(assegnazioni* as, assegnazioni* as2);
int free_assegnazioni(assegnazioni* as);


stato* new_stato1(String n);
stato* new_stato2( String n,action* actions, cambio_stato* cs);
stato* new_stato3( String n,action* actions, event *ev, elenco_stati* prox);
stato* new_stato4( String n,action* actions, elenco_cond* con);

action* new_action(azione* a, action* prox);
event* new_evento(evento* e, event* prox);
elenco_stati* new_el_stati(stato* statolista, stato* prox);
elenco_stati* new_el_stati1(stato* statolista);

cambio_stato* new_cambiostato(event* e, elenco_stati* es);
cambio_stato* add_cambiostato(cambio_stato* cs, cambio_stato* cs2);
int free_cambiostato(cambio_stato* cs);

elenco_cond* new_elencocond(cond* condi);
elenco_cond* add_elencocond(elenco_cond* prim, elenco_cond* sec);
int free_elencocond(elenco_cond* elen);

cond* new_cond(assegnazioni* pr, assegnazioni* sec, int par, struct cambio_stato* stat);
int free_cond(cond* condi);

action* add_stato(action* a, action* prox);
event* add_evento(event* e, event* prox);
elenco_stati* add_el_stati(elenco_stati* statolista, stato* prox);


int free_stato(stato* s);
int free_action(action* a);
int free_evento(event* e);
int free_el_stati(elenco_stati* statolista);
