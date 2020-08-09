/*
---Find Smallest Integer in the Array---
Given an array of integers your solution should find the smallest integer.

For example:

Given [34, 15, 88, 2] your solution will return 2
Given [34, -345, -1, 100] your solution will return -345
You can assume, for the purpose of this kata, that the supplied array will not be empty.
*/

section .text

global find_smallest_int
; int find_smallest_int(int *array, int size)
find_smallest_int:
  mov      eax, [rdi]
  
  .loop
  dec      esi
  cmp      eax, [rdi+rsi*4]
  cmovg    eax, [rdi+rsi*4]
  cmp      esi, 0
  jne      .loop
  
  ret  