%macro WRITE 2
mov rax, 1
mov rdi, 1
mov rsi, %1
mov rdx, %2
syscall
%endmacro

%macro READ 2
mov rax, 0
mov rdi, 0
mov rsi, %1
mov rdx, %2
syscall
%endmacro

section .data
msg1 db "Enter Multiplicant : "
len1 equ $-msg1
msg2 db "Enter Multiplier : "
len2 equ $-msg2
msg3 db "Multiplication : "
len3 equ $-msg3

section .bss
char_buff resb 17
m resq 1
n resq 1
result resq 1

section .text
global _start:
_start:
	WRITE msg1, len1
	READ char_buff, 17
	dec rax
	mov rcx, rax
	call accept
	mov [m], rbx
	
	WRITE msg2, len2
	READ char_buff, 17
	dec rax
	mov rcx, rax
	call accept
	mov [n], rbx
	
	mov rcx, [n]
	mov rbx, 00
l1:	add rbx, [m]
	dec rcx
	jnz l1
	
	mov [result], rbx
	WRITE msg3, len3
	mov rbx, [result]
	call display
	
	mov rax, 60
	mov rdi, 0
	syscall

accept: mov rsi, char_buff
	mov rbx, 00H
up1:	mov rdx, 00H
	mov dl, byte[rsi]
	cmp dl, 39H
	jbe sub30
	sub dl, 07H
sub30:	sub dl, 30H
	shl rbx, 04
	add rbx, rdx
	inc rsi
	dec rcx
	jnz up1
ret
	
display: mov rsi, char_buff
	 mov rcx, 16
up2:	 rol rbx, 04
	 mov dl, bl
	 and dl, 0FH
	 cmp dl, 09H
	 jbe add30
	 add dl, 07H
add30:	 add dl, 30H
	 mov byte[rsi], dl
	 inc rsi
	 dec rcx
	 jnz up2
	 WRITE char_buff, 16
ret
