/*
** EPITECH PROJECT, 2020
** struct.h
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct neigh_s
{
    char *name;
    struct neigh_s *next;
} neigh_t;

typedef struct node_s
{
    char *name;
    int x;
    int y;
    struct node_s *start;
    struct node_s *end;
    neigh_t *neighbourg;
    struct node_s *next;
} node_t;

typedef struct lemin_s
{
    char *buffer;
    char **tab;
    int nb_of_ants;
} lemin_t;

#endif /* !STRUCT_H_ */
