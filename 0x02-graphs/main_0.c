/* Description: Creates a graph and checks that structure is initialized */

#include <stdlib.h>
#include <stdio.h>

#include "graphs.h"

void graph_delete(graph_t *graph);

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	graph_t *graph;

	graph = graph_create();
	if (!graph)
	{
		printf("Failed to create graph\n");
		return (EXIT_FAILURE);
	}

	printf("Successfully created graph\n");
	printf("Number of vertices: %lu\n", graph->nb_vertices);
	printf("Vertices head -> %p\n", (void *)(graph->vertices));

	graph_delete(graph);

	return (EXIT_SUCCESS);
}
