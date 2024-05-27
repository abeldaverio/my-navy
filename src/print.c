/*
** EPITECH PROJECT, 2024
** print
** File description:
** functions to print specific type of content
*/

#include "mini_printf.h"
#include <stdbool.h>

int print_help(void)
{
    mini_printf("%s%s%s%s%s%s%s",
                "USAGE\n",
                "\t./navy [first_player_pid] navy_positions\n",
                "DESCRIPTION\n",
                "\tfirst_player_pid: only for the 2nd player. ",
                "pid of the first player.\n",
                "\tnavy_positions: file representing ",
                "the positions of the ships.\n");
    return 0;
}

static void print_map_line(char *line)
{
    bool space = false;

    for (int i = 0; line[i] != '\0'; i++) {
        if (space) {
            mini_printf(" ");
            i--;
        } else {
            mini_printf("%c", line[i]);
        }
        space = !space;
    }
    mini_printf("\n");
}

void print_map(char **map)
{
    mini_printf("%s\n%s\n", " |A B C D E F G H",
                "-+---------------");
    for (int i = 0; map[i] != NULL; i++) {
        mini_printf("%d|", i + 1);
        print_map_line(map[i]);
    }
}
