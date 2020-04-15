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

void mouve_ant(int nb_of_ants, char **tab) {
    int tab_lenght = my_tab_lenght(tab);
    int temp = 0;
    int test = 0;

    ant_t *ant = NULL;
    for (int temp = 0; temp < nb_of_ants; temp ++) {
        add_ant_at_front((temp - nb_of_ants + 1) * -1, 0, &ant);
    }
    ant_t *cp = ant;

    my_printf("#moves\n");
    for (;check_finish(tab_lenght, cp) != 1;) {
        for (; cp->next; cp = cp->next) {
            if (cp->previous == NULL && cp->current_pos != tab_lenght) {
                cp->current_pos += 1;
                if (test == 1)
                        my_printf(" ");
                test = 1;
                my_printf("P%d-%s", cp->name + 1, tab[cp->current_pos]);
                continue;
            }
            if (cp->previous) {
            cp = cp->previous;
            temp = cp->current_pos;
            cp = cp->next;
                if ((cp->current_pos == temp - 2) || (temp == tab_lenght && cp->current_pos == temp - 1)) {
                    cp->current_pos += 1;
                    if (test == 1)
                        my_printf(" ");
                    test = 1;
                    my_printf("P%d-%s", cp->name + 1, tab[cp->current_pos]);
                }
            }
        }
        cp = cp->previous;
        temp = cp->current_pos;
        cp = cp->next;
        if ((cp->current_pos == temp - 2) || (temp == tab_lenght && cp->current_pos == temp - 1)) {
            cp->current_pos += 1;
            if (test == 1)
                my_printf(" ");
            test = 1;
            my_printf("P%d-%s", cp->name + 1, tab[cp->current_pos]);
        }
        for (; cp->previous; cp = cp->previous);
        test = 0;
        my_printf("\n");
    }
}