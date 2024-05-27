/*
** EPITECH PROJECT, 2023
** my array len
** File description:
** calculate the length of an array
*/

#include <stdlib.h>

int my_arraylen(const char **array)
{
    int i;

    for (i = 0; array[i] != NULL; i++);
    return i;
}
