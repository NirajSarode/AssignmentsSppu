section .data
success : db "File opened successfully",10
len : equ $-success
erro   : db "Error in openeing File",10
len1: equ $-erro
msg2: db "INVALID COMMAND",10
len2: equ $-msg2
section .bss

%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro read 2
mov rax,0
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

file_des : resb 10
count : resq 2
fname : resb 8
buffer : resb 1000
fname2: resb 8
file_des2 : resb 10
section .text
global _start
_start:

pop rbx
pop rbx
pop rbx

mov rsi,rbx
mov al,byte[rsi]
cmp al,'T'
je type
cmp al,'C'
je copy
cmp al,'D'
je del
jmp error



type:
	pop rbx
	mov rsi,fname
up:	mov al,byte[rbx]
	mov byte[rsi],al
	inc rsi
	inc rbx
	cmp byte[rbx],'0'
	jne up
	
	mov rax,2
	mov rdi,fname
	mov rsi,2
	mov rdx,0777
	syscall
	
	bt rax,63
	jnc next
	jmp errorf
next:	
	mov qword[file_des],rax
	
	mov rax,0
	mov rdi,qword[file_des]
	mov rsi,buffer
	mov rdx,1000
	syscall
	
	mov qword[count],rax
	print buffer,qword[count]
	jmp exit
	
copy: 
	pop rbx
	mov rsi,fname
up1:	mov al,byte[rbx]
	mov byte[rsi],al
	inc rsi
	inc rbx
	cmp byte[rbx],'0'
	jne up1
	
	pop rbx
	xor rax,rax
	mov rsi,fname2
up2:	mov al,byte[rbx]
	mov byte[rsi],al
	inc rsi
	inc rbx
	cmp byte[rbx],'0'
	jne up2
	
	mov rax,2
	mov rdi,fname
	mov rsi,2
	mov rdx,0777
	syscall
	
	bt rax,63
	jnc next1
	jmp errorf
next1:	
	mov qword[file_des],rax
	
	mov rax,0
	mov rdi,qword[file_des]
	mov rsi,buffer
	mov rdx,1000
	syscall
	
	
	mov qword[count],rax
	;print buffer,qword[count]
	
	mov rax,2
	mov rdi,fname2
	mov rsi,2
	mov rdx,0777
	syscall
	
	bt rax,63
	jnc next2
	jmp errorf
next2:	
	mov qword[file_des2],rax
	
	mov rax,1
	mov rdi,qword[file_des2]
	mov rsi,buffer
	mov rdx,qword[count]
	syscall
	
	
jmp exit

del:

	pop rbx
	mov rsi,fname
up3:	mov al,byte[rbx]
	mov byte[rsi],al
	inc rsi
	inc rbx
	cmp byte[rbx],'0'
	jne up3
	
	mov rax,2
	mov rdi,fname
	mov rsi,2
	mov rdx,0777
	syscall
	
	bt rax,63
	jnc next4
	jmp error
	
next4:
	mov  rax,87
	mov rdi,fname
	syscall
	
	
	
	
jmp exit

error:
	print msg2,len2
	jmp exit
	
errorf:
	print erro,len1
	jmp exit
	
exit:
	mov rax,60
	mov rdi,0
	syscall















