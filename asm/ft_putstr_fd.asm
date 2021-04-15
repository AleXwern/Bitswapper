extern ft_strlen
section	.text
	global ft_putstr_fd
	
;void	ft_putstr(const char *s, int fd)
;Prints null terminated string s to set output.
;rdi=s	rsi=fd
ft_putstr_fd:
	call	ft_strlen	;Get string length -> RAX

	mov     rdx, rax	;length
	mov     rcx, rdi	;string
	push	rbx
	mov     rbx, rsi	;fd
	mov     rax, 4		;write
	int     80h
	pop		rbx

	ret
