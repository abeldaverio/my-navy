/*
** EPITECH PROJECT, 2023
** my str copy
** File description:
** copy a sting into another
*/

#include <stdlib.h>

void my_strcpy(char *dest, const char *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}
