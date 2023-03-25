bits 32
global start
extern kernel_main

MBOOT_HEADER_MAGIC EQU 0x1BADB002
MBOOT_HEADER_FLAGS EQU 0x00000001
MBOOT_CHECKSUM EQU - (MBOOT_HEADER_MAGIC+MBOOT_HEADER_FLAGS)

section .mboot
    align 4
    dd MBOOT_HEADER_MAGIC
    dd MBOOT_HEADER_FLAGS
    dd MBOOT_CHECKSUM

section .txt
start:
    cli                 ;turned off interrupts
    mov esp, stack_space ;set stack pointer
    call kernel_main
    hlt

section .bss
resb 4096
stack_space:
