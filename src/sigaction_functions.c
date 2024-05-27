/*
** EPITECH PROJECT, 2024
** sigction functions
** File description:
** function that are called when program receive siguser1 or siguser2
*/
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>

extern int GLOBAL;

void catch_siguser1(int, siginfo_t *info, void *)
{
    if (GLOBAL == 0) {
        GLOBAL = info->si_pid;
        return;
    }
    GLOBAL = SIGUSR1;
}

void catch_siguser2(int, siginfo_t *, void *)
{
    GLOBAL = SIGUSR2;
}

bool catch_signal(void)
{
    struct sigaction siguser1 = { 0 };
    struct sigaction siguser2 = { 0 };

    siguser1.sa_flags = SA_SIGINFO;
    siguser2.sa_flags = SA_SIGINFO;
    siguser1.sa_sigaction = &catch_siguser1;
    siguser2.sa_sigaction = &catch_siguser2;
    if (sigaction(SIGUSR1, &siguser1, NULL) == -1)
        return false;
    if (sigaction(SIGUSR2, &siguser2, NULL) == -1)
        return false;
    return true;
}
