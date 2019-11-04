ho scrtto solo la logica da seguire

stato status*=NULL;
interrupt inter*=NULL;
action action*=NULL;
eventi eventi*=NULL;
stato stato0*=NULL;

//funzione che esegue le azioni
int do(){
	//ci sara una chiamata a funzioni già preisposte
}
	
int analizzastato(status){	
	
	while(action!=NULL){
		do(*action);
		action=action.next;
		}
	while(eventi!=NULL){
		if(eventi*==inter*){
			status*=stato0;
			}
		eventi=eventi.next;
		stato=stato0.next;
		}
	analizzastato(status);
}


/*
void yyerror(char *s, ...)
{
	va_list ap;
	va_start(ap, s);
	fprintf(stderr, "%d: error: ", yylineno);
	vfprintf(stderr, s, ap);
	fprintf(stderr, "\n");
}

int main()
{
	printf("> ");
	return yyparse();
}
*/
