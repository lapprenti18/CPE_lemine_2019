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

void add_neighbour(neigh_t **head, char *room)
{
    neigh_t *new = malloc(sizeof(neigh_t));
    neigh_t *tmp = *head;

    new->next = NULL;
    new->name = room;
    if (*head == NULL) {
        *head = new;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
}

int main(void)
{
    lemin_t lemin;
    char *buffer = get_file();
    node_t *head = NULL;

    if (check_error(buffer) == 1) {
        free(buffer);
        return (84);
    }
    lemin.tab = my_str_to_word_array(buffer, '\n');
    for (int a = 0; lemin.tab[a]; a++) {
        if (my_strlen(lemin.tab[a]) > 1 && lemin.tab[a][0] == '#' && lemin.tab[a][1] != '#')
            lemin.tab[a][0] = '\0';
    }
    create_rooms(lemin.tab, head);
    get_nb_of_ants(&lemin, buffer);
    my_printf("#number_of_ants\n%d\n", lemin.nb_of_ants);
    my_free(&lemin, buffer);
    // find_bigger(&lemin);
    // start(&lemin);
    // my_free(&lemin, buffer);
    return (0);
}