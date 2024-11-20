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
menumsg db "",10
	db "1.String Length",10
	db "2.String Copy",10
	db "3.String Reverse",10
	db "4.String Compare",10
	db "5.String Concatenate",10	
	db "6.Check Palindrome",10
	db "7.Substring",10
	db "8.Exit",10
	db "Enter your choice : ",
menulen equ $-menumsg

msg1 db "Enter String 1 : "
len1 equ $-msg1
msg2 db "Enter String 2 : "
len2 equ $-msg2
msg3 db "Answer is : "
len3 equ $-msg3
msg4 db "Equal",10
len4 equ $-msg4
msg5 db "Not Equal",10
len5 equ $-msg5
msg6 db "Palindrome",10
len6 equ $-msg6
msg7 db "Not Palindrome",10
len7 equ $-msg7
msg8 db "Substring",10
len8 equ $-msg8
msg9 db "Not SubString",10
len9 equ $-msg9
msg10 db "Wrong Choice!",10
len10 equ $-msg10

section .bss
string1 resb 20
string2 resb 20
string3 resb 40
l1 resq 1
l2 resq 1
l3 resq 1
choice resb 2
char_buff resb 17

section .text
global _start:
_start:

WRITE msg1, len1
READ string1, 20
dec rax
mov [l1], rax

printmenu: 
WRITE menumsg, menulen
READ choice, 02
cmp byte[choice], 31H
je strlen
cmp byte[choice], 32H
je strcpy
cmp byte[choice], 33H
je strrev
cmp byte[choice], 34H
je strcmp
cmp byte[choice], 35H
je strcat
cmp byte[choice], 36H
je strpal
cmp byte[choice], 37H
je strsub
cmp byte[choice], 38H
je exit
WRITE msg10, len10
jmp printmenu



strlen:
mov rbx, [l1]
WRITE msg3, len3
call display
jmp printmenu




strcpy:
mov rsi, string1
mov rdi, string3
mov rcx, [l1]
cld
rep movsb
WRITE msg3, len3
WRITE string3, qword[l1]
jmp printmenu




strrev:
mov rsi, string1
add rsi, qword[l1]
dec rsi
mov rdi, string3
mov rcx, qword[l1]
u1:
mov bl, byte[rsi]
mov byte[rdi], bl
dec rsi
inc rdi
dec rcx
jnz u1
WRITE msg3, len3
WRITE string3, [l1]
jmp printmenu




strcmp:
WRITE msg2, len2
READ string2, 20
dec rax
mov [l2], rax
mov rbx, [l1]
cmp rbx, [l2]
jne ntequal
mov rsi, string1
mov rdi, string2
mov rcx, [l1]
repe cmpsb
cld
jne ntequal
WRITE msg4, len4
jmp printmenu
ntequal:
WRITE msg5, len5
jmp printmenu




strcat:
WRITE msg2, len2
READ string2, 20
dec rax
mov [l2], rax

mov rsi, string1
mov rdi, string3
mov rcx, [l1]
cld
rep movsb

mov rsi, string2
mov rcx, [l2]
rep movsb
mov rbx, [l1]
add rbx, [l2]
mov [l3], rbx
WRITE msg3, len3
WRITE string3, [l3]
jmp printmenu




strpal:
mov rsi, string1
mov rdi, string3
add rsi, qword[l1]
dec rsi
mov rcx, qword[l1]
u_rev:
mov bl, byte[rsi]
mov byte[rdi], bl
dec rsi
inc rdi
dec rcx
jnz u_rev

mov rsi, string1
mov rdi, string3
mov rcx, [l1]
cld
repe cmpsb
jne notpal
WRITE msg6, len6
jmp printmenu
notpal:
WRITE msg7, len7
jmp printmenu




strsub:
WRITE msg2, len2
READ string2, 20
dec rax
mov [l2], rax
mov rsi, string1
mov rdi, string2
mov rbx, [l2]

substr_loop:
mov dl, byte[rsi]
cmp dl, byte[rdi]
je same
mov rdi, string2
mov rbx, qword[l2]

same:
inc rsi
inc rdi
dec rbx
dec qword[l1]
cmp rbx, 00
je substring
cmp qword[l1], 00
jne substr_loop

WRITE msg9, len9
jmp printmenu

substring:
WRITE msg8, len8
jmp printmenu




exit:
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
add dl, 07H
add30: add dl, 30H
mov byte[rsi], dl
inc rsi
dec rcx
jnz up
WRITE char_buff, 16
ret
	
