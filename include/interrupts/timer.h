#ifndef TIMER_H
#define TIMER_H

#include "lib/stdint.h"

#define BASE_FREQ 1000

extern unsigned char asm_read_port(unsigned char port);
extern void asm_write_port(unsigned int port, unsigned char data);

/**
 * @ingroup interrupts
 *
 * @brief Initialize interrup timer.
 *
 */
void timer_init(uint32_t frequency);

/**
 * @ingroup interrupts
 *
 * @brief Interrupt handler IRQ0(timer).
 *
 */
void timer_handler();

#endif