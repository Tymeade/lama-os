all: kernel

kasm.o: kernel.asm
	nasm -f elf32 kernel.asm -o kasm.o

kc.o: kernel.c
	gcc -m32 -c kernel.c -o kc.o

kernel: kasm.o kc.o
	ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o

clean:
	rm kasm.o kc.o kernel

install: kernel
	cp kernel /boot/kernel-702
