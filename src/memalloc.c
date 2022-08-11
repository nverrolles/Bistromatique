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

char *malloc_res(char *nbr_one, char *nbr_two)
{
    char *res;

    if (my_strlen(nbr_one) > my_strlen(nbr_two))
        res = malloc(sizeof(char) * my_strlen(nbr_one) + 2);
    else
        res = malloc(sizeof(char) * my_strlen(nbr_two) + 2);
    return res;
}

char *clean_str(char *nbr)
{
    int i;
    int z = 0;
    char *cleaned;

    while (nbr[z] == '+' || nbr[z] == '-' || nbr[z] == '0')
        z++;
    i = z;
    while (nbr[i] >= '0' && nbr[i] <= '9')
        i++;
    cleaned = malloc_cleaned(cleaned, i, nbr, z);
    return cleaned;
}

char *malloc_cleaned(char *cleaned, int i, char *nbr, int z)
{
    cleaned = malloc(sizeof(char) * (i - z) + 3);
    if ((i - z) < 1) {
        cleaned[0] = '0';
        cleaned[1] = '\0';
    } else
        cleaned = my_strcpy_from(cleaned, nbr, i, z);
    return cleaned;
}

char *my_strcpy_from(char *dest, char *src, int end, int start)
{
    int i = 0;

    while (start < end) {
        dest[i] = src[start];
        start++;
        i++;
    }
    dest[i] = '\0';
    return dest;
}