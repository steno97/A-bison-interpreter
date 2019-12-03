%{
#include "bison.tab.h"
#include "dichiarazioni.h"
%}

%%
"global_variables"		{ return VAR; }
"events"				{ return EVENT; }
"commands"				{ return COMMAND; }
"state"					{ return STATE; }
"actions"				{ return ACTION; }

"char"|"CHAR"           { yylval->fn = 10; return TYPE; }
"int"|"INT"             { yylval->fn = 11; return TYPE; }
"float"|"FLOAT"         { yylval->fn = 12; return TYPE; }
"double"|"DOUBLE"       { yylval->fn = 13; return TYPE; }
"void"|"VOID"           { yylval->fn = 14; return TYPE; }
/* String codice 15*/
"if"|"IF"               { return IF; }
"elif"|"ELIF"           { return ELIF; }
"else"|"ELSE"           { return ELSE; }
[0-9]+ 					{ return NUMBER; }
([a-z]+[_a-z0-9]*)		{ return ALPHA; }

"+"	                    { return ADD; }
"-"						{ return SUB; }
"*"                     { return MUL; }
"/"                     { return DIV; }
"++""	                { return INCR; }
"--"					{ returd DECR;}  
"!"                     { return NOT; }
">" 			{ yylval->fn = 1; return CMP; }
"<" 			{ yylval->fn = 2; return CMP; }
"!=" 			{ yylval->fn = 3; return CMP; }
"==" 			{ yylval->fn = 4; return CMP; }
">=" 			{ yylval->fn = 5; return CMP; }
"<=" 			{ yylval->fn = 6; return CMP; }
"&&"			{ yylval->fn = 7; return CMP; }
"||"			{ yylval->fn = 8; return CMP; }

"("             { return LPAREN; }
")"             { return RPAREN; }
"]"             { return LBRACK; }
"["             { return RBRACK; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
";"             { return SEMI; }
","             { return COMMA; }
"="             { return ASSIGN; }
"&"             { return REFER; }
"\n"			{ return NEWLINE; }
"\t"			{ return SPACE; }
"#"				{ return COMMENT; }
"=>"			{ return CHANGESTATE; }
.              	{printf("Unknown token!n"); yyterminate();}

%%
