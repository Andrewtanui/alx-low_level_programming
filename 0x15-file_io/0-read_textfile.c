#include <stdio.h>
#include <stdlib.h>
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

    return bytesRead;
}
