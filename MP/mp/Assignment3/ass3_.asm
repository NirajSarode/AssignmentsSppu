section .data

menu : db "Enter ",10
       db "1.Hex to BCD",10
       db "2.BCD to HEX",10
       db "3.Exit",10
menu_len: equ $-menu

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

count : resb 2
count1: resb 2
count2: resb 2
choice: resb 2
num : resb 6
result : resb 16
num1 : resb 16


section .text
global _start
_start:

print menu,menu_len
accept choice,2
cmp byte[choice],31H
je case1
cmp byte[choice],32H
je case2
cmp byte[choice],33H
je exit

case1:
	accept num,5
	call atoh
	xor rbx,rbx
	mov bx,0x0A
	up1:
	   xor dx,dx
	   div bx
	   push dx
	   inc byte[count]
	   cmp eax,0
	   jnz up1
        up2:
           xor dx,dx
           pop dx
           cmp dl,9
           jbe next2
           add dl,07H
           next2:
           add dl,30H
           mov byte[result],dl
           print result,1
           dec byte[count]
           jnz up2
           
          jmp exit
           	
	
case2:
	accept num,5
	call atoh	
	mov rcx,rax
	mov dword[result], 00
a:	xor rax,rax
	xor rbx,rbx
	
	mov eax,00H
	mov ebx,00H
	mov al,cl
	AND al,0FH
	mov bx,0x01
	mul bx
	add dword[result],eax
a1:	
	ror ecx,4
	mov eax,00H
	mov al,cl
	AND al,0FH
	mov bx,0x0A
	mul bx
	add dword[result],eax
a2:	
	ror ecx,4
	mov eax,00H
	mov al,cl
	AND al,0FH
	mov bx,0x64
	mul bx
	add dword[result],eax
a3:	
	ror ecx,4
	mov eax,00H
	mov al,cl
	AND al,0FH
	mov bx,0x3E8
	mul bx
	add dword[result],eax
	
a4:	
	mov eax,00
	mov eax,dword[result]
a5:	
	call htoa
	
	jmp exit	
	
	
	
	
atoh:
mov rsi,num
xor rax,rax
mov byte[count1],4
up:
rol ax,4
mov dl,byte[rsi]
cmp dl,39H
jbe next
sub dl,07H
next:
sub dl,30H
add al,dl
inc rsi
dec byte[count1]
jnz up
ret

htoa:
mov rsi,num1
mov byte[count2],8
xor rbx,rbx
up3:
xor rbx,rbx
rol eax,4
mov bl,al
AND bl,0FH
cmp bl,9H
jbe down
add bl,07H
down:
add bl,30H
mov byte[rsi],bl
inc rsi
dec byte[count2]
jnz up3
print num1,8
ret

exit:
mov rax,60
mov rdi,0
syscall


       
