#include "descriptor_tables/descriptor_tables.h"
#include "video/text_framebuffer.h"

/*******************************************************************************
        IDT
*******************************************************************************/

/* IDT loading function */
extern void asm_idt_load(u32int table_address);

extern void keyboard_init();

/* keyboard interrupt handler */
extern void asm_keyboard_handler();

static void init_idt(void);

static void idt_set_gate(u8int num, u32int base, u16int selector, u8int flags);

idt_entry_t idt_entries[256];
idt_ptr_t idt_ptr;

void init_descriptor_tables(void) { init_idt(); }

void init_idt(void) {
  idt_ptr.limit = sizeof(idt_entry_t) * 256 - 1;
  idt_ptr.base = (u32int)&idt_entries;

  memset(&idt_entries, 0, sizeof(idt_entry_t) * 256);

  /* fill idt */
  idt_set_gate(INT_KEYBOARD, (u32int)asm_keyboard_handler, CODE_SELECTOR,
               INT_GATE);

  /* Programmable Interrupt Controller (PIC) initialization */
  pic_init();
  asm_idt_load((u32int)&idt_ptr);
  keyboard_init();
}

void idt_set_gate(u8int num, u32int base, u16int selector, u8int flags) {
  idt_entries[num].base_low = base & 0xFFFF;
  idt_entries[num].base_high = (base >> 16) & 0xFFFF;

  idt_entries[num].selector = selector;
  idt_entries[num].allways0 = 0;

  idt_entries[num].flags = flags;
}