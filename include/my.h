/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "struct.h"

char *my_strcat(char *start, char *line);
char **my_str_to_word_array(char *str, char separator);
int my_strlen(char const *str);
int my_showstr_remastered(char const *str);
int my_putnbr_base_unsigned(unsigned int nbr, char const *base);
int my_putnbr_base(long nbr, char const *base);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
void my_printf(char *str, ...);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
void add_node_at_front(int value, node_t **node);
void add_node_at_back(char *line, node_t **node);
char *my_check(char **tunnels, char *string);
void get_nb_of_ants(lemin_t *lemin, char *string);
void add_node_at_back(char *line, node_t **node);
void my_free(lemin_t *lemin, char *str);
void create_rooms(char **tab, node_t *head);
node_t *get_room(node_t *head, char *to_find);
int tab_len(char **tab);
int parser(lemin_t *lemin, char *str);

#endif /* !MY_H_ */
