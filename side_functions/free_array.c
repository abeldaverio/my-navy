/*
** EPITECH PROJECT, 2024
** free array
** File description:
** free a char array and all of its content
*/

#include <stdlib.h>

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
