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
;D:	,
;D:	resultado
	_resultado resd 1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	function
;R2:	<declaraciones> ::= <declaracion>

segment .text
	global main
	extern print_int, scan_int, print_boolean, scan_boolean, print_blank, print_endofline, print_string

;D:	int
;R10:	<tipo> ::= int
;D:	suma
;D:	(
;D:	int
;R10:	<tipo> ::= int
;D:	num1
;R27:	<parametro_funcion> ::= <tipo> <identificador>
;D:	;
;D:	int
;R10:	<tipo> ::= int
;D:	num2
;R27:	<parametro_funcion> ::= <tipo> <identificador>
;D:	)
;R26:	<resto_parametros_funcion> ::= 
;R25:	<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>
;R23:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;D:	{
;D:	return
;R29:	<declaraciones_funcion> ::= 
_suma:
	push ebp
	mov ebp, esp
	sub esp, 0
;D:	num1
;D:	+
	lea eax, [ebp + 12]
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	num2
;D:	;
	lea eax, [ebp + 8]
	push dword eax
;R80:	<exp> ::= <identificador>
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	mov ebx, [ebx]
	add eax, ebx
	push dword eax

;R72:	<exp> ::= <exp> + <exp>
	pop eax
	mov esp, ebp
	pop ebp
	ret
;R61:	<retorno_funcion> ::= return <exp>
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R22:	<funcion> ::=function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }
;D:	x
;R21:	<funciones> ::= 
;R20:	<funciones> ::= <funcion> <funciones>
main:
	mov dword [__esp], esp
;D:	=
;D:	1
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 1
	push dword eax
;R81:	<exp> ::= <constante>
;D:	;
	pop dword eax
	mov dword [_x], eax
;R43:	<asignacion> ::= <identificador> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	y
;D:	=
;D:	3
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 3
	push dword eax
;R81:	<exp> ::= <constante>
;D:	;
	pop dword eax
	mov dword [_y], eax
;R43:	<asignacion> ::= <identificador> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	resultado
;D:	=
;D:	suma
;D:	(
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	x
;D:	,

	mov eax, _x
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	y
;D:	)

	mov eax, _y
	push dword eax
;R80:	<exp> ::= <identificador>
;R92:	<resto_lista_expresiones> ::= 
;R91:	<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
	call _suma
	add esp, 8
	push dword eax
;R88:	<exp> ::= <identicador> ( <lista_expresiones> )
;D:	;
	pop dword eax
	mov dword [_resultado], eax
;R43:	<asignacion> ::= <identificador> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	resultado
;D:	;

	mov eax, _resultado
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
;D:	resultado
;D:	=
;D:	suma
;D:	(
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	x
;D:	,

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
;R92:	<resto_lista_expresiones> ::= 
;R91:	<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
	call _suma
	add esp, 8
	push dword eax
;R88:	<exp> ::= <identicador> ( <lista_expresiones> )
;D:	;
	pop dword eax
	mov dword [_resultado], eax
;R43:	<asignacion> ::= <identificador> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	resultado
;D:	;

	mov eax, _resultado
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
;D:	resultado
;D:	=
;D:	suma
;D:	(
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	10
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 10
	push dword eax
;R81:	<exp> ::= <constante>
;D:	,
;D:	y
;D:	)

	mov eax, _y
	push dword eax
;R80:	<exp> ::= <identificador>
;R92:	<resto_lista_expresiones> ::= 
;R91:	<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
	call _suma
	add esp, 8
	push dword eax
;R88:	<exp> ::= <identicador> ( <lista_expresiones> )
;D:	;
	pop dword eax
	mov dword [_resultado], eax
;R43:	<asignacion> ::= <identificador> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	resultado
;D:	;

	mov eax, _resultado
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
;D:	resultado
;D:	=
;D:	suma
;D:	(
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	3
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 3
	push dword eax
;R81:	<exp> ::= <constante>
;D:	,
;D:	5
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 5
	push dword eax
;R81:	<exp> ::= <constante>
;D:	)
;R92:	<resto_lista_expresiones> ::= 
;R91:	<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
	call _suma
	add esp, 8
	push dword eax
;R88:	<exp> ::= <identicador> ( <lista_expresiones> )
;D:	;
	pop dword eax
	mov dword [_resultado], eax
;R43:	<asignacion> ::= <identificador> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	resultado
;D:	;

	mov eax, _resultado
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
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
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
