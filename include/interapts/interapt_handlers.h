#ifndef INTERAPT_HANDLERS_H
#define INTERAPT_HANDLERS_H

#include "video/text_framebuffer.h"

/*------------------------------------------------
// Keyboard handler
//----------------------------------------------*/
#define KEYBOARD_STATUS_PORT 0x64
#define KEYBOARD_DATA_PORT 0x60

void keyboard_handler();

#endif