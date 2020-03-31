/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/

void my_putchar(char c);

int my_put_nb_aux(unsigned int nb)
{
    if (nb <10) {
        my_putchar(nb + '0');
    } else {
        my_put_nb_aux(nb / 10);
        my_put_nb_aux(nb % 10);
    }
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb <0) {
        my_putchar('-');
        my_put_nb_aux(0 - nb);
    } else {
        my_put_nb_aux(0 + nb);
    }
    return (0);
}