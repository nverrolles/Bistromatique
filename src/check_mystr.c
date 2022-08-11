/*
** EPITECH PROJECT, 2020
** check error
** File description:
** checker
*/

#include "../include/functions.h"

void check_next_ope(char *str, int i)
{
    if (str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == '%' ||
    str[i + 1] == ')' || str[i + 1] == '+' || (str[i + 1] == '-' && str[i] !=
    '(')) {
        write(2, "syntax error", 12);
        exit(84);
    }
}

void check_str(char *str)
{
    int buff = my_strlen(str) - 1;

    if (str[0] == '*' || str[0] == '/' || str[0] == '%') {
        write(2, "syntax error", 12);
        exit(84);
    }
    if (str[buff] == '+' || str[buff] == '-' ||
    str[buff] == '*' || str[buff] == '/' || str[buff] == '%') {
        write(2, "syntax error", 12);
        exit(84);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (i > 0 && str[i] == '(' && (str[i - 1] >= '0' && str[i - 1] <=
        '9')) {
            write(2, "syntax error", 12);
            exit(84);
        }
    }
}

void check_allstr(char *str)
{
    int bracket = 0;

    check_str(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            bracket++;
        if (str[i] == ')' && bracket > 0)
            bracket--;
    }
    if (bracket != 0) {
        write(2, "syntax error", 12);
        exit(84);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '+'
        || str[i] == '-') {
            check_next_ope(str, i);
        }
        if (str[i] == '(')
            check_next_ope(str, i);
    }
}
