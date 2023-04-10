#ifndef MULTIBOOT_H
#define MULTIBOOT_H

#include "lib/stdbool.h"
#include "lib/stdint.h"
#include "lib/stdio.h"
#include "lib/string.h"

typedef uint16_t multiboot_uint16_t;
typedef uint32_t multiboot_uint32_t;

/* is there a full memory map? */
#define MULTIBOOT_INFO_MEM_MAP 0x00000040

/* The symbol table for a.out. */
typedef struct multiboot_aout_symbol_table
{
    multiboot_uint32_t tabsize;
    multiboot_uint32_t strsize;
    multiboot_uint32_t addr;
    multiboot_uint32_t reserved;
} multiboot_aout_symbol_table_t;

/* The section header table for ELF. */
typedef struct multiboot_elf_section_header_table
{
    multiboot_uint32_t num;
    multiboot_uint32_t size;
    multiboot_uint32_t addr;
    multiboot_uint32_t shndx;
} multiboot_elf_section_header_table_t;

typedef struct multiboot_info
{
    /* Multiboot info version number */
    multiboot_uint32_t flags;

    /* Available memory from BIOS */
    multiboot_uint32_t mem_lower;
    multiboot_uint32_t mem_upper;

    /* "root" partition */
    multiboot_uint32_t boot_device;

    /* Kernel command line */
    multiboot_uint32_t cmdline;

    /* Boot-Module list */
    multiboot_uint32_t mods_count;
    multiboot_uint32_t mods_addr;

    union
    {
        multiboot_aout_symbol_table_t aout_sym;
        multiboot_elf_section_header_table_t elf_sec;
    } u;

    /* Memory Mapping buffer */
    multiboot_uint32_t mmap_length;
    multiboot_uint32_t mmap_addr;

    /* Drive Info buffer */
    multiboot_uint32_t drives_length;
    multiboot_uint32_t drives_addr;

    /* ROM configuration table */
    multiboot_uint32_t config_table;

    /* Boot Loader Name */
    multiboot_uint32_t boot_loader_name;

    /* APM table */
    multiboot_uint32_t apm_table;

    /* Video */
    multiboot_uint32_t vbe_control_info;
    multiboot_uint32_t vbe_mode_info;
    multiboot_uint16_t vbe_mode;
    multiboot_uint16_t vbe_interface_seg;
    multiboot_uint16_t vbe_interface_off;
    multiboot_uint16_t vbe_interface_len;
} multiboot_info_t;

struct multiboot_mmap_entry
{
    multiboot_uint32_t size; /* Structure size */
    multiboot_uint32_t addr; /* Block start address */
    multiboot_uint32_t len;  /* Block size in bytes */
#define MULTIBOOT_MEMORY_AVAILABLE 1
#define MULTIBOOT_MEMORY_RESERVED 2
    multiboot_uint32_t type; /* Block type */
} __attribute__((packed));

typedef struct multiboot_mmap_entry multiboot_memory_map_t;

void print_memmap(const struct multiboot_info* info);

#endif