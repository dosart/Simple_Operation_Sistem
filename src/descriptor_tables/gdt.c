#include "descriptor_tables/gdt.h"

gdt_entry_t gdt[5];
gdt_ptr_t gdt_ptr;

static void gdt_set_gate(uint32_t num, uint32_t base, uint32_t limit,
                         uint8_t access, uint8_t gran);

void gdt_init()
{
    gdt_ptr.limit = (sizeof(gdt_entry_t) * 5) - 1;
    gdt_ptr.base = (uint32_t)&gdt;

    gdt_set_gate(0, 0, 0, 0, 0);
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
    gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
    gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);

    asm_gdt_load((uint32_t)&gdt_ptr);
}

void gdt_set_gate(uint32_t num, uint32_t base, uint32_t limit, uint8_t access,
                  uint8_t gran)
{
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;

    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = (limit >> 16) & 0xF;

    gdt[num].granularity |= gran & 0xF0;
    gdt[num].access = access;
}