#include "descriptor_tables/idt.h"

static void idt_set_gate(uint8_t num, uint32_t base, uint16_t selector, uint8_t flags);

idt_entry_t idt[256];
idt_ptr_t idt_ptr;

void idt_init()
{
    idt_ptr.limit = sizeof(idt_entry_t) * 256 - 1;
    idt_ptr.base = (uint32_t)&idt;

    memset(&idt, 0, sizeof(idt_entry_t) * 256);

    idt_set_gate(IRQ0, (uint32_t)asm_timer_handler, 0x08, 0x8E);
    idt_set_gate(IRQ1, (uint32_t)asm_keyboard_handler, 0x08, 0x8E);

    asm_idt_load((uint32_t)&idt_ptr);

    pic_init();
    pic_enable();

    timer_init(BASE_FREQ);
}

void idt_set_gate(uint8_t num, uint32_t base, uint16_t selector, uint8_t flags)
{
    idt[num].base_low = base & 0xFFFF;
    idt[num].base_high = (base >> 16) & 0xFFFF;

    idt[num].selector = selector;
    idt[num].allways0 = 0;

    idt[num].flags = flags;
}