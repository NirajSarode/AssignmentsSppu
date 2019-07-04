section .data

arr : dd 102.56 , 200.30 , 205.34 ,326.02,150.23

count : dw 5
hundred : dd 100
msg1 : db "Mean = "
len1 : equ $-msg1
msg2 : db "Variance = "
len2 : equ $-msg2
msg3 : db "Standard Deviation = "
len3 : equ $-msg3
dot  db "."
newline : db 0x0A

section .bss

%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

count1 : resb 2
count2 : resb 2
count3 : resb 2
result : resb 2
mean : resb 2
var  : resb 2
sd   : resb 2
buffer : resb 10
temp : resb 10

section .text
global _start
_start:

	FINIT
	FLDZ
	mov rsi,arr
	mov byte[count1],5
	
up:	FADD dword[rsi]
	ADD rsi,4
	dec byte[count1]
	jnz up
	
	FIDIV word[count]
	FST dword[mean]
	
	print msg1,len1
	call disp
	
	mov rsi,arr
	mov byte[count1],5
	FLDZ
	
up2:	FLDZ	
	FLD dword[rsi]
	FSUB dword[mean]
	FMUL st0
	FADD
	add rsi,4
	dec byte[count1]
	jnz up2
	
	FIDIV word[count]
	
	FST dword[var]
	print msg2,len2
	call disp
	
	
	FLDZ
	FLD dword[var]
	FSQRT
	FST dword[sd]
	print msg3,len3
	call disp
	
	jmp exit
	
disp:
	FIMUL dword[hundred]
	FBSTP [buffer]
	mov rsi,buffer+9
	mov byte[count2],9
up3:	mov bl,byte[rsi]
	push rsi
	call htoa
	pop rsi
	dec rsi
	dec byte[count2]
	jnz up3
	print dot,1
	mov rsi,buffer
	mov bl,byte[rsi]
	call htoa
	ret
	
htoa:
	mov rdi,result
	mov byte[count3],2
up4:	rol bl,04
	mov cl,bl
	AND cl,0FH
	cmp cl,9
	jbe next
	add cl,07H
next:	add cl,30H
	mov byte[rdi],cl
	inc rdi
	dec byte[count3]
	jnz up4
	print result,2
	ret
	
exit:
	mov rax,60
	mov rdi,0
	syscall

		

