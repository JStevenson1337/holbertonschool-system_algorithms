#include "heap.h"

/**
 * heap_insert - Inserts a value in a Min Binary Heap
 *
 * @heap: Pointer to the heap
 * @data: Data contained in the node
 *
 * Return: Pointer to the created node, or NULL if it fails
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *node;

	if (!heap || !data)
		return (NULL);

	node = binary_tree_node(heap->root, data);
	if (!node)
		return (NULL);

	if (!heap->root)
		heap->root = node;
	else
		heapify_up(heap, node);

	heap->size += 1;

	return (node);
}

/**
 * heapify_up - Heapifies a node up
 *
 * @heap: Pointer to the heap
 * @node: Pointer to the node to heapify
 */
void heapify_up(heap_t *heap, binary_tree_node_t *node)
{
	binary_tree_node_t *parent;

	while (node->parent)
	{
		parent = node->parent;

		if (heap->data_cmp(parent->data, node->data) > 0)
		{
			parent->data = node->data;
			node->data = parent->data;
			node = parent;
		}
		else
			break;
	}
}
