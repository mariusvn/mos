
#include <stddef.h>

void *malloc(size_t size) {
	static void *last_pos = (void *) 0x8000;
	void *res = last_pos;
	last_pos += size + 1;
	return res;
}

void *calloc(size_t size) {
	char *mem = (char *) malloc(size);
	for (size_t i = 0; i < size; i++) {
		mem[i] = '\0';
	}
	return (void *) mem;
}
