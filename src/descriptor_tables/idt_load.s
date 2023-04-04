#
# Interrupt descriptor table helpers
#
.code32
.text
.globl asm_idt_load

/*
 * Load interrupt table
 * void asm_idt_load(unsigned long *addr)
 */
asm_idt_load:
    push %edx
    mov 8(%esp), %edx
    lidt (%edx)
    pop %edx
    ret