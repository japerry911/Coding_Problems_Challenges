section     .text
global      _fakebin

_fakebin:
    xor     rax, rax
    xor     rdx, rdx
    xor     rcx, rcx

    dec     rdx
    
_loop:
    inc     rdx
    mov     cl, [rdi + rdx]

    cmp     cl, 0
    jz      _exit

    cmp     cl, 0x35
    jge     _one

    cmp     cl, 0x35
    jl      _zero

    jmp     _loop

_one:
    mov     [rsi + rdx], BYTE '1'
    jmp     _loop

_zero:
    mov     [rsi + rdx], BYTE '0'
    jmp     _loop
    

_exit:
    mov     [rsi + rdx], BYTE 0
    mov     rax, rsi
    ret
