/*
** EPITECH PROJECT, 2019
** my_put_unsigned_nbr.c
** File description:
** my_put_unsigned_nbr.c
*/

#include "include/my.h"
#include "include/my_functions.h"

int my_put_nb_aux2(unsigned int nb)
{
    if (nb < 10) {
        my_putchar(nb + '0');
    } else {
        my_put_nb_aux2(nb / 10);
        my_put_nb_aux2(nb % 10);
    }
    return (0);
}

int my_put_unsigned_nbr(unsigned int nb)
{
    my_put_nb_aux2(0 + nb);
    return (0);
}