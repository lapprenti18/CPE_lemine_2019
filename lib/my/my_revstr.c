/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** my_revstr.c task03 day06
*/

#include <stdio.h>

char *my_revstr(char *str)
{
    char temporary = 0;
    int j = 0;
    int i = 0;
    int length = 0;

    for (; str[j] != 0; j++);
    length = j;
    j--;
    while (i < j) {
        temporary = str [i];
        str [i] = str [j];
        str [j] = temporary;
        i++;
        j--;
    }
    str[length] = 0;
    return (str);
}
