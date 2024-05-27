/*
** EPITECH PROJECT, 2024
** game_status
** File description:
** check game status
*/
#include <stdbool.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

static bool are_all_boat_dead(char **map)
{
    bool return_value = true;

    for (int y = 0; map[y] != NULL && return_value; y++)
        for (int x = 0; map[y][x] != '\0' && return_value; x++) {
            return_value = (map[y][x] < '6' && map[y][x] > '1') ? false : true;
        }
    return return_value;
}

bool check_game_status(char **my_map, pid_t enemy_pid)
{
    usleep(500000);
    if (are_all_boat_dead(my_map)) {
        kill(enemy_pid, SIGUSR2);
        return true;
    }
    kill(enemy_pid, SIGUSR1);
    return false;
}
