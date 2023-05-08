#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: Name of the file.
 * @text_content: Text to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 *         If filename is NULL, return -1.
 *         If the file can't be opened or written, return -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, bytes_written, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1);

	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (-1);

	for (length = 0; text_content[length]; length++)
		;

	bytes_written = write(file_descriptor, text_content, length);
	if (bytes_written == -1)
	{
		close(file_descriptor);
		return (-1);
	}

	close(file_descriptor);
	return (1);
}

