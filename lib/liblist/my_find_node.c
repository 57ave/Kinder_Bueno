/*
** EPITECH PROJECT, 2023
** day11
** File description:
** apply on node
*/

#include "my_list.h"
#include "stdlib.h"

list_t *my_find_node(list_t *begin,
    void const *data_ref, int (*cmp)())
{
    while (begin != NULL) {
        if (!cmp(begin->data, data_ref)) {
            return begin;
        }
        begin = begin->next;
    }
    return begin;
}
