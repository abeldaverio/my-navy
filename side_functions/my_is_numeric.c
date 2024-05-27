/*
** EPITECH PROJECT, 2024
** my is numeric
** File description:
** return true if the string is composed only of 0-9 characters
*/

#include <stdbool.h>

bool my_is_numeric(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            return false;
    return true;
}
