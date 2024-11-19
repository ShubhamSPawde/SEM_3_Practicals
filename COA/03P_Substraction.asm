%macro READ 2
mov rax, 0
mov rdi, 0
mov rsi, %1
mov rdx, %2
syscall
%endmacro

%macro WRITE 2
mov rax, 1
mov rdi, 1
mov rsi, %1
mov rdx, %2
syscall
%endmacro

section .data
msg1 db "Enter a : "
len1 equ $-msg1

msg2 db "Enter b : "
len2 equ $-msg2

msg3 db "Addition : "
len3 equ $-msg3

section .bss
char_buff resb 17
a resq 1
b resq 1
c resq 1

section .text
global _start:
_start:

WRITE msg1, len1
READ char_buff, 17
dec rax

mov rcx, rax
call accept

mov [a], rbx


WRITE msg2, len2
READ char_buff, 17
dec rax

mov rcx, rax
call accept

mov [b], rbx

WRITE msg3, len3

mov rax, [a]
mov rbx, [b]
sub rax, rbx
mov [c], rax

mov rbx, [c]
call display



mov rax, 60
mov rdi, 0
syscall




accept:
 mov rsi, char_buff
 mov rbx, 00H
up:
 mov rdx, 00H
 mov dl, byte[rsi]
 cmp dl, 39H
 jbe sub30
 sub dl, 07H
sub30: sub dl, 30H
 shl rbx, 04H
 add rbx, rdx
 inc rsi
 dec rcx
 jnz up
 
 
 display:
 mov rsi, char_buff
 mov rcx, 16
 up1:rol rbx, 04H
 mov dl, bl
 and dl, 0FH
 cmp dl, 09
 jbe add30
 add dl, 07H
 add30: add dl, 30H
 mov byte[rsi], dl
 inc rsi
 dec rcx
 jnz up1
 WRITE char_buff, 16
 ret