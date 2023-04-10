#include "descriptor_tables/gdt.h"
#include "descriptor_tables/idt.h"
#include "lib/stdio.h"
#include "multiboot/multiboot.h"

void kernel_main(const struct multiboot_info* info, void* kstack)
{
    clear();
    printf("My first kernel!\n");

    gdt_init();
    printf("Global Descriptor Table (GDT) init!\n");

    idt_init();
    printf("Interrup Descriptor Table (IDT) init!\n");

    print_memmap(info);
}