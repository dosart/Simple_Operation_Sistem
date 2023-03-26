;
; Load IDT and GDT
;

bits 32
global asm_idt_load, asm_gdt_load

section .txt

;
 ; Load idt
 ; void asm_idt_load(u32int table_address)
;
asm_idt_load:
	mov edx, [esp + 4]
    lidt [edx]
    sti
    ret

;
 ; Load gdt
 ; void asm_gdt_load(u32int table_address)
;
asm_gdt_load:
	mov eax, [esp + 4]
    lgdt [edx]
    jmp 0x08:.reload_cs

.reload_cs:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    ret
    