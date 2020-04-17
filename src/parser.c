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
    int i = 1;

    if ((string[0] >= '0' && string[0] <= '9') || string[0] == '-') {
        tmp[j++] = string[0];
    } else if (string[0] == '#') {
        for (; string[i] != '\n'; i++);
    }
    i += 1;
    for (; string[i] && string[i] != '\n'; i++) {
        if (string[i] == '#' && string[i - 1] == '\n') {
            for (; string[i] != '\n'; i++);
        } else if ((string[i] >= '0' && string[i] <= '9') || string[i] == '-') {
            tmp[j++] = string[i];
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

int parser(lemin_t *lemin, char *str)
{
    lemin->tab = my_str_to_word_array(str, '\n');
    return (0);
}
