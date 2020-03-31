/*
** EPITECH PROJECT, 2019
** my_print_f.c
** File description:
** my_print_f.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include <stdarg.h>
#include "include/my_functions.h"

static const my_functions_t tab[] = {
    {'i', &my_int},
    {'d', &my_int},
    {'s', &my_string},
    {'c', &my_char},
    {'b', &my_binary_base},
    {'o', &my_octal_base},
    {'x', &my_hex_base_x},
    {'X', &my_hex_base_big_x},
    {'u', &my_unsigned},
    {'S', &my_big_s},
    {'p', &my_pointers},
    {'%', &my_modulo},
    {'\0', NULL},
};

void board(char c, va_list ap)
{
    for (int j = 0; tab[j].character != '\0'; j++) {
        if (c == tab[j].character) {
            tab[j].func(ap);
        }
    }
}

void my_printf(char *str, ...)
{
    va_list ap;
    int j = 0;
    char *tmp = malloc(sizeof(char) * my_strlen(str) + 30);
    tmp[0] = '\0';
    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            i += 1;
            j = 0;
            reset_tmp(tmp);
            board(str[i], ap);
        } else {
            tmp[j] = str[i];
            tmp[j + 1] = '\0';
            j++;
        }
    }
    my_putstr(tmp);
    free(tmp);
    va_end(ap);
}