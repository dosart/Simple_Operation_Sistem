/*!
@file
@ingroup interrupts
@brief  The header file declares functions for controlling the Programmable Interrupt Controller, PIC.
*/
#ifndef PIC_H
#define PIC_H

#include "interrupts/port.h"
#include "lib/stdint.h"

#define PIC1_CMD_PORT 0x20
#define PIC1_DATA_PORT 0x21
#define PIC2_CMD_PORT 0xA0
#define PIC2_DATA_PORT 0xA1
#define PIC_IQW_CMD 0x11

/**
 * @ingroup interrupts
 *
 * @brief Initialize Programmable Interrupt Controller.
 *
 */
void pic_init();

/**
 * @ingroup interrupts
 *
 * @brief Enable IRQ0, IRQ1 (timer, keyboard).
 *
 */
void pic_enable();

#endif
