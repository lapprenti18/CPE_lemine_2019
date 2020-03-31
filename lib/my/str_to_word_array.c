/*
** EPITECH PROJECT, 2020
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>

int nb_of_args(char *str, char separator)
{
    int i = 0;
    int res = 0;

    while (str[i++] != 0) {
        if (str[i] == separator && str[i + 1] != separator)
            res += 1;
    }
    return (res + 1);
}

char **fill_array(char *str, char separator, char **array)
{
    int x = 0;
    int y = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == separator && str[i + 1] != separator) {
            array[y][x] = 0;
            y += 1;
            x = 0;
            i += 1;
        } else if (str[i] == separator && str[i + 1] == separator) {
            i += 1;
        } else {
            array[y][x] = str[i];
            x += 1;
            i += 1;
        }
    }
    array[y][x] = 0;
    array[y + 1] = NULL;
    return (array);
}

int line_length(char *buffer)
{
    int i = 0;

    for (; buffer[i] != '\n' && buffer[i] != 0; i++);
    return (i);
}

char **my_str_to_word_array(char *str, char separator)
{
    int length = 0;
    char **array;

    if (str == NULL || separator == 0)
        return (NULL);

    length = line_length(str);
    array = malloc(sizeof(char *) * (nb_of_args(str, separator) + 2));

    for (int j = 0; j < (nb_of_args(str, separator) + 1); j += 1)
        array[j] = malloc(sizeof(char) * (length + 1));

    return (fill_array(str, separator, array));
}