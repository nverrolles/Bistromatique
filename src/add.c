/*
** EPITECH PROJECT, 2020
** infiniadddddddd
** File description:
** poui
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/functions.h"

char *calc_add(char *longest, char *nbr)
{
    int tmp = 0;
    int i = 0;
    char *res = malloc(sizeof(char) * my_strlen(longest) + 2);

    while (nbr[i] != '\0' && longest[i] != '-') {
        tmp += (longest[i] - 48) + (nbr[i] - 48);
        if (tmp > 9) {
            res[i] = tmp - 10 + 48;
            tmp = tmp / 10;
        } else {
            res[i] = tmp + 48;
            tmp = 0;
        }
        i++;
    }
    return calc_add_rest(i, tmp, res, longest);
}

char *calc_add_rest(int i, int tmp, char *res, char *longest)
{
    while (longest[i] != '\0' && longest[i] != '-') {
        tmp = longest[i] - 48 + tmp;
        if (tmp > 9) {
            res[i] = tmp - 10 + 48;
            tmp = tmp / 10;
        } else {
            res[i] = tmp + 48;
            tmp = 0;
        }
        i++;
    }
    if (tmp != 0 && longest[i] == '-') {
        res[i] = 49;
        res[i + 1] = '-';
        res[i + 2] = '\0';
    }
    return finish_add(tmp, i, res, longest);
}

char *finish_add(int tmp, int i, char *res, char *longest)
{
    if (tmp != 0 && longest[i] != '-') {
        res[i] = 49;
        res[i + 1] = '\0';
    } else if (longest[i] == '-' && tmp == 0) {
        res[i] = '-';
        res[i + 1] = '\0';
    } else
        res[i] = '\0';
    return my_revstr(res);

}

char *my_add(char *s1, char *s2)
{
    char *nbr_one = my_revstr(clean_str(s1));
    char *nbr_two = my_revstr(clean_str(s2));

    if (my_strlen(nbr_one) > my_strlen(nbr_two)) {
        return calc_add(nbr_one, nbr_two);
    } else {
        return calc_add(nbr_two, nbr_one);
    }
}