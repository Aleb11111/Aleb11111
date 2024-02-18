bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    ; ...
       file_name db "file.txt", 0
       access_mode db "r", 0
       file_descriptor dd 0
       nr dd 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        push dword [file_descriptor]
        push dword 1
        push dword 1
        push dword nr        
        call [fread]
        add esp, 4*4
        push dword eax
        call [printf]
        add esp, 4*1
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
