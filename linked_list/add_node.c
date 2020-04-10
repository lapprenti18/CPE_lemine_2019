/*
** EPITECH PROJECT, 2020
** add_node.c
** File description:
** add_node.c
*/

#include "../include/my.h"

void add_node_at_front(int value, node_t **node)
{
    node_t *new = malloc(sizeof(node_t));


    if (*node == NULL) {
        new->next = NULL;
        *node = new;
        return;
    }
    new->next = *node;
}

void add_node_at_back(char *line, node_t **node)
{
    node_t *new = malloc(sizeof(node_t));
    node_t *tmp = *node;
    char **tab = my_str_to_word_array(line, ' ');

    new->start = NULL;
    new->end = NULL;
    new->next = NULL;
    new->name = tab[0];
    new->neighbourg = NULL;
    new->x = my_getnbr(tab[1]);
    new->y = my_getnbr(tab[2]);
    if (*node == NULL) {
        *node = new;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
}

// void delete_node(node_t **node, node_t *pointer)
// {
//     if (*node == NULL || pointer == NULL)
//         return;
//     if (*node == pointer) {
//         *node = pointer->next;
//     }
//     free(pointer);
// }