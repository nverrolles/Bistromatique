/*
** EPITECH PROJECT, 2020
** infiniadddddddd
** File description:
** poui
*/

#include "../include/functions.h"

char *prepare_sub(char *x, char *y)
{
    if (x[0] == '-') {
        y = my_strcat("-", y);
        return check_calc(x, y);
    }
    if (y[0] == '-')
        return check_calc(x, y + 1);
    return my_sub(x, y);
}

int check_between_par(char *calc, int i)
{
    while (calc[i] != ')') {
        if (calc[i] == '/' || calc[i] == '*' || calc[i] == '%'
        || calc[i] == '+' || (calc[i] == '-' && i > 0 && calc[i - 1] != '('))
            return 2;
        i++;
    }
    return 0;
}

char *my_strdup_from_to(char *str, int beg, int end)
{
    char *tmp = malloc(sizeof(char) * end - beg + 1);
    int i = 0;

    while (beg < end) {
        tmp[i] = str[beg];
        beg++;
        i++;
    }
    tmp[i] = '\0';
    return tmp;
}

int check_char(char *calc, int i)
{
    if (calc[i] == '+' || (calc[i] == '-' && i > 0 && calc[i - 1] != '('))
        return 0;
    if (calc[i] == '/' || calc[i] == '*' || calc[i] == '%')
        return 1;
    return 2;
}

int check_nbr_parser(char *calc, int i)
{
    if (calc[i] >= '0' && calc[i] <= '9')
        return 0;
    if (calc[i] == '/' || calc[i] == '*' || calc[i] == '%' || calc[i] == '+'
    || (calc[i] == '-' && i > 0 && calc[i - 1] != '(') ||
    calc[i] == '(' || calc[i] == ')')
        return 2;
    return 0;
}