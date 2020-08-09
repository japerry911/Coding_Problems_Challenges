/*
---Nth Even Number---
Return the Nth Even Number

nthEven(1) //=> 0, the first even number is 0
nthEven(3) //=> 4, the 3rd even number is 4 (0, 2, 4)

nthEven(100) //=> 198
nthEven(1298734) //=> 2597466
The input will not be 0.
*/

SECTION     .text
global      _nth_even

_nth_even:
    xor       eax, eax
    mov       edx, 1

    cmp       edi, 1
    jz        _exit

    mov       eax, 2
    imul      eax, edi
    sub       eax, 2
    
_exit:
    ret
