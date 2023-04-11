#include <stdlib.h>

/**
 * free_grid - frees a 2D array previously created by alloc_grid
 * @grid: the 2D array to free
 * @height: the height of the 2D array
 */
void free_grid(int **grid, int height)
{
    int i;

    if (grid == NULL || height <= 0)
        return;

    for (i = 0; i < height; i++)
    {
        if (grid[i] != NULL)
            free(grid[i]);
    }

    free(grid);
}

