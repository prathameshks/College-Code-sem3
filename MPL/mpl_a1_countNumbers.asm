%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro


section .data

msg db "Counting +ve and -ve elements of array.",10
msgl equ $-msg

msg1 db "Positive numbers are :"
msg1l equ $-msg1

msg2 db "Negetive numbers are :"
msg2l equ $-msg2

;creating array of hexadecimal numbers 

array db 12h,1h,90h,1ah,5h,32h,76h
;h - hexadecimal
;d - decimal
;o - octal

pcnt db 0
ncnt db 0
newline db 10


section .bss
dispbuff resb 2

section .text
global _start:
_start:


print msg,msgl

mov rsi,array
;point to start of array
mov rcx,07
;counter register


again:
;name of my loop

	bt byte[rsi],7 ;bit test
	jnc pnxt ;jump not carry




mov rax,60
syscall

; nasm -f elf64 mpl_a1_countNumbers.asm ;ld -o a mpl_a1_countNumbers.o;./a
