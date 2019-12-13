%option header-file="flex.lex.h"
%option noyywrap
%{
#include "bison.tab.h"
#include "dichiarazioni.h"
%}

%%
"global_variables"	{ return VAR; }
"events"	{ return EVENT; }
"commands"				{ return COMMAND; }
"state"					{ return STATE; }
"actions"				{ return ACTION; }

"char"	{ yylval.fn = 10; return TYPE; }
"int"	{ yylval.fn = 11; return TYPE; }
"float"	{ yylval.fn = 12; return TYPE; }
"double" { yylval.fn = 13; return TYPE; }
"void"	{ yylval.fn = 14; return TYPE; }

"if"|"IF"               { return IF; }
"elif"|"ELIF"           { return ELIF; }
"else"|"ELSE"           { return ELSE; }
"for"|"FOR"				{ return FOR; }
"while"|"WHILE"			{ return WHILE; }

"inc"	                { yylval.fn = 24; return OPERATORE; }
"dec"					{ yylval.fn = 25; return OPERATORE; }
"set"					{ yylval.fn = 26; return OPERATORE; } 
print_schermo_message	{ yylval.fn = 40; return PRINT; }

[0-9]+ 					{ return NUMBER; }
([a-z]+['_a-z0-9]*)		{ return ALPHA; }

"+"	                    { yylval.fn = 20; return OPERATORE; }
"-"						{ yylval.fn = 21; return OPERATORE; }
"*"                    	{ yylval.fn = 22; return OPERATORE; }
"/"                     { yylval.fn = 23; return OPERATORE; }

">" 			{ yylval.fn = 1; return CMP; }
"<" 			{ yylval.fn = 2; return CMP; }
"!=" 			{ yylval.fn = 3; return CMP; }
"==" 			{ yylval.fn = 4; return CMP; }
">=" 			{ yylval.fn = 5; return CMP; }
"<=" 			{ yylval.fn = 6; return CMP; }
"&&"			{ yylval.fn = 7; return CMP; }
"||"			{ yylval.fn = 8; return CMP; }

"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
";"             { return SEMI; }
","             { return COMMA; }
"="             { return ASSIGN; }

"//".*
[ \t ]
\\\n

"\r"			
"#"				{ return COMMENT; }
"=>"			{ return CHANGESTATE; }
"$end"     		{return ENFILE; exit(0);}
.              	{ yyerror("Mystery character %c\n", *yytext); printf("Unknown token!\n"); yyterminate();}
<<EOF>>         { exit(0); }

%%
