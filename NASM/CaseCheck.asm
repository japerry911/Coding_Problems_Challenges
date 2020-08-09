/*
Is the string uppercase?
Task
Create a method is_uppercase() to see whether the string is ALL CAPS. For example:

is_uppercase("c") == False
is_uppercase("C") == True
is_uppercase("hello I AM DONALD") == False
is_uppercase("HELLO I AM DONALD") == True
is_uppercase("ACSKLDFJSgSKLDFJSKLDFJ") == False
is_uppercase("ACSKLDFJSGSKLDFJSKLDFJ") == True
In this Kata, a string is said to be in ALL CAPS whenever it does not contain any lowercase letter 
so any string containing no letters at all is trivially considered to be in ALL CAPS.
*/

section     .text
global      _is_uppercase

_is_uppercase:
    xor     rax, rax
    xor     rsi, rsi
    
    dec     rsi

_check_loop:
    inc     rsi
    
    cmp     byte [rdi + rsi], 0
    je      _end

    cmp     byte [rdi + rsi], 97
    jge     _potential_false
    
    jmp     _check_loop

_end:
    mov     rax, 1
    ret

_potential_false:
    cmp     byte [rdi + rsi], 122
    jle     _false
    jmp     _check_loop

_false:
    mov     rax, 0
    ret
