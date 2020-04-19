/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** clean_tab
*/

#include "../include/my.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i += 1)
        free(tab[i]);
    free(tab);
}

char **check_rooms(char **tab, int i, int idx)
{
    char **tmp = NULL;

    for (; tab[i]; i += 1) {
        tmp = my_str_to_word_array(tab[i], '-');
        if (tab_len(tmp) == 2) {
            if (my_strcmp(tmp[0], tmp[1]) == 0)
                return (NULL);
            idx = i;
        }
        free_tab(tmp);
        if (idx == 0 && tab[i][0] && tab[i][0] != '#' &&
        tab_len(my_str_to_word_array(tab[i], ' ')) != 3)
            return (NULL);
        tmp = my_str_to_word_array(tab[i], ' ');
        if (tab_len(tmp) == 3)
            if (idx != 0 || !my_str_isnum(tmp[1]) || !my_str_isnum(tmp[2]))
                return (NULL);
        free_tab(tmp);
    }
    return (tab);
}

char **clean_comment(char **tab)
{
    int stock = 0;

    for (int i = 0; tab[i]; i += 1) {
        stock = 0;
        for (int j = 0; tab[i][j]; j += 1) {
            if (tab[i][j] != ' ' && tab[i][j] != '#')
                stock = j + 1;
            if (j > 1 && tab[i][j] == '#')
                tab[i][(tab[i][j - 1] == ' ') ? stock : j] = 0;
        }
    }
    return (tab);
}

char **clean_tab(char **tab)
{
    int i = 0;

    tab = clean_comment(tab);
    for (int a = 0; tab[a]; a++) {
        if (my_strlen(tab[a]) > 1 && tab[a][0] == '#' && tab[a][1] != '#')
            tab[a][0] = '\0';
    }
    for (; tab[i]; i += 1) {
        if (tab[i][0] && my_str_isnum(tab[i])) {
            i += 1;
            break;
        }
    }
    return (check_rooms(tab, i, 0));
}
