/*
** EPITECH PROJECT, 2020
** infiniadddddddd
** File description:
** poui
*/

#include "../include/functions.h"

char *check_calc(char *s1, char *s2)
{
    if (s1[0] == '-' && s2[0] == '-') {
        return my_strcat("-", my_add(s1, s2));
    } else if (s1[0] != '-' && s2[0] != '-')
        return my_add(s1, s2);
    else
        return my_sub(s1, s2);
}

int check_greatest_nbr(char *neg, char *pos)
{
    if ((my_strlen(neg) - 1) == my_strlen(pos))
        return (check_biggest(neg, pos));
    else if ((my_strlen(neg) - 1) > my_strlen(pos))
        return 1;
    else
        return 0;
}

int check_biggest(char *neg, char *pos)
{
    if (*neg == *pos)
        return check_biggest(neg + 1, pos + 1);
    if (*neg != '-') {
        if (*neg > *pos)
            return 1;
        else
            return 0;
    }
    return 0;
}

int bigger(char *s1, char *s2)
{
    int bigger = 1;

    if (my_strlen(s1) > my_strlen(s2)) {
        return 2;
    }
    if (my_strlen(s1) < my_strlen(s2)) {
        return 0;
    }
    for (int i = my_strlen(s1) - 1; i >= 0; i--) {
        if (s1[i] > s2[i]) {
            bigger = 2;
        }
        if (s1[i] < s2[i]) {
            bigger = 0;
        }
    }
    return bigger;
}