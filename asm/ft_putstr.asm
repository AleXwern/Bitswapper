extern ft_putstr_fd
section	.text
	global ft_putstr
	
ft_putstr:
	mov		rsi, 1
	call	ft_putstr_fd
	ret
