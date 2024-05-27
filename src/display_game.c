/*
** EPITECH PROJECT, 2024
** display_game
** File description:
** display game
*/
#include "mini_printf.h"
#include "functions.h"

void display_game(char **my_map, char **enemy_map)
{
    mini_printf("my navy:\n");
    print_map(my_map);
    mini_printf("\n");
    mini_printf("enemy navy:\n");
    print_map(enemy_map);
    mini_printf("\n");
}

bool display_end_game(char **my_map, char **enemy_map, int argc)
{
    display_game(my_map, enemy_map);
    if (argc == 3) {
        mini_printf("I won\n");
        return true;
    } else {
        mini_printf("Enemy won\n");
        return false;
    }
}
