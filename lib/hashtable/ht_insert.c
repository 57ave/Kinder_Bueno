/*
** EPITECH PROJECT, 2024
** secured
** File description:
** ht_insert.c
*/

#include "hashtable.h"
#include "my_string.h"
#include <stdlib.h>

static void check_null_list(hashtable_t *ht, list_t **list_adrr,
    list_t *list_copy, int indice)
{
    if (ht->list_array[indice] == NULL) {
        list_adrr = &ht->list_array[indice];
        list_copy = malloc(sizeof(list_t));
        list_copy->next = *list_adrr;
        *list_adrr = list_copy;
    }
}

static void apply_ht_insert(hashtable_t *ht, char *key, char *value)
{
    int hash = ht->hash(key, (int)ht->size);
    int indice = hash % ht->size;
    struct data *new_data = malloc(sizeof(struct data));
    list_t **list_adrr = NULL;
    list_t *list_copy = NULL;

    new_data->hash = hash;
    new_data->value = my_strdup(value);
    check_null_list(ht, list_adrr, list_copy, indice);
    if (ht->list_array[indice]->data == NULL) {
        ht->list_array[indice]->data = (void *)new_data;
    } else {
        list_adrr = &ht->list_array[indice];
        my_put_node(list_adrr, (void *)new_data);
    }
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int hash = 0;
    int indice = 0;
    list_t *node = NULL;

    if (ht == NULL || key == NULL || value == NULL)
        return 84;
    hash = ht->hash(key, (int)ht->size);
    indice = hash % ht->size;
    node = my_find_node(ht->list_array[indice], (void *)&hash, &cmp_hash);
    if (node != NULL)
        my_delete_nodes(&ht->list_array[indice], (void *)&hash, &cmp_hash);
    apply_ht_insert(ht, key, value);
    return 0;
}
