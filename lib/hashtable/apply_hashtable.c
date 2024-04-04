/*
** EPITECH PROJECT, 2024
** secured
** File description:
** ht_insert.c
*/

#include "hashtable.h"

int ht_apply(hashtable_t *ht, int (*applyf)(list_t *, size_t))
{
    for (size_t i = 0; i < ht->size; i++) {
        applyf(ht->list_array[i], i);
    }
    return 0;
}
