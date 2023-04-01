#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__


#include <string.h>

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
} symbol_t;


#endif /* __HUFFMAN_H__ */
