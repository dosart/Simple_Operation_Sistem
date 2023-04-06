/*!
@file
@defgroup video
@brief  Header file for OS console
*/
#ifndef VIDEO_H
#define VIDEO_H

#include "lib/stdint.h"

#define VIDEO_MEMORY 0xB8000

#define BLACK 0x0
#define BLUE 0x1
#define GREEN 0x2
#define CIAN 0x3
#define RED 0x4
#define MAGENA 0x5
#define BROWN 0x6

#define LIGHT_GRAY 0x7
#define DARK_GRAY 0x8
#define LIGHT_BLUE 0x9
#define LIGHT_GREEN 0xA
#define LIGHT_CIAN 0xB
#define LIGHT_RED 0xC
#define LIGHT_MAGENA 0xD
#define LIGHT_BROWN 0xE
#define WHITE 0xF

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define SCREEN_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT)

/**
 * @ingroup video
 *
 * @brief  Prints char to the OS console.
 *
 * @param c  char for output.
 */
void video_put_char(char c);

/**
 * @ingroup video
 *
 * @brief  Screen scrolling.
 */
void video_scroll();

/**
 * @ingroup video
 *
 * @brief  Positioning the cursor on the screen.
 */
void video_move_cursor(uint8_t x, uint8_t y);

/**
 * @ingroup video
 *
 * @brief  Clear the screen.
 */
void video_clear();

extern unsigned char asm_read_port(unsigned char port);
extern void asm_write_port(unsigned int port, unsigned char data);

#endif
