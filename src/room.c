/*
** EPITECH PROJECT, 2020
** parser.c
** File description:
** parser.c
*/

#include "../include/my.h"

void add_neighbour(neigh_t **head, node_t *node)
{
    neigh_t *new = malloc(sizeof(neigh_t));
    neigh_t *tmp = *head;

    new->next = NULL;
    new->node = node;
    if (*head == NULL) {
        *head = new;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
}

node_t *get_room(node_t *head, char *to_find)
{
    for (node_t *tmp = head; tmp; tmp = tmp->next)
        if (my_strcmp(tmp->name, to_find) == 0)
            return (tmp);
    return (NULL);
}

node_t *create_rooms(char **tab, node_t *head)
{
    char *s = NULL;

    for (int i = 0; tab[i]; i += 1) {
        if (tab_len(my_str_to_word_array(tab[i], ' ')) == 3) {
            if (i > 0 && my_strcmp(tab[i - 1], "##start") == 0) {
                add_node_at_back(tab[i], &head);
                add_node_at_back(tab[i], &head->start);
            }
            else if (i > 0 && my_strcmp(tab[i - 1], "##end") == 0) {
                add_node_at_back(tab[i], &head);
                add_node_at_back(tab[i], &head->end);
            }
            else
                add_node_at_back(tab[i], &head);
        }
    }
    for (node_t *tmp = head; tmp; tmp = tmp->next) {
        while ((s = my_check(tab, tmp->name)))
            add_neighbour(&tmp->neighbourg, get_room(head, s));
    }
    return (head);
}

void print_rooms(node_t *head)
{
    my_printf("#rooms\n");
    for (node_t *cp = head; cp; cp = cp->next) {
        if (my_strcmp(cp->name, head->start->name) == 0)
            my_printf("##start\n");
        if (my_strcmp(cp->name, head->end->name) == 0)
            my_printf("##end\n");
        my_printf("%s %d %d\n", cp->name, cp->x, cp->y);
    }
}

void fill_neigh(node_t **head, int distance)
{
    // static int i = 0;
    node_t *node = *head;

    node->distance = distance;
    for (; node->neighbourg; node->neighbourg = node->neighbourg->next) {
        if (distance + 1 < node->neighbourg->node->distance) {
            fill_neigh(&(node->neighbourg->node), distance + 1);
        }
    }
}