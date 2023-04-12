#include "queues.h"
#include "graphs.h"
#include "pathfinding.h"

/**
 * struct vertex_info_s - Information about a vertex to be stored in the queue
 * @vertex: Pointer to the actual vertex
 * @prev: Pointer to the previous vertex in the path
 * @distance: Distance from the start vertex
 *
 * This structure is used to store information about a vertex that should
 * be stored in the queue of vertices to be processed.
 */
typedef struct vertex_info_s
{
	vertex_t		*vertex;
	struct vertex_info_s	*prev;
	int			distance;
} vertex_info_t;

/**
 * dijkstra_graph - Searches for the shortest path between two vertices
 * @graph: Pointer to the graph to go through
 * @start: Pointer to the starting vertex
 * @target: Pointer to the target vertex
 *
 * Return: A pointer to the queue containing the shortest path,
 * or NULL on failure
 */
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target)
{
	int vertex_index;
	queue_t *vertex_queue, *path_queue;
	vertex_info_t *start_info, *target_info, *vertex_info;
	edge_t *edge;

	vertex_index = 0;
	vertex_queue = queue_create();
	path_queue = queue_create();
	start_info = NULL;
	target_info = NULL;
	if (!graph || !start || !target || !vertex_queue || !path_queue)
		return (NULL);
	start_info = (vertex_info_t *)malloc(sizeof(*start_info));
	if (!start_info)
		return (NULL);
	start_info->vertex = (vertex_t *)start;
	start_info->prev = NULL;
	start_info->distance = 0;
	if (queue_push_back(vertex_queue, start_info))
		return (NULL);
	while (vertex_queue->front)
	{
		vertex_info = (vertex_info_t *)dequeue(vertex_queue);
		if (vertex_info->vertex == target)
		{
			target_info = vertex_info;
			break;
		}
		for (edge = vertex_info->vertex->edges; edge; edge = edge->next)
		{
			if (edge->dest->index < vertex_info->vertex->index)
				continue;
			if ((edge->weight + vertex_info->distance) <
				edge->dest->edges->dest->distance)
			{
				edge->dest->edges->dest->distance =
					edge->weight + vertex_info->distance;
				edge->dest->edges->dest->prev =
					vertex_info->vertex;
				if (queue_push_back(vertex_queue,
					    edge->dest->edges->dest))
					return (NULL);
			}
		}
		free(vertex_info);
	}
	while (target_info)
	{
		printf("Vertex %d: %s\n", vertex_index, target_info->vertex->content);
		if (queue_push_front(path_queue, target_info->vertex))
			return (NULL);
		target_info = target_info->prev;
		vertex_index++;
	}
	return (path_queue);
}