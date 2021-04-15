section	.text
   global ft_putchar
	
ft_putchar:
	mov		byte [endl+0], dil
	mov		rcx, endl	;string
	push	rbx
	mov		rdx, 1		;len
	mov		rbx, 1
	mov		rax, 4
	int     80h
	pop		rbx
	
	ret

section .data			;I had some issues with getting the pointer of value so made this
	endl	dq 0x0,0x0	;less than ideal workaround