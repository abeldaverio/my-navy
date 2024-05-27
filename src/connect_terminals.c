/*
** EPITECH PROJECT, 2024
** connect_terminal
** File description:
** connect_terminal
*/
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <ucontext.h>
#include "mini_printf.h"
#include "functions.h"

extern int GLOBAL;

static void get_user2_pid(int usr1_pid)
{
    mini_printf("my_pid: %d\n\nwaiting for enemy...\n\n", usr1_pid);
    while (GLOBAL == 0) {
        pause();
    }
    mini_printf("enemy connected\n\n");
}

static bool check_user1(int usr2_pid, int usr1_pid)
{
    if (usr1_pid == 0)
        return false;
    if (kill(usr1_pid, SIGUSR1) == -1)
        return false;
    mini_printf("my_pid: %d\n\nsuccessfully connected to enemy\n\n", usr2_pid);
    return true;
}

int connect_terminal(int argc, const char **argv, int my_pid)
{
    if (!catch_signal())
        return -1;
    if (argc == 2) {
        get_user2_pid(my_pid);
        return GLOBAL;
    }
    if (argc == 3 && check_user1(my_pid, str_to_int(argv[1]))) {
        GLOBAL = str_to_int(argv[1]);
        return GLOBAL;
    }
    return -1;
}
