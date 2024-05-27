/*
** EPITECH PROJECT, 2024
** get map
** File description:
** function that takes an array of the coordinates in
** parametter and return an array with the map
*/

#include "functions.h"
#include "macro.h"
#include <stdbool.h>
#include <stdlib.h>

static void fill_empty_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        my_strcpy(map[i], "........");
    }
}

static char **init_map(void)
{
    char **map = malloc(sizeof(char *) * 9);

    if (map == NULL)
        return NULL;
    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 9);
        if (map[i] == NULL)
            return NULL;
    }
    map[8] = NULL;
    fill_empty_map(map);
    return map;
}

static bool fill_vertical(char **map, int len, char *coord)
{
    for (int i = 0; i < len; i++) {
        if (map[i + (MIN(coord[1], coord[4]) - '1')][coord[0] - 'A'] != '.')
            return false;
        map[i + (MIN(coord[1],
            coord[4]) - '1')][coord[0] - 'A'] = '0' + len;
    }
    return true;
}

static bool fill_horizontal(char **map, int len, char *coord)
{
    for (int i = 0; i < len; i++) {
        if (map[coord[1] - '1'][i + (MIN(coord[0], coord[3]) - 'A')] != '.')
            return false;
        map[coord[1] - '1'][i + (MIN(coord[0],
            coord[3]) - 'A')] = '0' + len;
    }
    return true;
}

static bool fill_boat(char **map, int len, bool direction, char *coord)
{
    if (direction == true)
        return fill_vertical(map, len, coord);
    else
        return fill_horizontal(map, len, coord);
}

char **get_map(char **coord)
{
    char **map = init_map();
    bool exit_condition = true;

    if (map == NULL)
        return NULL;
    if (coord != NULL)
        for (int i = 0; exit_condition && coord[i] != NULL; i++)
            exit_condition = fill_boat(map, coord[i][0] - '0',
                (coord[i][2] == coord[i][5]), coord[i] + 2);
    if (exit_condition)
        return map;
    free_array(map);
    return NULL;
}
