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
    return (final);
}

int check_error(char *str)
{
    (void)str;
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

int parser(lemin_t *lemin, char *str)
{

    lemin->tab = my_str_to_word_array(str, '\n');
    return (0);
}

int start(lemin_t *lemin)
{
    node_t *list = NULL;

    for (int i = 0; i <= find_bigger(lemin); i++) {
        add_node_at_back(i, &list);
    }

    node_t *cp = list;

    for (; cp; cp = cp->next) {
        printf("%d\n", cp->data);
    }

    return (0);
}

void my_free(lemin_t *lemin, char *str)
{
    for (int i = 0; lemin->tab[i] != NULL; i++) {
        free(lemin->tab[i]);
    }
    free(str);
}

int main(void)
{
    lemin_t lemin;
    char *buffer = get_file();

    if (check_error(buffer) == 1)
        return (84);
    lemin.tab = my_str_to_word_array(buffer, '\n');
    for (int a = 0; lemin.tab[a]; a++) {
        if (lemin.tab[a][0] == '#' && lemin.tab[a][1] != '#')
            lemin.tab[a][0] = '\0';
    }
    for (int a = 0; lemin.tab[a]; a++)
        printf("%s\n", lemin.tab[a]);
    // find_bigger(&lemin);
    // start(&lemin);
    // my_free(&lemin, buffer);
    return (0);
}