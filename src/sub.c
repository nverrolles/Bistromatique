/*
** EPITECH PROJECT, 2020
** infiniadddddddd
** File description:
** poui
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/functions.h"

char *do_sub(char *greatest, char *nbr, char *res)
{
    int i = 0;
    int tmp = 0;

    res = my_strcpy(res, greatest);
    while (nbr[i] != '\0' && nbr[i] != '-') {
        tmp += (greatest[i] - 48) - (nbr[i] - 48);
        if (tmp < 0) {
            res[i] = (tmp + 10) + 48;
            tmp = -1;
        } else {
            res[i] = tmp + 48;
            tmp = 0;
        }
        i++;
    }
    if (tmp != 0)
        return calc_sub_rest(greatest, res, i, tmp);
    else
        return print_result(my_revstr(res));
}

char *calc_sub_rest(char *greatest, char *res, int i, int tmp)
{
    while (greatest[i] != '\0' && greatest[i] != '-') {
        tmp += greatest[i] - 48;
        if (tmp < 0) {
            res[i] = (tmp + 10) + 48;
            tmp = -1;
        } else {
            res[i] = tmp + 48;
            tmp = 0;
        }
        i++;
    }
    if (tmp != 0 && greatest[i] == '-') {
        res[i] = 49;
        res[i + 1] = '-';
        res[i + 2] = '\0';
    }
    return finish_sub(greatest, res, i, tmp);
}

char *finish_sub(char *greatest, char *res, int i, int tmp)
{
    if (tmp != 0) {
        res[i] = 49;
        res[i + 1] = '\0';
    } else if (greatest[i] == '-') {
        res[i] = '-';
        res[i + 1] = '\0';
    } else
        res[i] = '\0';
    return print_result(my_revstr(res));
}

char *my_sub(char *s1, char *s2)
{
    char *nbr_one = my_revstr(clean_str(s1));
    char *nbr_two = my_revstr(clean_str(s2));

    if (s1[0] == '-') {
        nbr_one[my_strlen(nbr_one) + 1] = '\0';
        nbr_one[my_strlen(nbr_one)] = '-';
        return calc_sub(nbr_two, nbr_one);
    } else {
        nbr_two[my_strlen(nbr_two) + 1] = '\0';
        nbr_two[my_strlen(nbr_two)] = '-';
        return calc_sub(nbr_one, nbr_two);
    }
}

char *calc_sub(char *nbr_one, char *nbr_two)
{
    char *res = malloc_res(nbr_one, nbr_two);
    int len_diff = my_strlen(nbr_one) - my_strlen(nbr_two);

    if (len_diff == -1)
        len_diff = 1;
    if (check_greatest_nbr(my_revstr(nbr_two), my_revstr(nbr_one)) == 1) {
        return do_sub(my_revstr(nbr_two), my_revstr(nbr_one), res);
    } else {
        if (bigger(nbr_one, nbr_two + 1) == 0 && len_diff == 1) {
            nbr_one = my_strcat("-", nbr_one);
            do_sub(my_revstr(nbr_two + 1), my_revstr(nbr_one), res);
            res = my_strcat("-", res);
            return res;
        } else {
            return do_sub(my_revstr(nbr_one), my_revstr(nbr_two), res);
        }
    }
}