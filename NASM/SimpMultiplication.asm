section     .text
global      _simple_multiplication

_simple_multiplication:
    xor     rax, rax
    xor     rcx, rcx
    xor     rdx, rdx

    mov     rax, rdi
    mov     rcx, 2

    div     rcx
    
    cmp     rdx, 1
    jz      _nine
    jmp     _eight

_nine:
    mov     rcx, 9
    jmp     _finish

_eight:
    mov     rcx, 8
    jmp     _finish

_finish:
    mov     rax, rdi
    mul     rcx
    ret
