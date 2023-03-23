#ifndef __RB_TREES_H__
#define __RB_TREES_H__

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stddef.h>


#define MAXIMUM(X, Y) ((X >= Y) ? X : Y)

/**
 * enum rb_color_e - Possible color of a Red-Black tree
 *
 * @RED: 0 -> Red node
 * @BLACK: 1 -> Black node
 * @DOUBLE_BLACK: -> DOUBLE_BACK
 */
typedef enum rb_color_e
{
	RED = 0,
	BLACK,
	DOUBLE_BLACK
} rb_color_t;

/**
 * struct rb_tree_s - Red-Black tree node structure
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 * @color: Color of the node (RED or BLACK)
 */
typedef struct rb_tree_s
{
	int n;
	rb_color_t color;
	struct rb_tree_s *parent;
	struct rb_tree_s *left;
	struct rb_tree_s *right;
} rb_tree_t;

rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color);


/* 1-rb_tree_is_valid.c */
int rb_tree_is_valid(const rb_tree_t *tree);
int is_bst(const rb_tree_t *tree, int min, int max);
int correct_colors(const rb_tree_t *tree);
int find_height(const rb_tree_t *tree);
int check_rb_height(const rb_tree_t *tree, int blk_height, int height);

/* 2-rb_tree_insert.c */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value);
void rb_insert_fixup(rb_tree_t **tree, rb_tree_t *new_node);
rb_tree_t *rb_insert_fixup_LEFT(rb_tree_t **tree, rb_tree_t *new_node);
rb_tree_t *rb_insert_fixup_RIGHT(rb_tree_t **tree, rb_tree_t *new_node);
void rb_rotate_left(rb_tree_t **tree, rb_tree_t *x);
void rb_rotate_right(rb_tree_t **tree, rb_tree_t *y);

/* 3-array_to_rb_tree.c */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value);

/* 4-rb_tree_remove.c */
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n);
rb_tree_t *rb_tree_delete(rb_tree_t *root, rb_tree_t *remove);
void rb_transplant(rb_tree_t **root, rb_tree_t *x, rb_tree_t *y);
rb_tree_t *rb_delete_fixup(rb_tree_t *root, rb_tree_t *x);
rb_tree_t *rb_delete_fix_left(rb_tree_t **root, rb_tree_t *x);
rb_tree_t *rb_delete_fix_right(rb_tree_t **root, rb_tree_t *x);
rb_tree_t *tree_min(rb_tree_t *root);
#endif /*__RB_TREES_H__ */
