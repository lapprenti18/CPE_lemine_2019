/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** my_strlen.c task03 day04
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    size_t i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
