#!/bin/sh
# yum install binutils gcc grub2-tools qemu-kvm qemu-img virt-manager virt-install virt-viewer

as src/boot.s -o obj/boot.o

gcc -Iinclude -c src/vga.c -o obj/vga.o -std=c99 -ffreestanding
gcc -Iinclude -c src/main.c -o obj/main.o -std=c99 -ffreestanding

gcc -T linker.ld -o iso/boot/AsciiCharacters.bin -ffreestanding -nostdlib obj/boot.o obj/vga.o obj/main.o -lgcc

grub2-mkrescue -o AsciiCharacters.iso iso
#virt-install --name=AsciiCharacters --ram=16 --vcpus=1 --os-variant generic --cdrom=AsciiCharacters.iso --boot cdrom --disk none
