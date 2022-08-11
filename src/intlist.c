/*
** EPITECH PROJECT, 2020
** infiniadddddddd
** File description:
** poui
*/

#include "../include/functions.h"

void addpriotolist(mainlist_t *mainlist, char op, int _prio)
{
    list_sign_and_prio_t *head = mainlist->listSignAndPrio;
    list_sign_and_prio_t *newlistprio = malloc(sizeof(list_sign_and_prio_t));

    newlistprio->sign = op;
    newlistprio->prio = _prio;
    newlistprio->next = NULL;

    if (mainlist->listSignAndPrio != NULL) {
        while (mainlist->listSignAndPrio->next != NULL) {
            mainlist->listSignAndPrio = mainlist->listSignAndPrio->next;
        }
        mainlist->listSignAndPrio->next = newlistprio;
        mainlist->listSignAndPrio = head;
    } else {
        mainlist->listSignAndPrio = newlistprio;
    }
}

void addnbtolist(mainlist_t *mainlist, char *nb)
{
    list_nb_t *head = mainlist->listNb;
    list_nb_t *newlistnb = malloc(sizeof(list_nb_t));

    newlistnb->nb = my_strdup(nb);
    newlistnb->next = NULL;

    if (mainlist->listNb != NULL) {
        while (mainlist->listNb->next != NULL) {
            mainlist->listNb = mainlist->listNb->next;
        }
        mainlist->listNb->next = newlistnb;
        mainlist->listNb = head;
    } else {
        mainlist->listNb = newlistnb;
    }
}

void deleteeleminlist(mainlist_t *mainlist)
{
    list_nb_t *tmp1 = NULL;
    list_sign_and_prio_t  *tmp2 = NULL;

    while (mainlist->listNb != NULL) {
        tmp1 = mainlist->listNb;
        mainlist->listNb = mainlist->listNb->next;
        free(tmp1);
    }
    while (mainlist->listSignAndPrio != NULL) {
        tmp2 = mainlist->listSignAndPrio;
        mainlist->listSignAndPrio = mainlist->listSignAndPrio->next;
        free(tmp2);
    }
    free(mainlist);
}

mainlist_t *initfirstlist(void)
{
    mainlist_t *mymainlist = malloc(sizeof(mainlist_t));
    mymainlist->listNb = NULL;
    mymainlist->listSignAndPrio = NULL;

    return mymainlist;
}