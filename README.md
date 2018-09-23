## MOS

#### How to use MOS ?

Requirements:
 - [i686-elf-tools](https://github.com/lordmilko/i686-elf-tools)
 - qemu (`sudo apt-get install qemu`)

just use these commands:

```bash
./build.sh
qemu-system-i386 --kernel kernel/mos.bin
```

Et normalement ça se lance :)
