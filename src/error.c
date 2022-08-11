/*
** EPITECH PROJECT, 2020
** infiniadddddddd
** File description:
** poui
*/

#include "../include/functions.h"

void check_error(int ac, char **av)
{
    if (ac == 2) {
        if (my_strlen(av[1]) == 2 && av[1][0] == '-' && av[1][1] == 'h') {
            my_putstr("USAGE\n"
            "./calc base operators size_read\n\n"
            "DESCRIPTION\n"
            "- base: all the symbols of the base\n"
            "- operators: the symbols for the parentheses"
            " and the 5 operators\n"
            "- size_read: number of characters to be read\n");
            exit(0);
        } else {
            write(2, "syntax error", 12);
            exit(84);
        }
    }
    if (ac != 4) {
        write(2, "syntax error", 12);
        exit(84);
    }
    check_other_error(av);
}

void check_other_error(char **av)
{
    if (my_getnbr(av[3]) < 1) {
        write(2, "syntax error", 12);
        exit(84);
    }
    if (my_strlen(av[1]) != 10 || my_strlen(av[2]) != 7) {
        write(2, "syntax error", 12);
        exit(84);
    }
}

void check_zero(char *str)
{
    int is_null = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '0') {
            is_null = 0;
        }
    }
    if (is_null == 1) {
        write(2, "error", 5);
        exit(84);
    }
}
