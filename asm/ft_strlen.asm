section	.text
	global ft_strlen
	
ft_strlen:	;Prep. get string from RDI and store pointer in RAX/RBX
	push	rbx
	mov		rbx, rdi
	mov		rax, rdi
getchar:	;Compare character to 0 to see if we are at end. If 0 jump to return.
	cmp		byte [rax], 0
	jz		done
	inc		rax
	jmp		getchar
done:		;subtract RBX addr ftom RAX addr to see how many bytes we moved.
	sub		rax, rbx
	pop		rbx
	ret
