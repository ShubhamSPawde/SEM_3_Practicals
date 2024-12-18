section .data
msg  db "Multiplication using Add and Shift", 10
msg_len equ $-msg
msg1 db "Enter the multiplicand: ", 10
msg1_len equ $-msg1
msg2 db "Enter the multiplier: ", 10
msg2_len equ $-msg2
msg3 db "Multiplication Result/Product: ", 10
msg3_len equ $-msg3
msg_space db " ", 10
msg_space_len equ $-msg_space

%macro write 2
mov rax, 1
mov rdi, 1
mov rsi, %1
mov rdx, %2
syscall
%endmacro

%macro read 2
mov rax, 0
mov rdi, 0
mov rsi, %1
mov rdx, %2
syscall
%endmacro

section .bss
num resb 17
choice resb 2
buff resb 16
no resq 1
ccnt resq 1
no1 resq 1
no2 resq 1
A resq 1
B resq 1
Q resq 1
n resq 1

section .text
global _start
_start:
write msg1, msg1_len
read num, 17
dec rax
mov qword[ccnt], rax
call accept
mov qword[B], rbx
write msg2, msg2_len
read num, 17
dec rax
mov qword[ccnt], rax
call accept
mov qword[Q], rbx
mov qword[A], 00
mov qword[n], 64

above:
mov rax, qword[Q]
and rax, 01h
cmp rax, 01h
jne shift
mov rax, qword[A]
mov rbx, qword[B]
add rax, rbx
mov qword[A], rax

shift:
mov rax, qword[A]
mov rbx, qword[Q]
shr rbx, 01
and rax, 01
cmp rax, 01
jne shift_a
mov rdx, 01
ror rdx, 01
or rbx, rdx

shift_a:
mov rax, qword[A]
shr rax, 01
mov qword[A], rax
mov qword[Q], rbx
dec qword[n]
jnz above
write msg3, msg3_len
mov rbx, qword[A]
call disp
mov rbx, qword[Q]
call disp

mov rax, 60
mov rdi, 0
syscall

accept:
mov rbx, 00
mov rsi, num
mov rdx, 00h

up1:
shl rbx, 04h
mov dl, byte [rsi]
cmp dl, 39h
jbe sub_30
sub dl, 07h
sub_30:
sub dl, 30h
add rbx, rdx
inc rsi
dec qword[ccnt]
jnz up1
ret

disp:
mov rsi, buff
mov rcx, 16
mov rdx, 00

up2:
rol rbx, 04
mov dl, bl
and dl, 0fh
cmp dl, 09
jbe mc
add dl, 07h

mc:
add dl, 30h
mov [rsi], dl
inc rsi
dec rcx
jnz up2
write buff, 16
ret
