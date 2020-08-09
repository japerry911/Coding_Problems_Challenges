section     .text
global      _get_real_floor
_get_real_floor:
    xor     eax, eax
    
    cmp     edi, 0
    jle     _zero_or_below

    xor     edx, edx
    xor     ecx, ecx

_loop:
    cmp     edx, 0
    jnz     _test_for_thirteen
_mid_loop:
    inc     edx
    cmp     edx, edi
    jnz     _loop
    
    mov     eax, ecx
    ret

_test_for_thirteen:
    cmp     edx, 13
    jnz      _increment
    jmp     _mid_loop

_increment:
    inc     ecx
    jmp     _mid_loop

_zero_or_below:
    mov     eax, edi
    ret
