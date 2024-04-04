/*
** EPITECH PROJECT, 2024
** secured
** File description:
** ht_search.c
*/

#include "hashtable.h"

char *apply_ht_search(hashtable_t *ht, char *, int indice, int hash)
{
    list_t *node = my_find_node(ht->list_array[indice],
    (void *)&hash, &cmp_hash);
    struct data *data_node = node->data;

    return data_node->value;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int indice = 0;
    int hash = 0;

    if (ht == NULL || key == NULL) {
        return NULL;
    }
    hash = ht->hash(key, (int)ht->size);
    indice = hash % ht->size;
    if (ht->list_array == NULL)
        return NULL;
    if (ht->list_array[indice] == NULL)
        return NULL;
    if (my_find_node(ht->list_array[indice], (void *)&hash, &cmp_hash) == NULL)
        return NULL;
    return apply_ht_search(ht, key, indice, hash);
}
