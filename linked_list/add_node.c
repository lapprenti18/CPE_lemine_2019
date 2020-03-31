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

    new->data = value;

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

void add_node_at_back(int value, node_t **node)
{
    node_t *new = malloc(sizeof(node_t));
    node_t *tmp = *node;

    new->data = value;
    new->next = NULL;

    if (*node == NULL) {
        *node = new;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
}