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

  /* ORDER: RIGHT->BOTTOM->LEFT->TOP */

  while (start != target)
    {
      

    }



  return (queue);
}
