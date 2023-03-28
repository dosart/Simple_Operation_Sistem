#include "descriptor_tables/descriptor_tables.h"
#include "video/text_framebuffer.h"

void kernel_main() {
  char *text = "Hello world!\n";

  clear();
  print_text(text);
  init_descriptor_tables();
}
