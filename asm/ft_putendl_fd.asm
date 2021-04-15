extern ft_putstr_fd
section	.text
	global ft_putendl_fd
	
ft_putendl_fd:
	call	ft_putstr_fd
	push	rdi
	mov     rdi, endl
	call	ft_putstr_fd
	pop		rdi
	ret

section .data			;For some reason I couldn't get the addr of variabe with 0xA
	endl	db 0xa,0x0	;so I made a define that's printed instead
