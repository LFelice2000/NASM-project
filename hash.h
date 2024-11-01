#ifndef HASH_H
#define HASH_H

#define MAX_TABLE_SIZE 	1024*1024
#define TRUE			1
#define FLASE			0
#define MAX_LONG_ID 	100

typedef struct Hash_node
{
	struct Hash_node *next;	/** Si el hash (clave) es el mismo, siga el relevo */
	char key[MAX_LONG_ID];				/** Palabra clave */
	int value;			/**valor*/
	int categoria; /* categoría (variable, parámetro o función)*/
	int tipo;  /* tipo (entero o booleano) */
	int tamano; /* tamaño (número de elementos de un vector) */
	int numero_variables_locales;
	int posicion_variable_local;
	int numero_parametros;
	int posicion_parametros;
	char is_occupyed;	/** ¿Está ocupado? */
}Hash_node;


typedef struct hash_table
{
	Hash_node **table;	/** Tabla de picadillo */
}Hash_Table;

Hash_Table *creat_hash_table(void);
int add_node2HashTable(Hash_Table *Hs_table, Hash_node *node, unsigned int key_len);
Hash_node *get_value_from_hstable(Hash_Table *Hs_table, char *key, unsigned int key_len);
void hash_table_delete(Hash_Table *Hs_Table);
void init_hs_node(Hash_node *node);


#endif /**HASH_H*/
