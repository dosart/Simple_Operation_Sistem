#include "lib/kprint.h"

void kprintf(const char* format, ...)
{
    va_list list;
    va_start(list, format);

    kvprintf(format, list);
}

void kvprintf(const char* format, va_list list)
{
    char buff[SCREEN_WIDTH];
    int len = vsprintf(buff, format, list);

    for(int i = 0; i < len; ++i)
        video_put_char(buff[i]);
}

void kclear()
{
    video_clear();
}