
extern int yylineno; /* from lexer */
//void yyerror(char *s, ...);
extern int yyparse();
extern FILE *yyin;
extern int yylex();
union YYSTYPE yylval;

typedef char* String;
typedef char* evento;



//lettura di stringhe
struct symbol {
	/* a variable name */
	char *name;
	double value;
	struct ast *func;
	/* stmt for the function */
	struct symlist *syms; /* list of dummy args */

};
/* simple symtab of fixed size */
#define NHASH 9997
struct symbol symtab[NHASH];
/* list of symbols, for an argument list */
struct symlist {
	struct symbol *sym;
	struct symlist *next;
};

static unsigned symhash(char *sym);
String lookup(char* sym);

//lettura di stringhe






union YYSTYPE{
	int fn;
	String c;
	struct assegnazioni* as;
	struct operazioni* op;
	struct cond* con;
	struct elenco_cond* elen_con;
	struct stato* stat;
	struct elenco_stati* elen_stat;
	struct cambio_stato* camb_stat;
	struct action* azione;
	struct event* even;
	struct elenchi* elen;
	struct cicli* cic;
};
 


typedef struct assegnazioni{
	int type;
	String nome;
	void* value;
	struct assegnazioni* next;
}assegnazioni;

typedef struct operazioni{
	struct assegnazioni* primo;
	struct assegnazioni* secondo;
	struct assegnazioni* terzo;
	int operatore;
	int value;
}operazioni;

typedef struct cond{
	struct assegnazioni* primo;
	struct assegnazioni* secondo;
	int paragone;
	struct cambio_stato* s;
	struct action* az;
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
	struct cicli* cic;
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
	operazioni* op;
	struct action* next;
}action;

typedef struct event{
	evento value;
	struct event* next;
}event;

typedef struct elenchi{
	struct action* oper;
	struct cambio_stato* cambio;
}elenchi;

typedef struct cicli{
	int tipo;
	assegnazioni* as;
	elenco_cond* condi;
	elenchi* el;
	action* az;
	cond* con;
}cicli;

//creare funzioni per i cicli
cicli* new_cicli(int t, assegnazioni* asse, elenco_cond* con, action* a, cond* co);
cicli* new_cicli1(int t, assegnazioni* asse, elenchi* el, action* a, cond* co);
int free_cicli(cicli* c);

//creare il new stato per il ciclo
stato* new_stato5( String n,action* actions, elenco_cond* el_con,elenchi* cs,cicli* c);


int run(assegnazioni* ass,event* evv,event* azz,elenco_stati* el);

elenchi* new_elenchi( action* opera, cambio_stato* cambios);
elenchi* add_cambio_elenchi( elenchi* el, cambio_stato* cambio);
elenchi* add_oper_elenchi(elenchi* el, action* az);
int free_elenchi(elenchi* op);

operazioni* new_operazione( assegnazioni* pr, assegnazioni* sec, assegnazioni* ter, int operatore, int v);
int free_operazioni(operazioni* op);


assegnazioni* new_assegnazioni( String n, void* v, int tipo);
assegnazioni* add_assegnazioni(assegnazioni* as, assegnazioni* as2);
int free_assegnazioni(assegnazioni* as);


stato* new_stato1(String n);
stato* new_stato2( String n,action* actions, elenchi* cs);
stato* new_stato3( String n,action* actions, event *ev, elenco_stati* prox);
stato* new_stato4( String n,action* actions, elenco_cond* con, elenchi* cs);

action* new_action(operazioni* a, action* prox);
event* new_evento(evento e, event* prox);
elenco_stati* new_el_stati(stato* statolista, stato* prox);
elenco_stati* new_el_stati1(stato* statolista);

cambio_stato* new_cambiostato(event* e, elenco_stati* es);
cambio_stato* add_cambiostato(cambio_stato* cs, cambio_stato* cs2);
int free_cambiostato(cambio_stato* cs);

elenco_cond* new_elencocond(cond* condi);
elenco_cond* add_elencocond(elenco_cond* prim, elenco_cond* sec);
int free_elencocond(elenco_cond* elen);

cond* new_cond(assegnazioni* pr, assegnazioni* sec, int par, elenchi* stat);
int free_cond(cond* condi);

action* add_azione(action* a, action* prox);
event* add_evento(event* e, event* prox);
elenco_stati* add_el_stati(elenco_stati* statolista, stato* prox);


int free_stato(stato* s);
int free_action(action* a);
int free_evento(event* e);
int free_el_stati(elenco_stati* statolista);
