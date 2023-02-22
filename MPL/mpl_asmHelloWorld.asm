section .data

msg db 10, 9, "Welcome to ASM CODE",10
;msg - var name
;db - type data bytes
;10 - new line
;13 - carage return
;9 - tab

msglen equ $-msg 
;equ - type equate

msg1 db 9,"We are in SE COMP 1",10
msglen1 equ $-msg


section .bss


section .txt

global _start:
_start:

mov rax,1
mov rdi,1
mov rsi,msg
mov rdx,msglen
syscall
;syscall is permission from asm to OS for displaying on screen 


mov rax,60
syscall
;way to end the code if not written gives error as "Segmentation fault (core dumped)"



;(base) admin1@410-15:~$ nasm -f elf64 sample.asm 
;(base) admin1@410-15:~$ ld -o x sample.o
;(base) admin1@410-15:~$ ./x

;nasm -f elf64 sample.asm -o a.o; d -o x a.o; ./x
