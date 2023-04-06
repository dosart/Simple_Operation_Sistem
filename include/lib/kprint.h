#ifndef KPRINT_H
#define KPRINT_H

#include "common.h"
#include "lib/string.h"
#include "video/video.h"

/**
 * @ingroup video
 *
 * @brief  Prints char to the OS console.
 *
 * @param format  string for output.
 */
void kprintf(const char* format, ...);
void kvprintf(const char* format, va_list list);
void kclear();

#endif