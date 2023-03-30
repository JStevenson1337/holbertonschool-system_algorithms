#include "graphs.h"
/**
 * graph_create - initialize a graph structure
 *
 * Return: pointer to graph
 **/
graph_t *graph_create(void)
{
	graph_t *graph = (graph_t *)malloc(sizeof(graph_t));

	if (graph)
	{
		graph->nb_vertices = 0;
		graph->vertices = NULL;
	}

	return (graph);
}
