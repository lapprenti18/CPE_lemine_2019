/*
** EPITECH PROJECT, 2019
** my_printf_functions.c
** File description:
** my_print_functions.c
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/my_functions.h"

int my_string(va_list ap)
{
    my_putstr(va_arg(ap, char *));
    return (0);
}

int my_char(va_list ap)
{
    my_putchar(va_arg(ap, int));
    return (0);
}

int my_int(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
    return (0);
}

int my_big_s(va_list ap)
{
    my_showstr_remastered(va_arg(ap, char *));
    return (0);
}