/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** my_strcmp.c
*/

int my_strcmp(char const *s1, char const *s2)
{
    if (!*s1 || !*s2)
        return (15);
    for (int i = 0; s1[i] != '\0'; i += 1) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}