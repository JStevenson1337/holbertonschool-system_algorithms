#include "heap.h"
#include <sys/cdefs.h>
/**
 * heap_create - determine if a node’s value is greater or lower than another
 *
 * @data_cmp: pointer to a comparison function
 * Return: pointer to created heap or NULL
 */
heap_t *heap_create(int __attribute_maybe_unused__ (*data_cmp)(void *, void *))
{
	void *h1;

	h1 = malloc(sizeof(heap_t));
	if (!h1)
	{
		return (NULL);
	}

	return ((heap_t *)h1);
}
