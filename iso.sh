#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/mos.kernel isodir/boot/mos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "mos" {
	multiboot /boot/mos.kernel
}
EOF
grub-mkrescue -o mos.iso isodir
