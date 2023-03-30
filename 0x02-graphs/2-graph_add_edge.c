#include "graphs.h"
/**
 * edge_init -  allocates memory for a edge edge, initializes its contents, and
 *              places edge where it belongs in the source vertex
 * @src: source vertex
 * @dest: destination vertex
 * Return: 1 when an edge has been created | 0 on failure
 **/
int edge_init(vertex_t *src, vertex_t *dest)
{
	edge_t *edge, **edge_pointer;


	if (dest == NULL || src == NULL)
		return (0);

	/* Check that this edge doesn't already exist */
	for (edge_pointer = &src->edges; *edge_pointer; edge_pointer = &(*edge_pointer)->next)
		if ((*edge_pointer)->dest == dest)
			return (0);

	edge = malloc(sizeof(edge_t));
	if (edge == NULL)
		return (0);

	edge->dest = dest;
	edge->next = NULL;
	*edge_pointer = edge;

	/* Keep track of edge count */
	src->nb_edges += 1;

	return (1);
}

/**
 * find_node - searches for a vertex in a graph
 * @graph: pointer to graph
 * @content: content of vertex
 * Return: pointer to vertex | NULL if not in list
 **/
vertex_t *find_node(graph_t *graph, const char *content)
{
	vertex_t *p;

	for (p = graph->vertices; p; p = p->next)
		if (strcmp(p->content, content) == 0)
			return (p);

	return (NULL);
}

/**
 * graph_add_edge - adds an edge between two vertices in an existing graph
 * @graph: pointer to graph
 * @src: string identifying the vertex to make the connection from
 * @dest: string identifying the vertex to connect to
 * @type: type of edge.
 *          * If UNIDIRECTIONAL: one edge connecting src to dest is created
 *          * If BIDIRECTIONAL: two edges are created, connecting src to dest
 *                              and vice-versa
 * Return: 1 on success | 0 on failure
 **/
int graph_add_edge(
	graph_t *graph, const char *src, const char *dest, edge_type_t type)
{
	vertex_t *source, *destination;

	if (!graph || !src || !dest || type > BIDIRECTIONAL)
		return (0);

	source = find_node(graph, src);
	if (source == NULL)
		return (0);

	destination = find_node(graph, dest);
	if (destination == NULL)
		return (0);

	if (type == UNIDIRECTIONAL)
		return (edge_init(source, destination));

	edge_init(source, destination);
	edge_init(destination, source);
	return (1);
}