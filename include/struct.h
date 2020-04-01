/*
** EPITECH PROJECT, 2020
** struct.h
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct node_s
{
    char *name;
    int x;
    int y;
    struct node_s *start;
    struct node_s *end;
    struct node_s *neighbourg;
    struct node_s *next;
} node_t;

typedef struct lemin_s
{
    char *buffer;
    char **tab;
} lemin_t;

#endif /* !STRUCT_H_ */
