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
	if (parent == NULL || str == NULL || strlen(str) == 0)
	{
		return (NULL);
	}
	
	

}