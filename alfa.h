#ifndef _ALFA_H
#define _ALFA_H

#define MAX_LONG_ID 100
#define MAX_TAMANIO_VECTOR 64

/* otros defines */
 /*falta bool*/
typedef struct
{
    char lexema[MAX_LONG_ID+1];
    int tipo;
    int valor_entero;
    int es_direccion;
    int etiqueta;
    int local_scope;
} tipo_atributos;

/* CATEGORIAS*/
#define VARIABLE 1
#define PARAMETER 2
#define FUNCTION 3

/* CLASES */
#define ESCALAR 1

#define VECTOR 3

/* TIPOS */
#define INT 1

#define BOOLEAN 3

#endif