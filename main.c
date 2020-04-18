/*
** EPITECH PROJECT, 2020
** parser.c
** File description:
** parser.c
*/

#include "include/my.h"
#include "include/struct.h"

char *get_file(void)
{
    size_t len;
    char *buffer = NULL;
    char *final = NULL;

    while (getline(&buffer, &len, stdin) != -1) {
        final = my_strcat(final, buffer);
    }
    if (final == NULL)
        return (NULL);
    return (final);
}

int check_error(char *str)
{
    if (str == NULL)
        return (1);
    return (0);
}

char **rev_array(char *tab[])
{
    int i = 0;
    int j = 0;
    char *tmp = NULL;

    for (; tab[i]; i++);
    i--;

    while (j < i) {
        tmp = tab[i];
        tab[i] = tab[j];
        tab[j] = tmp;
        i--;
        j++;
    }
    return (tab);
}

int find_bigger(lemin_t *lemin)
{
    int max = my_getnbr(lemin->tab[0]);

    for (int i = 0; lemin->tab[i]; i++) {
        if (my_getnbr(lemin->tab[i]) > max)
            max = my_getnbr(lemin->tab[i]);
    }
    return (max);
}

int print_tunnels(char *tab[], node_t *head)
{
    int i = 0;
    char **tmp = NULL;
    int minus = 0;

    my_printf("#tunnels\n");
    for (; tab[i] && tab_len(my_str_to_word_array(tab[i], '-')) != 2; i += 1);
    for (; tab[i] != NULL; i++) {
        minus = 0;
        if (!tab[i][0] || tab[i][0] == '#')
            continue;
        for (int j = 0; tab[i][j]; j += 1)
            if (tab[i][j] == '-')
                minus += 1;
        tmp = my_str_to_word_array(tab[i], '-');
        if (minus != 1 || !get_room(head, tmp[0]) || !get_room(head, tmp[1]))
            return (0);
        my_printf("%s\n", tab[i]);
    }
    return (1);
}

char *find_path(node_t *head, char *way)
{
    for (neigh_t *neigh = head->neighbourg; neigh; neigh = neigh->next) {
        if (neigh->node->distance == head->distance - 1) {
            way = my_strcat(way, neigh->node->name);
            way = my_strcat(way, "\n");
            return (find_path(neigh->node, way));
        }
    }
    return (way);
}

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
    for (; tab[i]; i += 1)
        if (tab[i][0] && my_str_isnum(tab[i])) {
            i += 1;
            break;
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

int is_valid2(char *tab[])
{
    int i = 0;
    int k = -5;
    int valid = 0;
    int valid2 = 0;

    for (; tab[i]; i++) {
        if (my_strcmp(tab[i], "##start") == 0) {
            if (k == i - 1)
                return (1);
            k = i;
            valid += 1;
        } else if (my_strcmp(tab[i], "##end") == 0) {
            if (k == i -1)
                return (1);
            k = i;
            valid2 += 1;
        }
    }
    if (valid != 1 || valid2 != 1)
        return (1);
    return (0);
}

int check_line(char *str)
{
    int nb_hashtag = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '#')
            nb_hashtag++;
    }
    return (0);
}

int is_valid3(char *tab[])
{
    for (int i = 0; tab[i]; i++) {
        if (check_line(tab[i]) == 1)
            return (1);
    }
    return (0);
}

int is_valid(char *tab[])
{
    if (is_valid2(tab) == 1) {
        return (1);
    }
    if (is_valid3(tab) == 1) {
        return (1);
    }
    return (0);
}

int main(void)
{
    lemin_t lemin;
    char *buffer = get_file();
    node_t *head = NULL;
    node_t *start = NULL;
    char *way = NULL;
    char **moves = NULL;

    if (check_error(buffer) == 1) {
        free(buffer);
        return (84);
    }
    get_nb_of_ants(&lemin, buffer);
    if (lemin.nb_of_ants <= 0)
        return (84);

    my_printf("#number_of_ants\n%d\n", lemin.nb_of_ants);
    if (!(lemin.tab = clean_tab(my_str_to_word_array(buffer, '\n'))) || is_valid(lemin.tab) == 1) {
        return (84);
    }
    head = create_rooms(lemin.tab, head);
    print_rooms(head);
    if (print_tunnels(lemin.tab, head) == 0)
        return (84);
    start = get_room(head, head->start->name);
    fill_neigh(&start, 0);
    start = get_room(head, head->end->name);
    for (node_t *tmp = head; tmp; tmp = tmp->next) {
        for (char *s = NULL; (s = my_check(lemin.tab, tmp->name));)
            add_neighbour(&tmp->neighbourg, get_room(head, s));
    }
    way = find_path(start, way);
    if (get_room(head, head->end->name)->distance == __INT_MAX__)
        return (84);
    for (neigh_t *tmp = start->neighbourg; tmp; tmp = tmp->next)
        if (tmp->node->distance == head->distance - 1)
            way = my_strcat(my_strcat(tmp->node->name, "\n"), way);
    way = my_strcat(my_strcat(start->name, "\n"), way);
    moves = my_str_to_word_array(way, '\n');
    moves = rev_array(moves);
    mouve_ant(lemin.nb_of_ants, moves, 0);
    my_free(&lemin, buffer);
    return (0);
}