section	.text
	global ft_rotate_left

;unsigned int	ft_rotate_left(unsigned int num)
;Rotates integer num left by 1 byte. Bits that go over left border go back to right end.
;No apparent C implementation so I'll do it myself.
;rdi=num
ft_rotate_left:
	rol		ecx, 8
	mov		eax, ecx
	ret
