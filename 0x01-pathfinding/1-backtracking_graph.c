#include "graphs.h"
#include "queues.h"
#include "pathfinding.h"

/**
 * backtracking_graph - Searches for a path from start to target
 * in a graph
 *
 * @graph: Pointer to the graph to go through
 * @start: Pointer to the starting vertex
 * @target: Pointer to the target vertex
 *
 * Return: A pointer to the queue containing the path, NULL on failure
 */
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target)
{
	queue_t *q;
	edge_t *iter;
	vertex_t const *vertex;

	if (!graph || !start || !target)
		return (NULL);
	q = queue_create();
	if (!q)
		return (NULL);
	if (start == target)
		return (q);
	queue_push_back(q, (void *)start);
	vertex = start;
	while (vertex && vertex != target)
	{
		iter = vertex->edges;
		while (iter)
		{
			printf("Visited: %s\n", iter->dest->content);
			queue_push_back(q, (void *)iter->dest);
			if (iter->dest == target)
				return (q);
			iter = iter->next;
		}
		vertex = (vertex_t *)dequeue(q);
	}
	queue_delete(q);
	return (NULL);
}