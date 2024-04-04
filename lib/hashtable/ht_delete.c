/*
** EPITECH PROJECT, 2024
** secured
** File description:
** ht_delete.c
*/

#include "hashtable.h"

int cmp_hash(void *hash, void *hash_ref)
{
    if (hash == NULL)
        return 84;
    if (*(int *)hash == *(int *)hash_ref)
        return 0;
    return 1;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int hash = 0;
    int indice = 0;

    if (ht == NULL)
        return 84;
    hash = ht->hash(key, (int)ht->size);
    indice = hash % ht->size;
    if (ht->list_array == NULL)
        return 84;
    if (ht->list_array[indice] == NULL)
        return 84;
    if (my_delete_nodes(&ht->list_array[indice],
    (void *)&hash, &cmp_hash) == 84)
        return 84;
    return 0;
}
