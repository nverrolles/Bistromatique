/*
** EPITECH PROJECT, 2020
** infiniadddddddd
** File description:
** poui
*/

#include "../include/functions.h"

char *parser(char *calc)
{
    prio_pos_t trash;
    trash.prio = 0;
    mainlist_t *mymainlist = initfirstlist();

    check_allstr(calc);
    for (int i = 0; calc[i] != '\0'; i++) {
        if (check_char(calc, i) == 1 || check_char(calc, i) == 0)
            addpriotolist(mymainlist, calc[i], (trash.prio + check_char(calc,
                    i)));
        trash.pos = i;
        while (check_nbr_parser(calc, i) != 2 && calc[i] != '\0')
            i++;
        i = check_if_add(calc, trash, i, mymainlist);
        trash.prio += check_par(calc, i);
        if (calc[i] == '\0')
            break;
    }
    evalexpr(mymainlist);
    return (mymainlist->listNb->nb);
}

int check_if_add(char *calc, prio_pos_t trash, int i, mainlist_t *mymainlist)
{
    if (i != trash.pos) {
        if (calc[trash.pos] == '-' && (i - trash.pos) == 1) {
            addnbtolist(mymainlist, "-1");
            addpriotolist(mymainlist, '*', (trash.prio + 1));
        } else
            addnbtolist(mymainlist, my_strdup_from_to(calc, trash.pos, i));
        return (i - 1);
    }
    return i;
}

int check_par(char *str, int i)
{
    if (str[i] == '(' && check_between_par(str, i) == 2)
        return 2;
    if (str[i] == ')' && check_before_closing(str, i) == 2)
        return -2;
    return 0;
}

int check_before_closing(char *calc, int i)
{
    while (calc[i] != '(') {
        if (calc[i] == '/' || calc[i] == '*' || calc[i] == '%'
            || calc[i] == '+' || (calc[i] == '-' && calc[i - 1] != '('))
            return 2;
        i--;
    }
    return 0;
}