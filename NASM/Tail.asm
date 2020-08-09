section      .text
global       _correct_tail

_correct_tail:
    xor     rax, rax
    xor     rdx, rdx

_string_loop:
    inc     rdx
    cmp     [rdi + rdx], BYTE 0
    jz      _check_last_letter
    jmp     _string_loop

_check_last_letter:
    dec     rdx
    mov     cl, [rsi]
    cmp     [rdi + rdx], BYTE cl
    jz      _matching_tail
    
    ret

_matching_tail:
    mov     rax, 1
    ret
