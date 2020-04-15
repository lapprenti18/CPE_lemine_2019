/*
** EPITECH PROJECT, 2020
** parser.c
** File description:
** parser.c
*/

#include "../include/my.h"

char *my_check(char **tunnels, char *string)
{
    char **tmp = NULL;
    char *nb1 = NULL;
    char *nb2 = NULL;
    static int i = 0;

    for (; tunnels[i];) {
        if (!*(tunnels[i++]))
            continue;
        tmp = my_str_to_word_array(tunnels[i - 1], '-');
        if (!tmp || tab_len(tmp) != 2)
            continue;
        nb1 = tmp[0];
        nb2 = tmp[1];
        if (my_strcmp(string, nb1) == 0) {
            return (nb2);
        } else if (my_strcmp(string, nb2) == 0) {
            return (nb1);
        }
    }
    i = 0;
    return (NULL);
}

void get_nb_of_ants(lemin_t *lemin, char *string)
{
    char *tmp = malloc(sizeof(char) * 15);
    int j = 0;
    int i = 0;

    for (; string[i] && string[i] != '\n'; i++) {
        if (string[i] == '#') {
            for (; string[i] != '\n'; i++);
        } else if (string[i] >= '0' && string[i] <= '9') {
            tmp[j] = string[i];
            j++;
        }
    }
    tmp[j] = 0;
    lemin->nb_of_ants = my_getnbr(tmp);
    free(tmp);
}

int array_length(char *tab[])
{
    int len = 0;

    for (; tab[len]; len++);

    return (len);
}

void get_nb_ants(lemin_t *lemin, char *tab[])
{
    char *tmp = malloc(sizeof(char) * 15);
    int i = 0;

    for (; tab[i]; i++) {
        if (tab[i][0] != 0 && tab[i][0] == '#')
            continue;
    }
    if (i == array_length(tab)) {
        get_nb_of_ants(lemin, tab[0]);
    } else {
        get_nb_of_ants(lemin, tab[i - 1]);
    }
}

int parser(lemin_t *lemin, char *str)
{
    lemin->tab = my_str_to_word_array(str, '\n');
    return (0);
}
