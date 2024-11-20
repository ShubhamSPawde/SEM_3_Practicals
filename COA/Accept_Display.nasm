section .data
msg1 db "Enter a number : "
len1 equ $-msg1

msg2 db "Your number is : "
len2 equ $-msg2

section .bss
a resb 1

section .text
global _start
_start:

mov rax, 1
mov rdi, 1
mov rsi, msg1
mov rdx, len1
syscall

mov rax, 0
mov rdi, 0
mov rsi, a
mov rdx, 8
syscall

mov rax, 1
mov rdi, 1
mov rsi, msg2
mov rdx, len2
syscall

mov rax, 1
mov rdi, 1
mov rsi, a
mov rdx, len1
syscall

mov rax, 60
mov rdi, 0
syscall
