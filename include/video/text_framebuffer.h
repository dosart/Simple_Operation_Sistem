#ifndef TEXT_FRAMEBUFFER_H
#define TEXT_FRAMEBUFFER_H

#define VIDEO_MEMORY 0xB8000

/*	Main colors		*/

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

#include "common.h"

/* Move hardware cursor to reference screen position */
void move_cursor(u8int x, u8int y);

/*	Set colors	*/
void set_bkground_color(u8int color);
void set_text_color(u8int color);

/* Clean screen */
void clear(void);

/* Print text string */
void print_text(char *s);

/* Print hexadecimal value on screen */
void print_hex_value(u32int value);

/* Print decimal value on screen */
void print_dec_value(u32int value);

/* Print byte */
void print_byte(u8int value);

/* Print debug message */
void debug_msg(char *s, u32int value);

/* Print memory dump */
void print_dump(void *address, u32int size);

#endif