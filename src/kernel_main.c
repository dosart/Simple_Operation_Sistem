#include "descriptor_tables/gdt.h"
#include "descriptor_tables/idt.h"
#include "lib/stdio.h"

void kernel_main(void* multiboot, void* kstack)
{
    clear();
    printf("My first kernel!\n");

    gdt_init();
    printf("Global Descriptor Table (GDT) init!\n");

    idt_init();
    printf("Interrup Descriptor Table (IDT) init!\n");
}