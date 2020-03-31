/*
** EPITECH PROJECT, 2019
** my_strncmp.c
** File description:
** my_strncmp.c
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i += 1) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}
