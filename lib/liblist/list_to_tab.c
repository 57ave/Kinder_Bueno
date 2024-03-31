/*
** EPITECH PROJECT, 2023
** day11
** File description:
** my_add_in_sorted_list
*/

#include "my_list.h"
#include <stdlib.h>

char **list_to_tab(list_t *list, char *(*data_to_str)(void *data))
{
    int list_size = my_list_size(list);
    char **tab = malloc(sizeof(char *) * (list_size + 1));
    int i = 0;

    for (i = 0; list->next != NULL; i++) {
        tab[i] = data_to_str(list->data);
        list = list->next;
    }
    tab[i] = NULL;
    return tab;
}
