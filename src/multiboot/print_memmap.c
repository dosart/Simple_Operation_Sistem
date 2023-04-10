#include "multiboot/multiboot.h"

void print_memmap(const struct multiboot_info* info)
{
    if((info->flags & MULTIBOOT_INFO_MEM_MAP) == 0)
    {
        printf("No memory map provided\n");
        return;
    }

    const multiboot_uint32_t entry_count = info->mmap_length / (sizeof(multiboot_memory_map_t));
    multiboot_memory_map_t* entry = (multiboot_memory_map_t*)info->mmap_addr;
    uint64_t phys_memory_size = 0;

    printf("Memory Map:\n");
    for(multiboot_uint32_t i = 0; i < entry_count; i++)
    {
        printf("%s: \n", (entry + i)->type == MULTIBOOT_MEMORY_AVAILABLE ? "available" : "reserved");
        phys_memory_size += (entry + i)->len;
    }
}