#ifndef __PATHFINDING_H__
#define __PATHFINDING_H__


#include <stdio.h>
#include <string.h>
#include "graphs.h"
#include "queues.h"
#include "stdlib.h"

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



/* Task 0 */
queue_t *backtracking_array(char **map, int rows, int cols, point_t const 
*start, point_t const *target);
queue_node_t *queue_push_front(queue_t *queue, void *ptr);
int explore_map(char **map, int rows, int cols, point_t *start,
	point_t const *target, queue_t *q);

/* Task 1 */
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target);

/* Task 2 */
void print_visited_vertex(vertex_t const *v);
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target);


#endif /* __PATHFINDING_H__ */
