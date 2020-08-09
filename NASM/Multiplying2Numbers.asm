/*
---Multiplying 2 Numbers---
Implement a function which multiplies two numbers.
*/

SECTION .text
global multiply

multiply:
  xor    eax, eax
  imul   edi, esi
  mov    eax, edi
  ret