;
; Interapt handlers for IDT
;

bits 32
global asm_keyboard_handler
extern keyboard_handler

section .txt

;
 ; Keyboard interrupt handler
 ; void asm_keyboard_handler()
;
asm_keyboard_handler:
    call    keyboard_handler
    iretd
