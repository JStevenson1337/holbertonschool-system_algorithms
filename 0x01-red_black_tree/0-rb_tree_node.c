#include "rb_trees.h"
/**
 * rb_tree_node - function that creates a Red-Black Tree node
 *
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * @color: is the color of the node
 *
 * Return: pointer to new node
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *node;

	if (color > DOUBLE_BLACK || color < RED)
	{
		fprintf(stderr,
			"rb_tree_node: color out of rb_color_t range\n");
		return (NULL);
	}

	node = malloc(sizeof(rb_tree_t));
	if (!node)
		return (NULL);

	node->n = value;
	node->color = color;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
