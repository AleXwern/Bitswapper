section	.text
   global ft_memset

;void	*ft_memset(void *b, int c, size_t len)
;Sets len bytes from pointer b to c and returns the pointer to it.
;rdi=b	rsi=c	rdx=len
;rcx=b	rdx=c	r8=len		r9=
ft_memset:
	test	rcx, rcx
	jz		return					;jump to return if pointer is null
	xor		r9, r9					;RCX is used as counter for bytes set
memset_loop:
	mov		byte [rcx+r9], dl
	inc		r9
	cmp		r9, r8
	jb		memset_loop				;Continue loop is len bytes are not set
return:
	mov		rax, rcx
	ret
