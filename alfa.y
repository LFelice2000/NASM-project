%{
        
        #include <stdio.h>
        #include <stdlib.h>
        #include <stdbool.h>
        #include <string.h>
        #include "alfa.h"
        #include "generacion.h"
        #include "hash.h"
        #include "y.tab.h"
        
        
        void yyerror(char const *str);
        extern int line, col, error;
        extern FILE *yyin;
	extern FILE *yyout;
        extern int yylex();
        extern int yyleng;

        int tipo_actual;
        int clase_actual;

        Hash_Table *global_simbols = NULL;
        Hash_Table *local_simbols = NULL;
        bool local_scope_open = false, is_in_local, declare_in_local, token_found;
        Hash_node *found = NULL;
        int value, len = 0;

        int num_variables_locales_actual = 0;
        int pos_variable_local_actual = 0;
        int num_parametros_actual = 0;
        int pos_parametro_actual = 0;

        int contador_parametro = 0;

        FILE *declarations_file = NULL;
        char nombre_variable[50];
%}

%union

{
        tipo_atributos atributos;
}

%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEAN
%token TOK_ARRAY
%token TOK_FUNCTION
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_SCANF
%token TOK_PRINTF
%token TOK_RETURN          
%token TOK_PUNTOYCOMA
%token TOK_COMA                
%token TOK_PARENTESISIZQUIERDO 
%token TOK_PARENTESISDERECHO   
%token TOK_CORCHETEIZQUIERDO   
%token TOK_CORCHETEDERECHO     
%token TOK_LLAVEIZQUIERDA            
%token TOK_LLAVEDERECHA        
%token TOK_ASIGNACION          
%token TOK_MAS                 
%token TOK_MENOS               
%token TOK_DIVISION            
%token TOK_ASTERISCO           
%token TOK_AND                 
%token TOK_OR                  
%token TOK_NOT                 
%token TOK_IGUAL               
%token TOK_DISTINTO            
%token TOK_MENORIGUAL          
%token TOK_MAYORIGUAL          
%token TOK_MENOR 
%token TOK_MAYOR
%token <atributos> TOK_IDENTIFICADOR
%token <atributos> TOK_CONSTANTE_ENTERA
%token <atributos> TOK_TRUE
%token <atributos> TOK_FALSE
%token TOK_ERROR

%type <atributos> fn_name
%type <atributos> fn_declaracion
%type <atributos> programa
%type <atributos> initialize_hash
%type <atributos> escritura1
%type <atributos> escritura2
%type <atributos> declaraciones
%type <atributos> declaracion
%type <atributos> clase
%type <atributos> clase_escalar
%type <atributos> clase_vector
%type <atributos> tipo
%type <atributos> identificadores
%type <atributos> funciones
%type <atributos> funcion
%type <atributos> parametros_funcion
%type <atributos> resto_parametros_funcion
%type <atributos> parametro_funcion
%type <atributos> declaraciones_funcion
%type <atributos> sentencias
%type <atributos> sentencia
%type <atributos> sentencia_simple
%type <atributos> bloque
%type <atributos> asignacion
%type <atributos> bucle
%type <atributos> lectura
%type <atributos> escritura
%type <atributos> retorno_funcion
%type <atributos> lista_expresiones
%type <atributos> resto_lista_expresiones
%type <atributos> condicional
%type <atributos> comparacion
%type <atributos> elemento_vector
%type <atributos> exp
%type <atributos> constante
%type <atributos> constante_entera
%type <atributos> constante_logica
%type <atributos> identificador


%left TOK_OR
%left TOK_AND
%left TOK_IGUAL TOK_DISTINTO 
%left TOK_MENOR TOK_MAYOR TOK_MENORIGUAL TOK_MAYORIGUAL
%left TOK_MAS TOK_MENOS
%left TOK_ASTERISCO TOK_DIVISION
%right TOK_NOT

%%
programa: initialize_hash TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones escritura1 funciones escritura2 sentencias TOK_LLAVEDERECHA 
{ 
        fprintf(yyout, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
};

initialize_hash: {
        
        global_simbols = creat_hash_table(); 
        if(global_simbols == NULL){ 
                error = -1; 
                return -1;
        }  

        clase_actual = 1;
        escribir_subseccion_data(yyout);
        escribir_cabecera_bss(yyout);  
};

escritura1: 
{
        escribir_segmento_codigo(yyout);
};

escritura2: 
{
        escribir_inicio_main(yyout);
};

declaraciones: declaracion { fprintf(yyout, ";R2:\t<declaraciones> ::= <declaracion>\n");}
            | declaracion declaraciones { fprintf(yyout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");};

declaracion: clase identificadores TOK_PUNTOYCOMA { 
        
        fprintf(yyout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n"); };

clase: clase_escalar { clase_actual = ESCALAR; fprintf(yyout, ";R5:\t<clase> ::= <clase_escalar>\n"); }
            | clase_vector { clase_actual = VECTOR; fprintf(yyout, ";R7:\t<clase> ::= <clase_vector>\n"); };

clase_escalar: tipo { fprintf(yyout, ";R9:\t<clase_escalar> ::= <tipo>\n"); };

clase_vector: TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO constante_entera TOK_CORCHETEDERECHO { fprintf(yyout, ";R15:\t<clase_vector> ::= array <tipo> [<constante_entera>]\n"); };

tipo: TOK_INT { clase_actual = INT; fprintf(yyout, ";R10:\t<tipo> ::= int\n"); }
            | TOK_BOOLEAN { clase_actual = BOOLEAN; fprintf(yyout, ";R11:\t<tipo> ::= boolean\n"); };

identificadores: identificador { fprintf(yyout, ";R18:\t<identificadores> ::= <identificador>\n"); }
            | identificador TOK_COMA identificadores { fprintf(yyout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n"); };

funciones: funcion funciones { fprintf(yyout, ";R20:\t<funciones> ::= <funcion> <funciones>\n"); }
            | { fprintf(yyout, ";R21:\t<funciones> ::= \n"); };

fn_name: TOK_FUNCTION tipo TOK_IDENTIFICADOR {
        Hash_node node;

        found = get_value_from_hstable(global_simbols, $3.lexema, strlen($3.lexema));
        if(found) {
                fprintf(stdout, "Error (22) function already declared.\n");
                error = 1;
                return -1;
        }

        if(!local_scope_open) {
                local_simbols = creat_hash_table();
                if(!local_simbols) {
                       fprintf(stdout, "Error opening the local scope\n");
                        error = 1;
                        return -1;
                }
                local_scope_open = true;

                    strcpy(node.key, $3.lexema);
                    node.value = -1;

                    if(add_node2HashTable(global_simbols, &node, strlen(node.key)) == -1){
                        printf("Error inserting the node =(\n");
                        return -1;
                    }

                    if(add_node2HashTable(local_simbols, &node, strlen(node.key)) == -1){
                        printf("Error inserting the node =(\n");
                        return -1;
                    }
        }
        
        num_variables_locales_actual = 0;
        pos_variable_local_actual = 1;
        num_parametros_actual = 0;
        pos_parametro_actual = 0;
        
        strcpy($$.lexema, $3.lexema);
};

fn_declaracion: fn_name TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion {
       
        
        found = get_value_from_hstable(local_simbols, $1.lexema, strlen($1.lexema));
        if(!found) {
                fprintf(stdout, "Error (22) function not declared.\n");
                error = 1;
                return -1;
        }

        found->numero_parametros = num_parametros_actual;
        
        declararFuncion(yyout, $3.lexema, num_variables_locales_actual);

        strcpy($$.lexema, $1.lexema);
};

funcion: fn_declaracion sentencias TOK_LLAVEDERECHA {

        hash_table_delete(local_simbols);
        local_scope_open = false;
        declare_in_local = true;

        fprintf(yyout, ";R22:	<funcion> ::=function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n"); 
};

parametros_funcion: parametro_funcion resto_parametros_funcion { fprintf(yyout, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n"); }
        | { fprintf(yyout, ";R24:\t<parametros_funcion> ::= \n"); };

resto_parametros_funcion: TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion { fprintf(yyout, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n"); }
        | { fprintf(yyout, ";R26:\t<resto_parametros_funcion> ::= \n"); };

parametro_funcion: tipo identificador { 
        num_parametros_actual++;

        
        found = get_value_from_hstable(local_simbols, $2.lexema, strlen($2.lexema));
        if(!found) {
                fprintf(stdout, "Error(27): paramater %s does not exist\n", $2.lexema);
                error = 1;
                return -1;
        }

        found->posicion_parametros = pos_parametro_actual;

        pos_parametro_actual++;

        fprintf(yyout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n"); };

declaraciones_funcion: declaraciones { fprintf(yyout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n"); }
        | { fprintf(yyout, ";R29:\t<declaraciones_funcion> ::= \n"); };

sentencias: sentencia {fprintf(yyout, ";R30:\t<sentencias> ::= <sentencia>\n");}
          | sentencia sentencias {fprintf(yyout, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");};
          
sentencia: sentencia_simple TOK_PUNTOYCOMA {fprintf(yyout, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
         | bloque {fprintf(yyout, ";R33:\t<sentencia> ::= <bloque>\n");};
         
sentencia_simple: asignacion {fprintf(yyout, ";R34:\t<sentencia_simple> ::= <asignacion>\n");}
                | lectura {fprintf(yyout, ";R35:\t<sentencia_simple> ::= <lectura>\n");}
                | escritura {fprintf(yyout, ";R36:\t<sentencia_simple> ::= <escritura>\n");}
                | retorno_funcion {fprintf(yyout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");};

bloque: condicional { fprintf(yyout, ";R40:\t<bloque> ::= <condicional>\n"); }
            | bucle { fprintf(yyout, ";R41:\t<bloque> ::= <bucle>\n"); };
            
asignacion: TOK_IDENTIFICADOR TOK_ASIGNACION exp  {
        
        if(local_scope_open) {
                found = get_value_from_hstable(local_simbols, $1.lexema, strlen($1.lexema));
                if(!found) {
                        found = get_value_from_hstable(global_simbols, $1.lexema, strlen($1.lexema));
                        if(!found) {
                                fprintf(stdout, "Error asignacion(43) not in local or global table\n");
                        }     
                }          
        } else {
                found = get_value_from_hstable(global_simbols, $1.lexema, strlen($1.lexema));
                if(!found) {
                    fprintf(stdout, "Error asignacion(43) not in global table\n");
                }
        }

        if($1.tipo == FUNCTION){
                fprintf(stdout, "Error asignacion(43): tipo == categoria\n");
        }
        if($1.tipo == VECTOR){
                fprintf(stdout, "Error asignacion(43): la clase es vector\n");
        }
        if($1.tipo != $3.tipo){ /* Does not check table type*/
                fprintf(stdout, "Error asignacion(43): types when asigned dont match\n");
        }

        fprintf(yyout, ";asignar\n");
        /* Code for poping the right part of the statement */
        fprintf(yyout, "\tpop dword eax\n");

        /* Code for accessing to the memory for the correct value, if exp is an address */
        if($3.es_direccion == 1){
                fprintf(yyout, "\tmov dword eax, [eax]\n");
        }


        /* Code for making the assignment */
        fprintf(yyout, "\tmov dword [_%s], eax\n", $1.lexema);
       

        fprintf(yyout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n"); 
        
        }        
        
        | elemento_vector TOK_ASIGNACION  exp { fprintf(yyout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n"); };

elemento_vector: TOK_IDENTIFICADOR TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO { fprintf(yyout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n"); };

condicional: TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {fprintf(yyout, ";R50\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");}
           | TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {fprintf(yyout, ";R51\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");};       

bucle: TOK_WHILE TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA { fprintf(yyout, ";R52:\t<bucle> ::= while( <exp> ) { <sentencias> }\n"); };

lectura: TOK_SCANF TOK_IDENTIFICADOR {fprintf(yyout, ";R54:\t<lectura> ::= scanf <identificador>\n");};

escritura: TOK_PRINTF exp {
        
        if($2.es_direccion == 1) {
                operandoEnPilaAArgumento(yyout, 1);
        }

        if($2.tipo == BOOLEAN) {
                escribir(yyout, 1, 1);
        }
        if($2.tipo == INT) {
                escribir(yyout, 1, 0);
        }
        
        fprintf(yyout, ";R56:\t<escritura> ::= printf <exp>\n");
};
      
retorno_funcion: TOK_RETURN exp {
        retornarFuncion(yyout, 0);

        fprintf(yyout, ";R61:\t<retorno_funcion> ::= return <exp>\n");
};

exp: exp TOK_MAS exp { 
        sumar(yyout, 1, 1);

        fprintf(yyout, ";R72:\t<exp> ::= <exp> + <exp>\n");
        }
        | exp TOK_MENOS exp { fprintf(yyout, ";R73:\t<exp> ::= <exp> - <exp>\n"); }
        | exp TOK_DIVISION exp { fprintf(yyout, ";R74:\t<exp> ::= <exp> / <exp>\n"); }
        | exp TOK_ASTERISCO exp { fprintf(yyout, ";R75:\t<exp> ::= <exp> * <exp>\n"); }
        | TOK_MENOS exp { fprintf(yyout, ";R76:\t<exp> ::= - <exp>\n"); }
        | exp TOK_AND exp { fprintf(yyout, ";R77:\t<exp> ::= <exp> && <exp>\n"); }
        | exp TOK_OR exp { fprintf(yyout, ";R78:\t<exp> ::= <exp> || <exp>\n"); }
        | TOK_NOT exp { fprintf(yyout, ";R79:\t<exp> ::= ! <exp>\n"); }
        | TOK_IDENTIFICADOR { 
                
                if(local_scope_open) {
                        found = get_value_from_hstable(local_simbols, $1.lexema, strlen($1.lexema));
                        if(!found) {
                                found = get_value_from_hstable(global_simbols, $1.lexema, strlen($1.lexema));
                                if(!found) {
                                        fprintf(stdout, "Error asignacion(80) not in local or global table\n");
                                }
                        }
                        escribirParametro(yyout, found->posicion_parametros, num_parametros_actual);

                } else {
                        found = get_value_from_hstable(global_simbols, $1.lexema, strlen($1.lexema));
                        if(!found) {
                                fprintf(stdout, "Error asignacion(80) not in global table\n");
                        }
                }

                if(found->categoria == FUNCTION) {
                        fprintf(stdout, "Error exp(80) bad category\n");
                }

                $$.tipo = found->tipo;
                $$.es_direccion = 1;

                escribir_operando(yyout, $1.lexema, 1);

                fprintf(yyout, ";R80:\t<exp> ::= <identificador>\n");

                if($$.es_direccion == 1) {
                        operandoEnPilaAArgumento(yyout, 1);
                }
        }
        | constante {
                char tmp[100] = "\0";

                $$.tipo = $1.tipo; 
                $$.es_direccion = $1.es_direccion;

                sprintf(tmp, "%d", $1.valor_entero);

                escribir_operando(yyout, tmp, 0);

                fprintf(yyout, ";R81:\t<exp> ::= <constante>\n"); }
        | TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO { $$.tipo = $2.tipo; $$.es_direccion = $2.es_direccion; fprintf(yyout, ";R82:\t<exp> ::= ( <exp> )\n"); }
        | TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO { $$.tipo = $2.tipo; $$.es_direccion = $2.es_direccion; fprintf(yyout, ";R83:\t<exp> ::= ( <comparacion> )\n"); }
        | elemento_vector { $$.tipo = $1.tipo; $$.es_direccion = $1.es_direccion; fprintf(yyout, ";R85:\t<exp> ::= <elemento_vector>\n"); }
        | identificador TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO { 
                
                
                found = get_value_from_hstable(global_simbols, $1.lexema, strlen($1.lexema));
                printf("fucnion %d\n",found->numero_parametros);
                if(!found) {
                        fprintf(stdout, "fuction not found (88)\n");
                        error = 1;
                        return -1;
                }
                
                llamarFuncion(yyout, $1.lexema, found->numero_parametros);
                
                fprintf(yyout, ";R88:\t<exp> ::= <identicador> ( <lista_expresiones> )\n"); };

lista_expresiones: exp resto_lista_expresiones { fprintf(yyout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n"); }
        | { fprintf(yyout, ";R90:\t<lista_expresiones> ::= \n"); };

resto_lista_expresiones: TOK_COMA exp resto_lista_expresiones {fprintf(yyout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");}
        | {fprintf(yyout, ";R92:\t<resto_lista_expresiones> ::= \n"); };

comparacion: exp TOK_IGUAL exp { fprintf(yyout, ";R93:\t<comparacion> ::= <exp> == <exp>\n"); }
                | exp TOK_DISTINTO exp { fprintf(yyout, ";R94:\t<comparacion> ::= <exp> != <exp>\n"); }
                | exp TOK_MENORIGUAL exp { fprintf(yyout, ";R95:\t<comparacion> ::= <exp> <= <exp>\n"); }
                | exp TOK_MAYORIGUAL exp { fprintf(yyout, ";R96:\t<comparacion> ::= <exp> >= <exp>\n"); }
                | exp TOK_MENOR exp { fprintf(yyout, ";R97:\t<comparacion> ::= <exp> < <exp>\n"); }
                | exp TOK_MAYOR exp { fprintf(yyout, ";R98:\t<comparacion> ::= <exp> > <exp>\n"); };

constante: constante_logica { $$.tipo = $1.tipo; $$.es_direccion = $1.es_direccion; fprintf(yyout, ";R99:\t<constante> ::= <constante_logica>\n"); }
                | constante_entera { $$.tipo = $1.tipo; $$.es_direccion = $1.es_direccion; fprintf(yyout, ";R100:\t<constante> ::= <constante_entera\n"); };

constante_logica: TOK_TRUE { fprintf(yyout, ";R102:\t<constante_logica> ::= true\n"); }
                | TOK_FALSE  { fprintf(yyout, ";R103:\t<constante_logica> ::= false\n"); };               

constante_entera: TOK_CONSTANTE_ENTERA {
        $$.tipo = INT;
        $$.es_direccion = 0;
        $$.valor_entero = $1.valor_entero;
        
        
        fprintf(yyout, ";R104:\t<constante_entera> ::= <numero>\n"); 
};

identificador: TOK_IDENTIFICADOR {
        Hash_node node;
        int len = 0; 
        
        is_in_local = false;
        declare_in_local = false;

        init_hs_node(&node);
        strcpy(node.key, $1.lexema);
        node.value = $1.valor_entero;
                
        value = $1.valor_entero;
        if(local_scope_open) {

                found = get_value_from_hstable(local_simbols, $1.lexema, strlen($1.lexema));
                if (!found) {

                        node.posicion_variable_local = pos_variable_local_actual;
                        len = strlen(node.key);
                        if(add_node2HashTable(local_simbols, &node, len) == -1){
                                fprintf(stdout, "Error inserting the node =(\n");
                                return -1;
                        }
                        /*num_variables_locales_actual++;
                        pos_variable_local_actual++;*/

                        /* Output: declaration correct*/
                        fprintf(stdout, "%s\n", $1.lexema);
                        declare_in_local = true;
                }
                else {
                        is_in_local = true;
                }
        }
        
        len = strlen($1.lexema);
        found = get_value_from_hstable(global_simbols, $1.lexema, len);
        if ((!found) && (declare_in_local == false)){ /*Declaration Successful*/
                len = strlen($1.lexema);
                if(add_node2HashTable(global_simbols, &node, len) == -1){
                        fprintf(stdout, "Error inserting the node =(\n");
                        return -1;
                }

                declarar_variable(yyout, $1.lexema, 0, 1);
        
                /* Output: declaration correct*/
                fprintf(stdout, "%s\n", $1.lexema);

                fprintf(yyout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
        
        } else if(is_in_local == true || (is_in_local == false && declare_in_local == false && !found)) { /* token found*/
        /* Output: declaration error*/
                fprintf(stdout, "-1\t%s\n", $1.lexema);
        }
        

}
                
%%

void yyerror (char const *str)
{
	if(error == 0)
		fprintf(stdout,"**** Error sintactico en [lin %d, col %d]\n",line,col);
	error = 0;
}
