#include "heap.h"
/**
 * heap_create - determine if a node’s value is greater or lower than another
 *
 * @data_cmp: pointer to a comparison function
 * Return: pointer to created heap or NULL
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *h1;

	h1 = (heap_t *)malloc(sizeof(heap_t));

	if (!h1)
	{
		return (NULL);
	}

	return (h1);
	free(h1);
}
