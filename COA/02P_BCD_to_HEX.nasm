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
msg1 db "Enter BCD number : "
len1 equ $-msg1 
msg2 db "HEX Equivalent : "
len2 equ $-msg2

section .bss
char_buff resq 17
digit_cnt resb 1

section .text
global _start:
_start:

WRITE msg1, len1
READ char_buff, 17
dec rax

mov [digit_cnt], rax
mov rsi, char_buff
mov rcx, [digit_cnt]
mov rbx, 00H
up1:mov rax, 0AH
    mul rbx
    mov rbx, rax
    mov rdx, 00H
    mov dl, byte[rsi]
    sub dl, 30H
    add rbx, rdx
    inc rsi
    dec rcx
    jnz up1
 
WRITE msg2, len2 

call display


mov rax, 60
mov rdi, 0
syscall


display:
mov rsi, char_buff
mov rcx, 16
up:rol rbx, 04
   mov dl, bl
   and dl, 0FH
   cmp dl, 09H
   jbe add30
   add dl,07H
add30:add dl, 30H
   mov byte[rsi], dl
   inc rsi
   dec rcx
   jnz up
WRITE char_buff, 16
ret

    


