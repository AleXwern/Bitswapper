section	.text
   global ft_bswap

;t_uint32	ft_bswap(t_uint32 n)
;Makes use of bswap instruction and swaps bytes around for 32-bit integer.
;Can be used to convert values between little and big-endian.
;ecx=n
ft_bswap:
    bswap   ecx
    mov     eax, ecx
    ret