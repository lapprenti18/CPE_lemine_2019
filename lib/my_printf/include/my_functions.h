/*
** EPITECH PROJECT, 2019
** my_functions.h
** File description:
** my_functions.h
*/

#ifndef MY_FUNCTIONS_H_
#define MY_FUNCTIONS_H_
#include <stdarg.h>

typedef struct my_functions_s
{
    char character;
    int (*func)(va_list);
} my_functions_t;

int my_string(va_list ap);
int my_char(va_list ap);
int my_int(va_list ap);
int my_binary_base(va_list ap);
int my_octal_base(va_list ap);
int my_hex_base_x(va_list ap);
int my_hex_base_big_x(va_list ap);
int my_unsigned(va_list ap);
int my_big_s(va_list ap);
int my_pointers(va_list ap);
int my_putnbr_base_unsigned(unsigned int nbr, char const *base);
int my_put_unsigned_nbr(unsigned int nb);
int my_showstr_remastered(char const *str);
int my_modulo(va_list ap);
char *reset_tmp(char *str);

#endif /* !MY_FUNCTIONS_H_ */