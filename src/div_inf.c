/*
** EPITECH PROJECT, 2020
** divinf
** File description:
** iuoiuo
*/

#include "../include/functions.h"

char *calc_div(char *s1, char *s2)
{
    char *res = "0";

    if (bigger(s2, s1) == 2) {
        return "0";
    }
    while (bigger(s1, mul_inf(s2, res)) != 0) {
        res = check_calc(res, "1");
    }
    res = check_calc(res, "-1");
    return res;
}

char *div_inf(char *s1, char *s2)
{
    check_zero(s2);
    if (s1[0] == '0') {
        return "0";
    }
    if (s1[0] == '-' && s2[0] == '-') {
        return calc_div(s1 + 1, s2 + 1);
    }
    if (s1[0] == '-' || s2[0] == '-') {
        if (s1[0] == '-') {
            return my_strcat("-", calc_div(s1 + 1, s2));
        } else {
            return my_strcat("-", calc_div(s1, s2 + 1));
        }
    }
    s1 = clean_str(s1);
    s2 = clean_str(s2);
    return calc_div(s1, s2);
}