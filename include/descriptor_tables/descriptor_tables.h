#ifndef DESCRIPTOR_TABLES_H
#define DESCRIPTOR_TABLES_H

#include "common.h"
#include "interapts/pic.h"

/*------------------------------------------------------------------------------
//	Entry in Interrup Descriptor Table (IDT)
//----------------------------------------------------------------------------*/
struct idt_entry_struct {

  u16int base_low;
  u16int selector;
  u8int allways0;
  u8int flags;
  u16int base_high;

} __attribute__((packed));

typedef struct idt_entry_struct idt_entry_t;

/*------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------*/
struct idt_ptr_struct {

  u16int limit;
  u32int base;

} __attribute__((packed));

typedef struct idt_ptr_struct idt_ptr_t;

/* GDT and IDT initialization */
void init_descriptor_tables(void);

/* index in table IDT*/
#define INT_KEYBOARD 0x21

#define CODE_SELECTOR 0x08
#define INT_GATE 0x8e

#endif