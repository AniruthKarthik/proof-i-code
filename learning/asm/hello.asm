section .data 

msg db "hello earth",10 
; msg variable, db - define byte,10 - newline
len equ $ - msg 
; len variable equals current memory address - memory address of msg 

section .text 
; code section

global _start 
; entry point for the linker

_start:
    ; syscall register order as follows rax,rdi,rsi,rdx
    mov rax, 1 ; write
    ; 1 write ,60 exit ,0 read
    mov rdi, 1 ; file descriptor 
    ; 1 stdout
    mov rsi,msg ; buffer pointer
    mov rdx,len ; length
    syscall 

    
    mov rax,60
    xor rdi, rdi 
    syscall



