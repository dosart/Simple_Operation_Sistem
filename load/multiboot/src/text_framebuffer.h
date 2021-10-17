#ifndef        TEXT_FRAMEBUFFER_H
#define        TEXT_FRAMEBUFFER_H
/* Video memory begin address*/
#define        VIDEO_MEMORY    0xB8000

/*    Text mode colors       */
#define        BLACK        0x0
#define        BLUE         0x1
#define        GREEN        0x2
#define        CIAN         0x3
#define        RED          0x4
#define        MAGENA       0x5
#define        BROWN        0x6

#define        LIGHT_GRAY   0x7
#define        DARK_GRAY    0x8
#define        LIGHT_BLUE   0x9
#define        LIGHT_GREEN  0xA
#define        LIGHT_CIAN   0xB
#define        LIGHT_RED    0xC
#define        LIGHT_MAGENA 0xD
#define        LIGHT_BROWN  0xE
#define        WHITE        0xF

#define        SCREEN_WIDTH  80
#define        SCREEN_HEIGHT 25

typedef unsigned int u32int;
typedef unsigned short u16int;
typedef unsigned char u8int;

u8int default_background_color = BLACK;
u8int default_text_color = LIGHT_GRAY;

u16int *video_memory = (u16int *) VIDEO_MEMORY;
u8int width = SCREEN_WIDTH;
u8int height = SCREEN_HEIGHT;

void clear();
void print_str(const char *str, u8int background_color, u8int str_color);

#endif