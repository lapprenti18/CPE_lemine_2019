/*
** EPITECH PROJECT, 2019
** my_putnbr_base.c
** File description:
** my_putnbr_base.c
*/

#include <stdio.h>
#include <unistd.h>
#include "include/my.h"

int my_putnbr_base(long nbr, char const *base)
{
    int bas = my_strlen(base);
    if (nbr >= bas) {
        my_putnbr_base(nbr / bas, base);
    }
    my_putchar(base[nbr%bas]);
    return (0);
}

int my_putnbr_base_unsigned(unsigned int nbr, char const *base)
{
    unsigned int bas = my_strlen(base);
    if (nbr >= bas) {
        my_putnbr_base(nbr / bas, base);
    }
    my_putchar(base[nbr%bas]);
    return (0);
}