#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/mos.kernel isodir/boot/mos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
insmod vga

menuentry "mos" {
	multiboot /boot/mos.kernel vgaterm
	set gfxpayload=1024x768
	boot
}
EOF
grub-mkrescue -o mos.iso isodir
