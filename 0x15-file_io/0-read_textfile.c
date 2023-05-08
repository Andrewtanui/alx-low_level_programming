#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 *         O/w - the actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor;
	ssize_t bytes_read, bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * (letters + 1));
	if (buffer == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
	{
		free(buffer);
		return (0);
	}

	bytes_read = read(file_descriptor, buffer, letters);
	if (bytes_read == -1)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}

	buffer[bytes_read] = '\0'; /* Null-terminate the buffer for text printing */

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}

	free(buffer);
	close(file_descriptor);

	return (bytes_written);
}
=======
#include "main.h"

ssize_t read_textfile(const char *filename, size_t letters)
{
    if (filename == NULL)
        return 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL)
        return 0;

    char *buffer = (char *)malloc(sizeof(char) * (letters + 1));
    if (buffer == NULL)
    {
        fclose(file);
        return 0;
    }

    ssize_t bytesRead = fread(buffer, sizeof(char), letters, file);
    if (bytesRead < 0)
    {
        free(buffer);
        fclose(file);
        return 0;
    }

    ssize_t bytesWritten = fwrite(buffer, sizeof(char), bytesRead, stdout);
    if (bytesWritten != bytesRead)
    {
        free(buffer);
        fclose(file);
        return 0;
    }

    free(buffer);
    fclose(file);
>>>>>>> 3e663cdcd45a424928c0694002a2703c04aa71c7

    return bytesRead;
}
