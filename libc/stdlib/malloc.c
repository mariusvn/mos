
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

/*  WORK IN PROGRESS */


/*
 *  init:
 *  O: 1 si init
 *  1: rien
 *  ...
 *  256: 1er pack
 *
 * 	pack:
 *  0->3: magic int (ALLOC_MAGIC_NBR)
 *  4: is_blocked
 *  5->12: size
 *
 *  - On cree un enorme pack libre
 *  - au malloc
 *    - on coupe le pack avec la size, on le met en blocked, et on crée un autre
 *      pack au bou du notre qui pointe vers le meme pack que le précedent
 *  - au free
 *    - on passe le blocked on free, on va chercher le prochain pack blocked et
 *      on me la longeur du premier à la distance du premier au second
 */

int get_packs_nbr(size_t size)
{
	int res = 0;
	while (res * PACK_SIZE < size)
		res++;
	return res;
}

void init_malloc()
{
	char *origin = (char *) ALLOC_ORIGIN;
	*origin = 1;
}

int is_init_alloc()
{
	char *a = (char *) ALLOC_ORIGIN;
	if (*a == 1)
		return 1;
	return 0;
}

size_t get_pack_size(void *ptr)
{
	size_t *size = (size_t *)(ptr + 5);
	return (*size);
}

bool is_magic(void *ptr)
{
	int *magic = (int *) ptr;
	if (*magic == ALLOC_MAGIC_NBR)
		return true;
	return false;
}

bool is_pack_blocked(void *ptr)
{
	char *is_blocked = (char *)(ptr + 4);
	if (is_blocked == 1)
		return 1;
	return 0;
}

void init_pack(void *ptr, bool is_blocked, size_t *size)
{
	int *magic = (int *)ptr;
	char *blocked = (char *)(ptr + 4);
	size_t *psize = (size_t *)(ptr + 5);

	*magic = ALLOC_MAGIC_NBR;
	*blocked = is_blocked;
	*psize = size;
}

void *malloc(size_t size) {
	/*
	if (!is_init_alloc)
		return (NULL);
	void *act_ptr = ((void *) ALLOC_ORIGIN) + ALLOC_BASE_OFFSET;
	while (is_magic(act_ptr) && is_pack_blocked(act_ptr)) {
		act_ptr += get_pack_size(act_ptr);
	}
	if (is_magic(act_ptr)) //already a pack but free
	{
		if (get_pack_size(act_ptr) < size)
		{
			//TODO je recommence
		}
		else
		{

		}
	}



	WIP:  DO NOT TOUCH


	*/

	static void *last_pos = (void *) ALLOC_ORIGIN;
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
