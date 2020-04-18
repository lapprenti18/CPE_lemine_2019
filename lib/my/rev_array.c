/*
** EPITECH PROJECT, 2020
** rev_array.c
** File description:
** rev_array.c
*/

#include <stdlib.h>

char **rev_array(char *tab[])
{
    int i = 0;
    int j = 0;
    char *tmp = NULL;

    for (; tab[i]; i++);
    i--;

    while (j < i) {
        tmp = tab[i];
        tab[i] = tab[j];
        tab[j] = tmp;
        i--;
        j++;
    }
    return (tab);
}