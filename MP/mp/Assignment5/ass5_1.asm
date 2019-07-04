section .data
global count1,count2,count3
menu : db "Enter",10
       db "1.Count space",10
       db "2.Count Newline",10
       db "3.Count Character",10
       db "4.Exit",10
menu_len: equ $-menu

fname : db 'abc.txt',0
count1 : dq 00
count2 : dq 00
count3 : dq 00
error : db "File cannot be opened",10
error_len: equ $-error

success: db "File opened successfully",10
len : equ $-success
section .bss

global buffer

%macro print 02
mov rax,01
mov rdi,01
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro accept 02
mov rax,00
mov rdi,01
mov rsi,%1
mov rdx,%2
syscall
%endmacro

file_des : resb 64

tcount : resb 8
buffer : resb 1000
choice : resb 2

section .text
global _start
_start:

extern space_fun,enter_fun,char_fun
mov rax,2
mov rdi,fname
mov rsi,2
mov rdx,0777
syscall

mov qword[file_des],rax
bt rax,63
jnc down

print error,error_len
jmp exit

down:
	print success,len
	mov rax,0
	mov rdi,qword[file_des]
	mov rsi,buffer
	mov rdx,1000
	syscall
	
	mov qword[tcount],rax
men:	
	print menu,menu_len
	accept choice,02
	
	cmp byte[choice],31H
	je space
	cmp byte[choice],32H
	je enter
	cmp byte[choice],33H
	je char
	cmp byte[choice],34H
	je exit
	
	mov rbx,qword[tcount]
	mov qword[count1],rbx
	mov qword[count2],rbx
	mov qword[count3],rbx
	
	
space:
	call space_fun
	jmp men
	
enter:
	call enter_fun
	jmp men

char:
	call char_fun
	jmp men
	
exit:
mov rax,60
mov rdi,0
syscall

       
