%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

int col = 1;
int line = 1;
int error = 0;

%}

%option noyywrap
LETTER [a-zA-Z._]
DIGIT [0-9]
%%
"//".* { col+=yyleng; }
"\n" { line++; col=0; }
"true" { col += yyleng; fprintf(yyout, ";D:\ttrue\n"); return TOK_TRUE; }
"false" { col += yyleng; fprintf(yyout, ";D:\tfalse\n"); return TOK_FALSE; }
" " { col += yyleng; }
"\t" { col += yyleng; }
"main" { col += yyleng; fprintf(yyout, ";D:\tmain\n"); return TOK_MAIN; }
"int" { col += yyleng; fprintf(yyout, ";D:\tint\n"); return TOK_INT; }
"bool" { col += yyleng; fprintf(yyout, ";D:\tbool\n"); return TOK_BOOLEAN; }
"array" { col += yyleng; fprintf(yyout, ";D:\tarray\n"); return TOK_ARRAY; }
"function" { col += yyleng; fprintf(yyout, ";D:\tfunction\n"); return TOK_FUNCTION; }
"if" { col += yyleng; fprintf(yyout, ";D:\tif\n"); return TOK_IF; }             
"else" { col += yyleng; fprintf(yyout, ";D:\telse\n"); return TOK_ELSE; }           
"while" { col += yyleng; fprintf(yyout, ";D:\twhile\n"); return TOK_WHILE; }           
"scanf" { col += yyleng; fprintf(yyout, ";D:\tscanf\n"); return TOK_SCANF; }       
"printf" { col += yyleng; fprintf(yyout, ";D:\tprintf\n"); return TOK_PRINTF; }
"return" { col += yyleng; fprintf(yyout, ";D:\treturn\n"); return TOK_RETURN; }     
"=" { col += yyleng;  fprintf(yyout, ";D:\t=\n"); return TOK_ASIGNACION; }
"+" { col += yyleng;  fprintf(yyout, ";D:\t+\n"); return TOK_MAS; }
"-" { col += yyleng;  fprintf(yyout, ";D:\t-\n"); return TOK_MENOS; }
";" { col += yyleng;  fprintf(yyout, ";D:\t;\n"); return TOK_PUNTOYCOMA; }
"," { col += yyleng; fprintf(yyout, ";D:\t,\n"); return TOK_COMA; }
"(" { col += yyleng; fprintf(yyout, ";D:\t(\n"); return TOK_PARENTESISIZQUIERDO; }
")" { col += yyleng; fprintf(yyout, ";D:\t)\n"); return TOK_PARENTESISDERECHO; }
"[" { col += yyleng; fprintf(yyout, ";D:\t[\n"); return TOK_CORCHETEIZQUIERDO; }
"]" { col += yyleng; fprintf(yyout, ";D:\t]\n"); return TOK_CORCHETEDERECHO; }
"{" { col += yyleng; fprintf(yyout, ";D:\t{\n"); return TOK_LLAVEIZQUIERDA; }
"}" { col += yyleng; fprintf(yyout, ";D:\t}\n"); return TOK_LLAVEDERECHA; }
"/" { col += yyleng; fprintf(yyout, ";D:\t/\n"); return TOK_DIVISION; }
"*" { col += yyleng; fprintf(yyout, ";D:\t*\n"); return TOK_ASTERISCO; }
"&&" { col += yyleng; fprintf(yyout, ";D:\t&&\n"); return TOK_AND; }
"||" { col += yyleng; fprintf(yyout, ";D:\t||"); return TOK_OR; }
"!" { col += yyleng; fprintf(yyout, ";D:\t!"); return TOK_NOT; }
"==" { col += yyleng; fprintf(yyout, ";D:\t==\n"); return TOK_IGUAL; }
"!=" { col += yyleng; fprintf(yyout, ";D:\t!=\n"); return TOK_DISTINTO; }
"<=" { col += yyleng; fprintf(yyout, ";D:\t<=\n"); return TOK_MENORIGUAL; }
">=" {col += yyleng; fprintf(yyout, ";D:\t>=\n"); return TOK_MAYORIGUAL; }
"<" { col += yyleng; fprintf(yyout, ";D:\t<\n"); return TOK_MENOR; }
">" {col += yyleng; fprintf(yyout, ";D:\t>\n"); return TOK_MAYOR; }
{DIGIT}+ { col += yyleng; yylval.number=atoi(yytext); fprintf(yyout, ";D\t%s\n", yytext); return TOK_CONSTANTE_ENTERA; }
{LETTER}({DIGIT}|{LETTER})*{1,100} { if(yyleng > 100){fprintf(stdout,"****Error en [lin %d, col %d]: identificador demasiado largo (%s)\n",line,col-yyleng,yytext); error=1; return TOK_ERROR;} col += yyleng; strcpy(yylval.string,yytext); fprintf(yyout,";D:\t%s\n",yytext); return TOK_IDENTIFICADOR; }
{DIGIT}({LETTER}{DIGIT})*  { col += yyleng; strcpy(yylval.string, yytext); fprintf(stdout,"****Error en [lin %d, col %d]: simbolo no permitido (%s)\n",line,col-yyleng,yytext); error=1; return TOK_ERROR; }
[\_]({LETTER}{DIGIT})* { col += yyleng; strcpy(yylval.string,yytext); fprintf(stdout,"****Error en [lin %d, col %d]: simbolo no permitido (%s)\n",line,col-yyleng,yytext); error=1; return TOK_ERROR; }
({LETTER}{DIGIT})*[\_] { col += yyleng; strcpy(yylval.string,yytext); fprintf(stdout,"****Error en [lin %d, col %d]: simbolo no permitido (%s)\n",line,col-yyleng,yytext); error=1; return TOK_ERROR; }
. { col += yyleng; strcpy(yylval.string,yytext); fprintf(stdout,"****Error en [lin %d, col %d]: simbolo no permitido (%s)\n",line,col-yyleng,yytext); error=1; return TOK_ERROR; }

%%