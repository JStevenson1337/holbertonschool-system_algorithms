#include "graphs.h"
/**
 * graph_add_vertex - adds a vertex
 * @graph: pointer to the graph structure
 * @str: content of new vertex
 *
 * Return: pointer to new vertex
 **/
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *vertex;

	if (!graph || !str)
		return (NULL);

	for (vertex = graph->vertices; vertex; vertex = (vertex)->next)
		if (strcmp(str, (vertex)->content) == 0)
			return (NULL);

	vertex = malloc(sizeof(vertex_t));

	if (!vertex)
		return (NULL);

	(vertex)->content = strdup(str);
	(vertex)->nb_edges = 0;
	(vertex)->edges = NULL;
	(vertex)->next = NULL;
	(vertex)->index = (long unsigned int)index;
	return (vertex);
}
