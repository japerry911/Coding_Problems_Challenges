section         .text
global          _has_digits

_has_digits:
    xor     rax, rax
    xor     rdx, rdx
    xor     rsi, rsi

    cmp     rdi, 0
    jz      _False

    dec     rdx
    
_string_loop:
    inc     rdx
    mov     sil, [rdi + rdx]

    cmp     sil, 0
    jz      _False
    
    cmp     sil, 0x30
    jge     _Potential_Digit
    
    jmp     _string_loop

_False:
    mov     rax, 0
    ret

_Potential_Digit:
    cmp     sil, 0x39
    jg      _string_loop
    mov     rax, 1
    ret
