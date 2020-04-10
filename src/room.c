/*
** EPITECH PROJECT, 2020
** parser.c
** File description:
** parser.c
*/

#include "../include/my.h"

void create_rooms(char **tab, node_t *head)
{
    node_t *tmp = head;
    char *s = NULL;

    for (int i = 0; tab[i]; i += 1) {
        if (tab_len(my_str_to_word_array(tab[i], ' ')) == 3) {
            if (i > 0 && my_strcmp(tab[i - 1], "##start") == 0)
                add_node_at_back(tab[i], &head->start);
            else if (i > 0 && my_strcmp(tab[i - 1], "##end") == 0)
                add_node_at_back(tab[i], &head->end);
            else
                add_node_at_back(tab[i], &head);
        }
    }
    for (node_t *tmp = head; tmp; tmp = tmp->next) {
        while ((s = my_check(tab, tmp->name)))
            add_neighbour(&tmp->neighbourg, s);
    }
    while ((s = my_check(tab, head->start->name)))
        add_neighbour(&head->start->neighbourg, s);
    while ((s = my_check(tab, head->end->name)))
        add_neighbour(&head->end->neighbourg, s);
}

node_t *get_room(node_t *head, char *to_find)
{
    for (node_t *tmp = head; tmp; tmp = tmp->next)
        if (my_strcmp(tmp->name, to_find) == 0)
            return (tmp);
    return (NULL);
}
