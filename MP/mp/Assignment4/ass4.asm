section .data

msg : db "Enter first number" ,10
len : equ $-msg
msg1: db "Enter second number" ,10
len1: equ $-msg1
menu: db "Enter",10
      db "1.Successive Addition",10
      db "2.Add and Shift",10
menu_len: equ $-menu
ans : db "Product of two numbers is ",10
ansl: equ $-ans
new_line : db 10


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
mov rdi,0
mov rsi,%1
mov rdx,%2
syscall
%endmacro


num1 : resb 2
num2 : resb 2
num  : resb 6
new  : resb 10
count1 : resb 2
count : resb 2
choice : resb 2


section .text
global _start
_start:

print menu,menu_len
accept choice,02

cmp byte[choice],31H
je case1
cmp byte[choice],32H
je case2
cmp byte[choice],33H
je exit

case1:
	print msg,len
	accept num,03
	call Atoh
	mov word[num1],bx
	print msg1,len1
	accept num,03
	xor rbx,rbx
	call Atoh
	mov word[num2],bx
	mov edx,00
	;print ans,ansl
     up3:
	add dx,word[num1]
	dec word[num2]
	jnz up3
	call htoA
	print new_line,1
	jmp _start
	
	
case2:
	print msg,len
	accept num,03
	call Atoh
	mov word[num1],bx
	print msg1,len1
	accept num,03
	xor rbx,rbx
	call Atoh
	mov word[num2],bx
	mov rbx,00
	mov rcx,00
	mov rax,00
	mov byte[count],8
	mov bl,byte[num1]
	mov cl,byte[num2]
     up4:
        shr bx,01
        jnc down
        add ah,cl
        
        down:
        shr ax,01
        dec byte[count]
        jnz up4
        
        
        mov rdx,rax
        call htoA
    jmp _start	
	
exit:
mov rax,60
mov rdi,0
syscall	
	
	
Atoh:
     mov ebx,00
     mov rsi,num
     mov byte[count1],02H
     up:
        rol bx,04
        mov dl,byte[rsi]
        cmp dl,39H
        jbe next
        sub dl,07
        next:
        sub dl,30H
        add bl,dl
        inc rsi
        dec byte[count1]
        jnz up
     ret
     
htoA:
	xor cl,cl
	mov rdi,new
	mov byte[count1],8
     up1:
	rol edx,4
	mov cl,dl
	AND cl,0FH
	cmp cl,09H
	jbe next1
	add cl,07
	next1:
	add cl,30H
	mov byte[rdi],cl
	inc rdi
	dec byte[count1]
	jnz up1
	print new,8
    ret
	



