.text
.globl      _double_integer

_double_integer:
    xor     %rax, %rax
    imul    %rdi, 2
    mov     %rdi, %rax

    ret