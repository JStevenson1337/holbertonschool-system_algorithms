#include "pathfinding.h"
#include "queues.h"
/* Define the direction to explore the map */
static int direction[4][2] = {
	{1, 0},	/* right */
	{0, 1},	/* bottom */
	{-1, 0},	/* left */
	{0, -1}	/* top */
};

/**
 * backtracking_array - Searches for the first path from a starting point
 * to a target point within a two-dimensional array
 *
 * @map: Pointer to a read-only two-dimensional array
 * @rows: Number of rows of map
 * @cols: Number of columns of map
 * @start: Coordinates of the starting point
 * @target: Coordinates of the target point
 *
 * Return: A pointer to a queue containing the coordinates of the path,
 * or NULL if the path couldn't be found
 */
queue_t *backtracking_array(char **map, int rows, int cols,
	point_t const *start, point_t const *target)
{
	queue_t *q;
	point_t *point;
	int i;

	/* Allocate queue and point */
	q = queue_create();
	if (!q)
		return (NULL);
	point = malloc(sizeof(*point));
	if (!point)
		return (NULL);

	/* Set point to starting point */
	point->x = start->x;
	point->y = start->y;

	/* Enqueue starting point */
	if (!queue_push_back(q, point))
	{
		free(point);
		queue_delete(q);
		return (NULL);
	}

	/* Mark starting point as visited */
	map[point->x][point->y] = 1;

	/* Recursive exploration of the map */
	if (!explore_map(map, rows, cols, point, target, q))
	{
		for (i = 0; q->front; i++)
			free(dequeue(q));
		queue_delete(q);
		q = NULL;
	}

	return (q);
}

/**
 * explore_map - Recursively explores the map using backtracking
 *
 * @map: Pointer to a two-dimensional array
 * @rows: Number of rows of map
 * @cols: Number of columns of map
 * @start: Coordinates of the starting point
 * @target: Coordinates of the target point
 * @q: Pointer to the queue
 *
 * Return: 1 on success, 0 on failure
 */
int explore_map(char **map, int rows, int cols, point_t *start,
	point_t const *target, queue_t *q)
{
	point_t *point;
	int i, x, y;

	/* Check if target has been reached */
	if (start->x == target->x && start->y == target->y)
		return (1);

	/* Explore neighbour cells */
	for (i = 0; i < 4; i++)
	{
		/* Calculate neighbour cell coordinates */
		x = start->x + direction[i][0];
		y = start->y + direction[i][1];

		/* Check if neighbour cell is valid and not visited */
		if (x >= 0 && x < rows && y >= 0 && y < cols && map[x][y] == 0)
		{
			/* Mark neighbour cell as visited */
			map[x][y] = 1;

			/* Allocate new cell and enqueue it */
			point = malloc(sizeof(*point));
			if (!point)
				return (0);
			point->x = x;
			point->y = y;
			if (!queue_push_back(q, point))
			{
				free(point);
				return (0);
			}

			/* Print cell */
			printf("[%d, %d]\n", x, y);

			/* Recursive exploration of the map */
			if (explore_map(map, rows, cols, point, target, q))
				return (1);

			/* Dequeue cell and free it on failure */
			free(dequeue(q));
		}
	}

	/* Failure */
	return (0);
}
