/*
---Boolean to String---
Implement a function which convert the given boolean value into its string representation.
*/

SECTION .text
global boolean_to_string

boolean_to_string:
  cmp    edi, 1
  je     .true
  cmp    edi, 0
  je     .false
  
  .true:
  mov    eax, true
  ret
  
  .false:
  mov    eax, false
  ret
  
SECTION .data
  true    DB  'true', 0
  false   DB  'false', 0

/*SECTION .text
global boolean_to_string

boolean_to_string:
  cmp    edi, 1
  je     true_bool
  cmp    edi, 0
  je     false_bool
  
true_bool:
  mov    rax, true
  ret

false_bool:
  mov    rax, false
  ret
  
SECTION .data
  false   DW   'false'
  true    DW   'true'
*/