#ifndef __PATHFINDING_H__
#define __PATHFINDING_H__


#include <stdio.h>
#include <string.h>
#include "graphs.h"
#include "queues.h"
/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
    int x;
    int y;
} point_t;

queue_t *backtracking_array(char **map, int rows, int cols, point_t const 
*start, point_t const *target);
queue_node_t *queue_push_front(queue_t *queue, void *ptr);


#endif /* __PATHFINDING_H__ */
