/*
** EPITECH PROJECT, 2020
** parser.c
** File description:
** parser.c
*/

#include "include/my.h"
#include "include/struct.h"

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
    my_printf("\n");
}

void start_to_end(int nb_of_ants, char **tab)
{
    for (int temp = 0; temp < nb_of_ants; temp++)
        my_printf("P%d-%s\n", temp + 1, tab[1]);
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
    if (tab_lenght == 1)
        return (start_to_end(nb_of_ants, tab));
    nb_of_ants == 1 ? move_one(tab) : 0;
    for (;check_finish(tab_lenght, cp) != 1 && nb_of_ants != 1;)
        move(cp, tab, temp, tab_lenght);
}