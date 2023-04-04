#
# Interrupt descriptor table handlers
#
.code32
.text
.globl asm_timer_handler
.extern timer_handler, asm_load_data_kselectors, asm_load_data_uselectors

/*
 * Handle IRQ0
 * void asm_timer_handler(unsigned int)
 */
asm_timer_handler:
    pushal
    call asm_load_data_kselectors
    call timer_handler
    call asm_load_data_uselectors
    popal
    iretl
