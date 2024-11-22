section .note.GNU-stack noalloc noexec nowrite progbits

extern printf, scanf

%macro print 2
push rbp
mov rax, 0
mov rdi, %1
mov rsi, %2
call printf
pop rbp
%endmacro

%macro scan 2
push rbp
mov rax, 1
mov rdi, %1
mov rsi, %2
call scanf
pop rbp
%endmacro

%macro printfloat 2
push rbp
mov rax, 1
mov rdi, %1
movsd xmm0, %2
call printf
pop rbp
%endmacro

section .data
msg db "Enter a, b and c : ", 0
m1 db "%lf", 0
m2 db "%s", 0

section .bss
a resb 08
b resb 08
c resb 08
temp resw 1
r1 resq 1
r2 resq 1
t1 resb 08
t2 resb 08
t3 resb 08
t4 resb 08

section .text
global main
main:
print m2, msg
scan m1, a
scan m1, b
scan m1, c

finit
fld qword[b]
fmul st0, st0
fstp qword[t1] ; t1 => b^2
fld qword[a]
fmul qword[c]
mov qword[temp], 4
fimul word[temp]
fstp qword[t2] ; t2 => 4ac
fld qword[t1]
fsub qword[t2]
fstp qword[t3] ; t3 => b^2 - 4ac
fld qword[t3]
fabs
fsqrt
fstp qword[t4] ; t4 => sqrt(b^2 - 4ac)
fld qword[b]
fchs
fstp qword[t1] ; -b
fld qword[a]
mov qword[temp], 2
fimul word[temp]
fstp qword[t2] ; 2a
cmp qword[t3], 0
je same_root
fld qword[t1]
fadd qword[t4]
fdiv qword[t2]
fstp qword[r1]
printfloat m1, [r1]

same_root:
fld qword[t1]
fsub qword[t4]
fdiv qword[t2]
fstp qword[r2]
printfloat m1, [r2]

mov rax, 60
ret




