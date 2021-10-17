bits 32
global start
extern kernel_main


section .txt
        align 4
        dd 0x1BADB002            ;magic
        dd 0x00                  ;flags
        dd - (0x1BADB002 + 0x00) ;checksum. m+f+c should be zero

start:
    cli                 ;turned off interrupts
    mov esp, stack_space ;set stack pointer
    call kernel_main
    hlt

section .bss
resb 4096
stack_space:
