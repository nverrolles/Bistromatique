/*
** EPITECH PROJECT, 2020
** infiniadddddddd
** File description:
** poui
*/

#include <stdio.h>
#include "../include/functions.h"

int main (int ac, char **av)
{
    int len;
    char *buff;
    int offset = 0;
    int count = 0;

    check_error(ac, av);
    len = my_getnbr(av[3]);
    buff = malloc(sizeof(char) * len + 1);
    for (;(len = read(0 , buff + offset , len - offset)) > 1; count++)
        offset = offset + len;
    if (count == 0) {
        write(2, "syntax error", 12);
        exit(84);
    }
    buff[offset] = '\0';
    my_putstr(decrypt_str(parser(encrypt_str(buff, av[1], av[2])), av[1],
    av[2]));
    free (buff);
    return 0;
}
