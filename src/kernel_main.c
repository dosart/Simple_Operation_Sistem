#include "text_framebuffer.h"

void kernel_main() {
  char *text = "Hello world!";

  clear();
  print_text(text);
}
