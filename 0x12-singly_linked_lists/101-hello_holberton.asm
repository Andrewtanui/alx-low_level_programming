section .data
    msg db "Hello, Holberton", 0x0A, 0x00  ; Message to be printed (with newline)

section .text
    global main
    extern printf

main:
    mov rdi, msg        ; Set first argument (format string) to msg
    xor esi, esi        ; Set second argument (varargs) to 0
    call printf         ; Call printf to print the message

    xor eax, eax        ; Set return value to 0
    ret                 ; Return from main
