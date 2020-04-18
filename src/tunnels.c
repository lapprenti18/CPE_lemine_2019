/*
** EPITECH PROJECT, 2020
** tunnels.c
** File description:
** tunnels.c
*/

#include "../include/my.h"
#include "../include/struct.h"

int print_tunnels(char *tab[], node_t *head)
{
    int i = 0;
    char **tmp = NULL;
    int minus = 0;

    my_printf("#tunnels\n");
    for (; tab[i] && tab_len(my_str_to_word_array(tab[i], '-')) != 2; i += 1);
    for (; tab[i] != NULL; i++) {
        minus = 0;
        if (!tab[i][0] || tab[i][0] == '#')
            continue;
        for (int j = 0; tab[i][j]; j += 1)
            if (tab[i][j] == '-')
                minus += 1;
        tmp = my_str_to_word_array(tab[i], '-');
        if (minus != 1 || !get_room(head, tmp[0]) || !get_room(head, tmp[1]))
            return (0);
        my_printf("%s\n", tab[i]);
    }
    return (1);
}

char *find_path(node_t *head, char *way)
{
    for (neigh_t *neigh = head->neighbourg; neigh; neigh = neigh->next) {
        if (neigh->node->distance == head->distance - 1) {
            way = my_strcat(way, neigh->node->name);
            way = my_strcat(way, "\n");
            return (find_path(neigh->node, way));
        }
    }
    return (way);
}