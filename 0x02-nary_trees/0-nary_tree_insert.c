#include "nary_trees.h"
/**
 * nary_tree_insert - insert a node into the tree
 *
 * @parent: pointer to the parent node
 * @str: string to be stored in the tree
 *
 * Return - pointer to the new node or NULL if fail
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *new = calloc(1, sizeof(*new));
	char *str = strdup(_str);

	if (!new || !str)
		return (free(new), free(str), NULL);

	new->content = str;
	if (!parent)
		return (new);
	new->next = parent->children;
	parent->children = new;
	parent->nb_children++;
	return (new);
}