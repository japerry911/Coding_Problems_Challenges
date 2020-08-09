SECTION .text
global square

square:
  imul    edi, edi
  mov     eax, edi
  ret