%{
# include "bisonfile.h"
%}

%%
"global_variables"		{ return VAR; }
"events"				{ return EVENT; }
"commands"				{ return COMMAND; }
"state"					{ return STATE; }
"actions"				{ return ACTION; }

"byte"|"BYTE"			{ return BYTE; } 
"char"|"CHAR"           { return CHAR; }
"int"|"INT"             { return INT; }
"float"|"FLOAT"         { return FLOAT; }
"double"|"DOUBLE"       { return DOUBLE; }
"if"|"IF"               { return IF; }
"else"|"ELSE"           { return ELSE; }
"void"|"VOID"           { return VOID; }
[0-9]+ 					{ return NUMBER; }
([a-z]+[_a-z0-9]*)		{ return ALPHA; }

"+"	                    { return ADD; }
"-"						{ return SUB; }
"*"                     { return MUL; }
"/"                     { return DIV; }
"++""	                { return INCR; }
"--"					{ returd DECR;}  
"||"                    { return OR; }
"&&"                    { return AND; }
"!"                     { return NOT; }
"=="	                { return EQU; }
"!="					{ return NOTEQU; }	
">"	        			{ return MAJ; }
"<"						{ return LOV; }
">="					{ return MAJEQU; }
"<="					{ return LOVEQU; }

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
"#"				{ return COMMENT; }
"=>"			{ return CHANGESTATE; }
.              	{printf("Unknown token!n"); yyterminate();}

%%
