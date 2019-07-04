section .data
menu : db "Enter",10
       db "1 Ascending Order",10
       db "2 Descending Order",10
       db "3 Exit",10
menu_len : equ $-menu
error : db "Error in opening file",10
error_len : equ $-error
success:db "Success in file opening",10
success_len: equ $-success
count1 : db 00
count : db 00
fname : db 'num.txt',0

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

file_des : resb 100
buffer : resb 200
tcount : resb 10
choice : resb 2

section .text
global _start
_start:

mov rax,2
mov rdi,fname
mov rsi,2
mov rdx,0777
syscall

mov qword[file_des],rax
BT rax,63
jnc down
print error,error_len
jmp exit

down:
print success,success_len
mov rax,0
mov rdi,[file_des]
mov rsi,buffer
mov rdx,1000
syscall

mov qword[tcount],rax
print buffer,tcount
print menu,menu_len
accept choice,2
cmp byte[choice],31H
je asc
cmp byte[choice],32H
je des
cmp byte[choice],33H
je exit

asc:
	;call asc1
	mov byte[count],4
	up:
		mov ax,0
		mov dx,0
		mov byte[count1],4
		mov rdi,buffer
		mov rsi,buffer
		
	up1:
		mov al,byte[rsi]
		add rsi,2
		cmp byte[rsi],al
		jnc down1
		mov dl,byte[rsi]
		mov byte[rdi],dl
		mov byte[rsi],al
	down1:
		add rdi,2
		dec byte[count1]
		jnz up1
		dec byte[count]
		jnz up
		
	mov rax,1
	mov rdi,[file_des]
	mov rsi,buffer
	mov rdx,qword[tcount]
	syscall
	
	
	jmp exit
	
des:
jmp exit

	
exit:
mov rax,60
mov rdi,0
syscall



