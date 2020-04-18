/*
** EPITECH PROJECT, 2020
** parser.c
** File description:
** parser.c
*/

#include "include/my.h"
#include "include/struct.h"

char **clean_tab(char **tab)
{
    int stock = 0;
    int idx = 0;
    int i = 0;
    char **tmp = NULL;

    for (int i = 0; tab[i]; i += 1) {
        stock = 0;
        for (int j = 0; tab[i][j]; j += 1) {
            if (tab[i][j] != ' ' && tab[i][j] != '#')
                stock = j + 1;
            if (j > 1 && tab[i][j] == '#')
                tab[i][(tab[i][j - 1] == ' ') ? stock : j] = 0;
        }
    }
    for (int a = 0; tab[a]; a++) {
        if (my_strlen(tab[a]) > 1 && tab[a][0] == '#' && tab[a][1] != '#')
            tab[a][0] = '\0';
    }
    for (; tab[i]; i += 1) {
        if (tab[i][0] && my_str_isnum(tab[i])) {
            i += 1;
            break;
        }
    }
    for (; tab[i]; i += 1) {
        if (tab_len(tmp = my_str_to_word_array(tab[i], '-')) == 2) {
            if (my_strcmp(tmp[0], tmp[1]) == 0)
                return (NULL);
            idx = i;
        }
        if (idx == 0 && tab[i][0] && tab[i][0] != '#' &&
        tab_len(my_str_to_word_array(tab[i], ' ')) != 3)
            return (NULL);
        if (tab_len(tmp = my_str_to_word_array(tab[i], ' ')) == 3)
            if (idx != 0 || !my_str_isnum(tmp[1]) || !my_str_isnum(tmp[2]))
                return (NULL);
    }
    return (tab);
}

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