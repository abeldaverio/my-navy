/*
** EPITECH PROJECT, 2023
** str_to_int
** File description:
** str_to_int
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i ++;
    return (i);
}

int my_compute_power_rec(int nb, int p)
{
    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }
    return (nb * my_compute_power_rec(nb, p - 1));
}

int str_to_int(const char *str)
{
    int nb = 0;
    int n = my_strlen(str) - 1;

    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i ++) {
        if (str[i] == '-') {
            i ++;
            n --;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb + (str[i] - 48) * my_compute_power_rec(10, n);
            n --;
        } else {
            return 84;
        }
    }
    if (str[0] == '-') {
        nb = nb * -1;
    }
    return nb;
}
