#include "heap.h"
/**
 * heap_create - determine if a node’s value is greater or lower than another
 *
 * @data_cmp: pointer to a comparison function
 * Return: pointer to created heap or NULL
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{

	data_cmp = 0;

	heap_t *heap;

	heap = malloc(sizeof(heap_t));

	heap = heap_create(*data_cmp);

	if (heap == NULL)
	{
		return (NULL);
	}

	heap->root = NULL;
	heap->size = 0;

	return (heap);


}


