#include <stdlib.h>
#include "generacion.h"

int global_counter = 0;
int continue_counter = 0;
/* OBSERVACIÓN GENERAL A TODAS LAS FUNCIONES:
Todas ellas escriben el código NASM a un FILE* proporcionado como primer
argumento.
*/

void escribir_cabecera_bss(FILE *fpasm)
{
    if (fpasm == NULL)
    {
        printf("Error: insert a open file.\n");

        return;
    }

    fprintf(fpasm, ";escribir_cabecera_bss\n");
    fprintf(fpasm, "segment .bss\n\t__esp resd 1\n");
}
/*
Código para el principio de la sección .bss.
Con seguridad sabes que deberás reservar una variable entera para guardar el
puntero de pila extendido (esp). Se te sugiere el nombre __esp para esta variable.
*/
void escribir_subseccion_data(FILE *fpasm)
{
    if (fpasm == NULL)
    {
        printf("Error: insert a open file.\n");

        return;
    }

    fprintf(fpasm, ";escribir_subseccion_data\n");
    fprintf(fpasm, "segment .data\n");
    fprintf(fpasm, "	msg_error_indice_vector db \"Indice de vector fuera de rango\", 0\n");
    fprintf(fpasm, "	msg_error_division db \"Error division por 0\", 0\n");
}   


/*
Declaración (con directiva db) de las variables que contienen el texto de los
mensajes para la identificación de errores en tiempo de ejecución.
En este punto, al menos, debes ser capaz de detectar la división por 0.
*/

void declarar_variable(FILE *fpasm, char *nombre, int tipo, int tamano)
{

    if (fpasm == NULL)
    {
        printf("Error: insert a open file.\n");
        return;
    }

    if (nombre == NULL || tipo < 0 || tamano < 0)
    {
        printf("Error: wrong arguments\n");
    }

    /*BOOLEANO*/
    fprintf(fpasm, ";declarar_variable\n");
    if (tipo)
    {
        fprintf(fpasm, "\t_%s resd %d\n", nombre, tamano);
    }
    else if (tipo == 0)
    { /*ENTERO*/
        fprintf(fpasm, "\t_%s resd %d\n", nombre, tamano);
    }

    return;
}

/*
 Para ser invocada en la sección .bss cada vez que se quiera declarar una
variable:
- El argumento nombre es el de la variable.
- tipo puede ser ENTERO o BOOLEANO (observa la declaración de las constantes
del principio del fichero).
- Esta misma función se invocará cuando en el compilador se declaren
vectores, por eso se adjunta un argumento final (tamano) que para esta
primera práctica siempre recibirá el valor 1.
*/

void escribir_segmento_codigo(FILE *fpasm)
{
    if (fpasm == NULL)
    {
        printf("Error: insert a open file.\n");
        return;
    }

    /**	global main
	extern malloc, free
	extern scan_int, print_int, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string*/

    fprintf(fpasm, ";escribir_segmento_codigo\n");
    fprintf(fpasm, "segment .text\n");
    fprintf(fpasm, "\tglobal main\n");
    fprintf(fpasm, "\textern malloc, free\n");
    fprintf(fpasm, "\textern scan_int, print_int, scan_boolean, print_boolean\n");
    fprintf(fpasm, "\textern print_endofline, print_blank, print_string\n");
}

/*
Para escribir el comienzo del segmento .text, básicamente se indica que se
exporta la etiqueta main y que se usarán las funciones declaradas en la librería
alfalib.o
*/

void escribir_inicio_main(FILE *fpasm)
{

    if (fpasm == NULL)
    {
        printf("Error: insert a open file.\n");
        return;
    }

    fprintf(fpasm, "main:\n");
    fprintf(fpasm, "\tmov dword [__esp], esp\n");
    
}
/*
En este punto se debe escribir, al menos, la etiqueta main y la sentencia que
guarda el puntero de pila en su variable (se recomienda usar __esp).
*/

void escribir_fin(FILE *fpasm)
{
    if (fpasm == NULL)
    {
        printf("Error: insert a open file.\n");
        return;
    }

    fprintf(fpasm, "\tjmp end\n\n");
    fprintf(fpasm, "div_error:\n");
    fprintf(fpasm, "\tpush div_error_message\n");
    fprintf(fpasm, "\tcall print_string\n");
    fprintf(fpasm, "\tadd esp, 4\n");
    fprintf(fpasm, "\tcall print_endofline\n");
    fprintf(fpasm, "\tadd esp, 4\n");
    fprintf(fpasm, "\tjmp end\n\n");
    
    fprintf(fpasm, "rango_error:\n");
    fprintf(fpasm, "\tpush fin_indice_fuera_rango\n");
    fprintf(fpasm, "\tcall print_string\n");
    fprintf(fpasm, "\tadd esp, 4\n");
    fprintf(fpasm, "\tcall print_endofline\n");
    fprintf(fpasm, "\tadd esp, 4\n");
    fprintf(fpasm, "\tjmp end\n\n");

    fprintf(fpasm, "end:\n");
    fprintf(fpasm, "\tmov esp, [__esp]\n");
    fprintf(fpasm, "\tret\n");

    return;
}
/* IMPO: This function will be explained after vectors, (in the last slides)
Al final del programa se escribe:
- El código NASM para salir de manera controlada cuando se detecta un error
en tiempo de ejecución (cada error saltará a una etiqueta situada en esta
zona en la que se imprimirá el correspondiente mensaje y se saltará a la
zona de finalización del programa).
- En el final del programa se debe:
·Restaurar el valor del puntero de pila (a partir de su variable __esp)
·Salir del programa (ret).
*/

void escribir_operando(FILE *fpasm, char *nombre, int es_variable)
{

    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (nombre == NULL || es_variable > 1 || es_variable < 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    if (es_variable)
    {
        fprintf(fpasm, "\n\tmov eax, _%s\n", nombre);
        fprintf(fpasm, "\tpush dword eax\n");
        return;
    }
    
    fprintf(fpasm, "\n\tmov eax, %d\n", atoi(nombre));
    fprintf(fpasm, "\tpush dword eax\n");
    return;
}
/* 
Función que debe ser invocada cuando se sabe un operando de una operación
aritmético-lógica y se necesita introducirlo en la pila.
- nombre es la cadena de caracteres del operando tal y como debería aparecer
en el fuente NASM
- es_variable indica si este operando es una variable (como por ejemplo b1)
con un 1 u otra cosa (como por ejemplo 34) con un 0. Recuerda que en el
primer caso internamente se representará como _b1 y, sin embargo, en el
segundo se representará tal y como esté en el argumento (34).
*/
void asignar(FILE *fpasm, char *nombre, int es_variable)
{

    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (nombre == NULL || es_variable > 1 || es_variable < 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tpop dword eax\n");
    if (es_variable)
    {
        fprintf(fpasm, "\tmov dword _%s, eax\n\n", nombre);

        return;
    }

    fprintf(fpasm, "\tmov dword [_%s], eax\n", nombre);

    return;
}
/*
- Genera el código para asignar valor a la variable de nombre nombre.
- Se toma el valor de la cima de la pila.
- El último argumento es el que indica si lo que hay en la cima de la pila es
una referencia (1) o ya un valor explícito (0).
*/

/* FUNCIONES ARITMÉTICO-LÓGICAS BINARIAS */
/*
En todas ellas se realiza la operación como se ha resumido anteriormente:
- Se extrae de la pila los operandos
- Se realiza la operación
- Se guarda el resultado en la pila
Los dos últimos argumentos indican respectivamente si lo que hay en la pila es
una referencia a un valor o un valor explícito.

Deben tenerse en cuenta las peculiaridades de cada operación. En este sentido
sí hay que mencionar explícitamente que, en el caso de la división, se debe
controlar si el divisor es “0” y en ese caso se debe saltar a la rutina de error
controlado (restaurando el puntero de pila en ese caso y comprobando en el retorno
que no se produce “Segmentation Fault”)
*/
void sumar(FILE *fpasm, int es_variable_1, int es_variable_2)
{

    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (es_variable_1 > 1 || es_variable_1 < 0 || es_variable_2 > 1 || es_variable_2 < 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tpop dword ebx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable_1)
    {
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }

    if (es_variable_2)
    {
        fprintf(fpasm, "\tmov ebx, [ebx]\n");
    }

    fprintf(fpasm, "\tadd eax, ebx\n");
    fprintf(fpasm, "\tpush dword eax\n\n");

    return;
}

void restar(FILE *fpasm, int es_variable_1, int es_variable_2)
{

    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (es_variable_1 > 1 || es_variable_1 < 0 || es_variable_2 > 1 || es_variable_2 < 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tpop dword ebx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable_1)
    {
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }

    if (es_variable_2)
    {
        fprintf(fpasm, "\tmov ebx, [ebx]\n");
    }

    fprintf(fpasm, "\tsub eax, ebx\n");
    fprintf(fpasm, "\tpush dword eax\n\n");

    return;
}

void multiplicar(FILE *fpasm, int es_variable_1, int es_variable_2)
{

    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (es_variable_1 > 1 || es_variable_1 < 0 || es_variable_2 > 1 || es_variable_2 < 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tpop dword ecx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable_1)
    {
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }

    if (es_variable_2)
    {
        fprintf(fpasm, "\tmov ecx, [ecx]\n");
    }

    fprintf(fpasm, "\timul ecx\n");
    fprintf(fpasm, "\tmov edx, 0\n");
    fprintf(fpasm, "\tpush dword eax\n\n");

    return;
}

void dividir(FILE *fpasm, int es_variable_1, int es_variable_2)
{
    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (es_variable_1 > 1 || es_variable_1 < 0 || es_variable_2 > 1 || es_variable_2 < 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tpop dword ecx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable_1)
    {
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }

    if (es_variable_2)
    {
        fprintf(fpasm, "\tmov ecx, [ecx]\n");
    }

    fprintf(fpasm, "\tcdq\n");
    fprintf(fpasm, "\tcmp ecx, 0\n");
    fprintf(fpasm, "\tje div_error\n");

    fprintf(fpasm, "\tidiv ecx\n");
    fprintf(fpasm, "\tpush dword eax\n\n");

    return;
}

void o(FILE *fpasm, int es_variable_1, int es_variable_2)
{

    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }
    if (es_variable_1 < 0 || es_variable_2 < 0 || es_variable_1 > 1 || es_variable_2 > 1)
    {
        printf("Error: Wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tpop dword edx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable_1)
    {
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }

    if (es_variable_2)
    {
        fprintf(fpasm, "\tmov edx, [edx]\n");
    }

    fprintf(fpasm, "\tor eax, edx\n");
    /* true as 1 and false as 0 */
    fprintf(fpasm, "\tpush dword eax\n\n");

    return;
}

void y(FILE *fpasm, int es_variable_1, int es_variable_2)
{

    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (es_variable_1 < 0 || es_variable_2 < 0 || es_variable_1 > 1 || es_variable_2 > 1)
    {
        printf("Error: Wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tpop dword edx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable_1)
    {
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }

    if (es_variable_2)
    {
        fprintf(fpasm, "\tmov edx, [edx]\n");
    }

    fprintf(fpasm, "\tand eax, edx\n");
    /* true as 1 and false as 0 */
    fprintf(fpasm, "\tpush dword eax\n\n");

    return;
}

void cambiar_signo(FILE *fpasm, int es_variable)
{

    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (es_variable < 0 || es_variable > 1)
    {
        printf("Error: Wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tpop dword ebx\n");

    if (es_variable)
    {
        fprintf(fpasm, "\tmov ebx, [ebx]\n");
    }

    fprintf(fpasm, "\tmov dword eax, -1\n");
    fprintf(fpasm, "\tmov edx, 0\n");
    fprintf(fpasm, "\timul ebx\n");
    fprintf(fpasm, "\tpush dword eax\n\n");

    return;
}
/*
Función aritmética de cambio de signo.
Es análoga a las binarias, excepto que sólo requiere de un acceso a la pila ya
que sólo usa un operando.
*/
void no(FILE *fpasm, int es_variable, int cuantos_no)
{

    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (cuantos_no < 0 || es_variable > 1 || es_variable < 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }
    
    fprintf(fpasm, "\tpop dword eax\n");

    if(es_variable) {
        fprintf(fpasm, "\tmov dword eax, [eax]\n");
    }

    fprintf(fpasm, "\tcmp dword eax, 0\n");
    fprintf(fpasm, "\tjz yes%d\n", cuantos_no);
    fprintf(fpasm, "\tmov dword eax, 0\n");
    fprintf(fpasm, "\tjmp continue%d\n", cuantos_no);
    fprintf(fpasm, "\nyes%d:\n", cuantos_no);
    fprintf(fpasm, "\tmov dword eax, 1\n");
    fprintf(fpasm, "continue%d:\n\n", cuantos_no);
    fprintf(fpasm, "\tpush dword eax\n\n");
}
/* IMPO: The labels (etiquetas) will be explained in the flow control slides…
Función monádica lógica de negación. No hay un código de operación de la ALU
que realice esta operación por lo que se debe codificar un algoritmo que, si
encuentra en la cima de la pila un 0 deja en la cima un 1 y al contrario.
El último argumento es el valor de etiqueta que corresponde (sin lugar a dudas,
la implementación del algoritmo requerirá etiquetas). Véase en los ejemplos de
programa principal como puede gestionarse el número de etiquetas cuantos_no.
*/

/*
si top stack == 0
push 1
si top stack ==1
push 0

pop dword eax
cmp eax, 0
jnz not0

mov eax, 1
push dword eax
jmp continue

not0:
    mov dword eax, 0
    push eax

continue:
---------------------loooooop
pop dword eax
cmp eax, 0
jnz not1

mov eax, 1
push dword eax

not1:
    mov dword eax, 0
    push eax

*/

/*
!!x
pop dword eax
cmp eax, 0
jz countX

mov eax, 0
push eax
jmp endX

countX: mov eax, 1
push eax

endX:

*/

/* FUNCIONES COMPARATIVAS */
/*
Todas estas funciones reciben como argumento si los elementos a comparar son o
no variables. El resultado de las operaciones, que siempre será un booleano (“1”
si se cumple la comparación y “0” si no se cumple), se deja en la pila como en el
resto de operaciones. Se deben usar etiquetas para poder gestionar los saltos
necesarios para implementar las comparaciones.
*/
void igual(FILE *fpasm, int es_variable1, int es_variable2, int etiqueta)
{
    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (es_variable1 < 0 || es_variable2 < 0 || es_variable1 > 1 || es_variable2 > 1 || etiqueta < 0)
    {
        printf("Error: Wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tpop dword ebx\n");
    fprintf(fpasm, "\tpop dword eax\n");
    if (es_variable1)
    {
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }
    if (es_variable2)
    {
        fprintf(fpasm, "\tmov ebx, [ebx]\n");
    }

    fprintf(fpasm, "\tcmp eax, ebx\n");
    fprintf(fpasm, "\tjz near etiqueta%d\n", etiqueta);
    fprintf(fpasm, "\tpush dword 0\n");
    fprintf(fpasm, "\tjmp end%d\n\n", etiqueta);
    fprintf(fpasm, "etiqueta%d:\n", etiqueta);
    fprintf(fpasm, "\tpush dword 1\n\n");
    fprintf(fpasm, "end%d:\n\n", etiqueta);

    return;
}

void distinto(FILE *fpasm, int es_variable1, int es_variable2, int etiqueta)
{
    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (es_variable1 < 0 || es_variable2 < 0 || es_variable1 > 1 || es_variable2 > 1 || etiqueta < 0)
    {
        printf("Error: Wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tpop dword ebx\n");
    fprintf(fpasm, "\tpop dword eax\n");
    if (es_variable1)
    {
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }
    if (es_variable2)
    {
        fprintf(fpasm, "\tmov ebx, [ebx]\n");
    }

    fprintf(fpasm, "\tcmp eax, ebx\n");
    fprintf(fpasm, "\tjne near etiqueta%d\n", etiqueta);
    fprintf(fpasm, "\tpush dword 0\n");
    fprintf(fpasm, "\tjmp end%d\n\n", etiqueta);
    fprintf(fpasm, "etiqueta%d:\n", etiqueta);
    fprintf(fpasm, "\tpush dword 1\n\n");
    fprintf(fpasm, "end%d:\n\n", etiqueta);

    return;
}

void menor_igual(FILE *fpasm, int es_variable1, int es_variable2, int etiqueta)
{
    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (es_variable1 < 0 || es_variable2 < 0 || es_variable1 > 1 || es_variable2 > 1 || etiqueta < 0)
    {
        printf("Error: Wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tpop dword ebx\n");
    fprintf(fpasm, "\tpop dword eax\n");
    if (es_variable1)
    {
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }
    if (es_variable2)
    {
        fprintf(fpasm, "\tmov ebx, [ebx]\n");
    }

    fprintf(fpasm, "\tcmp eax, ebx\n");
    fprintf(fpasm, "\tjle near etiqueta%d\n", etiqueta);
    fprintf(fpasm, "\tpush dword 0\n");
    fprintf(fpasm, "\tjmp end%d\n\n", etiqueta);
    fprintf(fpasm, "etiqueta%d:\n", etiqueta);
    fprintf(fpasm, "\tmov dword eax, 1\n");
    fprintf(fpasm, "\tpush dword eax\n\n");
    fprintf(fpasm, "end%d:\n\n", etiqueta);

    return;
}

void mayor_igual(FILE *fpasm, int es_variable1, int es_variable2, int etiqueta)
{
    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (es_variable1 < 0 || es_variable2 < 0 || es_variable1 > 1 || es_variable2 > 1 || etiqueta < 0)
    {
        printf("Error: Wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tpop dword ebx\n");
    fprintf(fpasm, "\tpop dword eax\n");
    if (es_variable1)
    {
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }
    if (es_variable2)
    {
        fprintf(fpasm, "\tmov ebx, [ebx]\n");
    }

    fprintf(fpasm, "\tcmp eax, ebx\n");
    fprintf(fpasm, "\tjge near etiqueta%d\n", etiqueta);
    fprintf(fpasm, "\tpush dword 0\n");
    fprintf(fpasm, "\tjmp end%d\n\n", etiqueta);
    fprintf(fpasm, "etiqueta%d:\n", etiqueta);
    fprintf(fpasm, "\tpush dword 1\n\n");
    fprintf(fpasm, "end%d:\n\n", etiqueta);

    return;
}

void menor(FILE *fpasm, int es_variable1, int es_variable2, int etiqueta)
{
    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (es_variable1 < 0 || es_variable2 < 0 || es_variable1 > 1 || es_variable2 > 1 || etiqueta < 0)
    {
        printf("Error: Wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tpop dword ebx\n");
    fprintf(fpasm, "\tpop dword eax\n");
    if (es_variable1)
    {
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }
    if (es_variable2)
    {
        fprintf(fpasm, "\tmov ebx, [ebx]\n");
    }

    fprintf(fpasm, "\tcmp eax, ebx\n");
    fprintf(fpasm, "\tjl near etiqueta%d\n", etiqueta);
    fprintf(fpasm, "\tpush dword 0\n");
    fprintf(fpasm, "\tjmp end%d\n\n", etiqueta);
    fprintf(fpasm, "etiqueta%d:\n", etiqueta);
    fprintf(fpasm, "\tpush dword 1\n\n");
    fprintf(fpasm, "end%d:\n\n", etiqueta);

    return;
}

void mayor(FILE *fpasm, int es_variable1, int es_variable2, int etiqueta)
{
    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (es_variable1 < 0 || es_variable2 < 0 || es_variable1 > 1 || es_variable2 > 1 || etiqueta < 0)
    {
        printf("Error: Wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tpop dword ebx\n");
    fprintf(fpasm, "\tpop dword eax\n");
    if (es_variable1)
    {
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }
    if (es_variable2)
    {
        fprintf(fpasm, "\tmov ebx, [ebx]\n");
    }

    fprintf(fpasm, "\tcmp eax, ebx\n");
    fprintf(fpasm, "\tjg near etiqueta%d\n", etiqueta);
    fprintf(fpasm, "\tpush dword 0\n");
    fprintf(fpasm, "\tjmp end%d\n\n", etiqueta);
    fprintf(fpasm, "etiqueta%d:\n", etiqueta);
    fprintf(fpasm, "\tpush dword 1\n\n");
    fprintf(fpasm, "end%d:\n\n", etiqueta);

    return;
}

/* FUNCIONES DE ESCRITURA Y LECTURA */
/*
Se necesita saber el tipo de datos que se va a procesar (ENTERO o BOOLEANO) ya
que hay diferentes funciones de librería para la lectura (idem. escritura) de cada
tipo.
Se deben insertar en la pila los argumentos necesarios, realizar la llamada
(call) a la función de librería correspondiente y limpiar la pila.
*/
void leer(FILE *fpasm, char *nombre, int tipo)
{

    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (nombre == NULL || tipo > 1 || tipo < 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    /*Boolean*/
    if (tipo)
    {
        fprintf(fpasm, "\tpush dword _%s\n", nombre);
        fprintf(fpasm, "\tcall scan_boolean\n");
        /*Limpiar pila*/
        fprintf(fpasm, "\tadd esp, 4\n\n");
        return;
    }
    else
    {
        /*Entero*/
        fprintf(fpasm, "\tpush dword _%s\n", nombre);
        fprintf(fpasm, "\tcall scan_int\n");
        /*Limpiar pila*/
        fprintf(fpasm, "\tadd esp, 4\n\n");
        return;
    }
}

void escribir(FILE *fpasm, int es_variable, int tipo)
{

    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (es_variable > 1 || es_variable < 0 || tipo > 1 || tipo < 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable)
    {
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }

    fprintf(fpasm, "\tpush dword eax\n");

    /*Boolean*/
    if (tipo)
    {
        fprintf(fpasm, "\tcall print_boolean\n");
        /*Limpiar pila*/
        fprintf(fpasm, "\tadd esp, 4\n");
        fprintf(fpasm, "\tcall print_endofline\n\n");
        return;
    }
    else
    {
        /*Entero*/
        fprintf(fpasm, "\tcall print_int\n");
        /*Limpiar pila*/
        fprintf(fpasm, "\tadd esp, 4\n");
        fprintf(fpasm, "\tcall print_endofline\n\n");
        return;
    }
}

/*---------------------------------SECOND PART----------------------------------------------------*/

void ifthenelse_inicio(FILE *fpasm, int exp_es_variable, int etiqueta)
{
    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (exp_es_variable > 1 || exp_es_variable < 0 || etiqueta < 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tpop dword eax\n");
    if (exp_es_variable)
    {
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }

    fprintf(fpasm, "\tcmp eax, 0\n");
    fprintf(fpasm, "\tje near end_if%d\n\n", etiqueta);

    return;
}
/*
Generación de código para el inicio de una estructura if-then-else
Como es el inicio de uno bloque de control de flujo de programa que requiere de una nueva
etiqueta deben ejecutarse antes las tareas correspondientes a esta situación
exp_es_variable
Es 1 si la expresión de la condición es algo asimilable a una variable (identificador,
elemento de vector)
Es 0 en caso contrario (constante u otro tipo de expresión)
*/

void ifthen_inicio(FILE *fpasm, int exp_es_variable, int etiqueta)
{
    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (exp_es_variable > 1 || exp_es_variable < 0 || etiqueta < 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tpop dword eax\n");
    if (exp_es_variable)
    {
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }

    fprintf(fpasm, "\tcmp eax, 0\n");
    fprintf(fpasm, "\tje near end_if%d\n\n", etiqueta);

    return;
}
/*
Generación de código para el inicio de una estructura if-then
Como es el inicio de uno bloque de control de flujo de programa que requiere de una nueva
etiqueta deben ejecutarse antes las tareas correspondientes a esta situación
exp_es_variable
Es 1 si la expresión de la condición es algo asimilable a una variable (identificador,
elemento de vector)
Es 0 en caso contrario (constante u otro tipo de expresión)
*/

void ifthen_fin(FILE *fpasm, int etiqueta)
{
    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (etiqueta < 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    /**fprintf(fpasm, "\tjmp near fin_then%d\n\n", etiqueta);*/
    fprintf(fpasm, "\nend_if%d:\n", etiqueta);

    return;
}
/*
Generación de código para el fin de una estructura if-then
Como es el fin de uno bloque de control de flujo de programa que hace uso de la etiqueta
del mismo se requiere que antes de su invocación tome el valor de la etiqueta que le toca
según se ha explicado
Y tras ser invocada debe realizar el proceso para ajustar la información de las etiquetas
puesto que se ha liberado la última de ellas.
*/

void ifthenelse_fin_then(FILE *fpasm, int etiqueta)
{
    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (etiqueta < 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tjmp near fin_ifelse%d\n\n", etiqueta);
    fprintf(fpasm, "\nend_if%d:\n", etiqueta);

    return;
}
/*
Generación de código para el fin de la rama then de una estructura if-then-else
Sólo necesita usar la etiqueta adecuada, aunque es el final de una rama, luego debe venir
otra (la rama else) antes de que se termine la estructura y se tenga que ajustar las etiquetas
por lo que sólo se necesita que se utilice la etiqueta que corresponde al momento actual.
*/

void ifthenelse_fin(FILE *fpasm, int etiqueta)
{
    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (etiqueta < 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\nfin_ifelse%d:", etiqueta);

    return;
}
/*
Generación de código para el fin de una estructura if-then-else
Como es el fin de uno bloque de control de flujo de programa que hace uso de la etiqueta
del mismo se requiere que antes de su invocación tome el valor de la etiqueta que le toca
según se ha explicado
Y tras ser invocada debe realizar el proceso para ajustar la información de las etiquetas
puesto que se ha liberado la última de ellsssssssas.
*/

void while_inicio(FILE *fpasm, int etiqueta)
{
    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (etiqueta < 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    fprintf(fpasm, "begin_while%d:\n", etiqueta);

    return;
}
/*
Generación de código para el inicio de una estructura while
Como es el inicio de uno bloque de control de flujo de programa que requiere de una nueva
etiqueta deben ejecutarse antes las tareas correspondientes a esta situación
exp_es_variable
Es 1 si la expresión de la condición es algo asimilable a una variable (identificador,
elemento de vector)
Es 0 en caso contrario (constante u otro tipo de expresión)
*/

void while_exp_pila(FILE *fpasm, int exp_es_variable, int etiqueta)
{
    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (exp_es_variable > 1 || exp_es_variable < 0 || etiqueta < 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tpop dword eax\n");

    if (exp_es_variable)
    {
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }

    fprintf(fpasm, "\tcmp eax, 0\n");
    fprintf(fpasm, "\tje near fin_while%d\n\n", etiqueta);

    return;
}
/*
Generación de código para el momento en el que se ha generado el código de la expresión
de control del bucle
Sólo necesita usar la etiqueta adecuada, por lo que sólo se necesita que se recupere el valor
de la etiqueta que corresponde al momento actual.
exp_es_variable
Es 1 si la expresión de la condición es algo asimilable a una variable (identificador,
o elemento de vector)
Es 0 en caso contrario (constante u otro tipo de expresión)
*/

void while_fin(FILE *fpasm, int etiqueta)
{
    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (etiqueta < 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\tjmp near begin_while%d\n\n", etiqueta);
    fprintf(fpasm, "fin_while%d:\n", etiqueta);

    return;
}
/*
Generación de código para el final de una estructura while
Como es el fin de uno bloque de control de flujo de programa que hace uso de la etiqueta
del mismo se requiere que antes de su invocación tome el valor de la etiqueta que le toca
según se ha explicado
Y tras ser invocada debe realizar el proceso para ajustar la información de las etiquetas
puesto que se ha liberado la última de ellas.
*/

void escribir_elemento_vector(FILE *fpasm, char *nombre_vector, int tam_max, int exp_es_direccion) {

    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }                           

    if(nombre_vector == NULL || tam_max < 0 || exp_es_direccion > 1 || exp_es_direccion < 0){
        printf("Error: wrong arguments\n");
        return;
    }

    fprintf(fpasm, "\n\tpop dword eax\n");

    if(exp_es_direccion){
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }

    /* check if index is out of range */
    fprintf(fpasm, "\tcmp eax, 0\n");
    fprintf(fpasm, "\tjl near rango_error\n");
    fprintf(fpasm, "\tcmp eax, %d\n", tam_max);
    fprintf(fpasm, "\tjge near rango_error\n"); //aca esta el problema discutir el error
    /* vector's address in edx */
    fprintf(fpasm, "\tmov dword edx, _%s\n", nombre_vector);

    fprintf(fpasm, "\tlea eax, [edx + eax*4]\n");
    fprintf(fpasm, "\tpush dword eax\n");

    return;
}
/*
Generación de código para indexar un vector
Cuyo nombre es nombre_vector
Declarado con un tamaño tam_max
La expresión que lo indexa está en la cima de la pila
Puede ser una variable (o algo equivalente) en cuyo caso exp_es_direccion vale 1
Puede ser un valor concreto (en ese caso exp_es_direccion vale 0)
Según se especifica en el material, es suficiente con utilizar dos registros para realizar esta
tarea.
*/

/*-----------------------------THIRD PART-----------------------------*/

void declararFuncion(FILE *fd_asm, char *nombre_funcion, int num_var_loc)
{
    if (fd_asm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (nombre_funcion == NULL || num_var_loc <= 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    fprintf(fd_asm, "_%s:\n", nombre_funcion);
    fprintf(fd_asm, "\tpush ebp\n");
    fprintf(fd_asm, "\tmov ebp, esp\n");
    fprintf(fd_asm, "\tsub esp, %d\n", 4*num_var_loc);
}
/*
Generación de código para iniciar la declaración de una función.
Es necesario proporcionar
Su nombre
Su número de variables locales
*/

void retornarFuncion(FILE *fd_asm, int es_variable)
{

    if (fd_asm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (es_variable > 1 || es_variable < 0)
    {
        printf("Error: Wrong arguments\n");
        return;
    }

    fprintf(fd_asm, "\tpop eax\n");

    if (es_variable)
    {
        fprintf(fd_asm, "\tmov dword eax, [eax]\n");
    }

    fprintf(fd_asm, "\tmov esp, ebp\n");
    fprintf(fd_asm, "\tpop ebp\n");
    fprintf(fd_asm, "\tret\n");
}
/*
Generación de código para el retorno de una función.
La expresión que se retorna está en la cima de la pila.
Puede ser una variable (o algo equivalente) en cuyo caso exp_es_direccion vale 1
Puede ser un valor concreto (en ese caso exp_es_direccion vale 0)
*/

void escribirParametro(FILE *fpasm, int pos_parametro, int num_total_parametros)
{
    int d_ebp;

    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (pos_parametro < 0 || num_total_parametros < 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    d_ebp = 4 * (1 + (num_total_parametros - pos_parametro));

    fprintf(fpasm, "\tlea eax, [ebp + %d]\n", d_ebp);
    fprintf(fpasm, "\tpush dword eax\n");
}

/*
Función para dejar en la cima de la pila la dirección efectiva del parámetro que ocupa la
posición pos_parametro (recuerda que los parámetros se ordenan con origen 0) de un total
de num_total_parametros
*/

void escribirVariableLocal(FILE *fpasm, int posicion_variable_local)
{
    int d_ebp;

    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (posicion_variable_local < 1)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    d_ebp = 4 * posicion_variable_local;

    fprintf(fpasm, "\tlea eax, [ebp - %d]\n", d_ebp);
    fprintf(fpasm, "\tpush dword eax\n");
}
/*
Función para dejar en la cima de la pila la dirección efectiva de la variable local que ocupa
la posición posicion_variable_local (recuerda que ordenadas con origen 1)
*/

void asignarDestinoEnPila(FILE *fpasm, int es_variable)
{

    if (fpasm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (es_variable > 1 || es_variable < 0)
    {
        printf("Error: Wrong arguments\n");
        return;
    }

    /* lo que hay que asignar */
    fprintf(fpasm, "\tpop dword ebx\n");
    /* direccion donde hay que asignar */
    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable)
    {
        fprintf(fpasm, "\tmov dword eax, [eax]\n");
    }

    fprintf(fpasm, "\tmov dword [ebx], eax\n");
}

/*
Función para poder asignar a un destino que no es una variable “global” (tipo _x) por
ejemplo parámetros o variables locales (ya que en ese caso su nombre real de alto nivel, no
se tiene en cuenta pues es realmente un desplazamiento a partir de ebp: ebp+4 o ebp-8 por
ejemplo).
Se debe asumir que en la pila estará
Primero (en la cima) lo que hay que asignar
Debajo (se ha introducido en la pila antes) la dirección donde hay que asignar
es_variable
Es 1 si la expresión que se va a asignar es algo asimilable a una variable
(identificador, o elemento de vector)
Es 0 en caso contrario (constante u otro tipo de expresión)
*/

void operandoEnPilaAArgumento(FILE *fd_asm, int es_variable)
{

    if (fd_asm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (es_variable > 1 || es_variable < 0)
    {
        printf("Error: Wrong arguments\n");
        return;
    }

    if (es_variable)
    {
        fprintf(fd_asm, "\tpop dword eax\n");
        fprintf(fd_asm, "\tmov eax, [eax]\n");
        fprintf(fd_asm, "\tpush dword eax\n");
    }
}

/*
Como habrás visto en el material, nuestro convenio de llamadas a las funciones asume que
los argumentos se pasan por valor, esto significa que siempre se dejan en la pila “valores” y
no “variables”
Esta función realiza la tarea de dado un operando escrito en la pila y sabiendo si es variable
o no (es_variable) se deja en la pila el valor correspondiente
*/

void llamarFuncion(FILE *fd_asm, char *nombre_funcion, int num_argumentos)
{
    if (fd_asm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (nombre_funcion == NULL || num_argumentos <= 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    fprintf(fd_asm, "\tcall _%s\n", nombre_funcion);
    limpiarPila(fd_asm, num_argumentos);
    fprintf(fd_asm, "\tpush dword eax\n");
}
/*
Esta función genera código para llamar a la función nombre_funcion asumiendo que los
argumentos están en la pila en el orden fijado en el material de la asignatura.
Debe dejar en la cima de la pila el retorno de la función tras haberla limpiado de sus
argumentos
Para limpiar la pila puede utilizar la función de nombre limpiarPila
*/

void limpiarPila(FILE *fd_asm, int num_argumentos)
{
    if (fd_asm == NULL)
    {
        printf("Error: insert an open file.\n");
        return;
    }

    if (num_argumentos <= 0)
    {
        printf("Error: wrong arguments\n");
        return;
    }

    fprintf(fd_asm, "\tadd esp, %d\n", 4*num_argumentos);
}
/*
Genera código para limpiar la pila tras invocar una función
Esta función es necesaria para completar la llamada a métodos, su gestión dificulta el
conocimiento por parte de la función de llamada del número de argumentos que hay en la
pila
*/