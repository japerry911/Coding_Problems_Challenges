/*
---Character Recognition Software Corrections---
Character recognition software is widely used to digitise printed texts. 
Thus the texts can be edited, searched and stored on a computer.

When documents (especially pretty old ones written with a typewriter), are 
digitised character recognition softwares often make mistakes.

Your task is correct the errors in the digitised text. You only have to 
handle the following mistakes:

S is misinterpreted as 5
O is misinterpreted as 0
I is misinterpreted as 1
The test cases contain numbers only by mistake.
*/

; Please modify the string in-place and return it.
SECTION .text
global correct

correct:  
  mov    ecx, 0
  
loop_string:
  cmp    byte [rdi], '0'
  je     o_exchange
  cmp    byte [rdi], '5'
  je     s_exchange
  cmp    byte [rdi], '1'
  je     i_exchange
  cmp    byte [rdi], `\0`
  jne    increment
  jmp    reset
  
increment:
  add    ecx, 1
  inc    rdi
  jmp    loop_string

reset:
  dec    rdi
  sub    ecx, 1
  cmp    ecx, 0
  je     exit
  jmp    reset
  
exit:
  mov    rax, rdi
  ret

o_exchange:
  mov    byte [rdi], 'O'
  jmp    increment
  
s_exchange:
  mov    byte [rdi], 'S'
  jmp    increment
  
i_exchange:
  mov    byte [rdi], 'I'
  jmp    increment