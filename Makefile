CFLAGS= -pedantic -g -Wall

all: y.tab.o lex.yy.o hash.o generacion.o pruebaSintactico.o alfa

lex.yy.c: alfa.l
	flex alfa.l

lex.yy.o: lex.yy.c y.tab.h alfa.h
	gcc -c -o lex.yy.o lex.yy.c

y.tab.c: alfa.y
	bison -d -y -v alfa.y

hash.o: hash.c hash.h 
	gcc $(CFLAGS) -c hash.c

generacion.o: generacion.c generacion.h 
	gcc $(CFLAGS) -c generacion.c

y.tab.o: y.tab.c alfa.h generacion.h hash.h
	gcc $(CFLAGS) -c -o y.tab.o y.tab.c 

pruebaSintactico.o: alfa.h y.tab.h
	gcc $(CFLAGS) -c -o pruebaSintactico.o pruebaSintactico.c 

alfa: generacion.h
	gcc -o alfa generacion.o hash.o lex.yy.o y.tab.o pruebaSintactico.o
	
clean:
	rm -f alfa lex.yy.c y.tab.c y.output hash.o generacion.o pruebaSintactico.o lex.yy.o y.tab.o prg1