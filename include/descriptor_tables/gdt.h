/*!
@file
@ingroup descriptor_tables
@brief  The header file declares Global Descriptor Table (GDT).
*/
#ifndef GDT_H
#define GDT_H

#include "lib/stdint.h"

/**
 * @ingroup descriptor_tables
 *
 * @brief Entry in Global Descriptor Table (GDT).
 *
 */
typedef struct gdt_entry_struct
{
    uint16_t limit_low;  ///< Low limit word
    uint16_t base_low;   ///< Low base word
    uint8_t base_middle; ///< Middle part of the base
    uint8_t access;      ///< Access Byte
    uint8_t granularity; ///< Byte granularity
    uint8_t base_high;   ///< The older part of the base

} __attribute__((packed)) gdt_entry_t;

/**
 * @ingroup descriptor_tables
 *
 * @brief Structure of GDT Placement Pointers.
 *
 */
typedef struct gdt_ptr_struct
{
    uint16_t limit; ///< GDT table size
    uint32_t base;  ///< Address of the first GDT entry

} __attribute__((packed)) gdt_ptr_t;

/**
 * @ingroup descriptor_tables
 *
 * @brief Initialize interrup Descriptor Table (GDT).
 *        Creating five segments:
 *          - zero segment;
 *          - kernel code segment;
 *          - kernel data segment;
 *          - user code segment;
 *          - User data segment.
 */
void gdt_init();

/**
 * @ingroup descriptor_tables
 *
 * @brief Load Global Descriptor Table (GDT) to IDTR register.
 *
 */
extern void asm_gdt_load(uint32_t table_address);

#endif