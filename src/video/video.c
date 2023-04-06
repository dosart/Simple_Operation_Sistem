#include "video/video.h"

static uint8_t cursor_x = 0;
static uint8_t cursor_y = 0;

static uint8_t background_color = BLACK;
static uint8_t text_color = LIGHT_GRAY;

static uint8_t width = SCREEN_WIDTH;
static uint8_t height = SCREEN_HEIGHT;

static uint16_t* video_memory = (uint16_t*)VIDEO_MEMORY;

void video_put_char(char c)
{
    /* Create background and text colors to attribute byte */
    uint8_t attrib_byte = (background_color << 4) | (text_color & 0x0F);
    /* Create a word, in the high byte of which we put attributes */
    uint16_t attrib_word = attrib_byte << 8;
    /* Pointer to the current video memory location */
    uint16_t* location;

    if(c == 0x08 && cursor_x) /* Backspace character */
    {
        cursor_x--; /* Shifts the cursor if it is not at the beginning of the line */
    }
    else if(c == 0x09) /* TAB character */
    {
        cursor_x = (cursor_x + 8) & ~(8 - 1);
    }
    else if(c == '\r') /* Return - return to the beginning of the line */
    {
        cursor_x = 0;
    }
    else if(c == '\n') /* Enter - line feed */
    {
        cursor_x = 0; /* Cursor to the beginning of the line */
        cursor_y++;   /* One line down */
    }
    else /* Other characters (most meanings) */
    {
        /* Calculate the desired address in the video memory */
        location = video_memory + (cursor_y * width + cursor_x);
        /* Write a character to video memory with attributes */
        *location = c | attrib_word;
        /* Move cursor to the right */
        cursor_x++;
    }

    if(cursor_x > width)
    {
        cursor_x = 0;
        cursor_y++;
    }
    video_scroll();
    video_move_cursor(cursor_x, cursor_y);
}

void video_clear()
{
    /* Create background and text colors to attribute byte */
    uint8_t attrib_byte = (background_color << 4) |
                          (text_color & 0x0F);
    /* Creating a blank with attributes */
    uint16_t blank = 0x20 | (attrib_byte << 8);
    /* Create two spaces in a row to use 32-bit */
    /* data buses when copying to video memory */
    uint32_t wide_blank = (blank << 16) | blank;

    uint32_t* wide_buf = (uint32_t*)video_memory;
    uint32_t wide_buf_size = (width >> 2) * height;
    for(uint32_t i = 0; i < wide_buf_size; i++)
    {
        wide_buf[i] = wide_blank;
    }
    video_move_cursor(0, 0);
}

void video_scroll()
{
    /* Send background and text colors to attribute byte */
    uint8_t attrib_byte = (background_color << 4) | (text_color & 0x0F);

    /* Create a "space" character and add attributes to it */
    uint16_t blank = 0x20 | (attrib_byte << 8);

    /* If the last line of the screen is reached */
    if(cursor_y >= height)
    {
        int i;

        /* Shift all above rows up */
        for(i = 0 * width; i < (height - 1) * width; i++)
        {
            video_memory[i] = video_memory[i + width];
        }

        /* Fill in the last line with spaces */
        for(i = (height - 1) * width; i < height * width; i++)
        {
            video_memory[i] = blank;
        }

        /* Put the cursor at the beginning of the last line */
        cursor_y = 24;
        video_move_cursor(cursor_x, cursor_y);
    }
}

void video_move_cursor(uint8_t x, uint8_t y)
{
    /* Calculate cursor position for CRT */
    uint8_t cursor_position = y * width + x;

    /* Send the CRT register number to port 0x03D4 */
    asm_write_port(0x3D4, 0x0E);
    /* Send high byte of cursor position */
    asm_write_port(0x3D5, cursor_position >> 8);

    /* Send low byte of cursor position */
    asm_write_port(0x3D4, 0x0F);
    asm_write_port(0x3D5, cursor_position);

    cursor_x = x;
    cursor_y = y;
}
