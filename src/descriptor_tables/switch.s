.code32
.text
.globl  asm_load_data_kselectors,  asm_load_data_uselectors

/*
 * Load kernel selectors
*/
 asm_load_data_kselectors:
    push %eax
    mov $0x10,%eax
    mov %ax,%ds
    mov %ax,%es
    mov %ax,%fs
    mov %ax,%gs
    pop %eax
    ret

/*
 * Load user selectors
*/
 asm_load_data_uselectors:
    push %eax
    mov $0x2b,%eax
    mov %ax,%ds
    mov %ax,%es
    mov %ax,%fs
    mov %ax,%gs
    pop %eax
    ret