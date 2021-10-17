CC ?= gcc
LD ?= ld
ASM ?= nasm

CC_FLAGS := -m32 -c
LD_FLAGS := -m elf_i386 -T
ASM_FLAGS := -f elf32

OUTPUT_DIR = ./build

all: kernel

kernel: kernel_asm kernel_c
	$(LD) $(LD_FLAGS)  link.ld -o $(OUTPUT_DIR)/kernel $(OUTPUT_DIR)/kernel_asm.o $(OUTPUT_DIR)/kernel_c.o

kernel_asm: src/kernel.asm
	$(ASM) $(ASM_FLAGS) src/kernel.asm -o $(OUTPUT_DIR)/kernel_asm.o

kernel_c: src/kernel_main.c
	$(CC) $(CC_FLAGS) src/kernel_main.c -o $(OUTPUT_DIR)/kernel_c.o

.PHONY: clean
cleam:
	rm $(OUTPUT_DIR)/*