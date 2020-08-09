section     .text
global      _get_count

_get_count:
    xor     rax, rax
    xor     rdx, rdx
    xor     rcx, rcx

    dec     rdx

_string_loop:
    inc     rdx
    cmp     [rdi + rdx], BYTE 0
    jz      _exit
    cmp     [rdi + rdx], BYTE 'a'
    jz      _increment
    cmp     [rdi + rdx], BYTE 'e'
    jz      _increment
    cmp     [rdi + rdx], BYTE 'i'
    jz      _increment
    cmp     [rdi + rdx], BYTE 'o'
    jz      _increment
    cmp     [rdi + rdx], BYTE 'u'
    jz      _increment
    jmp     _string_loop

_increment:
    inc     rcx
    jmp     _string_loop

_exit:
    mov     rax, rcx
    ret
