/*
** EPITECH PROJECT, 2023
** day11
** File description:
** apply on node
*/

#include "my_list.h"
#include <stdlib.h>

int my_apply_on_nodes(list_t *begin, int (*pf)(void *))
{
    while (begin->data != NULL) {
        pf(begin->data);
        if (begin->next == NULL) {
            break;
        }
        begin = begin->next;
    }
    return 0;
}
