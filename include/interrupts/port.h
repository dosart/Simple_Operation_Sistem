/*!
@file
@ingroup interrupts
@brief  The header file declares functions for reading and writing from I/O ports.
*/
#ifndef PORT_H
#define PORT_H

#include "lib/stdint.h"

/**
 * @ingroup interrupts
 *
 * @brief Read byte from the port.
 *
 * @param port  Port number for reading.
 *
 * @returns Byte read from port.
 */
uint8_t asm_read_port(uint8_t port);

/**
 * @ingroup interrupts
 *
 * @brief Write byte to the port.
 *
 * @param port  Port number for writing.
 *
 */
void asm_write_port(uint32_t port, uint8_t data);

#endif
