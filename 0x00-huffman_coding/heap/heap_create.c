#include "heap.h"
/**
 * heap_create - determine if a node’s value is greater or lower than another
 *
 * @data_cmp: pointer to a comparison function
 * Return: pointer to created heap or NULL
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	void *h1;

<<<<<<< HEAD
	h1 = (heap_t *)malloc(sizeof(heap_t));

=======
	h1 = malloc(sizeof(heap_t));
	data_cmp(&h1, &h1);
	printf("heap size%lu\t\n", (void *)h1 = malloc(sizeof(unsigned long int)));
>>>>>>> parent of 518ab9b (corrected output)
	if (!h1)
	{
		return (NULL);
	}

<<<<<<< HEAD
	return ((heap_t *)h1);
=======
	return (h1);
>>>>>>> parent of 7176948 (corrected memory leak)
}
