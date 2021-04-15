section	.text
   global ft_test

;Used to test instructions
;rdi=1st	rsi=2nd 	rdx=3rd 	rcx=4th
ft_test:
    blsi    eax, edi
    ret
