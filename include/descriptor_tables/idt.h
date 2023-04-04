/*!
@file
@ingroup descriptor_tables
@brief  The header file declares Interrup Descriptor Table (IDT).
*/
#ifndef IDT_H
#define IDT_H

#include "interrupts/isr.h"
#include "interrupts/pic.h"
#include "interrupts/timer.h"
#include "lib/stdint.h"
#include "lib/string.h"

/**
 * @ingroup descriptor_tables
 *
 * @brief Entry in Interrup Descriptor Table (IDT).
 *
 */
typedef struct idt_entry_struct
{
    uint16_t base_low; ///< Low word of handler address
    uint16_t selector; ///< Kernel segment selector
    uint8_t allways0;
    uint8_t flags;      ///< Access Flags Byte
    uint16_t base_high; ///< High word of handler address

} __attribute__((packed)) idt_entry_t;

/**
 * @ingroup descriptor_tables
 *
 * @brief Structure of IDT Placement Pointers.
 *
 */
typedef struct idt_ptr_struct
{

    uint16_t limit; ///< IDT table size
    uint32_t base;  ///< Address of the first IDT entry

} __attribute__((packed)) idt_ptr_t;

/**
 * @ingroup descriptor_tables
 *
 * @brief Initialize interrup Descriptor Table (IDT).
          Filling the table with interrupt handlers.
 *
 */
void idt_init();

/**
 * @ingroup descriptor_tables
 *
 * @brief Load Interrup Descriptor Table (IDT) to IDTR register.
 *
 */
extern void asm_idt_load(uint32_t table_address);

/**
 * @ingroup descriptor_tables
 *
 * @brief Keyboard key press handler.
 *
 */
extern void asm_keyboard_handler();

/**
 * @ingroup descriptor_tables
 *
 * @brief Interrupt handler IRQ0(timer).
 *
 */
extern void asm_timer_handler();

#endif