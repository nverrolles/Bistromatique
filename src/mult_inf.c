/*
** EPITECH PROJECT, 2020
** multinf
** File description:
** ouioui
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../include/functions.h"

char *calcinf(char *s1, char *s2)
{
    int size = my_strlen(s1) + my_strlen(s2);
    char *tt = malloc(sizeof(char) * size + 1);

    for (int i = my_strlen(s1) - 1; i >= 0; i--)
        for (int y = my_strlen(s2) - 1; y >= 0; y--) {
            tt[i+y+1] += (s1[i] - '0') * (s2[y] - '0');
            tt[i+y] += tt[i+y+1] / 10;
            tt[i+y+1] %= 10;
        }
    for (int a = 0; a < size; a++)
        tt[a] += '0';
    return print_result(tt);
}

char *mul_inf(char *s1, char *s2)
{
    if (s1[0] == '-' && s2[0] == '-') {
        return calcinf(s1 + 1, s2 + 1);
    }
    if (s1[0] == '-' || s2[0] == '-') {
        if (s1[0] == '-') {
            return my_strcat("-", calcinf(s1 + 1, s2));
        } else {
            return my_strcat("-", calcinf(s1, s2 + 1));
        }
    }
    s1 = clean_str(s1);
    s2 = clean_str(s2);
    if (s1[0] == '0' || s2[0] == '0') {
        return "0";
    }
    return calcinf(s1, s2);
}
