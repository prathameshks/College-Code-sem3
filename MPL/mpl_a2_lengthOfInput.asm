%macro print 2            ;macro declaration with 4 parameters
mov rax,1                ;1st parameter has been moved to rax
mov rdi,1                ;2nd parameter has been moved to rdi
mov rsi,%1           ;3rd parameter has been moved to rsi
mov rdx,%2           ;4th parameter has been moved to rdx
syscall          ;Call the Kernal
%endmacro         ;end of macro


%macro read 2      ;macro declaration with 4 parameters
mov rax,0       ;1st parameter has been moved to rax
mov rdi,0     ;2nd parameter has been moved to rdi
mov rsi,%1   ;3rd parameter has been moved to rsi
mov rdx,%2      ;4th parameter has been moved to rdx
syscall     ;Call the Kernal
%endmacro     ;end of macro


section .data                               ;.data begins here
    m db 10,"Assembbly Program To display the Length of Input String",10
    l equ $-m
    m1 db 10d,13d,"Enter a string: "    ;m1 variable initialised with string
    l1 equ $-m1                         ;l1 stores length of string m1
    m2 db 10d,13d,"Entered String: "    ;m2 variable initialised with string
    l2 equ $-m2                         ;l2 stores length of string m2
    m3 db 10d,13d,"Length: "            ;m3 variable initialised with string
    l3 equ $-m3                         ;l3 stores length of string m3
        
section .bss                    ;.bss begins here
    buffer resb 50                      ;buffer array of size 50
    size equ $-buffer                   ;size variable to have input
    count resd 1                        ;to store size of buffer
    dispnum resb 4                      ;to display 16 digit length
        
section .text                               ;.text begins here
    global _start                       ;moving to _start label
    _start:                             ;_start label
        print m,l
        print m1,l1             ;macro call to display m1
        read buffer,size       ;macro call to input buffer
        mov [count],rax             ;length of buffer gets stored in count
        print m2,l2             ;macro call to display m2
        print buffer,[count]    ;macro call to display buffer
        call display
            
    Exit:
        mov rax,60                   ;sys_exit function
        mov rbx,0                   ;Sucessful Termination
        syscall                     ;Call the Kernel
                
    
    display:      
        mov rsi,dispnum+3          ;rsi points to 16th location of dispnum
        mov rax,[count]             ;rax now stores value of count
        mov rcx,4                   ;rcx gets initiaised with 16
        dec rax                     ;decrement the value of rax
    UP1:                                ;UP1 label
        mov rdx,0                   ;rdx gets initiaised with 0
        mov rbx,10                  ;rbx gets initialised with 10
        div rbx                     ;divide the contents of rax by rbx
        add dl,30h                  ;add 30 to the remainder
        mov [rsi],dl                ;dl content gets copied at rsi 
        dec rsi                     ;decrement rsi
        loop UP1                    ;jump to UP1 till rcx becomes 0
        print m3,l3             ;macro call to display m3
        print dispnum+2,2         ;macro call to display dispnum array
ret
                
                
;nasm -f elf64 mpl_a2_lengthOfInput.asm; ld -o a mpl_a2_lengthOfInput.o; ./a 