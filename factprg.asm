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
;D:	,
;D:	y
	_y resd 1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	scanf
;R2:	<declaraciones> ::= <declaracion>

segment .text
	global main
	extern print_int, scan_int, print_boolean, scan_boolean, print_blank, print_endofline, print_string

;R21:	<funciones> ::= 
main:
	mov dword [__esp], esp
;D:	x
	push dword _x
	call scan_int
	add esp, 4

;R54:	<lectura> ::= scanf <identificador>
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	y
;D:	=
;D:	1
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 1
	push dword eax
;R81:	<exp> ::= <constante>
;D:	;
	pop dword eax
	mov dword [_y], eax
;R43:	<asignacion> ::= <identificador> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	while
;D:	(
;D:	(
;D:	x
;D:	>

	mov eax, _x
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	1
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 1
	push dword eax
;R81:	<exp> ::= <constante>
;D:	)
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax, ebx
	jg near etiqueta0
	push dword 0
	jmp end0

etiqueta0:
	push dword 1

end0:

;R98:	<comparacion> ::= <exp> > <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	)
begin_while0:
	pop dword eax
	cmp eax, 0
	je near fin_while0

;D:	{
;D:	y
;D:	=
;D:	x
;D:	*

	mov eax, _x
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	y
;D:	;

	mov eax, _y
	push dword eax
;R80:	<exp> ::= <identificador>
	pop dword ecx
	pop dword eax
	mov eax, [eax]
	mov ecx, [ecx]
	imul ecx
	mov edx, 0
	push dword eax

;R75:	<exp> ::= <exp> * <exp>
	pop dword eax
	mov dword [_y], eax
;R43:	<asignacion> ::= <identificador> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	x
;D:	=
;D:	x
;D:	-

	mov eax, _x
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	1
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 1
	push dword eax
;R81:	<exp> ::= <constante>
;D:	;
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	sub eax, ebx
	push dword eax

;R73:	<exp> ::= <exp> - <exp>
	pop dword eax
	mov dword [_x], eax
;R43:	<asignacion> ::= <identificador> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
	jmp near begin_while0

fin_while0:
;R52:	<bucle> ::= while( <exp> ) { <sentencias> }
;R41:	<bloque> ::= <bucle>
;R33:	<sentencia> ::= <bloque>
;D:	printf
;D:	y
;D:	;

	mov eax, _y
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
;R31:	<sentencias> ::= <sentencia> <sentencias>
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
