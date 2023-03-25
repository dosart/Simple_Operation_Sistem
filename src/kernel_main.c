#include "text_framebuffer.h"

void kernel_main() {
  const char *str = "Hello world!";

  clear();
  print_str(str, BLACK, GREEN);
}

void print_str(const char *str, u8int background_color, u8int str_color) {
  /* Forming the attribute byte */
  u8int attribute_byte = (background_color << 4) | (str_color & 0xF);

  u8int i = 0;
  u8int j = 0;
  while (str[i]!='\0') {
    video_memory[j] = str[i] | (attribute_byte << 8);
    j = j + 1;
    i = i + 1;
  }
}

void clear() {
  /* Forming the attribute byte */
  u8int attribute_byte = (default_background_color << 4) | (default_text_color & 0xF);
  /* Create a blank with attributes */
  u16int narrow_blank = 0x20 | (attribute_byte << 8);
  /* Create two spaces in a row to use 32-bit data bus when copying to video memory*/
  u32int wide_blank = (narrow_blank << 16) | narrow_blank;
  /*Transforming the video buffer into an array of 32-bit numbers*/
  u32int *wide_buf = (u32int *) video_memory;

  /*Calculating the size of the 32-bit video buffer*/
  u32int N = (width >> 2)*height;
  /* Filling the video memory with spaces */
  u32int i;
  for (i = 0; i < N; i++) {
    wide_buf[i] = wide_blank;
  }
}