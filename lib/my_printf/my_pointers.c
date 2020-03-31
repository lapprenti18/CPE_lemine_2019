/*
** EPITECH PROJECT, 2019
** my_pointers.c
** File description:
** my_pointers.c
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/my_functions.h"

int my_pointers_adress(long long nb)
{
    my_putstr("0x");
    my_putnbr_base(nb, "0123456789abcdef");
    return (0);
}

int my_pointers(va_list ap)
{
    my_pointers_adress(va_arg(ap, long long));
    return (0);
}

int my_print_modulo(void)
{
    my_putstr("%");
    return (0);
}

int my_modulo(__attribute__((unused))va_list ap)
{
    my_print_modulo();
    return (0);
}