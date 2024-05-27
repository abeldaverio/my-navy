/*
** EPITECH PROJECT, 2024
** error handling
** File description:
** functions specificly made for checking error in the imputs
*/

#include "functions.h"
#include "macro.h"
#include <stdlib.h>
#include <stdbool.h>

bool check_coordinates(const char *index, int shiplen)
{
    if (index[2] != index[5] && index[3] != index[6])
        return false;
    if (index[2] == index[5]) {
        if ((ABS(index[3] - index[6]) + 1) != shiplen) {
            return false;
        }
    } else
        if (ABS(index[2] - index[5]) + 1 != shiplen)
            return false;
    return true;
}

bool check_coord_line(char *coord_line, int i)
{
    if (coord_line[0] != '2' + i || coord_line[1] != ':' ||
        !(coord_line[2] >= 'A' && coord_line[2] <= 'H') ||
        !(coord_line[3] >= '1' && coord_line[3] <= '8') ||
        coord_line[4] != ':' ||
        !(coord_line[5] >= 'A' && coord_line[5] <= 'H') ||
        !(coord_line[6] >= '1' && coord_line[6] <= '8') ||
        coord_line[7] != '\n') {
        return false;
    }
    return true;
}

static bool check_file_content(char **array)
{
    for (int i = 0; i < 4; i++) {
        if (!check_coord_line(array[i], i))
            return false;
        if (!check_coordinates(array[i], 2 + i)) {
            return false;
        }
    }
    return true;
}

static bool check_file(const char *path)
{
    char **array = get_coordinates(path);
    char **map_test = NULL;

    if (array == NULL)
        return false;
    if (!check_file_content(array)) {
        free_array(array);
        return false;
    }
    map_test = get_map(array);
    if (map_test == NULL)
        return false;
    free_array(map_test);
    free_array(array);
    return true;
}

bool args_error_handling(int argc, const char **argv)
{
    if (argc != 2 && argc != 3)
        return false;
    if (argc == 3 && !(my_is_numeric(argv[1]) && check_file(argv[2])))
        return false;
    if (argc == 2 && !check_file(argv[1]))
        return false;
    return true;
}
