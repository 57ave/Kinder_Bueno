/*
** EPITECH PROJECT, 2023
** day11
** File description:
** my_add_in_sorted_list
*/

#include "my_list.h"
#include <stdlib.h>

void add_node(list_t *list, void *data)
{
    list_t *node = malloc(sizeof(list_t));

    node->data = data;
    node->next = list->next;
    list->next = node;
}
