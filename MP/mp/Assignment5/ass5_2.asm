section .data
extern count1,count2,count3
section .bss

extern buffer

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

cnt : resb 2
cnt1 : resb 2
cnt2:resb 2
new : resb 8
a : resb 2

section .text
global main
main:
global space_fun,enter_fun,char_fun


space_fun:
	mov rsi,buffer
	mov byte[cnt],0
	up:
	cmp byte[rsi],0x20
	jne down1
	inc byte[cnt]
	down1:
	inc rsi
	dec qword[count1]
	jnz up
	
	cmp byte[cnt],09
	jbe next4
	add byte[cnt],07H
	next4:
	add byte[cnt],30H
	print cnt,1
	ret
	
enter_fun:
	mov rdi,buffer
	mov byte[cnt2],0
	up1:
	cmp byte[rdi],0x0A
	jne down
	inc byte[cnt2]
	down:
	inc rdi
	dec qword[count2]
	jnz up1
	
	cmp byte[cnt2],09
	jbe next
	add byte[cnt2],07H
	next:
	add byte[cnt2],30H
	print cnt2,1
	ret
	
char_fun:
	accept a,2
	mov al,byte[a]
	mov rsi,buffer
	mov byte[cnt],0
	up5:
	cmp al,byte[rsi]
	jne down5
	inc byte[cnt]
	down5:
	inc rsi
	dec qword[count3]
	jnz up5
	
	cmp byte[cnt],09
	jbe next5
	add byte[cnt],07H
	next5:
	add byte[cnt],30H
	print cnt,1
ret
	
	
	

