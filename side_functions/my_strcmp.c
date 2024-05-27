/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** compare 2 strings
*/

int my_strcmp(const char *str_1, const char *str_2)
{
    int i;

    for (i = 0; str_1[i] != '\0' || str_2[i] != '\0'; i++)
        if (str_1[i] != str_2[i])
            return (str_1[i] > str_2[i]) ? 0 : -1;
    if (str_1[i] == str_2[i])
        return 1;
    return (str_1[i] > str_2[i]) ? 0 : -1;
}
