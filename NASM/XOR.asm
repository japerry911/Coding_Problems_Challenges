section     .text
global      xorf

xorf:
  xor       rax, rax
  xor       rdi, rsi
  mov       rax, rdi
  ret  