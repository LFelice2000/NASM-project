segment .data

div_error_message db "Error for Division by zero", 0
fin_indice_fuera_rango db "Indice fuera de rango",0

segment .bss
	__esp resd 1
;D:	main
;D:	{
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	x
	_x resd 1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	printf
;R2:	<declaraciones> ::= <declaracion>

segment .text
	global main
	extern print_int, scan_int, print_boolean, scan_boolean, print_blank, print_endofline, print_string

;R21:	<funciones> ::= 
main:
	mov dword [__esp], esp
;D:	y
;D:	;
