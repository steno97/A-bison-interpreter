CFLAGS = -g

all:compilatore

compilatore: flex.lex.o bison.tab.o programma.o funzioni.o
		cc -g -o $@ bison.tab.o flex.lex.o programma.o funzioni.o -lm

flex.lex.o: flex.lex.c bison.tab.h dichiarazioni.h

bison.tab.o: bison.tab.c flex.lex.h dichiarazioni.h

flex.lex.c flex.lex.h: flex.l
		flex -o flex.lex.c flex.l

bison.tab.c bison.tab.h: bison.y
		bison -vd bison.y
