CC ?= gcc
LD ?= ld
ASM ?= nasm

OUTPUT_DIR = ./build
IDIR=./include

CC_FLAGS := -nostdlib -nostdinc -m32 -fno-builtin -fno-stack-protector -c -Wall -Werror -I include
LD_FLAGS := -m elf_i386 -T
ASM_FLAGS := -f elf32

SOURCES_C := $(shell find src -name "*.c")
SOURCES_ASM := $(shell find src -name "*.asm")

OBJECTS_C := $(SOURCES_C:.c=.o)
OBJECTS_ASM := $(SOURCES_ASM:.asm=.o)
EXECUTABLE := kernel


all: mkdir_build $(EXECUTABLE) $(SOURCES_C) $(SOURCES_ASM)
	@make clean

$(EXECUTABLE): $(OBJECTS_C) $(OBJECTS_ASM) 
	$(LD) $(LD_FLAGS) config/link.ld  $(OBJECTS_C) $(OBJECTS_ASM) -o $(OUTPUT_DIR)/$(EXECUTABLE)

%.o: %.c
	$(CC) $(CC_FLAGS) -o $@ $<

%.o: %.asm
	$(ASM) $(ASM_FLAGS) -o $@ $<

.PHONY: clean, mkdir_build

clean:
	rm $(shell find . -name "*.o")

mkdir_build:
	$(shell [ ! -d  $(OUTPUT_DIR) ] && mkdir $(OUTPUT_DIR))