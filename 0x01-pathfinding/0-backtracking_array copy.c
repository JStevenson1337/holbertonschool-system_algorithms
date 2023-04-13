#include "pathfinding.h"

/* backtracking_array - finds the shortest path to a target node
 *
 * @map: map to treverse
 * @rows: rows of the map
 * @cols: columns of the map
 * @start: starting point
 * @target: target to reach
 *
 * Return - ponter to the array of the path
*/
queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target)
{
  	queue_t *queue = NULL;
  	char **checked = NULL;
	point_t const *p_pos;
  	int y, x = 0;
  	(void)map;

  	/* **map = rows * cols; */



	/* ORDER: RIGHT->BOTTOM->LEFT->TOP */

	if (!map || !rows || !cols || !start || !target)
	{
		return (NULL);
	}

 	/* Create Map grid size of map */
 	for (y = 0; y < rows; y++)
	{
		for (x = 0; x < cols; x++)
		{
			/* alloctae memory for queue */

			/* TODO: Wrap in if for queue */

			memcpy(&(checked[y][x]), &(map[y][x]), ((cols * rows) * sizeof(char *)));
			p_pos = (point_t const *) start;

			/* TODO: Cretae queue */

			/* TODO: Queue Coords with queue_push_front*/
		}
	}

	if (p_pos->x < 0 ||p_pos->y < 0 || p_pos->x >= cols || p_pos->y >= rows)
	{
		return (NULL);
	}

	checked[p_pos->y][p_pos->x] = 1;

	printf("Checking coordinates [%d, %d]\n", p_pos->y, p_pos->x);

	for (y = 0; y < rows; y++)
		{
			if (p_pos->y == target->y &&  p_pos->x == target->x)
			{
				printf("target aquired at:\n\tTraveler: [%d, %d]\t\t Target:[%d, %d]\n", p_pos->y, p_pos->x, target->y, target->x);
				break;
			}

		}






	{
	
	}
	queue = (queue_t *)queue_push_front((queue_t *)(*checked), (queue_t *)p_pos); 

	return ((queue_t *)queue);
}
