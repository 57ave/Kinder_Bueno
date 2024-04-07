/*
** EPITECH PROJECT, 2024
** server
** File description:
** register a user/client
*/

#include "account.h"
#include "macro.h"
#include "my_string.h"

hashtable_t *init_account_tab(void)
{
    hashtable_t *ht = new_hashtable(&hash, LEN_TAB_ACCOUNT);

    if (ht == NULL) {
        return ht;
    }
    return ht;
}

enum code_account new_account(hashtable_t *ht, struct data_128 *data)
{
    if (ht_search(ht, (char *)data->key) != NULL) {
        return ALREADY_EXIST;
    }
    if (ht_insert(ht, (char *)data->key, (char *)data->value)) {
        return FAIL;
    }
    return OK;
}

enum code_account connect_account(hashtable_t *ht, struct data_128 *data)
{
    char *password = ht_search(ht, (char *)data->key);

    if (password == NULL) {
        return NOT_FOUND;
    }
    if (my_strcmp(password, (char *)data->value) != 0) {
        return WRONG_PASSWORD;
    }
    return OK;
}
