#include "graphs.h"
/**
 * graph_delete - deletes and frees a graph object and its members
 * @graph: pointer to graph
 **/
void graph_delete(graph_t *graph)
{
	vertex_t *vertex;
	edge_t *edge;
	void *temp;

	if (graph == NULL)
		return;

	vertex = graph->vertices;
	while (vertex)
	{
		free(vertex->content);
		edge = vertex->edges;
		while (edge)
		{
			temp = (void *)edge;
			edge = edge->next;
			free(temp);
		}
		temp = (void *)vertex;
		vertex = vertex->next;
		free(temp);
	}

	free(graph);
}
