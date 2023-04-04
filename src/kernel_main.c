#include "descriptor_tables/gdt.h"
#include "descriptor_tables/idt.h"
#include "lib/string.h"

char* hello = "Hello world!";
int screen_size = 80 * 25;

void kernel_main(void* multiboot, void* kstack)
{
    char* video = (char*)0xB8000;
    char buff[screen_size + 1];
    video[screen_size] = '\0';

    memset(buff, ' ', screen_size);
    strext(video, buff, 0x7);
    strext(video, hello, 0x7);

    gdt_init();
    idt_init();
}