/*
** EPITECH PROJECT, 2020
** infiniadddddddd
** File description:
** poui
*/

#include "../include/functions.h"

char *calc(char *x, char *y, char sign)
{
    switch (sign) {
        case '+':
            return check_calc(x, y);
        case '-':
            return prepare_sub(x, y);
        case '*':
            return mul_inf(x, y);
        case '/':
            return div_inf(x, y);
        case '%':
            return modinf(x, y);
        default:
            return "0";
    }
}

list_sign_and_prio_t *checksignhead(int place, mainlist_t *mylist,
                                    list_sign_and_prio_t *signhead)
{
    for (int a = 0; a < (place - 1); a++)
        mylist->listSignAndPrio = mylist->listSignAndPrio->next;
    if (mylist->listSignAndPrio->next != NULL &&
    mylist->listSignAndPrio->next->next == NULL &&
    mylist->listSignAndPrio != signhead)
        mylist->listSignAndPrio->next = NULL;
    else if (mylist->listSignAndPrio == signhead) {
        if (mylist->listSignAndPrio->next == NULL)
            return signhead;
        else if (mylist->listSignAndPrio->prio >=
        mylist->listSignAndPrio->next->prio)
            signhead = mylist->listSignAndPrio->next;
        else
            signhead->next = mylist->listSignAndPrio->next->next;
    } else {
        mylist->listSignAndPrio->next = mylist->listSignAndPrio->next->next;
    }
    return signhead;
}

int checkplace(int place, mainlist_t *mylist)
{
    int degree = -1;
    place = 0;

    for (int count = 0; mylist->listSignAndPrio != NULL; count++) {
        if (mylist->listSignAndPrio->prio > degree) {
            degree = mylist->listSignAndPrio->prio;
            place = count;
        }
        mylist->listSignAndPrio = mylist->listSignAndPrio->next;
    }
    return place;
}

void evalexpr(mainlist_t *mylist)
{
    list_sign_and_prio_t *signhead = mylist->listSignAndPrio;
    list_nb_t *nbhead = mylist->listNb;
    int place = 0;
    int oui = 1;

    while (mylist->listSignAndPrio != NULL && mylist->listNb->next != NULL) {
        place = checkplace(place, mylist);
        mylist->listSignAndPrio = signhead;
        for (int a = 0; a < place; a++) {
            mylist->listSignAndPrio = mylist->listSignAndPrio->next;
            mylist->listNb = mylist->listNb->next;
        }
        mylist->listNb->nb = calc(mylist->listNb->nb, mylist->listNb->next->nb,
        mylist->listSignAndPrio->sign);
        mylist->listNb->next = mylist->listNb->next->next;
        mylist->listSignAndPrio = signhead;
        mylist->listNb = nbhead;
        signhead = checksignhead(place, mylist, signhead);
        mylist->listSignAndPrio = signhead;
        oui++;
    }
}