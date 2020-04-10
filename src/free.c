/*
** EPITECH PROJECT, 2020
** parser.c
** File description:
** parser.c
*/

#include "../include/my.h"

void my_free(lemin_t *lemin, char *str)
{
    for (int i = 0; lemin->tab[i] != NULL; i++) {
        free(lemin->tab[i]);
    }
    free(str);
}