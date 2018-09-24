#!/bin/sh
qemu-system-i386 --kernel kernel/mos.kernel -device isa-debug-exit,iobase=0xf4,iosize=0x04
