#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

extern FILE *yyin;
extern FILE *yyout;

int main(int argc, char const **argv) {
    if (argc != 3) {
        printf("Wrong number of arguments received\n");
        return -1;
    }
    

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        printf("Error opening the input file.");
        return -1;
    }

    yyout = fopen(argv[2], "w");
    if (yyout == NULL) {
        printf("Error opening the output file.");
        fclose(yyin);
        return -1;
    }

    if(yyparse() == 0){
        printf("finished correctly\n");
    }

    fclose(yyin);
    fclose(yyout);

    return 0;
}