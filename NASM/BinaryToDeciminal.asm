/*
---Binary to Decimal---
Complete the function which converts a binary number (given as a string) to a decimal number.
*/

global _bin_to_dec

section .text

_bin_to_dec:
    xor         rax, rax
    xor         r9, r9
    xor         rsi, rsi
    xor         rcx, rcx
    
    mov         r10, 2
    dec         rsi
    
_calc_length:
    inc         r9
    inc         rsi
    cmp         BYTE [rdi + rsi], 0
    jnz         _calc_length

    dec         r9
    xor         rsi, rsi
    dec         rsi

_calc_decimal_loop:
    add          rcx, rax
    xor          rax, rax
    inc          rsi
    dec          r9
    cmp          r9, 0
    jnz          _binary_check
    cmp          BYTE [rdi + rsi], '1'
    je           _add_one

    mov          rax, rcx
    ret

_add_one:
    add          rcx, 1
    mov          rax, rcx
    ret

_binary_check:
    xor          r11, r11
    add          r11, r9
    mov          rax, 1
    cmp          BYTE [rdi + rsi], '1'
    je           _calc_power_of_two
    mov          rax, 0
    jmp          _calc_decimal_loop

_calc_power_of_two:
    mul          r10
    dec          r11
    cmp          r11, 0
    jnz          _calc_power_of_two
    jmp          _calc_decimal_loop
