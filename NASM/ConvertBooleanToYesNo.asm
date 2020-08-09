/*
---Convert Boolean to Yes or No---
Complete the method that takes a boolean value and return a "Yes" string for true, or a "No" string for false.
*/

section     .text
global      bool_to_word

bool_to_word:
    xor         rax, rax
        
    cmp         di, 1
    jge          _yes
    
    mov         rax, no
    ret

_yes:
    mov         rax, yes
    ret

section       .data
    yes:    db  "Yes", 0
    no:     db  "No", 0
