/*
** EPITECH PROJECT, 2023
** str to array
** File description:
** put a str into an array of str unsing \n as delimiter
*/

#include <stdlib.h>

static int count_lines(const char *str)
{
    int nb_of_lines = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            nb_of_lines++;
    return nb_of_lines;
}

static int count_col(const char *str, int i)
{
    int nb_of_col = 0;

    while (str[i] != '\n' && str[i] != '\0') {
        i++;
        nb_of_col++;
    }
    return nb_of_col;
}

static char *put_in_str(const char *str, int *i)
{
    int nb_of_col = count_col(str, *i);
    char *tmp = malloc(sizeof(char) * (nb_of_col + 1));

    if (tmp == NULL)
        return NULL;
    for (int z = 0; z < nb_of_col; z++) {
        tmp[z] = str[*i];
        *i += 1;
    }
    tmp[nb_of_col] = '\0';
    *i += 1;
    return tmp;
}

char **str_to_array(const char *str)
{
    char **array;
    int nb_of_lines;
    int i = 0;

    if (str == NULL) {
        return NULL;
    }
    nb_of_lines = count_lines(str);
    array = malloc(sizeof(char *) * (nb_of_lines + 1));
    if (array == NULL) {
        return NULL;
    }
    for (int j = 0; j < nb_of_lines; j++) {
        array[j] = put_in_str(str, &i);
        if (array[j] == NULL) {
            return NULL;
        }
    }
    array[nb_of_lines] = NULL;
    return array;
}
