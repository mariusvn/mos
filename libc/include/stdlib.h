#ifndef _STDLIB_H
#define _STDLIB_H 1

#include <sys/cdefs.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PACK_SIZE 4096
#define ALLOC_ORIGIN 0x8000
#define ALLOC_MAGIC_NBR 345
#define ALLOC_BASE_OFFSET 256

__attribute__((__noreturn__))
void abort(void);
void *malloc(size_t size);
void *calloc(size_t size);

#ifdef __cplusplus
}
#endif

#endif
