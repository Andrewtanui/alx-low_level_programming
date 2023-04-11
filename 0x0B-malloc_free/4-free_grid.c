#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2D array previously created by alloc_grid
 * @grid: the 2D array to free
 * @height: the height of the 2D array
 */
void free_grid(int **grid, int height)
{
	int index;

	for (index = 0; index < height; index++)
		free(grid[index]);

	free(grid);
}
