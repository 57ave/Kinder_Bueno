/*
** EPITECH PROJECT, 2023
** day1&
** File description:
** del node
*/

#include "my_list.h"
#include <stdio.h>

int my_delete_nodes(list_t **begin, void const *data_ref, int (*cmp)())
{
    list_t *list = *begin;

    if (!cmp((list)->data, data_ref)) {
        *begin = (*begin)->next;
        return 0;
    }
    if (list->next == NULL)
        return 84;
    while ((list)->next != NULL) {
        if (!cmp((list)->next->data, data_ref)) {
            (list)->next = (list)->next->next;
        }
        list = (list)->next;
    }
    return 0;
}
