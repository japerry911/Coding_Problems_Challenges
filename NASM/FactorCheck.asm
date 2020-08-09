section .text
global _check_for_factor

_check_for_factor:
  xor    rax, rax
  xor    rdx, rdx

  mov    rax, rdi
  div    rsi
    
  xor    rax, rax

  cmp    rdx, 0
  jnz     _False
  jmp    _True
  
_False:
  mov    al, 0
  ret

_True:
  mov    al, 1
  ret
