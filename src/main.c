/*
** EPITECH PROJECT, 2024
** main
** File description:
** main functions for my navy
*/

#include "functions.h"

int GLOBAL = 0;

int main(int argc, const char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 1)
        return print_help();
    if (!args_error_handling(argc, argv))
        return 84;
    return start_game(argc, argv, argv[argc - 1]);
}
