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
msglen1 equ $-msg1

msg2 db "Negetive numbers are :"
msglen2 equ $-msg2

;creating array of hexadecimal numbers 

array dq 12h,1h,90h,1ah,5h,32h,76h
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
	bt qword[rsi],07 ;bit test
	jnc pnxt ;jump not carry
	inc byte[ncnt]
	jmp pskip
	pnxt: inc byte[pcnt]
	pskip: inc rsi
loop again

print msg1,msglen1
mov bl,[pcnt]
call disp_result
print newline,1
print msg2,msglen2
mov bl,[ncnt]
call disp_result
print newline,1

mov rax,60
mov rdi,0
syscall


disp_result:
	mov rdi,dispbuff
	mov rcx,02
	dispup:
		rol bl,4
		mov dl,bl
		and dl,0fh
		add dl,30h
		cmp dl,39h
		jbe dispskip
		add dl,07h
	dispskip:
		mov [rdi],dl
		inc rdi
		loop dispup
		print dispbuff,2
	ret

; nasm -f elf64 mpl_a1_countNumbers.asm ;ld -o a mpl_a1_countNumbers.o;./a
