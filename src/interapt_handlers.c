#include "interapt_handlers.h"

extern char asm_read_port(unsigned char port);
extern void asm_write_port(unsigned int port, unsigned char data);

void keyboard_handler() {
  char status = asm_read_port(KEYBOARD_STATUS_PORT);
  if (status & 0x01) {
    char keycode = asm_read_port(KEYBOARD_DATA_PORT);

    if (keycode < 1) {
      goto end;
    }

    char *str = "keyboard_handler";
    print_text(str);
  }

end:
  /* end of interrupt; write EOI */
  asm_write_port(0x20, 0x20);
}