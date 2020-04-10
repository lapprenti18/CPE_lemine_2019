/*
** EPITECH PROJECT, 2020
** parser.c
** File description:
** parser.c
*/

#include "../include/my.h"

int tab_len(char **tab)
{
    int i = 0;

    for (; tab[i]; i += 1);
    return (i);
}