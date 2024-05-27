/*
** EPITECH PROJECT, 2024
** free
** File description:
** function to free all of the memory allocated elements in the program
*/

#include <stdlib.h>
#include "functions.h"

void free_elements(char **coord_array,
    char **my_map, char **enemy_map)
{
    free_array(coord_array);
    free_array(my_map);
    free_array(enemy_map);
}
