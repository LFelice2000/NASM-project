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
;D:	x
;R2:	<declaraciones> ::= <declaracion>

segment .text
	global main
	extern print_int, scan_int, print_boolean, scan_boolean, print_blank, print_endofline, print_string

;R21:	<funciones> ::= 
main:
	mov dword [__esp], esp
;D:	=
;D:	8
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 8
	push dword eax
;R81:	<exp> ::= <constante>
;D:	;
	pop dword eax
	mov dword [_x], eax
;R43:	<asignacion> ::= <identificador> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	x
;D:	;

	mov eax, _x
	push dword eax
;R80:	<exp> ::= <identificador>
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline

;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
	jmp end

div_error:
	push div_error_message
	call print_string
	add esp, 4
	call print_endofline
	add esp, 4
	jmp end

rango_error:
	push fin_indice_fuera_rango
	call print_string
	add esp, 4
	call print_endofline
	add esp, 4
	jmp end

end:
	mov esp, [__esp]
	ret
;R1:	<programa> ::= main { <declaraciones> <funciones> <sentencias> }
