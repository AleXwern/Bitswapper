section	.text
	global ft_rotate_right

;unsigned int	ft_rotate_right(unsigned int num)
;Rotates integer num right by 1 byte. Bits that go over right border go back to left end.
;No apparent C implementation so I'll do it myself.
;rdi=num
ft_rotate_right:
	ror		ecx, 8
	mov		eax, ecx
	ret
