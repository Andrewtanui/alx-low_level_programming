#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Return NULL if width or height is 0 or negative.
 * Allocate memory for the grid.
 * Allocate memory for each row of the grid.
 * Free previously allocated rows and return NULL if allocation fails.
 * Initialize each element of the row to 0.
 **/

int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(sizeof(int *) * height);

	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(int) * width);

		if (grid[i] == NULL)
		{
			for (; i >= 0; i--)
				free(grid[i]);

			free(grid);
			return (NULL);
		}
	}

	for (i = 0; i< height; i++)
	{
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}
