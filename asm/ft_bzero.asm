section	.text
   global ft_bzero

;void	ft_bzero(void *s, size_t n)
;Sets n bytes from pointer s to 0.
;Should be used effectively with sizeof(X) so error checks are left out.
;rcx=x	rdx=n	r8=		r9=
ft_bzero:
	xor		r8, r8					;RCX is used as counter for bytes set
	cmp		r8, rdx
	jae		return					;Return if n is 0
bzero_loop:
	mov		byte [rcx+r8], 0
	inc		r8
	cmp		r8, rdx
	jb		bzero_loop
return:
	ret
