section .data

amsg : db "Value of a"
alen : equ $-amsg
bmsg : db "Value of b"
blen : equ $-bmsg
cmsg : db "Value of c"
clen : equ $-cmsg

ff1 : db "%lf + %lfi",10,0
ff2 : db "%lf - %lfi",10,0

formatpf : db "%lf",10,0
formatsf : db "%lf"
four : dq 4.00
two  : dq 2.00
one  : dq -1.00
a    : dq 0.00
b    : dq 0.00
c    : dq 0.00


section .bss
b2 : resq 1
fac: resq 1
ta : resq 1
delta : resq 1
rdelta: resq 1
root1 : resq 1
root2 : resq 1
realn : resq 1
imagn : resq 1


%macro myprintf 1
mov rdi,formatpf
sub rsp,8
movsd xmm0 , [%1]
mov rax,1
call printf
add rsp,8
%endmacro

%macro myscanf 1
mov rdi,formatsf
mov rax,0
sub rsp,8
mov rsi,rsp
call scanf
mov r8,qword[rsp]
mov qword[%1],r8
add rsp,8
%endmacro

section .text


global main
main:

extern printf
extern scanf

myscanf a
myscanf b
myscanf c


	FINIT
	FLDZ
	FLD qword[b]
	FMUL qword[b]
	FSTP qword[b2]
	
	FLDZ
	FLD qword[four]
	FMUL qword[a]
	FMUL qword[c]
	FSTP qword[fac]
	
	FLDZ
	FLD qword[two]
	FMUL qword[a]
	FSTP qword[ta]
	
	FLDZ
	FLD qword[b2]
	FSUB qword[fac]
	FSTP qword[delta]
	
	BT qword[delta],63
	jc imag
	
	
real:	FLDZ
	FLD qword[delta]
	FSQRT
	FSTP qword[delta]
	
	FLDZ
	FSUB qword[b]
	FADD qword[rdelta]
	FDIV qword[ta]
	FSTP qword[root1]
	myprintf root1
	
	FLDZ
	FSUB qword[b]
	FSUB qword[rdelta]
	FDIV qword[ta]
	FSTP qword[root2]
	myprintf root2
	jmp exit
	
imag:	FLDZ
	FLD qword[delta]
	FMUL qword[one]
	FSQRT
	FSTP qword[rdelta]
	
	FLDZ
	FSUB qword[b]
	FDIV qword[ta]	
	FSTP qword[realn]
	
	FLDZ
	FSUB qword[rdelta]
	FDIV qword[ta]
	FSTP qword[imagn]
	
	mov rdi,ff1
	sub rsp,8
	movsd xmm0,[realn]
	movsd xmm1,[imagn]
	mov rax,2
	call printf
	add rsp,8
	
	mov rdi,ff2
	sub rsp,8
	movsd xmm0,[realn]
	movsd xmm1,[imagn]
	mov rax,2
	call printf
	add rsp,8
	
	jmp exit
	


exit:
	mov rax,60
	mov rdi,0
	syscall












