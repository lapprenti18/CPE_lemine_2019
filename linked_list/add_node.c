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

// void delete_node(node_t **node, node_t *pointer)
// {
//     if (*node == NULL || pointer == NULL)
//         return;
//     if (*node == pointer) {
//         *node = pointer->next;
//     }
//     free(pointer);
// }