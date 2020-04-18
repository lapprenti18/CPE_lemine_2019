/*
** EPITECH PROJECT, 2020
** parser.c
** File description:
** parser.c
*/

#include "include/my.h"
#include "include/struct.h"

void add_ant_at_front(int nb, int start, ant_t **node)
{
    ant_t *new = malloc(sizeof(ant_t));

    new->previous = NULL;
    new->next = NULL;
    new->name = nb;
    new->current_pos = start;
    if (*node == NULL) {
        *node = new;
        return;
    }
    (*node)->previous = new;
    new->next = *node;
    *node = new;
}

int my_tab_lenght(char **tab)
{
    int a = 0;

    for (; tab[a]; a++);
    return (a);
}

int check_finish(int tab_lenght, ant_t *cp)
{
    for (; cp->next; cp = cp->next) {
        if (cp->current_pos != tab_lenght) {
            return (0);
        }
    }
    if (cp->current_pos != tab_lenght) {
        return (0);
    }
    return (1);
}

void move_one(char **tab)
{
    for (int temp = 0; tab[temp]; temp++)
        my_printf("P1-%s\n", tab[temp]);
}

int print_move(int test, ant_t *cp, char **tab)
{
    cp->current_pos += 1;
    if (test == 1)
        my_printf(" ");
    my_printf("P%d-%s", cp->name + 1, tab[cp->current_pos]);
    return (1);
}