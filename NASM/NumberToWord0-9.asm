section .text
global switch_it_up

switch_it_up:
  cmp   edi, 0
  je    _zero

  cmp    edi, 1
  je     _one
  
  cmp    edi, 2
  je     _two
  
  cmp    edi, 3
  je     _three
  
  cmp    edi, 4
  je     _four
  
  cmp    edi, 5
  je     _five
  
  cmp    edi, 6
  je     _six
  
  cmp    edi, 7
  je     _seven
  
  cmp    edi, 8
  je     _eight
  
  cmp    edi, 9
  je     _nine
  
_zero:
  mov    eax, zero
  ret
  
_one:
  mov    eax, one
  ret
    
_two:
  mov    eax, two
  ret
  
_three:
  mov    eax, three
  ret
  
_four:
  mov    eax, four
  ret
  
_five:
  mov    eax, five
  ret
  
_six:
  mov    eax, six
  ret
  
_seven:
  mov    eax, seven
  ret
  
_eight:
  mov    eax, eight
  ret
  
_nine:
  mov    eax, nine
  ret
  
section  .data
zero:   db  "Zero", 0
one:    db  "One", 0
two:    db  "Two", 0
three:  db  "Three", 0
four:   db  "Four", 0
five:   db  "Five", 0
six:    db  "Six", 0
seven:  db  "Seven", 0
eight:  db  "Eight", 0
nine:   db  "Nine", 0