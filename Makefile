CFLAGS= -pedantic -g

all: generacion.o hash.o y.tab.c y.tab.o lex.yy.c lex.yy.o alfa.o alfa

lex.yy.c: alfa.l
	flex alfa.l

lex.yy.o: lex.yy.c y.tab.h
	gcc -c -o lex.yy.o lex.yy.c

y.tab.c: alfa.y
	bison -d -y -v alfa.y

hash.o: hash.c hash.h 
	gcc $(CFLAGS) -c hash.c

generacion.o: generacion.c generacion.h 
	gcc $(CFLAGS) -c generacion.c

y.tab.o: y.tab.c
	gcc $(CFLAGS) -c -o y.tab.o y.tab.c 

alfa.o: alfa.c y.tab.h
	gcc -Wall -ansi -pedantic -c -o alfa.o alfa.c

alfa: generacion.h
	gcc -o alfa generacion.o hash.o lex.yy.o y.tab.o alfa.o

clean:
	rm -f alfa  *.o lex.yy.c y.tab.c y.output hash.o generacion.o