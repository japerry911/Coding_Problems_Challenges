/*
---Abbreviate Name---
Write a function to convert a name into initials. This kata strictly 
takes two words with one space in between them.

The output should be two capital letters with a dot separating them.

It should look like this:

Sam Harris => S.H

Patrick Feeney => P.F
*/

section .text

global abbrev_name
; void abbrev_name(const char *name, char *output)
; Take the input `name` and write the output to `output`.
; Don't forget to add a null byte at the end!
abbrev_name:
  mov   dl, [rdi]
  and   dl, ~0x20
  mov   [rsi], dl
  mov   byte [rsi + 1], `.`
  
  
  ;Loop until start of last name
  .loop
  inc   rdi
  mov   dl, [rdi]
  cmp   dl, " "
  jne   .loop
  inc   rdi
  mov   dl, [rdi]
  
  and    dl, ~0x20
  mov   byte [rsi + 2], dl
  
  mov   byte [rsi + 3], `\0`
  ret