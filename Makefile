CFLAGS = -g

all:compilatore

compilatore: flex.lex.o bison.tab.o program.o functions.o
		cc -g -o $@ bison.tab.o flex.lex.o program.o functions.o -lm

flex.lex.o: flex.lex.c bison.tab.h declarations.h

bison.tab.o: bison.tab.c flex.lex.h declarations.h

flex.lex.c flex.lex.h: flex.l
		flex -o flex.lex.c flex.l

bison.tab.c bison.tab.h: bison.y
		bison -vd bison.y
