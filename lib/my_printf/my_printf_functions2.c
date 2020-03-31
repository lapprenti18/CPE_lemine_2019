/*
** EPITECH PROJECT, 2019
** my_printf_functions2.c
** File description:
** my_printf_functions2.c
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/my_functions.h"

int my_binary_base(va_list ap)
{
    my_putnbr_base_unsigned(va_arg(ap, unsigned int), "01");
    return (0);
}

int my_octal_base(va_list ap)
{
    my_putnbr_base_unsigned(va_arg(ap, unsigned int), "01234567");
    return (0);
}

int my_hex_base_x(va_list ap)
{
    my_putnbr_base_unsigned(va_arg(ap, unsigned int), "0123456789abcdef");
    return (0);
}

int my_hex_base_big_x(va_list ap)
{
    my_putnbr_base_unsigned(va_arg(ap, unsigned int), "0123456789ABCDEF");
    return (0);
}

int my_unsigned(va_list ap)
{
    my_put_unsigned_nbr(va_arg(ap, unsigned int));
    return (0);
}