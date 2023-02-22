section .data

msg1 db 9,"India is best",10

msg1l equ $-msg1

%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro universal 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro


section .bss

section .txt
global _start:
_start:

universal 1,1,msg1,msg1l
universal 1,1,msg1,msg1l
universal 1,1,msg1,msg1l


mov rax,60
syscall
