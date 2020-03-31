/*
** EPITECH PROJECT, 2019
** my_putstrc.c
** File description:
** my_putstr.c task02 day04
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (0);
}
