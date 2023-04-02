#include "heap.h"
/*
 * binary_tree_node -  creates a generic Binary Tree node
 *
 * @parent: pointer to the parent node of the node to be created
 * @data: data to be stored in the node
 *
 * Return - pointer to the created node or NULL if it fails
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	const binary_tree_node_t *node;

	node = (binary_tree_node_t *)malloc(sizeof(*node));

	if (!node && !data && !parent)
	{
		return (NULL);
	}

	printf("node: %lu\n", (size_t)node);
	printf("node->data: %lu\n", (unsigned long int)&node->data);


	
	if (node)
	{
		node = parent;
		node->data = parent->data;
		return (node);
	}
	else
		return (NULL);
}
