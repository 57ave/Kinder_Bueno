/*
** EPITECH PROJECT, 2024
** secured
** File description:
** hash.c
*/

#include <limits.h>
#include <stddef.h>

static unsigned int lose_lose_hash(char *key, int len)
{
    unsigned int hash = 0;
    int c = 0;

    if (key == NULL || len <= 0)
        return 0;
    if (len > 12242)
        len %= 12242;
    for (int i = 0; i != len; i++) {
        c = *key;
        hash += c;
        key++;
    }
    return hash;
}

static unsigned int sdbm_hash(char *key, int len)
{
    unsigned int hash = lose_lose_hash(key, len);
    int c = 0;

    if (key == NULL || len <= 0)
        return 0;
    if (len > 12242)
        len %= 12242;
    for (int i = 0; i != len; i++) {
        c = *key;
        hash = c + (hash << 6) + (hash << 16) - hash;
        key++;
    }
    return hash;
}

int hash(char *key, int len)
{
    unsigned int hash = 5381 << sdbm_hash(key, len);
    int c = 0;

    if (key == NULL || len <= 0)
        return 84;
    if (len > 12242)
        len %= 12242;
    for (int i = 0; i != len; i++) {
        c = *key;
        hash = ((hash << 5) + hash) + c;
        key++;
    }
    if (hash > INT_MAX)
        return hash % INT_MAX;
    return hash;
}
