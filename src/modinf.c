/*
** EPITECH PROJECT, 2020
** mod inf
** File description:
** modinf
*/

#include "../include/functions.h"

char *modinf(char *s1, char *s2)
{
    char *tt = malloc(sizeof(char) * my_strlen(s1) + 1);
    char *a = malloc(sizeof(char) * my_strlen(s1) + 1);
    char *b = malloc(sizeof(char) * my_strlen(s1) + 1);

    check_zero(s2);
    a = div_inf(s1, s2);
    b = mul_inf(a, s2);
    tt = my_sub(s1, b);

    return tt;
}
