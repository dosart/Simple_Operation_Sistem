# Simple operation sistem

This is not a REAL operation system. It's just a simple operation system created in educational purposes.
The main goal I'm following is to learn how OS is working from the ground up. Starting from the own boot sector, hardware and software interrupts, own drivers.

Simple bootloader with support Multiboot.

## Roadmap
* Boot secto
  * Reads the kernel from disk into memory (DONE)
  * Reads the kernel from disk into memory (DONE)
  * Describes Global Descriptor Table (DONE)
  * Switches to 32-bit Protected Mode (DONE)
  * Checks if CPU support 64-bit Long Mode and switches into (DONE)
  * In case, if 64-bit Long Mode isn't supported, fallback into 32-bit (DONE)
  * Gives execution to kernel (DONE)
  
* Kernel
  * Kernel entry in assembly, which calls extern kernel_main() in C (DONE)
  * Low-level I/O functions: port_byte_in, port_byte_out and similar (DONE)
  * Interrupt Descriptor Table (DONE)
  * Interrupt Service Routines and their mapping to IDT (DONE)
  * Handling Interrupt Requests (IRQ) (DONE)
  * Handling IRQ0 of Programmable Interval Timer (DONE)
    
* Drivers:
  * screen driver implements printing to the screen (DONE)
  * keyboard driver listen for IRQ1 interrupt and handle it (DONE)    

## Dependences:
- make
- gcc
- as
- qemu
