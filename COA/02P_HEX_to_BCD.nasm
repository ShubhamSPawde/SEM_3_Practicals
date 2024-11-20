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
msg1 db "Enter HEX number : "
len1 equ $-msg1 
msg2 db "BCD Equivalent : "
len2 equ $-msg2

section .bss
char_buff resb 17
cnt resb 1
a resb 1

section .text
global _start:
_start:

WRITE msg1, len1
READ char_buff, 17
dec rax
mov rcx, rax
call accept

mov rcx, 00H
mov rax, rbx

l1:mov rdx, 00H
   mov rbx, 0AH
   div rbx
   push rdx
   inc rcx
   cmp rax, 00H
   jne l1

mov byte[cnt], cl
WRITE msg2, len2

l2:pop rbx
   cmp bl, 09H
   jbe add30
   add bl, 07H
add30:add bl, 30H
   mov byte[a],bl
   WRITE a, 1
   dec byte[cnt]
   jnz l2
   
mov rax, 60
mov rdi, 0
syscall

accept:
   mov rsi, char_buff
   mov rbx, 00H
up:mov rdx, 00H
   mov dl, byte[rsi]
   cmp dl, 39H
   jbe sub30
   sub dl, 07H
sub30:sub dl, 30H
   shl rbx, 04H
   add rbx, rdx
   inc rsi
   dec rcx
   jnz up
   ret
