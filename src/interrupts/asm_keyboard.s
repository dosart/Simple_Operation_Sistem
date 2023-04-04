#
# Interrupt descriptor table handlers
#
.code32
.text
.globl asm_keyboard_handler
.extern keyboard_handler, asm_load_data_kselectors, asm_load_data_uselectors

/*
 * Handle IRQ1
 * void asm_ih_keyboard(unsigned int)
 */
asm_keyboard_handler:
    pushal
    call asm_load_data_kselectors
    call keyboard_handler
    call asm_load_data_uselectors
    popal
    iretl
