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

/**
 * struct dijkstra_node_s - struct with information about a graph node
 *                          to help us perform dijkstra's Algorithm
 * @vertex: current position in graph (vertex_t)
 * @via: previous position in graph (dijkstra_node_s)
 * @weight: weight of path from start point
 */
typedef struct dijkstra_node_s
{
	const vertex_t *vertex;
	struct dijkstra_node_s *via;
	int weight;
} dijkstra_node_t;


/**
 * struct a_star_node_s - struct with information about a graph node
 *                          to help us perform a_star_'s Algorithm
 * @vertex: current position in graph (vertex_t)
 * @via: previous position in graph (a_star_node_s)
 * @weight: weight of path from start point
 * @distance: distance to target in graph
 */
typedef struct a_star_node_s
{
	const vertex_t *vertex;
	struct a_star_node_s *via;
	int weight;
	double distance;
} a_star_node_t;

queue_t *backtracking_array(char **map, int rows, int cols,
	point_t const *start, point_t const *target);
int backtrack(char **map, int rows, int cols, point_t const *target,
	int x, int y, queue_t *path);
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target);
int dfs(vertex_t const *vertex);
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
			vertex_t const *target);
void print_visited_vertex(vertex_t const *v);

#endif /* __PATHFINDING_H__ */
