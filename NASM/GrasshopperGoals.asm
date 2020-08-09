section    .text
global     goals

goals:
  xor      eax, eax
  add      eax, edi
  add      eax, esi
  add      eax, edx
  ret