CC = gcc
CFLAGS = -m32
ASM = nasm
ASMFLAGS = -f macho
LD = ld
LDFLAGS = -macosx_version_min 10.10 -arch i386 -static -seg1addr 0x100000

all : kernel.img

clean :
	rm *.o *.img

kernel.img : kernel.o kernel-x86.o terminal.o
	$(LD) $(LDFLAGS) -o kernel.img kernel.o kernel-x86.o terminal.o

kernel-x86.o : kernel.x86
	$(ASM) $(ASMFLAGS) kernel.x86 -o kernel-x86.o

kernel.o : kernel.c
	$(CC) $(CFLAGS) -c kernel.c -o kernel.o

terminal.o : terminal.c
	$(CC) $(CFLAGS) -c terminal.c -o terminal.o

