#include "heap.h"
/**
 * binary_tree_node - creates a generic Binary Tree node
 *
 * @parent: pointer to the parent node of the node to be created
 * @data: data to be stored in the node
 *
 * Return: pointer to the created node or NULL if it fails
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *node;

	node = (binary_tree_node_t *)malloc(sizeof(*node));

	if (node)
	{
		node->left = NULL;
		node->right = NULL;
		node->parent = parent;
		node->data = data;
	}
	return (node);
}
