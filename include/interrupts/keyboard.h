/*!
@file
@ingroup interrupts
@brief  The header file declares the keyboard interrupt handling function.
*/
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "lib/stdint.h"

extern unsigned char asm_read_port(unsigned char port);
extern void asm_write_port(unsigned int port, unsigned char data);

#define KEYBOARD_STATUS_PORT 0x64
#define KEYBOARD_DATA_PORT 0x60
#define PIC1_CMD_PORT 0x20

/**
 * @ingroup interrupts
 *
 * @brief Keyboard key press handler.
 *
 */
void keyboard_handler();

#endif