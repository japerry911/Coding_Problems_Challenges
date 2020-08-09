/*
---Clock #2---
Clock shows 'h' hours, 'm' minutes and 's' seconds after midnight.

Your task is to make 'Past' function which returns time converted to milliseconds.

Example:
past(0, 1, 1) == 61000
Input constraints: 0 <= h <= 23, 0 <= m <= 59, 0 <= s <= 59
*/

global past

section .text

past:
    mov     eax, edi
    imul    eax, 3600000
    mov     ecx, esi
    imul    ecx, 60000
    add     eax, ecx
    mov     ecx, edx
    imul    ecx, 1000
    add     eax, ecx
    ret