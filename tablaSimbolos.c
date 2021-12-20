#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash.h"

#define BUFFER 200

int main(int argc, char *argv[]) {
    Hash_Table *local_simbols = NULL;
    Hash_Table *global_simbols = NULL;
    char line[BUFFER];
    char **lines = NULL;
    char * token = NULL, *token1 = NULL;
    FILE *fin = NULL;
    FILE *fout = NULL;
    int counter, i, len = 0;
    Hash_node *found = NULL, *node = NULL;
    int value;
    bool local_scope_open = false, is_in_local, declare_in_local, token_found;
    
    if(argc != 3) {
        printf("Syntax error: ./program <input_file> <output_file> ");
        return -1;
    }

    fin = fopen(argv[1], "r");
    if (fin == NULL) {
        printf("Error opening the input file.");
        return -1;
    }

    fout = fopen(argv[2], "w");
    if (fout == NULL) {
        printf("Error opening the input file.");
        fclose(fin);
        return -1;
    }

    global_simbols = creat_hash_table();
    if(!global_simbols) {
        printf("Error creating the table.");
        return -1;
    }

    lines = (char**)malloc(200*sizeof(char*));
    counter = 0;
    while (fgets(line, BUFFER, fin) != NULL) {
        lines[counter] = (char*)malloc((strlen(line)+1)*sizeof(char));
        strcpy(lines[counter], line);
        counter++;
    }

    for(i = 0; i < counter; i++) {
        token = strtok(lines[i], "\t");
        token1 = strtok(NULL, "\n");

        if(token1 != NULL){  
            value = atoi(token1);
        }

        /* Call */
        if(token1 == NULL) {
            token[strlen(token) - 1] = '\0';
            token_found = false;
            
            if(local_scope_open) {
                found = get_value_from_hstable(local_simbols, token, strlen(token));
                if(found) {
                    token_found = true;
                    fprintf(fout, "%s\t%d\n", found->key, found->value);
                }
            
            } 
            
            if(!token_found) {
                len = strlen(token);
                found = get_value_from_hstable(global_simbols, token, len);
                
                if (found) { /*Call Successful*/
                    fprintf(fout, "%s\t%d\n", found->key, found->value);
                } else { /* Search Failure */
                    fprintf(fout, "%s\t-1\n", token);
                }
            }
            
        } else { /* Declare */
            is_in_local = false;
            declare_in_local = false;

            if((strcmp(token, "cierre") == 0) && (strcmp(token1, "-999") == 0)){
                hash_table_delete(local_simbols);
                local_scope_open = false;
                declare_in_local = true;
                fprintf(fout, "cierre\n");
            }

            if(local_scope_open){
                
                found = get_value_from_hstable(local_simbols, token, strlen(token));
                if (!found) {
                    
                    node = (Hash_node*)malloc(sizeof(Hash_node));
                    init_hs_node(node);

                    strcpy(node->key, token);
                    node->value = value;

                    len = strlen(node->key);
                    if(add_node2HashTable(local_simbols, node, len) == -1){
                        printf("Error inserting the node =(\n");
                        return -1;
                    }

                    /* Output: declaration correct*/
                    fprintf(fout, "%s\n", node->key);
                    declare_in_local = true;
                    
                    free(node);
                    node = NULL;
                }
                else {
                    is_in_local = true;
                }
            }
            
            len = strlen(token);
            found = get_value_from_hstable(global_simbols, token, len);
            if ((!found) && (declare_in_local == false)){ /*Declaration Successful*/
                
                node = (Hash_node*)malloc(sizeof(Hash_node));
                init_hs_node(node);

                if (atoi(token1) < 0) {
                    
                    local_simbols = creat_hash_table();
                    if(!local_simbols) {
                        printf("Error creating the local table.");
                        return -1;
                    }
                    local_scope_open = true;

                    strcpy(node->key, token);
                    node->value = value;

                    if(add_node2HashTable(global_simbols, node, strlen(token)) == -1){
                        printf("Error inserting the node =(\n");
                        return -1;
                    }

                    if(add_node2HashTable(local_simbols, node, strlen(token)) == -1){
                        printf("Error inserting the node =(\n");
                        return -1;
                    }
                }

                else {
                    len = strlen(token);

                    strcpy(node->key, token);
                    node->value = value;
                    
                    if(add_node2HashTable(global_simbols, node, len) == -1){
                        printf("Error inserting the node =(\n");
                        return -1;
                    }
                }
                
                /* Output: declaration correct*/
                fprintf(fout, "%s\n", node->key);
                free(node);
                node = NULL;
            
            } else if(is_in_local == true || (is_in_local == false && declare_in_local == false && found)) { /* token found*/
                /* Output: declaration error*/
                fprintf(fout, "-1\t%s\n", token);
            }
        }
    }
    

    for(i = 0; i < counter; i++) {
        free(lines[i]);
    }
    
    hash_table_delete(global_simbols);
    free(lines);
    fclose(fin);
    fclose(fout);
    
    return 0;
}