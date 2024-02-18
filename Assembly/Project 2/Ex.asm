bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;Ex 1 1+9
        ;mov AH,1
        ;mov AL,9
        ;ADD AH,AL
    
        
        ;Ex2 1+15
        ;mov AH,1
        ;mov AL,15
        ;add AH,AL
    
        ;EX3 128+128
        ;mov AX, 128
        ;mov BX, 128
        ;add AX,BX
        
        
        ;Ex4 5-6
        ;mov AH,5
        ;mov AL,6
        ;sub AH,AL
        
        
        ;Ex5 10/4
        ;mov AX,10
        ;mov AL,6
        ;div AX
        
        ;Ex6 256*1
		;mov AX,256
		;mov DX,1
        ;mul DX
        ;push DX
        ;push AX
        ;pop EAX
		
		;Ex7 256/1
        ;mov AX,256
		;mov DX,1
        ;div DX
		
        ;Ex8 128+127
        ;mov AL,128
        ;mov BL,127
        ;add AL,BL
        
        ;Ex9 3*4
        ;mov AL,3
        ;mov DL,4
        ;mul DL
           
        ;Ex10 9=7
        ;mov AL,9
        ;add AL,7
         
        ;Ex11 128*2
        ;mov Al,128
        ;mov DL,2
        ;mul DL

        ;Ex12 4-5
        ;mov AL,4
        ;sub AL,5

        ;Ex13 2+8
        ;mov AL,2
        ;add AL,8
        
        ;Ex14 -2*5
        ;mov AL,-2
        ;mov DL,5
        ;mul DL
        
        ;Ex15 6*3
        ;mov Al,6
        ;mov DL,3
        ;mul DL
        
        ;Ex16 4*4
        ;mov AL,4
        ;mov DL,4
        ;mul DL
        
        ;Ex17 14+2
        ;mov AL,14
        ;add AL,2
        
        ;Ex18 127+129
        ;mov AL,127
        ;add AL,129
        
        ;Ex19 12/4
        ;mov AX,12
        ;mov DL,4
        ;div DL
        
        ;Ex20 13/3
        ;mov AX,13
        ;mov DL,3
        ;div DL
        
        ;Ex21 15/3
        ;mov AX,15
        ;mov DL,3
        ;div DL
        
        ;Ex22 16/4
        ;mov AX,16
        ;mov DL,4
        ;div DL
        
        ;Ex23 64*4
        mov
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
