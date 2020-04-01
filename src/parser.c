/*
** EPITECH PROJECT, 2020
** parser.c
** File description:
** parser.c
*/

#include "../include/my.h"

char *my_check(char *tunnel, char *string)
{
    char **tmp = NULL;
    char *nb1 = NULL;
    char *nb2 = NULL;
    int i = 0;

    tmp = my_str_to_word_array(tunnel, '-');
    nb1 = tmp[0];
    nb2 = tmp[1];

    if (my_strcmp(string, nb1) == 0)
        return (nb2);
    else if (my_strcmp(string, nb2) == 0)
        return (nb1);
    else
        return (NULL);
}