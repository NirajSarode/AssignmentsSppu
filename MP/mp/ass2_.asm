section .data

menu : dq "Enter Choice",10
       dq "1 Non-Overlapping without string",10
       dq "2 Non-Overlapping with string",10
       dq "3 Overlapping without string",10
       dq "4 Overlapping with string",10
       dq "5 Exit",10
len0 :equ $-menu
arr : dq 1234567892368541H,4563217539865412H,1863479523017963H,9632014586345210H,7510326845932456H,0x00,0x00,0x00,0x00,0x00,0x00
count : db 0
newline : db 0x0A
len: equ $-newline
count1:db 0
count2:db 0
count3:db 0
count4:db 0
colon :db ":" 
msg : db "Initial",10
len1: equ $-msg
msg2 : db "Final",10
len2: equ $-msg2

section .bss


new : resb 16
new1 : resb 16
choice : resb 2

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
global _start:
_start:

print menu,len0

accept choice,2

cmp byte[choice],31H
je case1

cmp byte[choice],32H
je case2

cmp byte[choice],33H
je case3

cmp byte[choice],34H
je case4

cmp byte[choice],35H
je exit




case1:
call print_array
mov rsi,arr
mov rdi,arr+40
mov byte[count4],5
up4:
mov rcx,qword[rsi]
mov qword[rdi],rcx
add rsi,8
add rdi,8
dec byte[count4]
jnz up4
print msg2,len2
call print_total
jmp _start


case2:
call print_array
mov rsi,arr
mov rdi,arr+40
mov byte[count4],5
up7:
cld
movsq
dec byte[count4]
jnz up7
print msg2,len2
call print_total
jmp _start

case3:

call print_array
mov rsi,arr
;mov arr2,rsi
mov rdi,arr+16
mov byte[count4],5
up6:
mov rcx,qword[rsi]
mov qword[rdi],rcx
add rsi,8
add rdi,8
dec byte[count4]
jnz up6
print msg2,len2
call print_total
jmp _start
jmp exit

case4:
call print_array
mov rsi,arr
mov rdi,arr+16
mov byte[count4],5
up8:
cld
movsq
dec byte[count4]
jnz up8
print msg2,len2
call print_total
jmp _start


print_total:
mov rsi,arr
mov byte[count],10
up5:
mov rdx,rsi
push rsi
call htoa
pop rsi
mov rcx,qword[rsi]
push rsi
call htoa2
pop rsi
add rsi,8
dec byte[count]
jnz up5
ret


print_array:

mov rsi,arr
mov byte[count],5
up:
mov rdx,rsi
push rsi
call htoa
pop rsi
mov rcx,qword[rsi]
push rsi
call htoa2
pop rsi
add rsi,8
dec byte[count]
jnz up
ret


htoa:
mov rdi,new
mov byte[count1],16
up1:
rol rdx,4
mov cl,dl
AND cl,0FH
cmp cl,9
jbe next
add cl,07
next:
add cl,30H
mov byte[rdi],cl
inc rdi
dec byte[count1]
jnz up1
print new,16
print colon,1
ret

htoa2:
xor rdx,rdx
mov rdi,new1
mov byte[count2],16
up2:
rol rcx,04
mov dl,cl
AND dl,0FH
cmp dl,9
jbe next1
add dl,07H
next1:
add dl,30H
mov byte[rdi],dl
inc rdi
dec byte[count2]
jnz up2
print new1,16
print newline,len
ret


exit:
mov rax,60
mov rdi,0
syscall
