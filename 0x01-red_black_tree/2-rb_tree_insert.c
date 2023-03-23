#include "rb_trees.h"

/**
 * rb_tree_insert - inserts a value in a Red-Black Tree
 *
 * @tree: double pointer to root node of Red-Black tree to insert the value in
 * @value: the value to store in the node to be inserted
 *
 * Return: pointer to created node, or NULL on failure
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *x = NULL;
	rb_tree_t *y = NULL;
	rb_tree_t *new = NULL;

	if (!tree)
		return (NULL);

	x = *tree;
	while (x != NULL)
	{
		y = x;
		if (x->n == value)
			return (NULL);
		if (value < x->n)
			x = x->left;
		else if (value > x->n)
			x = x->right;
	}
	new = rb_tree_node(y, value, RED);
	if (!new)
		return (NULL);

	if (y == NULL)
		*tree = new;
	else if (new->n < y->n)
		y->left = new;
	else
		y->right = new;
	rb_insert_fixup(tree, new);
	return (new);
}

/**
 * rb_insert_fixup - rotate nodes and recolor to fix violation
 *
 * @tree: double pointer to root node
 * @new_node: new node to fix
 *
 */
void rb_insert_fixup(rb_tree_t **tree, rb_tree_t *new_node)
{
	while (new_node->parent && new_node->parent->color == RED)
	{
		if (new_node->parent->parent && new_node->parent
			== new_node->parent->parent->left)
			new_node = rb_insert_fixup_RIGHT(tree, new_node);
		else
			new_node = rb_insert_fixup_LEFT(tree, new_node);
	}
	(*tree)->color = BLACK;
}

/**
 * rb_insert_fixup_LEFT - fixes when p->p->left
 *
 * @tree: root node
 * @new_node: node to be fixed
 *
 * Return: pointer to new node
 */
rb_tree_t *rb_insert_fixup_LEFT(rb_tree_t **tree, rb_tree_t *new_node)
{
	rb_tree_t *y = NULL;

	y = new_node->parent->parent->left;
	if (y && y->color == RED)
	{
		new_node->parent->color = BLACK;
		y->color = BLACK;
		new_node->parent->parent->color = RED;
		new_node = new_node->parent->parent;
	}
	else
	{
		if (new_node == new_node->parent->left)
		{
			new_node = new_node->parent;
			rb_rotate_right(tree, new_node);
		}
		new_node->parent->color = BLACK;
		new_node->parent->parent->color = RED;
		rb_rotate_left(tree, new_node->parent->parent);
	}
	return (new_node);
}

/**
 * rb_insert_fixup_RIGHT - fixes when p->p->right
 * @tree: root node
 * @new_node: node to be fixed
 *
 * Return: pointer to new node
 */
rb_tree_t *rb_insert_fixup_RIGHT(rb_tree_t **tree, rb_tree_t *new_node)
{
	rb_tree_t *y = NULL;

	y = new_node->parent->parent->right;
	if (y && y->color == RED)
	{
		new_node->parent->color = BLACK;
		y->color = BLACK;
		new_node->parent->parent->color = RED;
		new_node = new_node->parent->parent;
	}
	else
	{
		if (new_node == new_node->parent->right)
		{
			new_node = new_node->parent;
			rb_rotate_left(tree, new_node);
		}
		new_node->parent->color = BLACK;
		new_node->parent->parent->color = RED;
		rb_rotate_right(tree, new_node->parent->parent);
	}
	return (new_node);
}

/**
 * rb_rotate_left - rotates subtree to left
 *
 * @tree: root node
 * @x: node to rotate
 */
void rb_rotate_left(rb_tree_t **tree, rb_tree_t *x)
{
	rb_tree_t *y = NULL;

	y = x->right;
	x->right = y->left;
	if (y->left)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
		*tree = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
}

/**
 * rb_rotate_right - rotates subtree to right
 *
 * @tree: root node
 * @y: node to rotate
 */
void rb_rotate_right(rb_tree_t **tree, rb_tree_t *y)
{
	rb_tree_t *x = NULL;

	x = y->left;
	y->left = x->right;
	if (x->right)
		x->right->parent = y;
	x->parent = y->parent;
	if (y->parent == NULL)
		*tree = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;
	x->right = y;
	y->parent = x;
}
