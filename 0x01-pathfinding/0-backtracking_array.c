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
  int i = 0;
  (void)map;

  **map = rows * cols;
  /* ORDER: RIGHT->BOTTOM->LEFT->TOP */

  if (!map || !rows || !cols || !start || !target)
    return (NULL);

  /* Create Map grid size of map */
  for (i = 0; i < rows; i++)
      memcpy(checked[i], &map[i], sizeof((map \ (rows * cols)) -1 ));
      

      if ()
      
      
    }
  
  return (queue);
}
