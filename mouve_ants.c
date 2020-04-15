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
    my_printf("P1-%s\n", tab[0]);
}

int print_move(int test, ant_t *cp, char **tab)
{
    cp->current_pos += 1;
    if (test == 1)
        my_printf(" ");
    my_printf("P%d-%s", cp->name + 1, tab[cp->current_pos]);
    return (1);
}

int last_moves(ant_t *cp)
{
    int temp;

    cp = cp->previous;
    temp = cp->current_pos;
    cp = cp->next;
    return (temp);
}

void move(ant_t *cp, char **tab, int temp, int tab_lenght)
{
    int test = 0;

    for (; cp->next; cp = cp->next) {
        if (cp->previous == NULL && cp->current_pos != tab_lenght) {
            test = print_move(test, cp, tab);
            continue;
        }
        if (cp->previous) {
            temp = last_moves(cp);
            if ((cp->current_pos == temp - 2) || (temp == tab_lenght && \
            cp->current_pos == temp - 1))
                test = print_move(test, cp, tab);
        }
    }
    temp = last_moves(cp);
    if ((cp->current_pos == temp - 2) || (temp == tab_lenght && \
    cp->current_pos == temp - 1))
        test = print_move(test, cp, tab);
    for (; cp->previous; cp = cp->previous);
}

void mouve_ant(int nb_of_ants, char **tab, int temp)
{
    int tab_lenght = my_tab_lenght(tab) - 1;
    ant_t *ant = NULL;
    ant_t *cp;

    for (int temp = 0; temp < nb_of_ants; temp++)
        add_ant_at_front((temp - nb_of_ants + 1) * -1, 0, &ant);
    cp = ant;
    my_printf("#moves\n");
    nb_of_ants == 1 ? move_one(tab) : 0;
    for (;check_finish(tab_lenght, cp) != 1 && nb_of_ants != 1;) {
        move(cp, tab, temp, tab_lenght);
        my_printf("\n");
    }
}