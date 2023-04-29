section .data
    msg db "Hello, Holberton\n", 0x0A, 0x00  ; Message to be printed (with newline)

section .text
    global main
    extern printf

main:
    push rbp            ; Save rbp on the stack
    mov rbp, rsp        ; Set rbp to current rsp value
    sub rsp, 16         ; Allocate 16 bytes of space on the stack
    mov rdi, msg        ; Set first argument (format string) to msg
    xor esi, esi        ; Set second argument (varargs) to 0
    mov eax, 0          ; Set return value to 0
    call printf         ; Call printf to print the message
    add rsp, 16         ; Deallocate the 16 bytes of space on the stack
    mov rsp, rbp        ; Restore rsp to its original value
    pop rbp             ; Restore rbp from the stack
    ret                 ; Return from main
