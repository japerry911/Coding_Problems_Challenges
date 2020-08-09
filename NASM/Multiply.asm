global     multiply
section   .text

multiply:
  xor      eax, eax
  mov      eax, edi
  mul      esi
  ret