/*
** EPITECH PROJECT, 2024
** get buffer
** File description:
** open a file and return the buffer
*/

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

static bool fill_array(char **array, FILE *fd)
{
    size_t a = 0;

    for (int i = 0; i < 5; i++)
        array[i] = NULL;
    for (int i = 0; i < 4; i++)
        if (getline(array + i, &a, fd) == -1)
            return false;
    if (getline(array + 4, &a, fd) != -1) {
        free(array[4]);
        array[4] = NULL;
        free_array(array);
        return false;
    }
    return true;
}

char **get_coordinates(const char *path)
{
    FILE *fd = fopen(path, "r");
    char **array = malloc(sizeof(char *) * 5);

    if (fd == NULL || array == NULL)
        return NULL;
    if (!fill_array(array, fd))
        return NULL;
    fclose(fd);
    free(array[4]);
    array[4] = NULL;
    return array;
}
