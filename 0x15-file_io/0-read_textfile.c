#include "main.h"
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters)
{
    if (filename == NULL)
        return 0;

    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        return 0;

    char buffer[1024];
    ssize_t bytes_read, bytes_written, total_bytes_written = 0;

    while (letters > 0)
    {
        bytes_read = read(fd, buffer, sizeof(buffer));
        if (bytes_read == -1)
        {
            close_file(fd);
            return 0;
        }

        if (bytes_read == 0)
            break;

        bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
        if (bytes_written == -1 || bytes_written != bytes_read)
        {
            close_file(fd);
            return 0;
        }

        total_bytes_written += bytes_written;
        letters -= bytes_written;
    }

    close_file(fd);
    return total_bytes_written;
}
