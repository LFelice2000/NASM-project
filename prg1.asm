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
;D:	z
	_z resd 1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
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
;D:	scanf
;D:	y
	push dword _y
	call scan_int
	add esp, 4

;R54:	<lectura> ::= scanf <identificador>
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	scanf
;D:	z
	push dword _z
	call scan_int
	add esp, 4

;R54:	<lectura> ::= scanf <identificador>
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	if
;D:	(
;D:	(
;D:	x
;D:	==

	mov eax, _x
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 0
	push dword eax
;R81:	<exp> ::= <constante>
;D:	)
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, ebx
	jz near etiqueta0
	push dword 0
	jmp end0

etiqueta0:
	push dword 1

end0:

;R93:	<comparacion> ::= <exp> == <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	==

	mov eax, _y
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 0
	push dword eax
;R81:	<exp> ::= <constante>
;D:	)
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, ebx
	jz near etiqueta1
	push dword 0
	jmp end1

etiqueta1:
	push dword 1

end1:

;R93:	<comparacion> ::= <exp> == <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
	pop dword edx
	pop dword eax
	and eax, edx
	push dword eax

;R77:	<exp> ::= <exp> && <exp>
;D:	(
;D:	z
;D:	==

	mov eax, _z
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 0
	push dword eax
;R81:	<exp> ::= <constante>
;D:	)
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, ebx
	jz near etiqueta2
	push dword 0
	jmp end2

etiqueta2:
	push dword 1

end2:

;R93:	<comparacion> ::= <exp> == <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	)
	pop dword edx
	pop dword eax
	and eax, edx
	push dword eax

;R77:	<exp> ::= <exp> && <exp>
;D:	{
	pop dword eax
	cmp eax, 0
	je near end_if0

;D:	printf
;D:	0
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 0
	push dword eax
;R81:	<exp> ::= <constante>
;D:	;
	pop dword eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline

;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	else
;D:	{
;D:	if
;D:	(
;D:	(
;D:	x
;D:	>

	mov eax, _x
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 0
	push dword eax
;R81:	<exp> ::= <constante>
;D:	)
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax, ebx
	jg near etiqueta3
	push dword 0
	jmp end3

etiqueta3:
	push dword 1

end3:

;R98:	<comparacion> ::= <exp> > <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	>

	mov eax, _y
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 0
	push dword eax
;R81:	<exp> ::= <constante>
;D:	)
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax, ebx
	jg near etiqueta4
	push dword 0
	jmp end4

etiqueta4:
	push dword 1

end4:

;R98:	<comparacion> ::= <exp> > <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	)
	pop dword edx
	pop dword eax
	and eax, edx
	push dword eax

;R77:	<exp> ::= <exp> && <exp>
;D:	{
	pop dword eax
	cmp eax, 0
	je near end_if1

;D:	if
;D:	(
;D:	(
;D:	z
;D:	>

	mov eax, _z
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 0
	push dword eax
;R81:	<exp> ::= <constante>
;D:	)
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax, ebx
	jg near etiqueta5
	push dword 0
	jmp end5

etiqueta5:
	push dword 1

end5:

;R98:	<comparacion> ::= <exp> > <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;D:	{
	pop dword eax
	cmp eax, 0
	je near end_if2

;D:	printf
;D:	1
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 1
	push dword eax
;R81:	<exp> ::= <constante>
;D:	;
	pop dword eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline

;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	else
;D:	{
;D:	printf
;D:	5
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 5
	push dword eax
;R81:	<exp> ::= <constante>
;D:	;
	pop dword eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline

;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
	jmp near fin_ifelse3


end_if3:
;R51	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	if

fin_ifelse3:;R50	<condicional> ::= if ( <exp> ) { <sentencias> }
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	x
;D:	<

	mov eax, _x
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 0
	push dword eax
;R81:	<exp> ::= <constante>
;D:	)
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax, ebx
	jl near etiqueta6
	push dword 0
	jmp end6

etiqueta6:
	push dword 1

end6:

;R97:	<comparacion> ::= <exp> < <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	>

	mov eax, _y
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 0
	push dword eax
;R81:	<exp> ::= <constante>
;D:	)
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax, ebx
	jg near etiqueta7
	push dword 0
	jmp end7

etiqueta7:
	push dword 1

end7:

;R98:	<comparacion> ::= <exp> > <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	)
	pop dword edx
	pop dword eax
	and eax, edx
	push dword eax

;R77:	<exp> ::= <exp> && <exp>
;D:	{
	pop dword eax
	cmp eax, 0
	je near end_if3

;D:	if
;D:	(
;D:	(
;D:	z
;D:	>

	mov eax, _z
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 0
	push dword eax
;R81:	<exp> ::= <constante>
;D:	)
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax, ebx
	jg near etiqueta8
	push dword 0
	jmp end8

etiqueta8:
	push dword 1

end8:

;R98:	<comparacion> ::= <exp> > <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;D:	{
	pop dword eax
	cmp eax, 0
	je near end_if4

;D:	printf
;D:	2
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 2
	push dword eax
;R81:	<exp> ::= <constante>
;D:	;
	pop dword eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline

;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	else
;D:	{
;D:	printf
;D:	6
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 6
	push dword eax
;R81:	<exp> ::= <constante>
;D:	;
	pop dword eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline

;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
	jmp near fin_ifelse5


end_if5:
;R51	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	if

fin_ifelse5:;R50	<condicional> ::= if ( <exp> ) { <sentencias> }
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	x
;D:	<

	mov eax, _x
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 0
	push dword eax
;R81:	<exp> ::= <constante>
;D:	)
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax, ebx
	jl near etiqueta9
	push dword 0
	jmp end9

etiqueta9:
	push dword 1

end9:

;R97:	<comparacion> ::= <exp> < <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	<

	mov eax, _y
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 0
	push dword eax
;R81:	<exp> ::= <constante>
;D:	)
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax, ebx
	jl near etiqueta10
	push dword 0
	jmp end10

etiqueta10:
	push dword 1

end10:

;R97:	<comparacion> ::= <exp> < <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	)
	pop dword edx
	pop dword eax
	and eax, edx
	push dword eax

;R77:	<exp> ::= <exp> && <exp>
;D:	{
	pop dword eax
	cmp eax, 0
	je near end_if5

;D:	if
;D:	(
;D:	(
;D:	z
;D:	>

	mov eax, _z
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 0
	push dword eax
;R81:	<exp> ::= <constante>
;D:	)
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax, ebx
	jg near etiqueta11
	push dword 0
	jmp end11

etiqueta11:
	push dword 1

end11:

;R98:	<comparacion> ::= <exp> > <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;D:	{
	pop dword eax
	cmp eax, 0
	je near end_if6

;D:	printf
;D:	3
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 3
	push dword eax
;R81:	<exp> ::= <constante>
;D:	;
	pop dword eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline

;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	else
;D:	{
;D:	printf
;D:	7
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 7
	push dword eax
;R81:	<exp> ::= <constante>
;D:	;
	pop dword eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline

;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
	jmp near fin_ifelse7


end_if7:
;R51	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	if

fin_ifelse7:;R50	<condicional> ::= if ( <exp> ) { <sentencias> }
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	x
;D:	>

	mov eax, _x
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 0
	push dword eax
;R81:	<exp> ::= <constante>
;D:	)
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax, ebx
	jg near etiqueta12
	push dword 0
	jmp end12

etiqueta12:
	push dword 1

end12:

;R98:	<comparacion> ::= <exp> > <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	<

	mov eax, _y
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 0
	push dword eax
;R81:	<exp> ::= <constante>
;D:	)
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax, ebx
	jl near etiqueta13
	push dword 0
	jmp end13

etiqueta13:
	push dword 1

end13:

;R97:	<comparacion> ::= <exp> < <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	)
	pop dword edx
	pop dword eax
	and eax, edx
	push dword eax

;R77:	<exp> ::= <exp> && <exp>
;D:	{
	pop dword eax
	cmp eax, 0
	je near end_if7

;D:	if
;D:	(
;D:	(
;D:	z
;D:	>

	mov eax, _z
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 0
	push dword eax
;R81:	<exp> ::= <constante>
;D:	)
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax, ebx
	jg near etiqueta14
	push dword 0
	jmp end14

etiqueta14:
	push dword 1

end14:

;R98:	<comparacion> ::= <exp> > <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;D:	{
	pop dword eax
	cmp eax, 0
	je near end_if8

;D:	printf
;D:	4
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 4
	push dword eax
;R81:	<exp> ::= <constante>
;D:	;
	pop dword eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline

;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	else
;D:	{
;D:	printf
;D:	8
;R104:	<constante_entera> ::= <numero>
;R100:	<constante> ::= <constante_entera

	mov eax, 8
	push dword eax
;R81:	<exp> ::= <constante>
;D:	;
	pop dword eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline

;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
	jmp near fin_ifelse9


end_if9:
;R51	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	}

fin_ifelse9:;R50	<condicional> ::= if ( <exp> ) { <sentencias> }
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
	jmp near fin_ifelse9


end_if9:
;R51	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
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
