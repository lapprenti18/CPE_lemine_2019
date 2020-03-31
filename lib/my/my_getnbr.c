/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** my_getnbr.c
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = 0;
    int res = 0;

    while (str[i] != '\0') {
        if (str[i] == '-') {
            sign += 1;
        } else if (str[i] >= '0' && str[i] <= '9') {
            res = (res * 10) + (str[i] - '0');
        }
        i++;
    }
    if (sign % 2 == 0) {
        return (res);
    }
    if (sign % 2 == 1) {
        res *= -1;
        return (res);
    }
    return (0);
}