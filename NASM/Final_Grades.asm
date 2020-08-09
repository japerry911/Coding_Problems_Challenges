;Create a function finalGrade, which calculates the final grade of a student
;depending on two parameters: a grade for the exam and a number of completed
;projects.

;This function should take two arguments: exam - grade for exam (from 0 to 100);
;projects - number of completed projects (from 0 and above);

;This function should return a number (final grade). There are four types of
;final grades:

;100, if a grade for the exam is more than 90 or if a number of completed
;projects more than 10.
;90, if a grade for the exam is more than 75 and if a number of completed
;projects is minimum 5.
;75, if a grade for the exam is more than 50 and if a number of completed
;projects is minimum 2.
;0, in other cases

global      _final_grade
section     .text

_final_grade:
    xor       eax, eax

    cmp       edi, 90
    jg        One_Hundred

    cmp       esi, 10
    jg        One_Hundred

    cmp       edi, 75
    jg        Ninety

_Failed_Ninety_Label:

    cmp       edi, 50
    jg        Seventy_Five

_Failed_Seventy_Five_Label:
    
    mov       eax, 0
    ret

One_Hundred:
    mov       eax, 100
    ret

Ninety:
    cmp       esi, 5
    jge       Ninety_Complete
    jmp       _Failed_Ninety_Label

Ninety_Complete:
    mov       eax, 90
    ret

Seventy_Five:
    cmp       esi, 2
    jge       Seventy_Five_Complete
    jmp       _Failed_Seventy_Five_Label

Seventy_Five_Complete:
    mov       eax, 75
    ret