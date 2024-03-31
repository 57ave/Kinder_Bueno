/*
** EPITECH PROJECT, 2023
** day11
** File description:
** my_list_size
*/

#include "my_list.h"
#include <stdlib.h>

int my_list_size(list_t const *begin)
{
    int size = 0;

    while (begin != NULL) {
        begin = begin->next;
        size++;
    }
    return size;
}
