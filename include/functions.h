/*
** EPITECH PROJECT, 2024
** functions.h
** File description:
** header for the functions used in my_navy
*/

#ifndef FUNCTIONS_H
    #define FUNCTIONS_H

    #include <stdbool.h>
    #include <sys/types.h>

//side functions
int my_strcmp(const char *, const char *);
bool my_is_numeric(const char *);
char **get_coordinates(const char *path);
char **str_to_array(const char *);
int my_arraylen(char **);
int str_to_int(const char *str);
void my_strcpy(char *dest, char *);
void free_array(char **);

char **get_map(char **);
bool check_coord_line(char *coord_line, int i);
bool check_coordinates(const char *index, int shiplen);
int print_help(void);
void print_map(char **map);
bool args_error_handling(int argc, const char **argv);
int connect_terminal(int argc, const char **argv, int my_pid);
int start_game(int argc, const char **argv, const char *file);
bool catch_signal(void);
bool check_game_status(char **my_map, pid_t enemy_pid);
void display_game(char **my_map, char **enemy_map);
bool display_end_game(char **my_map, char **enemy_map, int argc);
void free_elements(char **, char **, char **);

#endif
