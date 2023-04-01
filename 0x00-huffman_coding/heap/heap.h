#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdlib.h>
#include <stdio.h>



heap_t *heap_create(int (*data_cmp)(void *, void *));

#endif // HEAP_H_
