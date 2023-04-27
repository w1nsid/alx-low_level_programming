extern printf

section .data
    msg db "Hello, Holberton", 10, 0
    fmt db "%s", 0

section .text
    global main

main:
    push rbp
    mov rbp, rsp

    lea rdi, [fmt]
    lea rsi, [msg]
    xor eax, eax
    call printf

    mov eax, 0
    leave
    ret
