section	.text
	global ft_memcpy

;void	*ft_memcpy(void *dst, const void *src, size_t n)
;Moves n bytes from src to dst. Memory areas should not overlap.
;Returns pointer to dst.
;rcx=dst	rdx=src		r8=n		r9=
ft_memcpy:
	xor		r9, r9
	cmp		r9, r8
	je		return
memcpy_loop:
	movzx	r10d, byte [rdx + r9]
	mov		byte [rcx + r9], r10b
	inc		r9
	cmp		r9, r8
	jb		memcpy_loop
return:
	mov		rax, rcx
	ret
