/*
** EPITECH PROJECT, 2024
** game loop
** File description:
** functions where the game will be playing
*/

#include "functions.h"
#include "mini_printf.h"
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

extern int GLOBAL;

static void send_attack(char x, char y, pid_t enemy_pid, char **enemy_map)
{
    for (char i = 'A'; i <= x; i++) {
        kill(enemy_pid, SIGUSR1);
        usleep(20000);
    }
    kill(enemy_pid, SIGUSR2);
    usleep(20000);
    for (char i = '1'; i <= y; i++) {
        kill(enemy_pid, SIGUSR1);
        usleep(20000);
    }
    kill(enemy_pid, SIGUSR2);
    pause();
    if (GLOBAL == SIGUSR1) {
        enemy_map[y - '1'][x - 'A'] = 'x';
        mini_printf("\nresult: %c%c:hit\n\n", x, y);
    } else {
        enemy_map[y - '1'][x - 'A'] = (enemy_map[y - '1'][x - 'A'] == 'x') ?
            'x' : 'o';
        mini_printf("\nresult: %c%c:missed\n\n", x, y);
    }
}

static bool my_turn(char **enemy_map, pid_t enemy_pid)
{
    int imput_size = 0;
    size_t i = 0;
    char *imput = NULL;

    usleep(20000);
    mini_printf("attack: ");
    imput_size = getline(&imput, &i, stdin);
    if (imput_size == -1)
        return true;
    if (imput_size != 3 || !(imput[0] <= 'H' && imput[0] >= 'A' &&
        imput[1] <= '8' && imput[1] >= '1')) {
        mini_printf("\nwrong position\n\n");
        free(imput);
        return my_turn(enemy_map, enemy_pid);
    } else {
        send_attack(imput[0], imput[1], enemy_pid, enemy_map);
        free(imput);
        pause();
    }
    return (GLOBAL == SIGUSR2);
}

static void check_attack(char **my_map, pid_t enemy_pid, int x, int y)
{
    if (x < 0 || y < 0)
        return;
    if (my_map[y][x] >= '2' && my_map[y][x] <= '5') {
        kill(enemy_pid, SIGUSR1);
        usleep(20000);
        my_map[y][x] = 'x';
        mini_printf("result: %c%c:hit\n\n", x + 'A', y + '1');
    } else {
        kill(enemy_pid, SIGUSR2);
        usleep(20000);
        my_map[y][x] = (my_map[y][x] == 'x') ? 'x' : 'o';
        mini_printf("result: %c%c:missed\n\n", x + 'A', y + '1');
    }
}

static bool enemy_turn(int x, int y, char **my_map, pid_t enemy_pid)
{
    mini_printf("waiting for enemy's attack...\n\n");
    pause();
    while (GLOBAL == SIGUSR1) {
        x++;
        pause();
    }
    pause();
    while (GLOBAL == SIGUSR1) {
        y++;
        pause();
    }
    check_attack(my_map, enemy_pid, x, y);
    if (check_game_status(my_map, enemy_pid))
        return true;
    return false;
}

static bool play_turn(int *argc, char **my_map,
    char **enemy_map, pid_t enemy_pid)
{
    if (*argc == 2) {
        if (my_turn(enemy_map, enemy_pid)) {
            *argc = 3;
            return true;
        }
        if (enemy_turn(-1, -1, my_map, enemy_pid)) {
            return true;
        }
    } else {
        if (enemy_turn(-1, -1, my_map, enemy_pid)) {
            *argc = 2;
            return true;
        }
        if (my_turn(enemy_map, enemy_pid))
            return true;
    }
    return false;
}

static int start_game_loop(pid_t enemy_pid, const char *file, int argc)
{
    char **coord_array = get_coordinates(file);
    char **my_map = get_map(coord_array);
    char **enemy_map = get_map(NULL);
    bool exit_condition = false;

    if (coord_array == NULL || my_map == NULL || enemy_map == NULL)
        return 84;
    while (!exit_condition) {
        display_game(my_map, enemy_map);
        exit_condition = play_turn(&argc, my_map, enemy_map, enemy_pid);
    }
    exit_condition = display_end_game(my_map, enemy_map, argc);
    free_elements(coord_array, my_map, enemy_map);
    return (exit_condition) ? 0 : 1;
}

int start_game(int argc, const char **argv, const char *file)
{
    pid_t my_pid = getpid();
    pid_t enemy_pid = connect_terminal(argc, argv, my_pid);

    if (enemy_pid == -1)
        return 84;
    return start_game_loop(enemy_pid, file, argc);
}
