/*
** EPITECH PROJECT, 2020
** is_valid.c
** File description:
** is_valid.c
*/

#include "../include/my.h"
#include "../include/struct.h"

int check_error(char *str)
{
    if (str == NULL)
        return (1);
    return (0);
}

int is_valid2(char *tab[])
{
    int i = 0;
    int k = -5;
    int valid = 0;
    int valid2 = 0;

    for (; tab[i]; i++) {
        if (my_strcmp(tab[i], "##start") == 0) {
            if (k == i - 1)
                return (1);
            k = i;
            valid += 1;
        } else if (my_strcmp(tab[i], "##end") == 0) {
            if (k == i -1)
                return (1);
            k = i;
            valid2 += 1;
        }
    }
    if (valid != 1 || valid2 != 1)
        return (1);
    return (0);
}

int is_valid(char *tab[])
{
    if (is_valid2(tab) == 1) {
        return (1);
    }
    return (0);
}