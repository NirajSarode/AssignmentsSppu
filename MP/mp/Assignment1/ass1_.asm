section .data
arr : dq 1234567892368541H,9563217539865412H,1863479523017963H,9632014586345210H,7510326845932456H
msg :db "Positive Count = "
len : equ $-msg
msg1:db "Negative Count = "
len1: equ $-msg1
newline:db 10
ncount : db 00
pcount : db 00
tcount : db 00

section .bss

%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro accept 2
mov rax,0
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .text
global _main
_main:

mov rsi,arr
mov byte[tcount],5
up:
mov rax,qword[rsi]
BT rax,63
jnc pos


inc byte[ncount]
add rsi,8
dec byte[tcount]
jnz up
jmp a

pos:
inc byte[pcount]
add rsi,8
dec byte[tcount]
jnz up
jmp a

a:

cmp byte[ncount],09H
jbe next1
add byte[ncount],07H
next1:
add byte[ncount],30H


cmp byte[pcount],09H
jbe next
add byte[pcount],07H
next:
add byte[pcount],30H




print msg,len
print pcount,1
print newline,1
print msg1,len1
print ncount,1
print newline,1

mov rax,60
mov rdi,0
syscall

