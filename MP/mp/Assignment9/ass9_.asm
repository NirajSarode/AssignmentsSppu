section .data
msg : db  "Factorial of a number is ",10
len : equ $-msg
count : db 0
count1 : db 00

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

new : resb 10

section .text
global _start
_start:

pop rbx
pop rbx
pop rbx

mov cl,byte[rbx]

cmp cl,39H
jbe next
sub cl,07H
next:
sub cl,30H

xor rbx,rbx
mov bl,cl

up:	push rbx
	dec rbx
	inc byte[count]
	cmp rbx,0x01
	jne up

	mov eax,0x01	
up1:
	pop rbx
	mul ebx
	dec byte[count]
	jnz up1
	
call htoa
jmp exit

htoa:
	xor rbx,rbx
	mov rsi,new
	mov byte[count1],8
	up3:
	rol eax,04
	mov bl,al
	AND bl,0FH
	cmp bl,09H
	jbe down
	add bl,07H
down:	add bl,30H
	mov byte[rsi],bl
	inc rsi
	dec byte[count1]
	jnz up3
	print new,8
	ret
	
exit:
mov rax,60
mov rdi,0
syscall	

