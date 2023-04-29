section .data
    msg db "Hello, Holberton", 0x0A, 0x00  ; Message to be printed (with newline)

section .text
    global main
    extern printf

main:
    sub rsp, 8          ; Align stack to 16-byte boundary
    mov rdi, msg        ; Set first argument (format string) to msg
    xor esi, esi        ; Set second argument (varargs) to 0
    mov eax, 0          ; Set return value to 0
    call printf         ; Call printf to print the message
    add rsp, 8          ; Restore stack alignment
    ret                 ; Return from main
