/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H

    #include "my_list.h"
    #include <stddef.h>

struct data {
    int hash;
    char *value;
    struct data *next;
};

typedef struct hashtable {
    size_t size;
    int (*hash)(char *, int);
    list_t **list_array;
} hashtable_t;

int hash(char *key, int len);

hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

int ht_apply(hashtable_t *ht, int (*pf)(list_t *, size_t));

int cmp_hash(void *hash, void *hash_ref);
#endif /* HASHTABLE_H */
