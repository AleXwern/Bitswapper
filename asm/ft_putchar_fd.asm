section	.text
   global ft_putchar_fd
	
ft_putchar_fd:
	mov     rdx, 1		;length
	mov     [rcx], rdi	;string
	mov     rbx, rsi	;fd
	mov     rax, 4		;write
	int     80h
	ret
