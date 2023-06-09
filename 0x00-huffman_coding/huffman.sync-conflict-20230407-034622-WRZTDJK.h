#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__



#include <string.h>
#include <stdlib.h>

#include "heap/heap.h"


/**
 * struct symbol_s - Stores a char and its associated frequency
 *
 * @data: The character
 * @freq: The associated frequency
 */
typedef struct symbol_s
{
    char data;
    size_t freq;
}symbol_t;


symbol_t *symbol_create(char data, size_t freq);


heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size);
int compare_frequencies(void *p1, void *p2);
void free_internal_node(void *data);

#endif /* __HUFFMAN_H__ */
