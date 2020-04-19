/*
** EPITECH PROJECT, 2020
** parser.c
** File description:
** parser.c
*/

#include "include/my.h"
#include "include/struct.h"

void play_moves(lemin_t *lemin, char *way)
{
    char **moves = NULL;

    moves = my_str_to_word_array(way, '\n');
    moves = rev_array(moves);
    mouve_ant(lemin->nb_of_ants, moves, 0);
}

int following(lemin_t *lemin, node_t *head)
{
    char *way = NULL;
    node_t *start = NULL;

    if (print_tunnels(lemin->tab, head) == 0)
        return (84);
    start = get_room(head, head->start->name);
    fill_neigh(&start, 0);
    start = get_room(head, head->end->name);
    for (node_t *tmp = head; tmp; tmp = tmp->next)
        for (char *s = NULL; (s = my_check(lemin->tab, tmp->name));)
            add_neighbour(&tmp->neighbourg, get_room(head, s));
    way = find_path(start, way);
    if (get_room(head, head->end->name)->distance == __INT_MAX__)
        return (84);
    for (neigh_t *tmp = start->neighbourg; tmp; tmp = tmp->next)
        if (tmp->node->distance == head->distance - 1)
            way = my_strcat(my_strcat(tmp->node->name, "\n"), way);
    way = my_strcat(my_strcat(start->name, "\n"), way);
    play_moves(lemin, way);
    return (0);
}

int main(void)
{
    lemin_t lemin;
    char *buffer = get_file();
    node_t *head = NULL;

    if (check_error(buffer) == 1)
        return (84);
    get_nb_of_ants(&lemin, buffer);
    if (lemin.nb_of_ants <= 0)
        return (84);
    my_printf("#number_of_ants\n%d\n", lemin.nb_of_ants);
    if (!(lemin.tab = clean_tab(my_str_to_word_array(buffer, '\n')))
    || is_valid(lemin.tab) == 1)
        return (84);
    head = create_rooms(lemin.tab, head);
    print_rooms(head);
    if (following(&lemin, head) == 84)
        return (84);
    my_free(&lemin, buffer);
    return (0);
}