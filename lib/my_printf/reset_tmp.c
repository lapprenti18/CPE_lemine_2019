/*
** EPITECH PROJECT, 2019
** reset_tmp.c
** File description:
** reset_tmp.c
*/

int my_putstr(char const *str);

char *reset_tmp(char *str)
{
    int i = 0;

    my_putstr(str);
    while (str[i] != '\0') {
        str[i] = '\0';
        i += 1;
    }
    str = '\0';
    return (str);
}