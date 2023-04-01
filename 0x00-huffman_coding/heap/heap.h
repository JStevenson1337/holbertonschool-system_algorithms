#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct binary_tree_node_s - Binary tree node data structure
 *
 * @data: Data stored in a node
 * @left: Pointer to the left child
 * @right: Pointer to the right child
 * @parent: Pointer to the parent node
 */
typedef struct binary_tree_node_s
{
    void *data;
    struct binary_tree_node_s *right;
    struct binary_tree_node_s *parent;
    struct binary_tree_node_s *left;
} binary_tree_node_t;

/**
 * struct heap_s - Heap data structure
 *
 * @size: Size of the heap (number of nodes)
 * @data_cmp: Function to compare two nodes data
 * @root: Pointer to the root node of the heap
 */
typedef struct heap_s
{
    size_t size;
    int (*data_cmp)(void *, void *);
    binary_tree_node_t *root;
} heap_t;


heap_t *heap_create(int (*data_cmp)(void *, void *));

#endif /*  __HEAP_H__ */
