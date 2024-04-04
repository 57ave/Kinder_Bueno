/*
** EPITECH PROJECT, 2024
** secured
** File description:
** new_hashtable.c
*/

#include "hashtable.h"
#include <stdlib.h>

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *table = malloc(sizeof(hashtable_t));

    if (table == NULL || len <= 0 || hash == NULL) {
        return NULL;
    }
    table->hash = hash;
    table->size = len;
    table->list_array = malloc(sizeof(list_t *) * len);
    if (table->list_array == NULL) {
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        table->list_array[i] = malloc(sizeof(list_t));
        table->list_array[i]->data = NULL;
        table->list_array[i]->next = NULL;
    }
    return table;
}
