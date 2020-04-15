/*
** EPITECH PROJECT, 2020
** struct.h
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct neigh_s neigh_t;

typedef struct node_s
{
    char *name;
    int x;
    int y;
    int distance;
    struct node_s *start;
    struct node_s *end;
    neigh_t *neighbourg;
    struct node_s *next;
} node_t;

struct neigh_s
{
    node_t *node;
    struct neigh_s *next;
};

typedef struct lemin_s
{
    char *buffer;
    char **tab;
    int nb_of_ants;
} lemin_t;

typedef struct ant_s
{
    int name;
    int current_pos;
    struct ant_s *next;
    struct ant_s *previous;
} ant_t;

#endif /* !STRUCT_H_ */
