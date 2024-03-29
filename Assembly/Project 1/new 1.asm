bits 32 
; assembling for the 32 bits architecture

; Write a program in the assembly language that computes the following arithmetic expression, considering the following data types for the variables:
; a - byte, b - word
; (b / a * 2 + 10) * b - b * 15;
; ex. 1: a = 10; b = 40; Result: (40 / 10 * 2 + 10) * 40 - 40 * 15 = 18 * 40 - 1600 = 720 - 600 = 120
; ex. 2: a = 100; b = 50; Result: (50 / 100 * 2 + 10) * 50 - 50 * 15 = 12 * 50 - 750 = 600 - 750 = - 150


; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a db 10
    b dw 40

; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;(b / a * 2 + 10) * b - b * 15;
        
        ;b/a
        mov AX, [b]
        div byte [a] ;AX/a=b/a=AL       AX%a=AH
        ;b/a*2
        mov BL, 2
        mul BL ;BL*AL=AX
        add AX,10 ;AX=(b/a*2+10)
        
        mul word [b] ; AX*b = DX:AX = (b/a*2+10)*b
        ;DX:AX -> BX:CX
        mov BX,DX
        mov CX,AX
        ;BX:CX = EBX
        push BX
        push CX
        pop EBX
           
        
        ;b*15
        mov AX,15
        mul word [b] ; AX*b = 15*b = DX:AX
        push DX
        push AX
        pop EAX
        
        ;EBX=(b / a * 2 + 10) * b 
        ;EAX =b*15
        
        sub EBX,EAX ; EBX=EBX-EAX
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
