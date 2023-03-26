#include "pic.h"

extern unsigned char asm_read_port(unsigned char port);
extern void asm_write_port(unsigned int port, unsigned char data);

extern void pic_init() {
  asm_write_port(PIC1_CMD_PORT, PIC_IQW_CMD); /* init PIC1 */
  asm_write_port(PIC2_CMD_PORT, PIC_IQW_CMD); /* init PIC2 */

  asm_write_port(PIC1_DATA_PORT, 0x20); /* IQW2 offset */
  asm_write_port(PIC2_DATA_PORT, 0x28); /* IQW2 offset */

  asm_write_port(PIC1_DATA_PORT, 0x00); /* IQW3 no cascade */
  asm_write_port(PIC2_DATA_PORT, 0x00); /* IQW3 no cascade */

  asm_write_port(PIC1_DATA_PORT, 0x01); /* IQW4 no cascade */
  asm_write_port(PIC2_DATA_PORT, 0x01); /* IQW4 no cascade */

  asm_write_port(PIC1_DATA_PORT, 0xff); /* disable irq PIC1 */
  asm_write_port(PIC2_DATA_PORT, 0xff); /* disable irq PIC2 */
}