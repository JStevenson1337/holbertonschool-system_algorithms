#include "graphs.h"
/**
 * initialize_vertex - allocates memory for a new vertex
 * @str: contents of the vertex
 * @index: store index
 *
 * Return: pointer to new vertex
 **/
vertex_t *initialize_vertex(const char *str, size_t index)
{
	vertex_t *node = malloc(sizeof(vertex_t));

	if (!node)
		return (NULL);

	node->content = strdup(str);
	node->nb_edges = 0;
	node->edges = NULL;
	node->next = NULL;
	node->index = index;
	return (node);
}

/**
 * graph_add_vertex - adds a vertex
 * @graph: pointer to the graph structure
 * @str: content of new vertex
 *
 * Return: pointer to new vertex
 **/
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t **vertex;

	if (!graph || !str)
		return (NULL);

	for (vertex = &graph->vertices; *vertex; vertex = &(*vertex)->next)
		if (strcmp(str, (*vertex)->content) == 0)
			return (NULL);

	*vertex = initialize_vertex(str, graph->nb_vertices);
	graph->nb_vertices += 1;
	return (*vertex);
}
