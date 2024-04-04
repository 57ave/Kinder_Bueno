/*
** EPITECH PROJECT, 2024
** secured
** File description:
** delete_hashtable.c
*/

#include "hashtable.h"
#include <stdlib.h>

int my_free(void *ptr)
{
    free(ptr);
    ptr = NULL;
    return 0;
}

int delete_list(list_t *list, size_t)
{
    if (list == NULL) {
        return -1;
    }
    return my_apply_on_nodes(list, &my_free);
}

void delete_hashtable(hashtable_t *ht)
{
    if (ht == NULL) {
        return;
    }
    ht_apply(ht, &delete_list);
    free(ht);
    return;
}
