section    .text
global     _if

_if:
  xor      rax, rax
  
  cmp      rdi, 1
  jz       _true
  jmp      _false
  
_true:
  call     rsi
  ret
  
_false:
  call      rdx
  ret