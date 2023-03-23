#include "rb_trees.h"
/**
 * array_to_rb_tree - builds a Red-Black Tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: the number of elements in the array
 * Return: pointer to the root node of the created R-B tree, or NULL on failure
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	rb_tree_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (rb_tree_insert(&tree, array[i]) == NULL)
		{
			for (j = 0; j < size && array[j] != array[i]; j++)
			{}
			if (j == i)
				return (NULL);
		}
	}
	return (tree);
}
