#include "interrupts/keyboard.h"

void keyboard_handler()
{
    uint8_t status = asm_read_port(KEYBOARD_STATUS_PORT);
    if(status & 0x01)
    {
        char keycode = asm_read_port(KEYBOARD_DATA_PORT);

        if(keycode < 1)
        {
            goto end;
        }
    }

end:
    asm_write_port(PIC1_CMD_PORT, 0x20); /* end of interrupt */
}