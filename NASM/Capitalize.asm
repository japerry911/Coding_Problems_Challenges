section    .text
global     changeCase

changeCase:
  xor      ax,ax                   ; Initialize ax Return Register
  
  cmp      di,0x41                 ; Compare input char (di Register) to 0x41 (A) 
  jge      _Possible_Letter1       ; If greater than or equal to 0x41, jump to Possible_Letter1
  
_Return_NonValid_Char:
  mov      ax,di                   ; Mov nonvalid letter into ax Return Register
  ret                              ; Return ax Register
  
_Possible_Letter1:
  cmp      di,0x5A                ; Compare input char (di Register) to 0x5A (Z)
  jg       _Possible_Letter2       ; If greater than 0x51, jump to _Possible_Letter2
  jmp      _ChangeCase             ; Confirmed Letter otherwise, go to ChangeCase
  
_Possible_Letter2:
  cmp      di,0x61                ; Compare input char (di Register) to 0x61 (a)
  jl       _Return_NonValid_Char  ; Invalid Character, return input, jump to _Return_NonValid_Char
  cmp      di,0x7A                ; Compare input char (di Register) to 0x7A (z)
  jg       _Return_NonValid_Char  ; Invalid Character, return input, jump to _Return_NonValid_Char
  jmp      _ChangeCase            ; Valid Character, go to _ChangeCase
  
_ChangeCase:
  xor      di, 0x20               ; ChangeCase of character by running XOR on the input register & 0x20
  mov      ax, di                 ; Mov the final modified/case-changed input to ax
  ret                             ; Return ax Register