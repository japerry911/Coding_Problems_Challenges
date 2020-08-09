section .text
global sum_array

sum_array:
  xor     rax, rax
  cmp     rsi, 0
  je      empty

array_loop:
  add     rax, [rdi]
  add     rdi, 4
  dec     rsi
  cmp     rsi, 0
  jne     array_loop
  
  ret
  
empty:
  mov     rax, 0
  ret
