#include "huffman.h"
#include "heap/heap.h"

/**
 * symbol_create - creates a symbol_t data structure
 * @data: data to be stored in structure
 * @freq: freq to be stored in structure
 * Return: pointer to the created structure
 **/
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *new_symbols;

	new_symbols = (symbol_t *)malloc(sizeof(symbol_t));

	if (new_symbols == NULL)
		return (NULL);

	new_symbols->data = data;
	new_symbols->freq = freq;
	return (new_symbols);
}
