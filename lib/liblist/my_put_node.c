/*
** EPITECH PROJECT, 2023
** day11
** File description:
** my_param_to_list
*/

#include "my_list.h"
#include <stdlib.h>

int my_put_node(list_t **list, void *data)
{
    list_t *node = NULL;

    node = malloc(sizeof(list_t));
    if (node == NULL) {
        return 1;
    }
    node->data = data;
    node->next = *list;
    *list = node;
    return 0;
}
