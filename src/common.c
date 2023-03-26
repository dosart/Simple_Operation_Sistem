#include "common.h"

void *memset(void *buf, char z, u32int bytes) {
  char *tmp_buf = buf;
  while (bytes) {
    *tmp_buf++ = z;
    --bytes;
  }
  return buf;
}