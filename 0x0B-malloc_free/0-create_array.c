#include <stdlib.h>

// Function that creates an array of chars and initializes it with a specific char.
// Parameters:
// - size: unsigned integer indicating the size of the array to be created.
// - c: char indicating the character with which to initialize each element of the array.
// Returns:
// - NULL if size = 0
// - Pointer to the array, or NULL if it fails.
char *create_array(unsigned int size, char c)
{
        if (size == 0) {
        return NULL;
    }
    char *array = malloc(sizeof(char) * size);

    
    if (array == NULL) {
        return NULL;
    }

    for (unsigned int i = 0; i < size; i++) {
        array[i] = c;
    }
    return array;
}

