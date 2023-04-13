#include "pathfinding.h"
#include "queues.h"
/**
 * backtracking_array - Finds the shortest path from start to target in a
 * two-dimensional array.
 * The algorithm explores all adjacent cells starting from start, then exploring
 * right, bottom, left, top.
 *
 * @map: Two-dimensional array
 * @rows: Number of rows of map
 * @cols: Number of columns of map
 * @start: Starting point
 * @target: Target point
 *
 * Return: Queue containing the path from start to target.
 * If no path is found, return NULL.
 */
queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start,
    point_t const *target)
{
    int x = start->x, y = start->y;
    queue_t *q = queue_create(), *path = queue_create();
    point_t *point;

    if (!q || !path)
        return (NULL);
    point = malloc(sizeof(*point));
    if (!point)
    {
        free(q);
        free(path);
        return (NULL);
    }
    queue_push_back(q, point);
    while (q->front)
    {
        point = dequeue(q);
        if (point->x == target->x && point->y == target->y)
        {
            queue_push_back(path, point);
            free(point);
            queue_delete(q);
            return (path);
        }
        if (point->x < 0 || point->x >= cols || point->y < 0 ||
            point->y >= rows || map[point->y][point->x] == '1')
        {
            free(point);
            continue;
        }
        map[point->y][point->x] = '1';
        x = point->x + 1;
        y = point->y;
        point = malloc(sizeof(*point));
        if (!point)
            return (NULL);
        point->x = x, point->y = y;
        queue_push_back(q, point);
        x = point->x;
        y = point->y + 1;
        point = malloc(sizeof(*point));
        if (!point)
            return (NULL);
        point->x = x, point->y = y;
        queue_push_back(q, point);
        x = point->x - 1;
        y = point->y;
        point = malloc(sizeof(*point));
        if (!point)
            return (NULL);
        point->x = x, point->y = y;
        queue_push_back(q, point);
        x = point->x;
        y = point->y - 1;
        point = malloc(sizeof(*point));
        if (!point)
            return (NULL);
        point->x = x, point->y = y;
        queue_push_back(q, point);
        x = point->x - 1;
        y = point->y;
        point = malloc(sizeof(*point));
        if (!point)
            return (NULL);
        point->x = x, point->y = y;
        queue_push_back(q, point);
        point = malloc(sizeof(*point));
        if (!point)
            return (NULL);
        point->x = x, point->y = y;
        queue_push_back(path, point);
    }
    queue_delete(q);
    queue_delete(path);
    return (NULL);
}