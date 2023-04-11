#include "main.h"
#include <stdlib.h>

int word_len(char *str);
int count_words(char *str);
char **strtow(char *str);

/**
 * strtow - splits a string into words
 * @str: the string to split
 *
 * Return: a pointer to an array of strings (words), or NULL if it fails
 */
char **strtow(char *str)
{
    char **words;
    int i, j, k, n, len, count;

    if (str == NULL || *str == '\0')
        return (NULL);

    len = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
            len++;
    }

    words = malloc(sizeof(char *) * (len + 1));
    if (words == NULL)
        return (NULL);

    count = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            n = i;
            while (str[n] != ' ' && str[n] != '\0')
                n++;

            words[count] = malloc(sizeof(char) * (n - i + 1));
            if (words[count] == NULL)
            {
                for (k = 0; k < count; k++)
                    free(words[k]);
                free(words);
                return (NULL);
            }

            for (j = 0; i < n; i++, j++)
                words[count][j] = str[i];
            words[count][j] = '\0';
            count++;
            i--;
        }
    }
    words[count] = NULL;

    return (words);
}

