/*
** EPITECH PROJECT, 2019
** my_showstr_remastered.c
** File description:
** my_showstr_remastered.c
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>

int my_showstr_remastered(char const *str)
{
    if (str == NULL) {
        my_putstr("\\000");
        return (0);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 32) || (str[i] >= 127)) {
            if (str[i] <= 7) {
                my_putstr("\\00");
                my_putnbr_base(str[i], "01234567");
            } else if (str[i] == 127) {
                my_putstr("\\");
                my_putnbr_base(str[i], "01234567");
            } else {
                my_putstr("\\0");
                my_putnbr_base(str[i], "01234567");
            }
        } else {
            my_putchar (str[i]);
        }
    }
    return (0);
}