SOURCES=src/entry_point.o src/kernel_main.o src/lib/string.o

CFLAGS=-Wall -Werror -fno-pie -nostdlib -nostdinc -fno-builtin -fno-stack-protector -m32 -g -I include

LDFLAGS=-T config/link.ld -m elf_i386 

ASFLAGS=--32

OUTPUT_DIR = ./bin

all: mkdir_build $(SOURCES) link clean

mkdir_build:
	$(shell [ ! -d  $(OUTPUT_DIR) ] && mkdir $(OUTPUT_DIR))

link:
	ld $(LDFLAGS) -o $(OUTPUT_DIR)/kernel $(SOURCES)

clean:
	rm $(shell find . -name "*.o")

clean_all:
	@make clean
	rm $(OUTPUT_DIR)/kernel

run:
	@make all && qemu-system-x86_64 -kernel $(OUTPUT_DIR)/kernel

