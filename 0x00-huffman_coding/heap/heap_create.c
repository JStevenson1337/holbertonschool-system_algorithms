#include "heap.h"
/**
 * heap_create - determine if a node’s value is greater or lower than another
 *
 * @data_cmp: pointer to a comparison function
 * Return: pointer to created heap or NULL
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *h = NULL;

	h = (heap_t *)malloc(sizeof(*h));
	if (!h)
		return (NULL);
	h->root = NULL;
	h->size = 0;
	h->data_cmp = data_cmp;
	return (h);
}
