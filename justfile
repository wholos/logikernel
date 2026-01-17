all:
    @gcc -m32 -c kernel/main.c -o kernel/kernel.o
    @ld -m elf_i386 -T kernel/linker.ld -o bin/kernel.bin kernel/kernel.o
    @rm kernel/kernel.o

build: all

clean:
    @rm bin/kernel.bin
