#ifndef STDIO_H
#define STDIO_H

#include "lib/kprint.h"

#define printf(msg, ...) kprintf(msg, ##__VA_ARGS__)
#define clear() kclear()

#endif