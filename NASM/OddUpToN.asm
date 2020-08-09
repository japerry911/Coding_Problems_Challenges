section     .text
global      _oddcnt

_oddcnt:
    xor     rax, rax
    xor     rcx, rcx

_loop:
    test    rdi, 1
    jz      _increment_counter
_mid_loop:
    dec     rdi
    cmp     rdi, 0
    jne     _loop

    mov     rax, rcx
    ret

_increment_counter:
    inc     rcx
    jmp     _mid_loop

