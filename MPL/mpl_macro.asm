section .data

msg1 db "India is best",10

msg1l equ $-msg1

%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro firstchar 1
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,1
syscall
%endmacro


section .bss

section .txt
global _start:
_start:

print msg1,msg1l

firstchar msg1

mov rax,60
syscall
