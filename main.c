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

    for (int i = 0; str[i] && str[i] != '\n'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (1);
    }
    return (0);
}

int find_bigger(lemin_t *lemin)
{
    int max = my_getnbr(lemin->tab[0]);

    for (int i = 0; lemin->tab[i]; i++) {
        if (my_getnbr(lemin->tab[i]) > max)
            max = my_getnbr(lemin->tab[i]);
    }
    // printf("\n%d\n", max);
    return (max);
}

void print_tunnels(char *tab[])
{
    int i = 0;

    my_printf("#tunnels\n");
    for (; tab[i] != NULL && i < 1; i++);
    for (; tab[i] != NULL && tab[i][0] != 0 && tab[i][1] != 0 && tab[i][1] != '-'; i++);
    for (; tab[i] != NULL; i++) {
        if (!tab[i][0] || tab[i][0] == '#')
            continue;
        my_printf("%s\n", tab[i]);
    }
}

void find_path(node_t *head)
{
    for (neigh_t *neigh = head->neighbourg; neigh; neigh = neigh->next) {
        if (neigh->node->distance == head->distance - 1) {
            printf("%s\n", neigh->node->name);
            return (find_path(neigh->node));
        }
    }
}

int main(void)
{
    lemin_t lemin;
    char *buffer = get_file();
    node_t *head = NULL;
    node_t *start = NULL;

    if (check_error(buffer) == 1) {
        free(buffer);
        return (84);
    }
    get_nb_of_ants(&lemin, buffer);
    my_printf("#number_of_ants\n%d\n", lemin.nb_of_ants);
    lemin.tab = my_str_to_word_array(buffer, '\n');
    for (int a = 0; lemin.tab[a]; a++) {
        if (my_strlen(lemin.tab[a]) > 1 && lemin.tab[a][0] == '#' && lemin.tab[a][1] != '#')
            lemin.tab[a][0] = '\0';
    }
    head = create_rooms(lemin.tab, head);
    print_rooms(head);
    print_tunnels(my_str_to_word_array(buffer, '\n'));
    start = get_room(head, head->start->name);
    fill_neigh(&start, 0);
    start = get_room(head, head->end->name);
    for (node_t *tmp = head; tmp; tmp = tmp->next) {
        for (char *s = NULL; s = my_check(lemin.tab, tmp->name);)
            add_neighbour(&tmp->neighbourg, get_room(head, s));
    }
    find_path(start);
    my_free(&lemin, buffer);
    return (0);
}