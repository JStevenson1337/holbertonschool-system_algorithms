#include "heap.h"
/**
 * heap_extract - extract the root node of a Min Binary Heap
 * @heap: Pointer to the heap
 *
 * Return: Pointer to the data stored in the root node of the heap
 *         NULL upon failure or if the heap is empty
 */
void *heap_extract(heap_t *heap)
{
	binary_tree_node_t *last;
	void *data;

	if (!heap || !heap->root)
		return (NULL);

	data = heap->root->data;
	last = heap->root;

	if (heap->size > 1)
	{
		last = heap_node(heap, heap->size - 1);
		if (!last)
			return (NULL);
		heap->root->data = last->data;
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
		free(last);
		heap->size--;
		heapify(heap->root);
	}
	else
	{
		free(heap->root);
		heap->size--;
		heap->root = NULL;
	}
	return (data);
}

/**
 * heapify - rearrange a binary tree following a heap structure
 * @node: Pointer to the root node of the tree
 */
void heapify(binary_tree_node_t *node)
{
	binary_tree_node_t *tmp;
	heap_t *heap = NULL;

	if (!node)
		return;

	tmp = node;
	while (tmp->left || tmp->right)
	{
		if (tmp->right && 
			heap->data_cmp(tmp->data, tmp->right->data) > 0)
		{
			if (tmp->left &&
			    heap->data_cmp(tmp->right->data, tmp->left->data) > 0)
			{
				swap_data(tmp, tmp->left);
				tmp = tmp->left;
			}
			else
			{
				swap_data(tmp, tmp->right);
				tmp = tmp->right;
			}
		}
		else if (tmp->left &&
			 heap->data_cmp(tmp->data, tmp->left->data) > 0)
		{
			swap_data(tmp, tmp->left);
			tmp = tmp->left;
		}
		else
			break;
	}
}

/**
 * swap_data - swap two nodes data
 * @node_1: Pointer to the node 1
 * @node_2: Pointer to the node 2
 */
void swap_data(binary_tree_node_t *node_1, binary_tree_node_t *node_2)
{
	void *tmp;

	tmp = node_1->data;
	node_1->data = node_2->data;
	node_2->data = tmp;
}

/**
 * heap_node - returns a node from the heap
 * @heap: Pointer to the heap
 * @index: Index of the node to get
 *
 * Return: Node or NULL upon failure
 */
binary_tree_node_t *heap_node(heap_t *heap, size_t index)
{
	binary_tree_node_t *node;

	if (!heap || index >= heap->size)
		return (NULL);

	node = heap->root;
	while (node && index)
	{
		if (index % 2)
			node = node->left;
		else
			node = node->right;
		index = (index - 1) / 2;
	}
	return (node);
}