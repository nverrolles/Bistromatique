/*
** EPITECH PROJECT, 2020
** infiniadddddddd
** File description:
** poui
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/functions.h"

char *print_result(char *res)
{
    int i = 0;
    int null_num = 1;

    (res[0] == '-') ? (i = 1) : (i = 0);
    for (int i = 0; res[i] != '\0'; i++) {
        if (res[i] != '0') {
            null_num = 0;
        }
    }
    if (null_num == 1) {
        return "0";
    }
    if (my_strlen(res) == 1 && res[0] == '0') {
        return res;
    }
    while (res[i] == '0') {
        for (int j = i; res[j] != '\0'; j++) {
            res[j] = res[j + 1];
        }
    }
    return res;
}