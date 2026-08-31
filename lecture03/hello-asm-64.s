.section    .data
string:
    .ascii  "hello, world\n"
string_end:
    .equ len, string_end - string

.section    .text
.globl	    main
main:
    # write(1, "hello, world\n", 13)
    mov     $1, %rax        # System call number 1 (write)
    mov     $1, %rdi	    # file descriptor 1 (stdout)
    mov     $string, %rsi   # string content
    mov     $len, %rdx	    # string length
    syscall		    # Trap / Interrupt

    # exit(0)
    mov     $60, %rax       # System call 60 (exit)
    mov     $0, %rdi	    # exit status
    syscall		    # Trap / Interrupt
